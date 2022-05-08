#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <conio.h>

#define MAXLEN 100

using namespace std;

struct Consumator
{
    char nume[MAXLEN];
    int varsta;
    char telefon[MAXLEN];
};

struct Node
{
    Consumator inf;
    Node *next;
};

Node *newNode(struct Consumator consumator)
{
    Node *newElement = (Node *)malloc(sizeof(struct Node));
    strcpy(newElement->inf.nume, consumator.nume);
    newElement->inf.varsta = consumator.varsta;
    strcpy(newElement->inf.telefon, consumator.telefon);
    newElement->next = NULL;
    return newElement;
}

bool isEmpty(Node *lista)
{
    return lista == NULL;
}

void inserare(Node *&lista, struct Consumator consumator)
{
    Node *newElement = newNode(consumator);
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
    if (isEmpty(lista))
    {
        cout << "Lista este vida" << endl;
        return;
    }
    else
    {
        while (lista != NULL)
        {
            cout << lista->inf.nume << " " << lista->inf.varsta << " " << lista->inf.telefon << endl;
            lista = lista->next;
        }
    }
}

void readFromFile(Node *&lista)
{
    ifstream file;
    file.open("lab2.txt", ios::in);
    struct Consumator consumator;
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> consumator.nume >> consumator.varsta >> consumator.telefon;
            inserare(lista, consumator);
        }
    }
    file.close();
}

int size(Node *lista)
{
    int i = 0;
    if (isEmpty(lista))
        return 0;
    else
    {
        while (lista != NULL)
        {
            lista = lista->next;
            i++;
        }
    }
    return i;
}

void printFirstFive(Node *lista)
{
    if (isEmpty(lista))
    {
        cout << "Lista este vida" << endl;
        return;
    }
    if (size(lista) < 5)
    {
        cout << "Lista are mai putin de 5 elemente" << endl;
        return;
    }
    else
    {
        int i = 0;
        while (lista != NULL && i < 5)
        {
            cout << lista->inf.nume << " " << lista->inf.varsta << " " << lista->inf.telefon << endl;
            lista = lista->next;
            i++;
        }
    }
}

void printOldStudents(Node *lista)
{
    if (isEmpty(lista))
    {
        cout << "Lista este vida" << endl;
    }
    else
    {
        while (lista != NULL)
        {
            if (lista->inf.varsta > 20)
            {
                cout << lista->inf.nume << " " << lista->inf.varsta << " " << lista->inf.telefon << endl;
            }
            lista = lista->next;
        }
    }
}

int main()
{
    Node *lista = NULL;
    int optiune;
    struct Consumator consumator;
    do
    {
        system("cls");
        cout << "1. Afisarea listei" << endl;
        cout << "2. Citirea din fisier" << endl;
        cout << "3. Dimensiunea curenta a listei" << endl;
        cout << "4. Inserarea unui consumator (la sfarsit)" << endl;
        cout << "5. Afisarea datelor despre primii 5 consumatori" << endl;
        cout << "6. Afisarea persoanelor cu varsta mai mare de 20 de ani" << endl;
        cout << "0. Iesire" << endl;
        cout << "\t Optiunea aleasa: ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            afisare(lista);
            break;
        case 2:
            readFromFile(lista);
            break;
        case 3:
            cout << "Dimensiunea curenta a listei: " << size(lista) << endl;
            break;
        case 4:
            cout << "Numele consumatorului: ";
            cin >> consumator.nume;
            cout << "Varsta consumatorului: ";
            cin >> consumator.varsta;
            cout << "Telefonul consumatorului: ";
            cin >> consumator.telefon;
            inserare(lista, consumator);
            break;
        case 5:
            printFirstFive(lista);
            break;
        case 6:
            printOldStudents(lista);
            break;
        case 0:
            exit(0);
        }
        _getch();
    } while (optiune != 0);
    return 0;
}