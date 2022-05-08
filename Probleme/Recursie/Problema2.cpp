#include <iostream>

using namespace std;

unsigned long prod(unsigned n)
{
    if (n == 1)
        return 1;
    else
        return (3 * n - 2) * prod(n - 1);
}

int main()
{
    unsigned n;
    cout << "n=";
    cin >> n;
    cout << "Product of the first " << n << " terms is " << prod(n);
}