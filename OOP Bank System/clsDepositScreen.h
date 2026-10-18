#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;
class clsDepositScreen : protected clsScreen
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
    static void ShowDepositScreen()
    {
        _DrowScreenHeader("\t  Deposit Screen");

        string AccountNumber = _ReedAccountNumber();

        while (!clsBankClient::IsClientExit(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] not exit";
            AccountNumber = _ReedAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);


        double Amount;
        cout << "\n\nPlease enter deposit amount ?";
        Amount = clsInputValidate <double> ::ReadNumber();


        char Answer = 'n';
        cout << "\nAre you sure you want to perform this transaction ?";
        cin >> Answer;


        if (Answer == 'Y' || Answer == 'y')
        {
            Client.Deposit(Amount);
            cout << "\nDeposit Amunt Successfuly.\n";
            cout << "\nNew Balance is :" << Client.Accountbalance;
        }
        else
        {
            cout << "\nOpration was cancelled\n";
        }
    }

};

