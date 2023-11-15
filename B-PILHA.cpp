#include <iostream>;

using namespace std;


typedef struct no {
    int numero;
    no* prox;
} No;

typedef struct pilha {
    No* topo;
} Pilha;

Pilha* inicializa()
{
    No* topo = NULL;
}

Pilha* push(Pilha* p, int valor)
{
    No* novo = new No();
    novo->numero = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

void pop(Pilha* p)
{
    p->topo = p->topo->prox;
}

Pilha* listar(Pilha* p)
{
    No* aux = p->topo;
    while(aux != NULL){
        cout << aux->numero << "\n";
        aux = aux->prox;
    }
}

No* buscar(Pilha* p, int valor)
{
    No* aux = p->topo;
    while(aux != NULL){
        if(aux->numero == valor){
            cout << "Número presente: "<< aux->numero << "\n";
            return aux;
        }
        aux = aux->prox;
    }

    cout << "Número não encontrado na pilha!! \n";
    return NULL;
}

int main()
{
    Pilha* p = new Pilha();
    p = push(p, 7);
    p = push(p, 8);
    p = push(p, 12);
    pop(p);

    listar(p);

    No* busca = buscar(p, 8);

    return 0;
}
