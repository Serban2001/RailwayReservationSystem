#ifndef Canc_h
#define Canc_h

#include <iostream>

using namespace std;

class Canc
{
public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    char clas[10];
    int nosc;
    int d, m, y;
    float amr;
    void getcancdet()
    {
        cout << "Enter the details as follows\n";
        cout << "PNR no: ";
        cin >> pnr;
        cout << "Date of cancellation(DD MM YYYY): ";
        cin >> d >> m >> y;
        cout << "...........END OF GETTING DETAILS...........\n";
    }
    void displaycancdet()
    {
        cout << "...........................................\n";
        cout << "...........................................\n";
        cout << "PNR No:" << pnr;
        cout << "\n\nTrain No: " << tno;
        cout << "\nTrain Name: ";
        cout << tname;
        cout << "\n\nBoarding Point: ";
        cout << bp;

        cout << "\n\nDestination Point: ";
        puts(dest);
        cout << "\n\nYour class: ";
        puts(clas);
        cout << "\n\nNo of seats to be cancelled: " << nosc;

        for (int i = 0; i < nosc; i++)
        {
            cout << "\n\nPassenger " << i + 1 << " Name: ";
            cout << pname[i];
            cout << "\nPassenger " << i + 1 << " Age: " << age[i];
        }

        cout << "\n\nDate of cancellation: " << d << "-" << m << "-" << y;
        cout << "\n\nYou can collect: " << amr << "rs" << endl;
        cout << "*****************************************\n";
        cout << ".........END OF CANCELLATION.............\n";
        cout << "*****************************************\n";
    }
};

#endif
