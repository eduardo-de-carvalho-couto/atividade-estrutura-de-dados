#include <iostream>;

using namespace std;

typedef struct reg{
    int infor;
    reg* prox;
}No;

typedef struct TipoFila{
    No* topo;
    int tamanho;
}Fila;

Fila* inserir(Fila* f, int valor)
{
    No* novo = new No();
    novo->infor = valor;
    if(f->topo == NULL){
        f->topo = novo;
        return f;
    }
    No* aux = f->topo;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return f;
}

Fila* consultar(Fila* f)
{
    No* aux = f->topo;
    while(aux != NULL){
        cout  << aux->infor << "\n";
        aux = aux->prox;
    }

    return f;
}

No* buscar(Fila* f, int valor)
{
    No* aux = f->topo;
    while(aux != NULL){
        if(aux->infor == valor){
            cout << "Número presente: "<< aux->infor << "\n";
            return aux;
        }
        aux = aux->prox;
    }

    cout << "Número não encontrado na pilha!! \n";
    return NULL;

}

int main()
{
    Fila* f = new Fila();
    f = inserir(f, 2);
    f = inserir(f, 5);
    f = inserir(f, 7);
    f = inserir(f, 1);
    consultar(f);
    No* busca = buscar(f, 1);

    return 0;
}
