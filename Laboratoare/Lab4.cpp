#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int inf;
    Node *left;
    Node *right;
};

struct ListNode
{
    int inf;
    ListNode *next;
};

Node *newNode(int data);
Node *newNodeList(int data);
bool isEmpty(Node *root);
bool isEmptyList(ListNode *list);
void inserare(ListNode *&list, long val);
void insertLastDigit(Node *root, ListNode *&list);
void afisareLista(ListNode *list);
Node *creare();
void RSD(Node *root);
void SRD(Node *root);
void SDR(Node *root);
int findMaxValue(Node *root);
bool allPositiveValues(Node *root);
void afisareNivel(Node *root, int currentLevel, int necessaryLevel);
int countMaxValues(Node *root, int maxValue);

int main()
{
    Node *root = creare();
    ListNode *list = NULL;
    cout << "Parcurgerea preordine (RSD):" << endl;
    RSD(root);
    cout << endl;
    cout << "Parcurgerea inordine (SRD):" << endl;
    SRD(root);
    cout << endl;
    cout << "Parcurgerea postordine (SDR):" << endl;
    SDR(root);
    cout << endl;
    cout << "Valoarea maxima in arbore: " << findMaxValue(root) << endl;
    cout << "Aceasta se intalneste in arbore de " << countMaxValues(root, findMaxValue(root)) << " ori" << endl;
    insertLastDigit(root, list);
    cout << "Am inserat in lista valorile din arbore cu ultima cifra 3 sau 5" << endl;
    cout << "Continutul listei dupa inserare:" << endl;
    afisareLista(list);
    cout << endl;
    if (allPositiveValues(root))
    {
        cout << "Toate valorile din arbore sunt pozitive" << endl;
    }
    else
    {
        cout << "Nu toate valorile din arbore sunt pozitive" << endl;
    }
    int nivel;
    cout << "Valoarea nivelului de pe care trebuie sa afisam: ";
    cin >> nivel;
    cout << "Valorile de pe nivelul " << nivel << " sunt: ";
    afisareNivel(root, 1, nivel);
    return 0;
}

Node *newNode(int data)
{
    Node *newElement = (Node *)malloc(sizeof(Node));
    newElement->inf = data;
    newElement->left = NULL;
    newElement->right = NULL;
    return newElement;
}

ListNode *newNodeList(long data)
{
    ListNode *newElement = (ListNode *)malloc(sizeof(ListNode));
    newElement->inf = data;
    newElement->next = NULL;
    return newElement;
}

bool isEmpty(Node *root)
{
    return root == NULL;
}

bool isEmptyList(ListNode *list)
{
    return list == NULL;
}

Node *creare()
{
    int nr;
    cout << "Valoarea: ";
    cin >> nr;
    if (nr != 0)
    {
        Node *newElement = newNode(nr);
        cout << "Introduceti descendentul stang al nodului " << newElement->inf << " :" << endl;
        newElement->left = creare();
        cout << "Introduceti descendentul drept al nodului " << newElement->inf << " :" << endl;
        newElement->right = creare();
        return newElement;
    }
}

void inserare(ListNode *&list, long val)
{
    ListNode *newElement = newNodeList(val);
    if (isEmptyList(list))
    {
        list = newElement;
        return;
    }
    else
    {
        ListNode *l = list;
        while (l->next != NULL)
        {
            l = l->next;
        }
        l->next = newElement;
    }
}

void insertLastDigit(Node *root, ListNode *&list)
{
    if (isEmpty(root))
        return;
    if (root->inf % 10 == 3 || root->inf % 10 == 5)
        inserare(list, root->inf);
    insertLastDigit(root->left, list);
    insertLastDigit(root->right, list);
}

void afisareLista(ListNode *list)
{
    if (isEmptyList(list))
    {
        cout << "Lista este vida" << endl;
        return;
    }
    else
    {
        while (list != NULL)
        {
            cout << list->inf << " ";
            list = list->next;
        }
    }
}

void RSD(Node *root)
{
    if (isEmpty(root))
    {
        return;
    }
    else
    {
        cout << root->inf << " ";
        RSD(root->left);
        RSD(root->right);
    }
}

void SRD(Node *root)
{
    if (isEmpty(root))
    {
        return;
    }
    else
    {
        SRD(root->left);
        cout << root->inf << " ";
        SRD(root->right);
    }
}

void SDR(Node *root)
{
    if (isEmpty(root))
    {
        return;
    }
    else
    {
        SDR(root->left);
        SDR(root->right);
        cout << root->inf << " ";
    }
}

int findMaxValue(Node *root)
{
    if (isEmpty(root))
    {
        return -1;
    }
    int maxim = root->inf;
    int lmax = findMaxValue(root->left);
    int rmax = findMaxValue(root->right);
    if (lmax > maxim)
        maxim = lmax;
    if (rmax > maxim)
        maxim = rmax;
    return maxim;
}

int countMaxValues(Node *root, int maxValue)
{
    if (isEmpty(root))
    {
        return 0;
    }
    if (root->inf == maxValue)
        return 1 + countMaxValues(root->left, maxValue) + countMaxValues(root->right, maxValue);
    else
        return countMaxValues(root->left, maxValue) + countMaxValues(root->right, maxValue);
}

bool allPositiveValues(Node *root)
{
    if (isEmpty(root))
        return false;
    if (root->inf < 0)
        return false;
    else
        return (allPositiveValues(root->left) && allPositiveValues(root->right));
}

void afisareNivel(Node *root, int currentLevel, int necessaryLevel)
{
    if (!isEmpty(root))
    {
        if (currentLevel == necessaryLevel)
        {
            cout << root->inf << " ";
        }
        afisareNivel(root->left, currentLevel + 1, necessaryLevel);
        afisareNivel(root->right, currentLevel + 1, necessaryLevel);
    }
}