#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdetClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUserScreen.h"
#include"clsLoginRegistrScreen.h"
#include"Global.h"
#include"clsCurrencyMainScreen.h"


using namespace std;

class clsMainScreen : protected clsScreen
{

private:
	enum enMainMenuoOption{eListClient = 1 , eAddNewClient = 2 , eDeleteClient = 3 , eUpdetlient = 4 ,
	                       eFindClient = 5 , eTransaction = 6 , eManageUser = 7 , eLoginRegister = 8 ,eCurrencyExechange = 9, eExit = 10};

	static void _GoBakeToMainMenuo()
	{
	    cout << setw(37) << left << "" << "\nPrasue Any Key To Bake Mein Menuo....";
		system("pause > 0");

		ShowMainMenuoScreen();
	}

	static void _ShowAllClientScrren()
	{
		//cout << "\nListclient will be hear ....";
		clsClientListScreen::ShowClientList();
	}

	static void _ShowAddNewClientScreen()
	{
		//cout << "\nAdd new client Screen will be hear ....";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _DeleteClientScreen()
	{
		//cout << "\nDelete client Screen will be hear ....";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _UpdetClientScreen()
	{
		//cout << "\nUpdet client Screen will be hear ....";
		clsUpdetClientScreen::ShowUpdetClientScreen();
	}

	static void _FindClientScreen()
	{
		//cout << "\nFind client Screen will be hear ....";
		clsFindClientScreen::ShowFindCliendScreen();
	}

	static void _TransactionScreen()
	{
		//cout << "\nTransaction will be hear ....";
		clsTransactionScreen::ShowTransactionMenuoScreen();
	}

	static void _ManageUserScreen()
	{
		clsManageUserScreen::ShowManangeUserMenuoScreen();
	}

	static void _LoginRegisterScreen()
	{
		clsLoginRegistrScreen::ShowLoginRegisterListScreen();
	}

	static void _CurrencyMainScreen()
	{
		clsCurrencyMainScreen::ShowCurrencyMainScreen();
	}

	static void _Logeout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static short _ReadMainMenuoOption()
	{
		short Choose;
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 To 10] ?";
		Choose = clsInputValidate <int> ::ReadNumberBetween(1, 10);
		return Choose;
	}

	static void _PerformMainMenuoOption(enMainMenuoOption MainMenuoOptin)
	{
		switch (MainMenuoOptin)
		{

		case enMainMenuoOption::eListClient:
		{
			system("cls");
			_ShowAllClientScrren();
			_GoBakeToMainMenuo();
			break;
		}

		case enMainMenuoOption::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBakeToMainMenuo();
			break;
		}

		case enMainMenuoOption::eDeleteClient:
		{
			system("cls");
			_DeleteClientScreen();
			_GoBakeToMainMenuo();
			break;
		}

		case enMainMenuoOption::eUpdetlient:
		{
			system("cls");
			_UpdetClientScreen();
			_GoBakeToMainMenuo();
			break;
		}

		case enMainMenuoOption::eFindClient:
		{
			system("cls");
			_FindClientScreen();
			_GoBakeToMainMenuo();
			break;
		}

		case enMainMenuoOption::eTransaction:
		{
			system("cls");
			_TransactionScreen();
			_GoBakeToMainMenuo();
			break;
		}

		case enMainMenuoOption::eManageUser:
		{
			system("cls");
			_ManageUserScreen();
			_GoBakeToMainMenuo();
			break;
		}

		case enMainMenuoOption::eLoginRegister:
		{
			system("cls");
			_LoginRegisterScreen();
			_GoBakeToMainMenuo();
			break;
		}

		case enMainMenuoOption::eCurrencyExechange:
		{
			system("cls");
			_CurrencyMainScreen();
			_GoBakeToMainMenuo();
			break;
		}

		case enMainMenuoOption::eExit:
		{
			system("cls");
			_Logeout();
			break;
		}

		default:
			break;
		}
	}

	public:

	static void ShowMainMenuoScreen()
	{
		system("cls");
		_DrowScreenHeader("\t  Main Screen\n");
		

		cout << "\n\t\t\t\t    =============================================\n";
		cout << "\n\t\t\t\t\t\t\tMain Menuo\n";
		cout << "\n\t\t\t\t    =============================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client Screen.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Updet Client.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transaction Client.\n";
		cout << setw(37) << left << "" << "\t[7] Manage User.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << "\n\t\t\t\t   =============================================\n";

		_PerformMainMenuoOption((enMainMenuoOption)_ReadMainMenuoOption());
	}

};

