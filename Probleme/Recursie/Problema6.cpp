#include <iostream>

using namespace std;

void createArray(int a[], unsigned n);
void printArray(int a[], unsigned n);
void printArrayRec(int a[], unsigned n, unsigned i);
void printArrayRecNew(int a[], unsigned n);

int main()
{
    unsigned n;
    cout << "Nr. of elements : ";
    cin >> n;
    int a[n];
    createArray(a, n);
    cout << "Printing array iteratively";
    printArray(a, n);
    cout << "\nPrinting array recursively";
    printArrayRec(a, n, 0);
    cout << "\nPrinting array (2nd way)";
    printArrayRecNew(a, n);
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

void printArrayRec(int a[], unsigned n, unsigned i)
{
    if (i >= n)
        return;
    cout << "\na[" << i << "]=" << a[i];
    i++;
    printArrayRec(a, n, i);
}

void printArrayRecNew(int a[], unsigned n)
{
    if (n == 1)
        cout << "\na[0]=" << a[0];
    else
    {
        printArrayRecNew(a, n - 1);
        cout << "\na[" << n - 1 << "]=" << a[n - 1];
    }
}