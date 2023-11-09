#ifndef Detail_h
#define Detail_h

class Detail
{
public:
    int tno;
    char tname[100];

    char bp[100];
    char dest[100];
    int c1, c1fare;
    int c2, c2fare;
    int d, m, y;
    void getdetail()
    {
        cout << "Enter the details as follows\n";
        cout << "Train no:";
        cin >> tno;
        cout << "Train name:";
        cin.sync();
        cin.getline(tname, 100);
        
        cin >> tname;
        cout << "Boarding point:";
        cin >> bp;
        cout << "Destination pt:";
        cin >> dest;

        cout << "No of seats in First class & Fare per ticket:";
        cin >> c1 >> c1fare;
        cout << "No of seats in Second class & Fare per ticket:";
        cin >> c2 >> c2fare;
        cout << "Date of travel:";
        cin >> d >> m >> y;
    }
    void displaydetail()
    {

        cout << tno << "\t\t" << tname << "\t" << bp << "\t\t\t" << dest << "\t\t\t";
        cout << c1 << "\t\t\t" << c1fare << "\t\t\t" << c2 << "\t\t\t" << c2fare << "\t\t\t";
        cout << d << "-" << m << "-" << y << "\t" << endl
             << endl;
    }
};

#endif
