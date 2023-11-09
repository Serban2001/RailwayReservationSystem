#ifndef Reser_h
#define Reser_h

class Reser
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
    int nosr;
    int i;
    int d, m, y;
    int con;

    float amc;
    void getresdet()
    {
        cout << "\nEnter the details as follows\n";
        cout << "\nTrain no: ";
        cin >> tno;
        cout << "Train name: ";
        cin >> tname;
        cout << "\nBoarding point: ";
        cin >> bp;
        cout << "\nDestination pt: ";
        cin >> dest;
        cout << "\nNo of seats required: ";
        cin >> nosr;
        cout << "\n\n";
        for (i = 0; i < nosr; i++)
        {
            cout << "Passenger " << i + 1 << " Name: ";
            cin.sync();
            cin.getline(pname[i], 100);
            
            cout << "Passenger " << i + 1 << " Age: ";
            cin >> age[i];
        }
        cout << "\n\nEnter Class\nF-first class\nS-second class\n: ";
        cin >> clas;
        cout << "\nDate of travel(DD MM YYYY): ";
        cin >> d >> m >> y;
        cout << "\n\nEnter the concession category\n";
        cout << "1.Military\n2.Senior citizen\n";
        cout << "3.Children below 5 yrs\n4.None\n: ";
        cin >> con;
        cout << "............END OF GETTING DETAILS............\n";
    }
    void displayresdet()
    {
        cout << "\n...............................................\n";
        cout << "...............................................\n";
        cout << "PNR No: " << pnr;
        cout << "\n\nTrain No: " << tno;
        cout << "\n\nTrain Name: ";
        cout << tname;
        cout << "\n\nBoarding Point: ";
        cout << bp;
        cout << "\n\nDestination Point: ";
        cout << dest;
        cout << "\n\nNo of seats reserved: " << nosr;
        for (i = 0; i < nosr; i++)
        {
            cout << "\n\nPassenger " << i + 1 << " Name:";
            cout << pname[i];
            cout << "\nPassenger " << i + 1 << " Age:" << age[i];
        }

        cout << "\n\nYour class: ";
        cout << clas;
        cout << "\n\nDate of reservation: " << d << "-" << m << "-" << y;
        cout << "\n\nYour concession category: " << con;
        cout << "\n\nYou must pay: " << amc << endl;
        cout << "***********************************************\n";
        cout << "***********************************************\n\n";
    }
};

#endif
