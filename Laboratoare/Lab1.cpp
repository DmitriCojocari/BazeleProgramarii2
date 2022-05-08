#include <iostream>

using namespace std;

long func(long n)
{
    if (n < 10)
        return 2;
    else
        return n + func(n / 10);
}

int main()
{
    long n;
    cout << "n=";
    cin >> n;
    cout << "Valoarea functiei: " << func(n);
    return 0;
}