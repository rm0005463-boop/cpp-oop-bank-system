#pragma once
#include<iostream>
#include"iomanip"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWthidrowScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"

using namespace std;

class clsTransactionScreen : protected clsScreen
{
private:

	enum enTransactionMenuoOption{eDeposit = 1 , eWthdrow = 2 , eShowTotalBalance = 3 ,eTransfer = 4, eTransferLog = 5, eShowMainMenuo = 6};

	static void _ShowDepositScrren()
	{
		//cout << "\nDeposit Screen will be hear ....";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrowClientScreen()
	{
		//cout << "\nWthdrow Screen will be hear ....";
		clsWthidrowScreen::ShowWithdrowScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		//cout << "\nTotal Balance Screen will be hear ....";
		clsTotalBalancesScreen::ShowTotalBalanceScreen();
	}

	static void _ShowTrasferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTranferLogScreen();
	}

	static void _GoBakeToTransactionMenuo()
	{
		cout << setw(37) << left << "" << "\nPrasue Any Key To Bake Mein Menuo....";
		system("pause > 0");

		ShowTransactionMenuoScreen();
	}

	static short _ReadTransactionMenuoOption()
	{
		short Choose;
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 To 6] ?";
		Choose = clsInputValidate <int> ::ReadNumberBetween(1, 6);
		return Choose;
	}

	static void _PerformMainMenuoOption(enTransactionMenuoOption TransactionMenuoOptin)
	{
		switch (TransactionMenuoOptin)
		{

		case enTransactionMenuoOption::eDeposit:
		{
			system("cls");
			_ShowDepositScrren();
			_GoBakeToTransactionMenuo();
			break;
		}

		case enTransactionMenuoOption::eWthdrow:
		{
			system("cls");
			_ShowWithdrowClientScreen();
			_GoBakeToTransactionMenuo();
			break;
		}

		case enTransactionMenuoOption::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBakeToTransactionMenuo();
			break;
		}

		case enTransactionMenuoOption::eTransfer:
		{
			system("cls");
			_ShowTrasferScreen();
			_GoBakeToTransactionMenuo();
			break;
		}

		case enTransactionMenuoOption::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBakeToTransactionMenuo();
			break;
		}

		case enTransactionMenuoOption::eShowMainMenuo:
		{
			///*system("cls");
			//_ShowMainMenuoScreen();
			//_GoBakeToTransactionMenuo();
			//break;*/

		}

		default:
			break;
		}
	}


public:

	static void ShowTransactionMenuoScreen()
	{

		if (!CheckAccessRight(clsUser::enPermission::pTransaction))
		{
			return;
		}


		system("cls");
		_DrowScreenHeader("\tTransaction Screen\n");
		
		cout << "\n\n\t\t\t\t    =============================================\n";
		cout << "\n\t\t\t\t\t\tTransaction Menuo\n";
		cout << "\n\t\t\t\t    =============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Wthdrow.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer .\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log .\n";
		cout << setw(37) << left << "" << "\t[6] Main Menuo.\n";
		cout << "\n\t\t\t\t    =============================================\n";

		_PerformMainMenuoOption((enTransactionMenuoOption)_ReadTransactionMenuoOption());
	}

};

