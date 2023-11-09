#ifndef Login_h
#define Login_h

class Login
{
public:
    char id[100];
    char pass[100];

    void getid()
    {
        cout << "Enter your id:";
        cin >> id;
        cout << "Enter the password: ";
        cin >> pass;
    }
    void displayid()
    {
        cout << id << "\t" << pass << endl;
    }
};

#endif
