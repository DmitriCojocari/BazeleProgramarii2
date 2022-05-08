#include <iostream>

using namespace std;

void createArray(int a[], unsigned n);
void printArray(int a[], unsigned n);
int prod(int a[], unsigned n);

int main()
{
    unsigned n;
    cout << "Nr. of elements : ";
    cin >> n;
    int a[n];
    createArray(a, n);
    cout << "The array is : ";
    printArray(a, n);
    cout << "\nProduct of elements in array : " << prod(a, n);
    return 0;
}

void createArray(int a[], unsigned n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() % 10) - 3;
    }
}

void printArray(int a[], unsigned n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\na[" << i << "]=" << a[i];
    }
}

int prod(int a[], unsigned n)
{
    if (n == 1)
        return a[0];
    else
        return (a[n - 1] * prod(a, n - 1));
}