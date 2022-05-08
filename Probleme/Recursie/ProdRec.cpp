#include <iostream>

using namespace std;

int prodRec(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    else if (b < 0)
        return -a + prodRec(a, b + 1);
    else
        return a + prodRec(a, b - 1);
}

int main()
{
    int a, b;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << a << "*" << b << "=" << prodRec(a, b);
    return 0;
}