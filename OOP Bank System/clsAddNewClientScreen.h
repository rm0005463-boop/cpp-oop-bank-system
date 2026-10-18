#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
	 static void _ReadClientInfo(clsBankClient & Client)
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

	static void ShowAddNewClientScreen()
{

        if (!CheckAccessRight(clsUser::enPermission::pAddNewClient))
        {
            return;
        }


        _DrowScreenHeader("\t  Add New Client Screen");
       

    string AccountNumber;

    cout << "\n\nPleas Enter Client AccountNumber :";
    AccountNumber = clsInputValidate <string> ::ReadString();


    while (clsBankClient::IsClientExit(AccountNumber))
    {
        cout << "\nAccountNumber is Araday Exiet , choose anther once:";
        AccountNumber = clsInputValidate <string> ::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNweClientOpject(AccountNumber);
    


    cout << "\n\n\tAdd Client Info :";
    cout << "\n_________________________";

    _ReadClientInfo(NewClient);


    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAcount Add Successfuly :-)\n";
        _PrintClient(NewClient);
        break;
    }
    case clsBankClient::enSaveResults::svFildEmptyOpject:
    {
        cout << "\nErorr account is not saved becous it's empty ";
        break;
    }
    case clsBankClient::enSaveResults::svFildAccountNumberExits:
    {
        cout << "\nAccount Alradey In Used";
        break;
    }

    }

}

};

