#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXLEN 100

using namespace std;

struct Node
{
    char inf;
    Node *next;
};

Node *newNode(char ch)
{
    Node *newElement = (Node *)malloc(sizeof(struct Node));
    newElement->inf = ch;
    newElement->next = NULL;
    return newElement;
}

bool isEmpty(Node *lista)
{
    return lista == NULL;
}

void inserare(Node *&lista, char ch)
{
    Node *newElement = newNode(ch);
    if (isEmpty(lista))
    {
        lista = newElement;
        return;
    }
    else
    {
        Node *l = lista;
        while (l->next != NULL)
        {
            l = l->next;
        }
        l->next = newElement;
    }
}

void afisare(Node *lista)
{
    while (lista != NULL)
    {
        cout << lista->inf << " ";
        lista = lista->next;
    }
}

int main()
{
    Node *lista = NULL;
    string cuvant = "", copie = "";
    char ch;
    cout << "Caracterul dorit: ";
    cin >> ch;
    while (ch != '0')
    {
        inserare(lista, ch);
        cout << "Caracterul dorit: ";
        cin >> ch;
    }
    while (lista != NULL)
    {
        cuvant += lista->inf;
        lista = lista->next;
    }
    copie = cuvant;
    reverse(copie.begin(), copie.end());
    (cuvant == copie) ? cout << "Cuvantul " << cuvant << " este palindrom" << endl : cout << "Cuvantul " << cuvant << " nu este palindrom" << endl;
    return 0;
}