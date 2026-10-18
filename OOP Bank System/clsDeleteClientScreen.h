#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\n\tClient Card";
        cout << "\n_____________________________";
        cout << "\nFirst Name    :" << Client.FirstName;
        cout << "\nLast Name     :" << Client.LastName;
        cout << "\nFull Name     :" << Client.FullName();
        cout << "\nEmial         :" << Client.Emial;
        cout << "\nPhone         :" << Client.Phone;
        cout << "\nAccountNumber :" << Client.AccountNumber();
        cout << "\nPinCode       :" << Client.PinCode;
        cout << "\nAccountbalane :" << Client.Accountbalance;
        cout << "\n_____________________________";
    }

public:

    static void ShowDeleteClientScreen()
    {

        if (!CheckAccessRight(clsUser::enPermission::pDeleteClient))
        {
            return;
        }


        string AccountNumber;

        _DrowScreenHeader("\t Delete Client Screen");

        cout << "\nPleas Enter AccountNumber :";
        AccountNumber = clsInputValidate <string> ::ReadString();

        while (!clsBankClient::IsClientExit(AccountNumber))
        {
            cout << "\nAccountNumber is not fount , choose agin :";
            AccountNumber = clsInputValidate <string> ::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        char Answer = 'n';

        cout << "\n\nAre you sure you want to Delet this clinet y/n :";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted successly:-)";
                _PrintClient(Client1);
            }
            else
            {
                cout << "\nErorr Client was not deleted \n";
            }
        }
    }

};

