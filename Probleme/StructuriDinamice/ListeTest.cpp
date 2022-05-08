#include <iostream>

using namespace std;

struct Node
{
    int inf;
    Node *next;
    Node *prev;
};

Node *newNode(int data)
{
    Node *newElement = new Node();
    newElement->inf = data;
    newElement->next = NULL;
    newElement->prev = NULL;
}

bool isEmpty(Node *lista)
{
    return lista == NULL;
}

void insertStart(Node *&lista, int data)
{
    Node *newElement = newNode(data);
    if (isEmpty(lista))
    {
        lista = newElement;
        return;
    }
    else
    {
        newElement->next = lista;
        newElement->prev = NULL;
        lista = newElement;
    }
}

void insertEnd(Node *&lista, int data)
{
    Node *newElement = newNode(data);
    if (isEmpty(lista))
    {
        lista = newElement;
        return;
    }
    else
    {
        Node *x = lista;
        while (x != NULL)
        {
            x = x->next;
        }
        x->next = newElement;
        newElement->prev = x;
    }
}

void insertAfter(Node *&lista, Node *element, int data)
{
    Node *newElement = newNode(data);
    if (isEmpty(lista))
    {
        lista = newElement;
    }
    else if (lista == element)
    {
        newElement->next = lista->next;
        newElement->prev = lista;
        lista->next = newElement;
    }
    else
    {
        newElement = element->next;
        newElement->prev = element;
        element->next->prev = newElement;
        element->next = newElement;
    }
}

void printList(Node *lista)
{
    if (isEmpty(lista))
    {
        cout << "Lista vida. Nu sunt valori de afisat" << endl;
    }
    else
    {
        while (!isEmpty(lista))
        {
            cout << lista->inf << " ";
            lista = lista->next;
        }
    }
}

int main()
{
    Node *lista = (Node *)malloc(sizeof(Node));
    lista = NULL;
    insertStart(lista, 5);
    insertStart(lista, 6);
    printList(lista);
    return 0;
}