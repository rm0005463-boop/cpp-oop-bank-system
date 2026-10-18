#pragma once
#include<iostream>
#include"iomanip"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListUserScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdetUserScreen.h"
#include"clsFindUserScreen.h"

using namespace std;

class clsManageUserScreen : protected clsScreen
{
private:
	enum enManageUserMenuoOption {
		eListUser = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdetUser = 4,
		eFindUser = 5, eMainMenuo = 6
	};

	static void _GoBakeToManageUserMenuo()
	{
		cout << setw(37) << left << "" << "\nPrasue Any Key To Bake Mein Menuo....";
		system("pause > 0");

		ShowManangeUserMenuoScreen();
	}

	static void _ShowListUserScreen()
	{
		//cout << "\nListclient will be hear ....";
		clsListUserScreen::ShowUsertList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\nAdd new client Screen will be hear ....";
		clsAddNewUserScreen::ShowAddNewUser();
	}

	static void _DeleteUserScreen()
	{
		//cout << "\nDelete client Screen will be hear ....";
		clsDeleteUserScreen::ShowDeleteClientScreen();
	}

	static void _UpdetUserScreen()
	{
		//cout << "\nUpdet client Screen will be hear ....";
		clsUpdetUserScreen::ShowUpdetUserScreen();
	}

	static void _FindUserScreen()
	{
		//cout << "\nFind client Screen will be hear ....";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static short _ReadManageUserMenuoOption()
	{
		short Choose;
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 To 6] ?";
		Choose = clsInputValidate <int>::ReadNumberBetween(1, 6);
		return Choose;
	}

	static void _PerformMangaeUserMenuoOption(enManageUserMenuoOption MainMenuoOptin)
	{
		switch (MainMenuoOptin)
		{

		case enManageUserMenuoOption::eListUser:
		{
			system("cls");
			_ShowListUserScreen();
			_GoBakeToManageUserMenuo();
			break;
		}

		case enManageUserMenuoOption::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBakeToManageUserMenuo();
			break;
		}

		case enManageUserMenuoOption::eDeleteUser:
		{
			system("cls");
			_DeleteUserScreen();
			_GoBakeToManageUserMenuo();
			break;
		}

		case enManageUserMenuoOption::eUpdetUser:
		{
			system("cls");
			_UpdetUserScreen();
			_GoBakeToManageUserMenuo();
			break;
		}

		case enManageUserMenuoOption::eFindUser:
		{
			system("cls");
			_FindUserScreen();
			_GoBakeToManageUserMenuo();
			break;
		}

		case enManageUserMenuoOption::eMainMenuo:
		{
			//system("cls");
	
		}

		default:
			break;
		}
	}

public:

	static void ShowManangeUserMenuoScreen()
	{
		system("cls");

		if (!CheckAccessRight(clsUser::enPermission::pManageUser))
		{
			return;
		}


		_DrowScreenHeader("\t Manage User Screen\n");
		
		cout << "\n\n\t\t\t\t    =============================================\n";
		cout << "\n\t\t\t\t\t\t\t Manage User Menuo\n";
		cout << "\n\t\t\t\t    =============================================\n";
		cout << setw(37) << left << "" << "\t[1] List User.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Updet User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menuo.\n";
		cout << "\n\t\t\t\t    =============================================\n";

		_PerformMangaeUserMenuoOption((enManageUserMenuoOption)_ReadManageUserMenuoOption());
	}


};

