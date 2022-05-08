#include <iostream>

using namespace std;

struct Nod
{
    int inf;
    Nod *next;
};

Nod *newNode(int inf)
{
    // alocam memorie pentru nodul nou
    Nod *nodNou = new Nod();
    // initializam campul informational
    nodNou->inf = inf;
    // stabilim legatura
    nodNou->next = NULL;
    return nodNou;
}

void push(Nod *&top, int inf)
{
    // alocam memorie pentru nodul care trebuie inserat
    Nod *nodNou = newNode(inf);
    // il punem in varful stivei
    nodNou->next = top;
    top = nodNou;
}

void printStack(Nod *top)
{
    while (top != NULL)
    {
        cout << top->inf << endl;
        top = top->next;
    }
}

int productNegatives(Nod *top)
{
    int p = 1;
    while (top != NULL)
    {
        if (top->inf < 0)
        {
            p *= top->inf;
        }
        top = top->next;
    }
    return p;
}

int main()
{
    // se citesc numere pana la introducerea lui 0
    // stiva vida
    Nod *top = NULL;
    int x;
    do
    {
        cout << "Numarul dorit : ";
        cin >> x;
        push(top, x);
    } while (x != 0);
    printStack(top);
    cout << "Product of negative elements : " << productNegatives(top);
    return 0;
}