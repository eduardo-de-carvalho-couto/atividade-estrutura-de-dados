#include <iostream>

using namespace std;

int soma(int n)
{

    if(n == 0){
        return 0;
    }

    if((n % 2) != 0){
        return soma(n-1);
    }

    return (n + soma(n-1));
}

int main()
{
    cout << "Soma = " << soma(9);

    return 0;
}
