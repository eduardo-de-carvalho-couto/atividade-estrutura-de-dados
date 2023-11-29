#include <iostream>

using namespace std;

typedef struct no{
    int info;
    no *prox;
    no *ant;
}No;

typedef struct listaDupla{
    No *inicio;
    No *fim;
    int tamanho;
}ListaDupla;

void imprimeRecursivo(No *no);
No *buscaRecursiva(No *no, int info);

ListaDupla *inicializar()
{
    ListaDupla *LD = new ListaDupla();
    LD->inicio = LD->fim = NULL;
    LD->tamanho = 0;

    return LD;
}

int ListaVazia(ListaDupla *LD)
{
    return (LD->inicio == LD->fim)&&(LD->tamanho == 0);
}

ListaDupla *inserirInicio(ListaDupla *LD, int k)
{
    No *novo = new No();
    novo->info = k;
    novo->ant = NULL;

    if(ListaVazia(LD)){
        novo->prox = NULL;
        LD->inicio = LD->fim = novo;
        LD->tamanho++;
    } else {
        novo->prox = LD->inicio;
        LD->inicio->ant = novo;
        LD->inicio = novo;
        LD->tamanho++;
    }

    return LD;
}

ListaDupla *inserir(ListaDupla *LD, int k, int posicao)
{
    No *aux = LD->inicio;

    No *novo = new No();
    novo->info = k;
    novo->ant = NULL;

    //INSERIR NA LISTA VAZIA
    if(ListaVazia(LD)){
        novo->prox = NULL;
        LD->inicio = LD->fim = novo;
        LD->tamanho++;

        return LD;
    }

    for(int i = 1;i <= LD->tamanho + 1;i++){
        //INSERIR NO INICIO DA LISTA
        if(i == posicao && i == 1){
            LD->inicio->ant = novo;
            novo->prox = LD->inicio;
            LD->inicio = novo;
            LD->tamanho++;

            return LD;
        }

        //INSERIR NO FINAL DA LISTA
        if(i == posicao && i == LD->tamanho + 1){
            LD->fim->prox = novo;
            novo->ant = LD->fim;
            LD->fim = novo;
            LD->tamanho++;

            return LD;
        }

        //INSERIR NO MEIO DA LISTA
        if(i == posicao) {
            aux->ant->prox = novo;
            novo->ant = aux->ant;
            novo->prox = aux;
            aux->ant = novo;
            LD->tamanho++;

            return LD;
        }

        //ESSE IF GARANTE QUE AUX RECEBE PROX SOMENTE SE ESTIVER DENTRO DO TAMANHO DA LISTA
        if(i <= LD->tamanho){
            aux = aux->prox;
        }
    }

    if(posicao > LD->tamanho + 1){
        cout<<"Posição inválida\n";
        //LD->fim->prox = novo;
        //novo->ant = LD->fim;
        //LD->fim = novo;
        //LD->tamanho++;

        return LD;
    }
}

void consultarLista(ListaDupla *LD)
{
    if(ListaVazia(LD)){
        cout <<"LISTA VAZIA!!"<<endl;
        return;
    }

    No *aux = LD->inicio;
    cout << "(RECURSIVO) Número = " << aux->info<< "\n";
    imprimeRecursivo(aux->prox);
}

//RECURSIVIDADE
void imprimeRecursivo(No *no)
{
    No *aux = no;
    if(aux == NULL){
        return;
    }
    cout << "(RECURSIVO) Número = " << aux->info<< "\n";
    imprimeRecursivo(aux->prox);
}

No *buscar(ListaDupla *LD, int info)
{
    No *aux = LD->inicio;
    if(ListaVazia(LD)){
        cout <<"LISTA VAZIA!!"<<endl;
        return NULL;
    } else {
        /*
        for(aux=LD->inicio;aux!=NULL;aux=aux->prox){
            if(aux->info == info){
                return aux;
            }
        }
        */
        if(aux->info == info){
            return aux;
        }

        buscaRecursiva(aux->prox, info);
    }

}

//RECURSIVO
No *buscaRecursiva(No *no, int info)
{
    No *aux = no;
    if(aux->info == info){
        return aux;
    }

    if(aux->prox == NULL){
        cout <<"Item não encontrado na lista.";
        return NULL;
    }

    buscaRecursiva(aux->prox, info);
}

ListaDupla *excluir(ListaDupla *LD, No *CP)
{
    if(CP == NULL){
        cout<<"Esse nó não existe na lista!\n";

        return LD;
    }

    if(CP->ant == NULL){
        LD->inicio = CP->prox;
    } else if(CP->prox == NULL){
        CP->ant->prox = NULL;
        LD->fim = CP->ant;
    } else {
        CP->ant->prox = CP->prox;
        CP->prox->ant = CP->ant;
        LD->tamanho--;
    }

    return LD;
}

ListaDupla *Inserir_Inicio(int x, ListaDupla *L)
{
    No *no = buscar(L, x);
    if(no != NULL){
        cout<<"Este nó já existe na lista\n";
        return L;
    }
    No *novo;
    novo = new No;
    novo->info = x;
    novo->prox = L->inicio;
    novo->ant = NULL;
    L->inicio = novo;
    if (L->fim == NULL)
        L->fim = L->inicio;
    else
        L->inicio->prox->ant = novo;
    L->tamanho++;
    return L;
}

int main()
{
    ListaDupla *l;
    ListaDupla *n;

    l = inicializar();
    l = inserir(l, 9, 2);
    l = inserir(l, 2, 1);
    l = inserir(l, 7, 2);
    l = inserir(l, 19, 4);
    l = inserir(l, 29, 4);
    l = inserir(l, 12, 6);
    l = inserir(l, 119, 5);
    l = inserir(l, 112, 12);
    l = inserir(l, 100, 1);

    l = Inserir_Inicio(29, l);


    No *noParaExcluir = buscar(l, 2);//Verificar esse método
    cout <<"No para excluir = "<<noParaExcluir->info<<"\n";
    l = excluir(l, noParaExcluir);

    consultarLista(l);


    return 0;
}
