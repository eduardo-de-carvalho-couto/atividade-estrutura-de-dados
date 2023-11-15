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

void imprime(Lista *l)
{
    Lista* aux;
    for (aux = l; aux != NULL; aux = aux->prox){
        cout << "número = " << aux->numero<< "\n";
    }
}

int vazia(Lista* l)
{
    return (l == NULL);
}

Lista* busca(Lista* l, int valor)
{
    Lista* p;
    for(p=l;p != NULL; p=p->prox){
        if (p->numero == valor) {
            return p;
        }
    }

    return NULL;
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

    imprime(l);
    cout <<"Valor da busca: " << busca(l, 37)->numero<< "\n";
    cout << "O número de itens é: " << numDeElementos(l) <<"\n";

    return 0;
}
