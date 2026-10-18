#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsWthidrowScreen :protected clsScreen
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

    static string _ReedAccountNumber()
    {
        string AccountNumber;
        cout << "\n\nPlease Enter Account Number ?";
        AccountNumber = clsInputValidate <string> ::ReadString();

        return AccountNumber;
    }

public:
    static void ShowWithdrowScreen()
    {
        _DrowScreenHeader("\t  Withdrow Screen");

        string AccountNumber = _ReedAccountNumber();

        while (!clsBankClient::IsClientExit(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] not exit";
            AccountNumber = _ReedAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);


        double Amount;
        cout << "\n\nPlease enter withdrow amount ?";
        Amount = clsInputValidate <double> ::ReadNumber();


        char Answer = 'n';
        cout << "\nAre you sure you want to perform this transaction ?";
        cin >> Answer;


        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Withdrow(Amount))
            {
                cout << "\nAmount withdrow successfuly.\n";
                cout << "New balance is " << Client.Accountbalance;
            }
            else
            {
                cout << "\nCanot withdrow insufecent balance!";
                cout << "\nAmount to withdrow is :" << Amount;
                cout << "\nYour balance is :" << Client.Accountbalance;
            }
        }
        else
        {
            cout << "\nOpration was cancellet.";
        }
    }

};

