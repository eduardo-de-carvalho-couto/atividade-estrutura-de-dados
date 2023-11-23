#include <iostream>

using namespace std;

int produto(int a, int b)
{
    if(b == 1){
        return a;
    }

    if(b > 1){
        return produto(a, b-1) + a;
    }
}

int main()
{
    cout << "Resultado = " << produto(2,5);

    return 0;
}
