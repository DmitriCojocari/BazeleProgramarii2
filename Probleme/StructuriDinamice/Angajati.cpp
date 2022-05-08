#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct DataNasterii
{
    unsigned zi;
    unsigned luna;
    unsigned an;
};

struct Angajat
{
    string nume;
    string prenume;
    DataNasterii dataNasterii;
    string telefon;
    string post;
    unsigned stagiu;
    double salariu;
    unsigned nrOreLucrate;
    unsigned nrZileLucrate;
};

struct Node
{
    Angajat angajat;
    Node *prev;
    Node *next;
};

Node *first = NULL;
Node *last = NULL;

void readFromFile();
void insertEnd(struct Angajat);
void printList(Node *);
int countEmployees(Node *);
double computeMonthlySalary(double, unsigned, unsigned);
double maxSalary(Node *);
void printMaxSalaryEmployee(Node *);
void sortedInsertion(Node **, Node *);
void insertionSort(Node **);
int countBornInMonth(Node *, unsigned);

int main()
{
    readFromFile();
    int option;
    do
    {
        system("cls");
        cout << "1. Afisarea listei" << endl;
        cout << "2. Afisarea numarului de angajati" << endl;
        cout << "3. Angajatul cu salariu maxim " << endl;
        cout << "4. Angajatii sortati in ordine descrascatoare a stagiului" << endl;
        cout << "5. Numarul angajatilor nascuti intr-o luna data m" << endl;
        cout << "Optiunea aleasa -> ";
        cin >> option;
        switch (option)
        {
        case 1:
            printList(first);
            break;
        case 2:
            cout << "Numarul de angajati : " << countEmployees(first) << endl;
            break;
        case 3:
            cout << "Salariul maxim : " << maxSalary(first) << endl;
            cout << "Angajatul/angajatii cu salariu maxim : ";
            printMaxSalaryEmployee(first);
            break;
        case 4:
            cout << "Angajatii sortati descrescator dupa stagiu: " << endl;
            insertionSort(&first);
            printList(first);
            break;
        case 5:
            unsigned month;
            cout << "Luna pentru cautare : ";
            cin >> month;
            cout << "Numarul persoanelor nascute in luna " << month << " :" << countBornInMonth(first, month) << endl;
            break;
        }
        _getch();
    } while (option != 0);
    return 0;
}

void insertEnd(struct Angajat angajat)
{
    Node *aux;
    aux = new Node;
    aux->angajat = angajat;
    aux->prev = last;
    aux->next = NULL;

    // daca lista e vida
    if (last == NULL)
    {
        // adaugam elementul la inceput
        first = aux;
    }
    else
    {
        last->next = aux;
    }
    last = aux;
}

void readFromFile()
{
    struct Angajat angajatFisier;
    ifstream readFile;
    readFile.open("angajati.in", ios::in);
    while (!readFile.eof())
    {
        readFile >> angajatFisier.nume >> angajatFisier.prenume >> angajatFisier.dataNasterii.zi >> angajatFisier.dataNasterii.luna >> angajatFisier.dataNasterii.an >> angajatFisier.telefon >> angajatFisier.post >> angajatFisier.stagiu >> angajatFisier.salariu >> angajatFisier.nrOreLucrate >> angajatFisier.nrZileLucrate;
        insertEnd(angajatFisier);
    }
    readFile.close();
}

void printList(Node *first)
{
    while (first != NULL)
    {
        cout << first->angajat.nume << " "
             << first->angajat.prenume << " "
             << first->angajat.dataNasterii.zi << " "
             << first->angajat.dataNasterii.luna << " "
             << first->angajat.dataNasterii.an << " "
             << first->angajat.telefon << " "
             << first->angajat.post << " "
             << first->angajat.stagiu << " "
             << first->angajat.salariu << " "
             << first->angajat.nrOreLucrate << " "
             << first->angajat.nrZileLucrate;
        first = first->next;
        cout << "\n";
    }
}

int countEmployees(Node *first)
{
    int count = 0;
    while (first != NULL)
    {
        count++;
        first = first->next;
    }
    return count;
}

double computeMonthlySalary(double salary, unsigned numberOfHours, unsigned numberOfDays)
{
    return salary * numberOfHours * numberOfDays;
}

double maxSalary(Node *first)
{
    double maxSalary = computeMonthlySalary(first->angajat.salariu, first->angajat.nrOreLucrate, first->angajat.nrZileLucrate);
    first = first->next;
    while (first != NULL)
    {
        double currentSalary = computeMonthlySalary(first->angajat.salariu, first->angajat.nrOreLucrate, first->angajat.nrZileLucrate);
        if (currentSalary > maxSalary)
        {
            maxSalary = currentSalary;
        }
        first = first->next;
    }
    return maxSalary;
}

void printMaxSalaryEmployee(Node *first)
{
    double maxWage = maxSalary(first);
    while (first != NULL)
    {
        double salary = computeMonthlySalary(first->angajat.salariu, first->angajat.nrOreLucrate, first->angajat.nrZileLucrate);
        if (salary == maxWage)
        {
            cout << first->angajat.nume << " " << first->angajat.prenume;
        }
        first = first->next;
    }
}

// insereaza elementele in lista in mod sortat
void sortedInsertion(struct Node **first, struct Node *newNode)
{
    struct Node *current;
    // daca lista este vida
    if (*first == NULL)
        // varfului listei ii atribuim adresa nodului nou
        *first = newNode;
    // daca nodul trebuie inserat la inceput
    // am pus <= pentru ca sortarea sa fie descrescatoare
    else if ((*first)->angajat.stagiu <= newNode->angajat.stagiu)
    {
        // stabilim legaturile corespunzatoare
        newNode->next = *first;
        newNode->next->prev = newNode;
        *first = newNode;
    }
    else
    {
        current = *first;
        // cautam nodul dupa care trebuie inserat nodul nou
        while (current->next != NULL && current->next->angajat.stagiu > newNode->angajat.stagiu)
        {
            current = current->next;
            // facem legatura corespunzatoare
            newNode->next = current->next;
            // daca nodul nu e inserat la sfarsitul listei
            if (current->next != NULL)
                newNode->next->prev = newNode;
            // stabilim legaturile
            current->next = newNode;
            newNode->prev = current;
        }
    }
}

// efectuam sortarea prin insertie, rezultatul il vom pastra intr-o noua lista
void insertionSort(struct Node **first)
{
    // lista sortata
    struct Node *newSortedList = NULL;
    struct Node *current = *first;
    while (current != NULL)
    {
        struct Node *next = current->next;
        current->prev = current->next = NULL;
        // inseram nodul curent in lista noua (care va fi sortata la inserare)
        sortedInsertion(&newSortedList, current);
        current = next;
    }
    // atribuim pointerului listei initiale, adresa listei nou formate (sortata)
    *first = newSortedList;
}

int countBornInMonth(Node *first, unsigned month)
{
    int count = 0;
    while (first != NULL)
    {
        if (first->angajat.dataNasterii.luna == month)
        {
            count++;
            // cout << first->angajat.nume << " " << first->angajat.prenume << endl;
        }
        first = first->next;
    }
    return count;
}