
#include <iostream>;

using namespace std;


typedef struct lista {
    int numero;
    lista* prox;
} Lista;

Lista* inicializa()
{
    return NULL;
}

Lista* insere(Lista *l, int i)
{
    Lista* novo = new Lista();
    novo->numero = i;
    novo->prox = l;//Pega o no do topo da lista encadeada
    return novo; //esse será o novo primeiro no
}

Lista* inserirNoFim(Lista *l, int valor)
{
    Lista* novo = new Lista();
    novo->numero = valor;
    novo->prox = NULL;

    Lista* aux = l;
    while(aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
    return l; //Retorne SEMPRE o TOPO DA LISTA para essa implementação!!
}

//USAR RECURSIVIDADE
void imprime(Lista* l)
{
    Lista* aux = l;
    if(aux == NULL){
        return;
    }
    cout << "(RECURSIVO) Número = " << aux->numero<< "\n";
    imprime(aux->prox);
}

int vazia(Lista* l)
{
    return (l == NULL);
}

//USAR RECURSIVIDADE
Lista* buscar(Lista* l, int valor)
{
    Lista* b = l;
    if(b->numero == valor) {
        return b;
    }
    if(b->prox == NULL){
        return NULL;
    }
    return buscar(b->prox, valor);
}


//USAR RECURSIVIDADE
void remover(Lista* l, int valor)
{
    Lista* b = l;
    if(b == NULL){
        cout << "O valor não existe na lista\n";
    }
    if(b->prox->numero == valor){
        cout << b->prox->numero << "removido\n";
        b->prox = (b->prox)->prox;

        return;
    }
    remover(b->prox, valor);

}

int numDeElementos(Lista* l)
{
    int contador = 0;
    Lista* p;
    for(p=l;p != NULL; p=p->prox){
        contador++;
    }

    return contador;
}


int main()
{
    Lista* l;
    int numDeItens;


    l = inicializa();
    l = insere(l, 27);
    l = insere(l, 29);
    l = insere(l, 37);
    l = inserirNoFim(l, 7);
    l = insere(l, 9);

    remover(l, 29);//Utilizando recursividade

    imprime(l);//Utilizando recursividade
    cout <<"Valor da busca(RECURSIVO): " << buscar(l, 37)->numero << "\n";//Utilizando recursividade
    cout << "O número de itens é: " << numDeElementos(l) <<"\n";

    return 0;
}
