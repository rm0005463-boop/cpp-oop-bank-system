#pragma once
#include<iostream>
#include"Global.h"
#include"clsDate.h"

using namespace std;

class clsScreen
{
protected:

	static void _DrowScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\n\t\t\t\t      _______________________________________\n";
		cout << "\n\n\t\t\t\t\t" << Title;
		
		if (SubTitle != "")
		{
			cout << "\n\n\t\t\t\t\t" << SubTitle;
		}
		cout << "\n\t\t\t\t      _______________________________________\n";

		cout << "\n\t\t\t\t\tUser : " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\tDate : " << clsDate::DateToString(clsDate());
	
	}

	static bool CheckAccessRight(clsUser::enPermission Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\n\t\t\t\t      _______________________________________\n";
			cout << "\n\n\t\t\t\t\t Access Denin! Contact to your Admin ";
			cout << "\n\t\t\t\t      _______________________________________\n";
			return false;
		}
		else
		{
			return true;
		}
	}

};

