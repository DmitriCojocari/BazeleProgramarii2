#include <iostream>

using namespace std;

struct Node
{
    string inf;
    Node *next;
};

Node *newNode(string data)
{
    Node *newElement = new Node();
    newElement->inf = data;
    newElement->next = NULL;
}

bool isEmpty(Node *top)
{
    return top == NULL;
}

void insert(Node *&stack, string data)
{
    Node *newElement = newNode(data);
    newElement->next = stack;
    stack = newElement;
}

void remove(Node *&stack)
{
    if (isEmpty(stack))
    {
        cout << "Nothing to remove" << endl;
    }
    else
    {
        Node *x = stack;
        stack = stack->next;
        cout << "Successfully removed " << x->inf << " from the stack" << endl;
        delete x;
    }
}

void printStack(Node *stack)
{
    if (isEmpty(stack))
    {
        cout << "Empty stack. Nothing to print";
        return;
    }
    else
    {
        while (stack != NULL)
        {
            cout << stack->inf << " ";
            stack = stack->next;
        }
    }
}

int main()
{
    Node *Stiva = NULL;
    string word;
    cout << "Introduceti cuvinte. Pentru a opri introducerea, tastati 'gata'" << endl;
    do
    {
        cout << "Cuvantul dorit: ";
        cin >> word;
        if (word == "gata")
            break;
        insert(Stiva, word);
    } while (word != "gata");
    printStack(Stiva);
    return 0;
}