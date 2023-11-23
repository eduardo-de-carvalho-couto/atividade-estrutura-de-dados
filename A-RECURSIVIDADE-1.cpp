#include <iostream>

using namespace std;

int f1(int n)
{
    if (n == 0)
        return (1);
    else
        return(n * f1(n-1));
}

int f2(int n)
{
    if (n == 0)
        return (1);
    if (n == 1)
        return (1);
    else
        return(f2(n-1)+ 2 * f2(n-2));
}

int f3(int n) {
    if (n == 0)
        cout << "Zero ";
    else {
        cout << " "<< n ;
        cout << " "<< n << " ";
        f3(n-1);
    }
}

int main()
{
    cout << "resultado f1 = " << f1(0) << "\n";
    cout << "resultado f1 = " << f1(1) << "\n";
    cout << "resultado f1 = " << f1(5) << "\n\n";

    cout << "resultado f1 = " << f2(0) << "\n";
    cout << "resultado f1 = " << f2(1) << "\n";
    cout << "resultado f1 = " << f2(5) << "\n\n";

    f3(0);
    f3(1);
    f3(5);
}

