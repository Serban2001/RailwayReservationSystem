#include "Canc.h"
#include "Reser.h"
#include "Detail.h"
#include "Login.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

void manage();
void user();
void database();
void res();
void displaypassdetail();
void cancell();
void enquiry();
void displaycan();

char f[10] = "F";
char s[10] = "S";
int addr, ad, flag, f1, d, m, amt;
float tamt;

int main()
{
    int ch;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << ".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    do
    {
        cout << "......................MAIN MENU......................\n";
        cout
            << "1.Admin mode\n2.User mode\n3.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            database();
            break;
        case 2:
            user();
            break;
        case 3:
            exit(0);
        }
    } while (ch < 3);
    return 0;
}
void database()
{
    char password[15];
    const char *pass = "1234";
    cout << "Enter the administrator password: ";
    cin >> password;
    Detail a;
    fstream f;
    int ch;
    if (strcmp(pass, password) != 0)
    {
        cout << "Enter the password correctly\n";
        cout << "You are not permitted to login in this mode\n";
    }
    if (strcmp(pass, password) == 0)
    {
        char c;
        do
        {
            cout << "...........ADMINISTRATOR MENU...........\n";
            cout << "1.Add Train Details in Database\n";
            cout << "2.Display All Trains Details\n3.User Management\n";
            cout << "4.Display All Reservations\n5.Display Cancellations\n6.Return to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> ch;

            cout << endl;
            switch (ch)
            {
            case 1:
                f.open("t.txt", ios::in | ios::out | ios::binary | ios::app);
                do
                {
                    a.getdetail();
                    f.write((char *)&a, sizeof(a));
                    cout << "Do you want to add one more record?\n";
                    cout << "y-for Yes\nn-for No\n: ";
                    cin >> c;
                } while (c == 'y');
                f.close();
                break;
            case 2:
                cout << "Train No.\tTrain Name\tBoarding Station\tDestination Station\tFirst Class Seats\tFirst Class Fare\tSecond Class Seats\tSecond Class Fare\tDate\n";
                f.open("t.txt", ios::in | ios::out | ios::binary | ios::app);
                f.seekg(0);
                while (f.read((char *)&a, sizeof(a)))
                {
                    a.displaydetail();
                }
                f.close();
                cout << "\n\n";
                break;
            case 3:
                manage();
                break;
            case 4:
                displaypassdetail();
                break;
            case 5:
                displaycan();
            }
        } while (ch < 6);

        f.close();
    }
}
void displaycan()
{
    fstream f3;
    Canc c;
    f3.open("cn.txt", ios::in | ios::out | ios::binary);
    f3.seekg(0);
    while (f3.read((char *)&c, sizeof(c)))
    {
        c.displaycancdet();
    }
    f3.close();
}
void res()
{
    Detail a;
    Reser b;
    fstream f1, f2;
    time_t t;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary | ios::app);
    int ch;
    cout << "\nEnter Train No.: ";
    cin >> b.tno;

    while (f1.read((char *)&a, sizeof(a)))
    {
        if (a.tno == b.tno)
        {
            cout << "\nEnter Train No. again for confirmation\n";
            b.getresdet();
            if (strcmp(b.clas, f) == 0)
            {
                if (a.c1 >= b.nosr)
                {
                    strcpy(b.tname, a.tname);
                    amt = a.c1fare;
                    addr = f1.tellg();
                    ad = sizeof(a);
                    f1.seekp(addr - (ad));
                    a.c1 = a.c1 - b.nosr;
                    f1.write((char *)&a, sizeof(a));
                    if (b.con == 1)
                    {
                        cout << "Concession category: MILITARY PERSONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category: SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category: CHILDREN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt;
                    }
                    srand((unsigned)time(&t));
                    b.pnr = rand();
                    f2.write((char *)&b, sizeof(b));
                    b.displayresdet();
                    cout << "------------------------------------------------------\n";
                    cout << "--------------Your ticket is reserved-----------\n";
                    cout << "-----------------End of reservation menu-------\n";
                }
                else
                {
                    cout << "**********Sorry requested seats are not available********\n";
                }
            }
            else if (strcmp(b.clas, s) == 0)
            {
                if (a.c2 >= b.nosr)
                {
                    strcpy(b.tname, a.tname);
                    amt = a.c2fare;
                    addr = f1.tellg();
                    ad = sizeof(a);
                    f1.seekp(addr - (ad));
                    a.c2 = a.c2 - b.nosr;
                    f1.write((char *)&a, sizeof(a));
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PERSONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt;
                    }
                    srand((unsigned)time(&t));
                    b.pnr = rand();
                    f2.write((char *)&b, sizeof(b));
                    b.displayresdet();
                    cout << "---------------------------------------\n";
                    cout << "--------Your ticket is reserved--------\n";
                    cout << "------------End of reservation---------\n";
                }
                else
                {
                    cout << "********Sorry requested seats are not available*******\n";
                }
            }
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << "............Wrong train no......................\n";
        cout << "......Enter the train no from the data base.....\n";
    }
    f1.close();
    f2.close();
}
void displaypassdetail()
{
    fstream f;
    Reser b;
    f.open("p.txt", ios::in | ios::out | ios::binary);
    f.seekg(0);
    while (f.read((char *)&b, sizeof(b)))
    {
        b.displayresdet();
    }
    f.close();
}
void enquiry()
{
    cout << "Train No.\tTrain Name\tBoarding Station\tDestination Station\tFirst Class Seats\tFirst Class Fare\tSecond Class Seats\tSecond Class Fare\tDate\n";
    fstream f;
    f.open("t.txt", ios::in | ios::out | ios::binary);
    Detail a;
    while (f.read((char *)&a, sizeof(a)))
    {
        a.displaydetail();
    }
    f.close();
}
void cancell()
{
    Detail a;
    Reser b;
    Canc c;
    int flagc = 0;
    fstream f1, f2, f3, temp;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary);
    f3.open("cn.txt", ios::in | ios::out | ios::binary | ios::app);
    temp.open("temp.txt", ios::in | ios::out | ios::binary | ios::app);
    cout << "**********CANCELLATION MENU*********\n";
    c.getcancdet();
    while (f2.read((char *)&b, sizeof(b)))
    {
        if (b.pnr == c.pnr)
        {
            c.tno = b.tno;
            strcpy(c.tname, b.tname);
            strcpy(c.bp, b.bp);
            strcpy(c.dest, b.dest);
            c.nosc = b.nosr;
            for (int j = 0; j < c.nosc; j++)
            {
                strcpy(c.pname[j], b.pname[j]);
                c.age[j] = b.age[j];
            }
            strcpy(c.clas, b.clas);
            if (strcmp(c.clas, f) == 0)
            {
                while (f1.read((char *)&a, sizeof(a)))
                {

                    if (a.tno == c.tno)
                    {
                        a.c1 = a.c1 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a);
                        f1.seekp(addr - (ad));
                        f1.write((char *)&a, sizeof(a));
                        tamt = b.amc;

                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one atleast month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        c.displaycancdet();
                    }
                }
            }
            else if (strcmp(c.clas, s) == 0)
            {
                while (f1.read((char *)&a, sizeof(a)))
                {

                    if (a.tno == c.tno)
                    {
                        a.c2 = a.c2 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a);
                        f1.seekp(addr - (ad));
                        f1.write((char *)&a, sizeof(a));
                        tamt = b.amc;

                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }

                        c.displaycancdet();
                    }
                }
            }
            flagc = 1;
        }
        else
        {
            if (flagc != 1)
            {
                flagc = 0;
            }
            temp.write((char *)&b, sizeof(b));
        }
    }
    if (flagc == 0)
    {
        cout << "\n\nEnter the correct PNR no\n\n";
    }
    f3.write((char *)&c, sizeof(c));
    f1.close();
    f2.close();
    f3.close();
    remove("p.txt");
    rename("temp.txt", "p.txt");
}
void user()
{
    Login a;
    int flagu;
    int ch;
    cout << "*****************************************************\n";
    cout << "***********WELCOME TO THE USER MENU****************\n";
    cout << "****************************************************\n";
    char password[15];

    fstream f;
    f.open("id.txt", ios::in | ios::out | ios::binary);
    char id[100];
    cout << "Enter your id: ";
    cin >> id;

    cout << "Enter the password: ";
    cin >> password;
    while (f.read((char *)&a, sizeof(a)))
    {
        if ((strcmp(a.id, id) == 0) && (strcmp(a.pass, password) == 0))
        {
            do
            {
                cout << "1.Reserve\n2.Cancell\n3.Enquiry\n4.Return to the main menu\n";
                cout << "Enter your choice:";
                cin >> ch;
                cout << endl;
                switch (ch)
                {
                case 1:
                    res();
                    break;
                case 2:
                    cancell();
                    break;
                case 3:
                    enquiry();
                    break;
                }
            } while (ch <= 3);

            return;
        }
        else
        {
            flagu = 1;
        }
    }
    if (flagu == 1)
    {
        cout << "Enter your user id and password correctly\n";
    }
}
void manage()
{
    int ch;
    fstream f;
    char c;
    Login a;
    cout << ".........WELCOME TO THE USER MANAGEMENT MENU........\n";
    do
    {
        cout << "1.Add User in Database\n";
        cout << "2.Display details\n3.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            f.open("id.txt", ios::in | ios::out | ios::binary | ios::app);
            do
            {
                a.getid();
                f.write((char *)&a, sizeof(a));
                cout << "Do you want to add one more record\n";
                cout << "y-Yes\nn-No\n";
                cin >> c;
            } while (c == 'y');
            f.close();
            break;

        case 2:
            f.open("id.txt", ios::in | ios::out | ios::binary);

            f.seekg(0);
            cout << "UserID\tPassword\n";
            while (f.read((char *)&a, sizeof(a)))
            {
                a.displayid();
            }
            f.close();
            break;
        }
    } while (ch < 3);
}
