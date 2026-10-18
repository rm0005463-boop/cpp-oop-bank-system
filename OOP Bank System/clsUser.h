#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"clsPerson1.h"
#include"clsString.h"
#include<string>
#include"clsDate.h"
#include"clsUtil.h"

using namespace std;
class clsUser : public clsPerson1
{
private:
	enum  enMode{EmptyMode = 1 , UpdetMode = 2 , AddNewMode = 3};
	enMode _Mode;
	
	string _UserName;
	string _PassWord;
	int _Permission;
	string _Time;
	

	bool _MarkUserForDelete = false;

	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _ConvertLogingDataFromFile(string Line, string Serbertor = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector<string> vLoginRegisterRecord = clsString::Split(Line, Serbertor);

		LoginRegisterRecord.Time = vLoginRegisterRecord[0];
		LoginRegisterRecord.UserName = vLoginRegisterRecord[1];
		LoginRegisterRecord.PassWord = clsUtil::DecryptText(vLoginRegisterRecord[2]);
		LoginRegisterRecord.Permission = stoi(vLoginRegisterRecord[3]);
      
		return LoginRegisterRecord;
	}

	static clsUser _ConvertLienToUserOpject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdetMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));

	}

	static string _ConvertUserOpjectToLien(clsUser User , string Seberator = "#//#")
	{
		string stUserRecord;
		stUserRecord += User.FirstName + Seberator;
		stUserRecord += User.LastName + Seberator;
		stUserRecord += User.Emial + Seberator;
		stUserRecord += User.Phone + Seberator;
		stUserRecord += User._UserName + Seberator;
		stUserRecord += clsUtil::EncryptText(User._PassWord) + Seberator;
		stUserRecord += to_string(User._Permission);

		return stUserRecord;
	}

	static vector <clsUser> _LoadDataFromFileToVector()
	{
		
		vector<clsUser> vUser;
		fstream MyFile;
		

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLienToUserOpject(Line);
				vUser.push_back(User);
			}

			MyFile.close();
		}

		return vUser;
	}

	static void _SavdDataToFile(vector<clsUser>& vUser)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			string Lien;

			for (clsUser &U : vUser)
			{
				if (U._MarkUserForDelete == false)
				{
					Lien = _ConvertUserOpjectToLien(U);
					MyFile << Lien << endl;
				}
			}

			MyFile.close();
		}
	}

	static clsUser _GetEmptyUserOpject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	void _Updet()
	{
		vector<clsUser> _vUser = _LoadDataFromFileToVector();

		for (clsUser& User : _vUser)
		{
			if (User.UserName == UserName)
			{
				User = *this;
				break;
			}
		}

		_SavdDataToFile(_vUser);
	}
	void _AddNew()
	{
		_AddUserDataToFile(_ConvertUserOpjectToLien(*this));
	}

	void _AddUserDataToFile(string stDataLien)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in | ios::app);

		string UserData;

		if (MyFile.is_open())
		{
			UserData = stDataLien;
			MyFile << UserData << endl;

			MyFile.close();
		}
	}

	string _PrepareLoginInRecord(string Seberator = "#//#")
	{
		string LoginInfo;

		LoginInfo += clsDate::GetSystemDateTimeString() + Seberator;
		LoginInfo += UserName + Seberator;
		LoginInfo += clsUtil::EncryptText(PassWord) + Seberator;
		LoginInfo += to_string(Permission);

		return LoginInfo;
	}

public:

	clsUser(enMode Mode, string FirstName, string LastName, string Emial, string Phone, string UserName,
		string PassWord, int Permission) : clsPerson1(FirstName, LastName, Emial, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_PassWord = PassWord;
		_Permission = Permission;
	}

	enum enPermission{eAll = -1,pListClient = 1 , pAddNewClient = 2 , pDeleteClient =4,pUpdetClient = 8 , pFindClient = 16,
	                  pTransaction = 32 , pManageUser = 64 , pShowLoginInRegister = 128};

	struct stLoginRegisterRecord
	{
		string Time;
		string UserName;
		string PassWord;
		int Permission;
	};


	bool MarkForDelete()
	{
		return _MarkUserForDelete;
	}


	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	
	__declspec(property(get = GetUserName, put = SetFirstName))string UserName;

	void SetPassWord(string PassWord)
	{
		_PassWord = PassWord;
	}
	string GetPassWord()
	{
		return _PassWord;
	}

	__declspec(property(get = GetPassWord, put = SetPassWord))string PassWord;


	void SetPeermisston(int Permission)
	{
		_Permission = Permission;
	}
	int GetPermissn()
	{
		return _Permission;
	}

	__declspec(property(get = GetPermissn, put = SetPeermisston))int Permission;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		string Lien;

		if (MyFile.is_open())
		{
			while (getline(MyFile, Lien))
			{
				clsUser User = _ConvertLienToUserOpject(Lien);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserOpject();
	}

	static clsUser Find(string UserName, string PassWord)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Lien;

			while (getline(MyFile, Lien))
			{
				clsUser User = _ConvertLienToUserOpject(Lien);

				if (User.UserName == UserName && User.PassWord == PassWord)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();
		}
		return _GetEmptyUserOpject();
	}

	enum enSaveResult{svFildEmptyOpject=1 , svSucceeded , svFildUserNameExit};
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResult::svFildEmptyOpject;
			}
		}

		case enMode::UpdetMode:
		{
			_Updet();
			return enSaveResult::svSucceeded;
			break;
		}

		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExit(_UserName))
			{
				return enSaveResult::svFildUserNameExit;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdetMode;
				return enSaveResult::svSucceeded;
			}

		}

		}
    }

	 bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	static bool IsUserExit(string UserName)
	 {
		 clsUser User = clsUser::Find(UserName);
		 return(!User.IsEmpty());
	 }

	 static clsUser GetAddNewUserOpject(string UserName)
	 {
		 return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	 }

	 bool Delete()
	 {
		 vector<clsUser> vUser = _LoadDataFromFileToVector();

		 for (clsUser& User : vUser)
		 {
			 if (User.UserName == UserName)
			 {
				 User._MarkUserForDelete = true;
				 break;
			 }
		 }

		 _SavdDataToFile(vUser);
		 *this = _GetEmptyUserOpject();

		 return true;
	 }

	 static vector<clsUser> GetUserList()
	 {
		 return _LoadDataFromFileToVector();
	 }

    bool CheckAccessPermission(enPermission Permission)
	 {
		 if (this->Permission == enPermission::eAll)
			 return true;

		 if ((Permission & this->Permission) == Permission)
			 return true;

		 else
		 {
			 return false;
		 }
	 }

    void RegisterLogin()
	{
		string stDataLien = _PrepareLoginInRecord();

     	fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		
		if (MyFile.is_open())
		{
	
			MyFile << stDataLien << endl;

			MyFile.close();
		}
	}

	static vector<stLoginRegisterRecord> GetLoginRegiserList()
	{
		 vector<stLoginRegisterRecord> vLoginRegisterRecord;
		 fstream MyFile;
		 
		 
		 MyFile.open("LoginRegister.txt", ios::in);
		 
		 if (MyFile.is_open())
		 {
		 	string Line;
			stLoginRegisterRecord LoginRegisterRecord;


		 	while (getline(MyFile, Line))
		 	{

		 		LoginRegisterRecord = _ConvertLogingDataFromFile(Line);

		 		vLoginRegisterRecord.push_back(LoginRegisterRecord);
		 	}
		 
		 	MyFile.close();
		 }
		 
		 return vLoginRegisterRecord;

	}
};

