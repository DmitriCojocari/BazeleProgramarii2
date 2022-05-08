#include <iostream>

using namespace std;

void createArray(int a[], unsigned n);
void printArray(int a[], unsigned n);
void reverseArray(int a[], unsigned i, unsigned j);

int main()
{
    unsigned n;
    cout << "Nr. of elements : ";
    cin >> n;
    int a[n];
    createArray(a, n);
    cout << "Array contents : ";
    printArray(a, n);
    cout << "\nPrinting reversed array :";
    reverseArray(a, 0, n - 1);
    printArray(a, n);
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

void reverseArray(int a[], unsigned i, unsigned j)
{
    if (i >= j)
        return;
    else
    {
        swap(a[i], a[j]);
        reverseArray(a, i + 1, j - 1);
    }
}