#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    // alocam memorie pentru nodul nou
    Node *nodNou = new Node();
    // initializam campul informational
    nodNou->data = data;
    // stabilim legatura
    nodNou->next = NULL;
    return nodNou;
}

// coada e vida daca primul element nu are nici o referinta
bool isEmpty(Node *first)
{
    return first == NULL;
}

void insert(Node *&first, Node *&last, int data)
{
    // alocam memorie pentru elementul care trebuie inserat
    Node *nodNou = newNode(data);

    // daca coada nu e vida
    if (last != NULL)
        // inseram nodul nou
        last->next = nodNou;

    // ultimul element primeste adresa nodului nou
    last = nodNou;
    if (first == NULL)
        // daca coada e vida atunci primul nod primeste adresa elementului nou
        first = nodNou;
}

int remove(Node *&first)
{
    // daca stiva e vida, nu putem sterge nimic
    if (isEmpty(first))
        return 0;
    // pastram intr-o variabila auxiliara adresa primului element
    Node *tmp = first;
    // actualizam adresa primului element cu adresa nodului urmator
    first = first->next;
    // returnam elementul sters
    int rezultat = tmp->data;
    // stergem adresa fostului prim element
    delete tmp;
    return rezultat;
}

void printQueue(Node *first)
{
    Node *x = first;
    while (x != NULL)
    {
        cout << x->data << " ";
        x = x->next;
    }
}

int main()
{
    Node *first = NULL;
    Node *last = NULL;
    insert(first, last, 2);
    insert(first, last, 4);
    insert(first, last, 6);
    insert(first, last, 7);
    insert(first, last, 8);
    printQueue(first);
    cout << remove(first) << endl;
    cout << remove(first) << endl;
    cout << remove(first) << endl;
    cout << "\n";
    printQueue(first);
    return 0;
}