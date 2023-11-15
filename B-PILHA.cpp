#include <iostream>;

using namespace std;


typedef struct pilha {
    int numero;
    pilha* prox;
} Pilha;

Pilha* inicializa()
{
    return NULL;
}

Pilha* push(Pilha* p, int valor)
{
    Pilha* novo = new Pilha();
    novo->numero = valor;
    novo->prox = p;
    return novo;
}

void pop(Pilha* p)
{
    p = p->prox;
}
