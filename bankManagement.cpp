#include <bits/stdc++.h>
using namespace std;

class Bank
{
    public:
        vector<map<string, string>> v;
        string name, address, acc_type, password;
        int balance;

    int logIn();
    void displayAccount();
    void createAccount();
    void withDraw();

};

void Bank::createAccount()
    {
        cout << endl;
        cout << "Enter your NAME : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Your ADDRESS : ";
        getline(cin, address);
        cout << "Enter Your ACCOUNT TYPE Saving(S) or Current(C) : ";
        getline(cin, acc_type);
        cout << "Enter your PASSWORD : ";
        getline(cin, password);
        cout << "Enter the AMOUNT : ";
        cin >> balance;
        cout << endl;

        cout << "Account Created Successfully...!!" << endl;
        cout << endl;

        map<string, string> m{{"name", name}, {"address", address}, {"acc_type", acc_type}, {"password", password}, {"balance", to_string(balance)}};
        v.push_back(m);

    }
int Bank::logIn()
{
        string n, p;
        cout << endl;
        cout << "Enter Your Name : ";
        cin.ignore();
        getline(cin, n);
        cout << "Enter Your Password : ";
        cin >> p;
        cout << endl;
        int i=0, s = v.size();
        while (i<s)
        {
            if(v[i]["name"] == n and v[i]["password"] == p)
            {
               return i;
            }
            i++;
        }
        i = -1;
        return i;
}
void Bank::displayAccount()
    {
        int i = logIn();
        if(i != -1)
        {
            cout << endl;
            cout << "NAME         : " << v[i]["name"] << endl;
            cout << "ADDRESS      : " << v[i]["address"] << endl;
            cout << "ACCOUNT TYPE : " << v[i]["acc_type"] << endl;
            cout << "BALANCE      : " << v[i]["balance"] << endl;
            cout << "PASSWORD     : " << v[i]["password"] << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << "Account Not Exist...!!"<<endl;
            cout << endl;
        }

    }
void Bank :: withDraw()
{
    int i = logIn();
    if(i != -1)
    {
        int b;
        cout << "Enter the Amount to Withdraw : ";
        cin >> b;
        int balance = stoi(v[i]["balance"]);
        if(b > balance)
        {
            cout << endl;
            cout << "Not Enough balance...!!" << endl;
            cout << endl;
        }
        else
        {
            cout << "WithDraw Successfull..!!!" << endl;
            balance -= b;
            v[i]["balance"] = to_string(balance);
        }

    }
    else
    {
        cout << endl;
        cout << "Enter Correct Inforamtion...Password or Name is Wrong...!!" << endl;
        cout << endl;
    }

}


int main()
{
    string name, address, acc_type, password;
    int balance;
    bool status = true;
    int option = -1;
    Bank client;

    do{

        cout << "1. Open Account" << endl;
        cout << "2. Display Account" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "9. Exit" << endl;
        cout << endl;
        cout << "Choose your option Number : " ;
        cin >> option;
        if(option == 1){
            client.createAccount();
        }
        else if(option == 2)
        {
            client.displayAccount();
        }
        else if(option == 3)
        {
            client.withDraw();
        }
        else if(option == 9)
        {
            status = false;
        }

    }while(status);
    cout << endl;
    cout << "Thanks For Banking With us!!" << endl;
    cout << endl;

    return 0;
}
