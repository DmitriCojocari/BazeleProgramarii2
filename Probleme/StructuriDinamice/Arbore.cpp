#include <iostream>

using namespace std;

struct Node
{
    int inf;
    Node *left;
    Node *right;
};

Node *newNode(int data);
bool isEmpty(Node *root);
Node *creare();
void RSD(Node *root);
void SRD(Node *root);
void SDR(Node *root);
void afisareFrunze(Node *root);
bool isInTree(Node *root, int value);
void afisareNivel(Node *root, int currentLevel, int requiredLevel);
int inaltimeArbore(Node *root);

int main()
{
    Node *root = creare();
    cout << "Parcurgerea preordine (RSD):" << endl;
    RSD(root);
    cout << endl;
    cout << "Parcurgerea inordine (SRD):" << endl;
    SRD(root);
    cout << endl;
    cout << "Parcurgerea postordine (SDR):" << endl;
    SDR(root);
    cout << endl;
    cout << "Frunzele din arbore: ";
    afisareFrunze(root);
    cout << endl;
    cout << "Inaltimea arborelui: " << inaltimeArbore(root) << endl;
    return 0;
}

Node *newNode(int data)
{
    Node *newElement = (Node *)malloc(sizeof(Node));
    newElement->inf = data;
    newElement->left = NULL;
    newElement->right = NULL;
}

bool isEmpty(Node *root)
{
    return root == NULL;
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

void afisareFrunze(Node *root)
{
    if (isEmpty(root))
    {
        return;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            cout << root->inf << " ";
        }
        afisareFrunze(root->left);
        afisareFrunze(root->right);
    }
}

bool isInTree(Node *root, int value)
{
    if (isEmpty(root))
        return false;
    else if (root->inf == value)
        return true;
    else
        return (isInTree(root->left, value) || isInTree(root->right, value));
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

int inaltimeArbore(Node *root)
{
    if (isEmpty(root))
        return -1;
    int lHeight = inaltimeArbore(root->left);
    int rHeight = inaltimeArbore(root->right);
    return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
}