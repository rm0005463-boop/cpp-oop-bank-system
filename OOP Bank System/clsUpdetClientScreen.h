#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

using namespace std;

class clsUpdetClientScreen : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FistName :";
		Client.FirstName = clsInputValidate <string> ::ReadString();

		cout << "\nEnter LastName :";
		Client.LastName = clsInputValidate <string> ::ReadString();

		cout << "\nEnter Emial :";
		Client.Emial = clsInputValidate <string> ::ReadString();

		cout << "\nEnter Phone :";
		Client.Phone = clsInputValidate <string> ::ReadString();

		cout << "\nEnter PinCode :";
		Client.PinCode = clsInputValidate <string> ::ReadString();

		cout << "\nEnter Accountbalance :";
		Client.Accountbalance = clsInputValidate <float> ::ReadfloatNumber();

	}

	static void PrintClient(clsBankClient Client)
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

    static void ShowUpdetClientScreen()
    {

        if (!CheckAccessRight(clsUser::enPermission::pUpdetClient))
        {
            return;
        }


        _DrowScreenHeader("\t  Updet Client Screen");
        
        string AccountNumber;

        cout << "\n\nPleas Enter Client AccountNumber :";
        AccountNumber = clsInputValidate <string> ::ReadString();


        while (!clsBankClient::IsClientExit(AccountNumber))
        {
            cout << "\nAccountNumber is Araday Exiet , choose anther once:";
            AccountNumber = clsInputValidate <string> ::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        PrintClient(Client);

        char Answer = 'n';
        cout << "\nAre you sure you want to updet this client ? y/n ?";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            cout << "\n\n\tUpdet Client Info :";
            cout << "\n_________________________";

            _ReadClientInfo(Client);


            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAcount Upeded Successfuly :-)\n";
                PrintClient(Client);
                break;
            }
            case clsBankClient::enSaveResults::svFildEmptyOpject:
            {
                cout << "\nErorr account is not saved becous it's empty ";
                break;
            }


            }
        }
    }
};

