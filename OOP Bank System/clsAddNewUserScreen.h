#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;
class clsAddNewUserScreen :protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FistName :";
		User.FirstName = clsInputValidate <string> ::ReadString();

		cout << "\nEnter LastName :";
		User.LastName = clsInputValidate <string> ::ReadString();

		cout << "\nEnter Emial :";
		User.Emial = clsInputValidate <string> ::ReadString();

		cout << "\nEnter Phone :";
		User.Phone = clsInputValidate <string> ::ReadString();

		cout << "\nEnter PassWord :";
		User.PassWord = clsInputValidate <string> ::ReadString();
		
		cout << "\nEnter Permission :";
		User.Permission = _ReadPermissionToSet();

	}

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

	static int _ReadPermissionToSet()
	{
		int Permission = 0 ;

		char Answer = 'n';
		cout << "\nDo you want to give full access ? y/n ?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to :";


		cout << "\nShow Client List ? y/n ?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermission::pListClient;
		}

		cout << "\nAdd New Client ? y/n ?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermission::pAddNewClient;
		}

		cout << "\nDelete Client ? y/n ?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermission::pDeleteClient;
		}

		cout << "\nUpdet Client ? y/n ?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermission::pUpdetClient;
		}

		cout << "\nFind Client ? y/n ?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermission::pFindClient;
		}

		cout << "\nTransaction ? y/n ?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermission::pTransaction;
		}

		cout << "\nManage User ? y/n ?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermission::pManageUser;
		}

		cout << "\nLogin Register ? y/n ?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermission::pShowLoginInRegister;
		}

		return Permission;
	}

public:
	static void ShowAddNewUser()
	{
		_DrowScreenHeader("\t Add New User");

		string UserName = "";
		cout << "\nPlease Enter UserName ?";
		UserName = clsInputValidate <string> ::ReadString();

		while (clsUser::IsUserExit(UserName))
		{
			cout << "\nUser Name alrady Used , choose anther once ";
			UserName = clsInputValidate <string> ::ReadString();
		}

		clsUser AddNew = clsUser::GetAddNewUserOpject(UserName);
		_ReadUserInfo(AddNew);


		clsUser::enSaveResult SaveResult;
		SaveResult = AddNew.Save();


		switch (SaveResult)
		{
		case clsUser::enSaveResult::svSucceeded:
		{
			cout << "\nUser Added Sccussfully .";
			_PrintUser(AddNew);
			break;
		}

		case clsUser::enSaveResult::svFildEmptyOpject:
		{
			cout << "\nErorr User was not saved , becouse it's empty.";
			break;
		}

		case clsUser::enSaveResult::svFildUserNameExit:
		{
			cout << "\nErorr User was not saved , becouse user it's exit!";
			break;
		}
		}
    }

};

