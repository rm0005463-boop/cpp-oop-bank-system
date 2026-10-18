#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"

using namespace std;
class clsClientListScreen : protected clsScreen
{
private:

   static void PrintClientRecordLien(clsBankClient Client)
{
    cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
    cout << "|" << left << setw(20) << Client.FullName();
    cout << "|" << left << setw(12) << Client.Phone;
    cout << "|" << left << setw(20) << Client.Emial;
    cout << "|" << left << setw(10) << Client.PinCode;
    cout << "|" << left << setw(12) << Client.Accountbalance <<"  |";
}

public:
 
static void ShowClientList()
{

    if (!CheckAccessRight(clsUser::enPermission::pListClient))
    {
        return;
    }


    vector<clsBankClient>vClient = clsBankClient::GetClientList();
    string Title = "\tClient List Screen";

    string SubTitle = "\t    (" + to_string(vClient.size()) + ") Client(s).";

    _DrowScreenHeader(Title, SubTitle);
 

    cout << setw(8) << left << "" << "\n\n\t_______________________________________________________";
    cout << "____________________________________________\n" << endl;

    cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
    cout << "|" << left << setw(20) << "Client Name";
    cout << "|" << left << setw(12) << "Phone";
    cout << "|" << left << setw(20) << "Emial";
    cout << "|" << left << setw(10) << "Pin Code";
    cout << "|" << left << setw(12) << "Acountbalnce  |";

    cout << setw(8) << left << "" << "\n\t_________________________________________________________";
    cout << "__________________________________________\n" << endl;


    if (vClient.size() == 0)
    {
        cout << "\n\nClient Invalid In the";
    }

    for (clsBankClient& Client : vClient)
    {
        PrintClientRecordLien(Client);
        cout << endl;
    }

    cout << setw(8) << left << "" << "_______________________________________________________";
    cout << "____________________________________________\n" << endl;

}
};

