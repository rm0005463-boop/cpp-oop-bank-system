#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

using namespace std;
class clsFindUserScreen :protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\n\tUser Card";
		cout << "\n_____________________________";
		cout << "\nFirst Name    :" << User.FirstName;
		cout << "\nLast Name     :" << User.LastName;
		cout << "\nFull Name     :" << User.FullName();
		cout << "\nEmial         :" << User.Emial;
		cout << "\nPhone         :" << User.Phone;
		cout << "\nUserName      :" << User.UserName;
		cout << "\nPasssWord     :" << User.PassWord;
		cout << "\nPermission    :" << User.Permission;
		cout << "\n_____________________________";
	}
public:
	static void ShowFindUserScreen()
	{
		_DrowScreenHeader("\t Find User Screen");
		 
		string UserName = "";
		cout << "\nPlease Enter UserName ?";
		UserName = clsInputValidate <string> ::ReadString();

		while (!clsUser::IsUserExit(UserName))
		{
			cout << "\nUserName it's not found , try agane ?";
			UserName = clsInputValidate <string> ::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found -:)";
		}
		else
		{
			cout << "\nUser was not found -:(";
		}

		_PrintUser(User);
	}
};

