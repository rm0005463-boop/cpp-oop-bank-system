#pragma once
#include<iostream>
#include"clsUser.h"
#include"Global.h"
#include"clsScreen.h"
#include<fstream>
#include"clsMainScreen.h"
#include"clsDate.h"


using namespace std;
class clsLoginScreen :protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFild = false;
		int FildLoginCount = 0;

		string UserName, PassWord;
		do
		{

			if (LoginFild)
			{
				FildLoginCount++;
				cout << "\nInvalid UserName/PassWord!";
				cout << "\nYou have " << (3 - FildLoginCount)
					<< " trial (s) to login\n\n";
			}

			if (FildLoginCount == 3)
			{
				cout << "\n\nYou are locet after 3 filed trials";
				return false;

			}


			cout << "\nPlease Enter UserName ?";
			cin >> UserName;

			cout << "\nPlease Enter PassWord ?";
			cin >> PassWord;


			CurrentUser = clsUser::Find(UserName, PassWord);

			LoginFild = CurrentUser.IsEmpty();
		
		} while (LoginFild);


		
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenuoScreen();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrowScreenHeader("\t Login Screen");

		return _Login();
	}
};

