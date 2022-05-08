#include <iostream>

using namespace std;

void createArray(int a[], unsigned n);
void printArray(int a[], unsigned n);
bool find(int a[], unsigned n, int valueToFind);

int main()
{
    unsigned n;
    cout << "Nr. of elements : ";
    cin >> n;
    int a[n];
    createArray(a, n);
    cout << "The array is : ";
    printArray(a, n);
    int x;
    cout << "\nValue to search : ";
    cin >> x;
    find(a, n, x) ? cout << "Value " << x << " is present in the array" : cout << "There is no such value in the array";
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

bool find(int a[], unsigned n, int valueToFind)
{
    if (n == 1)
        return (a[0] == valueToFind);
    else
    {
        if (a[n - 1] == valueToFind)
            return true;
        else
        {
            return find(a, n - 1, valueToFind);
        }
    }
}