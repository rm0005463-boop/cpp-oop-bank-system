#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"Global.h"

using namespace std;
class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\tClient Card";
		cout << "\n_____________________________";
		cout << "\nFull Name     :" << Client.FullName();
		cout << "\nAccountNumber :" << Client.AccountNumber();
		cout << "\nAccountbalane :" << Client.Accountbalance;
		cout << "\n_____________________________";
	}

	static string _ReadAcooundNumber()
	{
		string AccountNumber;

		cout << "\n\nPlease Enter AccountNumber To Transfer From :";
		AccountNumber = clsInputValidate <string> ::ReadString();

		while (!clsBankClient::IsClientExit(AccountNumber))
		{
			cout << "\nAccountNumber is not found , tray agine : ";
			AccountNumber = clsInputValidate <string> ::ReadString();
		}

		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient &SourceClient)
	{
		float Amount;
		cout << "\n\nEnter Amount To Transfer :";
		Amount = clsInputValidate <int>::ReadNumber();

        while(Amount > SourceClient.Accountbalance)
        {
        	cout << "\nAmount Execeeda Avilabal Balance , Enter Anther Amount :";
        	Amount = clsInputValidate <int> ::ReadNumber();
        }
        
        	return Amount;
        }

public:
	static void ShowTransferScreen()
	{
		_DrowScreenHeader("\t Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAcooundNumber());
		_PrintClient(SourceClient);


		clsBankClient DestinationClient = clsBankClient::Find(_ReadAcooundNumber());
		_PrintClient(DestinationClient);
	

		float Amount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sour you want to perfrom this opration ? y/n ?";
		cin >> Answer;

		if(Answer == 'Y' || Answer == 'y');
		{
			if (SourceClient.Transfer(Amount, DestinationClient , CurrentUser.UserName))
			{
				cout << "\nTransfer Done Successfully.";
			}
			else
			{
				cout << "\nTransfer Fiald .";
			}
		}
		
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);

	}
};

