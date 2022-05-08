#include <iostream>

using namespace std;

struct Node
{
    int inf;
    Node *next;
};

Node *newNode(int data)
{
    Node *newElement = new Node();
    newElement->inf = data;
    newElement->next = NULL;
}

bool isEmpty(Node *first)
{
    return first == NULL;
}

void insert(Node *&first, Node *&last, int data)
{
    Node *newElement = newNode(data);
    last->next = newElement;
    last = newElement;
}

void remove(Node *&first)
{
    if (isEmpty(first->next))
    {
        cout << "Empty queue" << endl;
    }
    else
    {
        Node *x = first;
        first = first->next;
        delete x;
    }
}

void printQueue(Node *first)
{
    if (isEmpty(first))
    {
        cout << "Empty queue. Nothing to print" << endl;
    }
    else
    {
        Node *x = first;
        while (x != NULL)
        {
            cout << x->inf << " ";
            x = x->next;
        }
    }
}

int main()
{
    Node *sant;
    sant->next = NULL;
    Node *last = sant;
    insert(sant->next, last, 5);
    insert(sant->next, last, 10);
    remove(sant);
    remove(sant);
    remove(sant);
    printQueue(sant->next);
    return 0;
}