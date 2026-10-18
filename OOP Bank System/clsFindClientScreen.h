#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
{
private:

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

	static void ShowFindCliendScreen()
	{
		string AccountNumber;

		if (!CheckAccessRight(clsUser::enPermission::pFindClient))
		{
			return;
		}


		_DrowScreenHeader("\t Find Client Screen");
		

		cout << "\n\nPleas Enter Client AccountNumber :";
		AccountNumber = clsInputValidate <string> ::ReadString();


		while (!clsBankClient::IsClientExit(AccountNumber))
		{
			cout << "\nAccountNumber is not found , Enter anther once:";
			AccountNumber = clsInputValidate <string> ::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)";
		}
		else
		{
			cout << "\nClient was not Found :-(";
		}

		PrintClient(Client);
	}
};

