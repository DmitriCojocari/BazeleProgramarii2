#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
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
    bool operator<(const Angajat &a) const
    {
        return stagiu > a.stagiu;
    }
};

list<Angajat>::iterator it;

void readFromFile(list<Angajat> &);
void printList(list<Angajat>);
double computeMonthlySalary(double, unsigned, unsigned);
double maxSalary(list<Angajat>);
void printEmployeeMaxSalary(list<Angajat>);
int countBornInMonth(list<Angajat>, unsigned);

int main()
{

    list<Angajat> listaAngajati;
    readFromFile(listaAngajati);
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
            printList(listaAngajati);
            break;
        case 2:
            cout << "Numarul de angajati : " << listaAngajati.size() << endl;
            break;
        case 3:
            cout << "Salariul maxim : " << maxSalary(listaAngajati) << endl;
            cout << "Angajatul/angajatii cu salariu maxim : ";
            printEmployeeMaxSalary(listaAngajati);
            break;
        case 4:
            cout << "Angajatii sortati descrescator dupa stagiu: " << endl;
            listaAngajati.sort();
            printList(listaAngajati);
            break;
        case 5:
            unsigned month;
            cout << "Luna pentru cautare : ";
            cin >> month;
            cout << "Numarul persoanelor nascute in luna " << month << " :" << countBornInMonth(listaAngajati, month) << endl;
            break;
        }
        _getch();
    } while (option != 0);
    return 0;
}

void readFromFile(list<Angajat> &lista)
{
    struct Angajat angajatFisier;
    ifstream readFile;
    readFile.open("angajati.in", ios::in);
    while (!readFile.eof())
    {
        readFile >> angajatFisier.nume >> angajatFisier.prenume >> angajatFisier.dataNasterii.zi >> angajatFisier.dataNasterii.luna >> angajatFisier.dataNasterii.an >> angajatFisier.telefon >> angajatFisier.post >> angajatFisier.stagiu >> angajatFisier.salariu >> angajatFisier.nrOreLucrate >> angajatFisier.nrZileLucrate;
        lista.push_back(angajatFisier);
    }
    readFile.close();
}

void printList(list<Angajat> lista)
{
    for (it = lista.begin(); it != lista.end(); it++)
    {
        cout << (*it).nume << " "
             << (*it).prenume << " "
             << (*it).dataNasterii.zi << " "
             << (*it).dataNasterii.luna << " "
             << (*it).dataNasterii.an << " "
             << (*it).telefon << " "
             << (*it).post << " "
             << (*it).stagiu << " "
             << (*it).salariu << " "
             << (*it).nrOreLucrate << " "
             << (*it).nrZileLucrate << endl;
    }
}

double computeMonthlySalary(double salaryPerHour, unsigned workedHours, unsigned workedDays)
{
    return salaryPerHour * workedHours * workedDays;
}

double maxSalary(list<Angajat> lista)
{
    double max = computeMonthlySalary(lista.front().salariu, lista.front().nrOreLucrate, lista.front().nrZileLucrate);
    for (it = lista.begin(); it != lista.end(); it++)
    {
        double currentSalary = computeMonthlySalary((*it).salariu, (*it).nrOreLucrate, (*it).nrZileLucrate);
        if (currentSalary > max)
        {
            max = currentSalary;
        }
    }
    return max;
}

void printEmployeeMaxSalary(list<Angajat> lista)
{
    double max = maxSalary(lista);
    for (it = lista.begin(); it != lista.end(); it++)
    {
        double salary = computeMonthlySalary((*it).salariu, (*it).nrOreLucrate, (*it).nrZileLucrate);
        if (salary == max)
        {
            cout << (*it).nume << " " << (*it).prenume << endl;
        }
    }
}

int countBornInMonth(list<Angajat> lista, unsigned month)
{
    int count = 0;
    for (it = lista.begin(); it != lista.end(); it++)
    {
        if ((*it).dataNasterii.luna == month)
        {
            count++;
        }
    }
    return count;
}