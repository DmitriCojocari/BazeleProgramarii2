#include <iostream>

using namespace std;

unsigned sum(unsigned n)
{
    if (n == 1)
        return 1;
    else
        return (2 * n - 1) + sum(n - 1);
}

int main()
{
    unsigned n;
    cout << "n=";
    cin >> n;
    cout << "Sum of first " << n << " terms is " << sum(n);
    return 0;
}