#pragma once
#include<iostream>
#include"clsPerson1.h"
#include<vector>
#include<string>
#include<fstream>
#include"clsString.h"
#include"clsDate.h"
#include"Global.h"
#include"clsUtil.h"

using namespace std;

class clsBankClient : public  clsPerson1
{
private:
	enum enMode{UpdetMode = 0 , EmptyMode = 1 , AddNewMode = 2};
	enMode _Mode;

	string _AccountNumber;
	float  _Accountbalance;
	string _PinCode;
	bool  _MarkToDelete = false;
	struct sTransferLog;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdetMode , vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	static string _ConvertClientOpjectToLient(clsBankClient Client, string Sepreator = "#//#")
	{
		string stClientRecort = "";
		
		stClientRecort += Client.FirstName + Sepreator;
		stClientRecort += Client.LastName + Sepreator;
		stClientRecort += Client.Emial + Sepreator;
		stClientRecort += Client.Phone + Sepreator;
		stClientRecort += Client.AccountNumber() + Sepreator;
		stClientRecort += Client.PinCode + Sepreator;
		stClientRecort += to_string(Client.Accountbalance);

		return stClientRecort;
	}

	static vector<clsBankClient> _LoadClientDataFromFile()
	{
		fstream MyFile;
		vector<clsBankClient> vClient;

		MyFile.open("Clients.txt", ios::in);
		
		if (MyFile.is_open())
		{
			string Lien;

			while (getline(MyFile, Lien))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Lien);
				vClient.push_back(Client);
			}

			MyFile.close();
		}


		return vClient;
	}

	static void _SaveClientDataToFile(vector <clsBankClient> vClient)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLien;

		if (MyFile.is_open())
		{

			for (clsBankClient& C : vClient)
			{
				if (C._MarkToDelete == false)
				{
					DataLien = _ConvertClientOpjectToLient(C);
					MyFile << DataLien << endl;
				}
			}
			MyFile.close();
		}
	}

	static clsBankClient _GetEmptyClientOpject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

	void _Updet()
	{
		vector<clsBankClient> _vClient = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientDataToFile(_vClient);
	}
	void _AddNew()
	{
		_AddClientDataToFile(_ConvertClientOpjectToLient(*this));
	}

	void _AddClientDataToFile(string stDataLien)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		
		string DataLine;

		if (MyFile.is_open())
		{
			DataLine = stDataLien;
			MyFile << DataLine << endl;

			MyFile.close();
		}

	}

	static sTransferLog _ConvertTransferLogDataFromFile(string Line , string Seberator = "#//#")
	{
	   sTransferLog TransferLoging ;
	   vector<string> vTransferLoging = clsString::Split(Line, Seberator);

	   TransferLoging.TimeDate              = vTransferLoging[0];
	   TransferLoging.SourceClient      = vTransferLoging[1];
	   TransferLoging.DestinationClient = vTransferLoging[2];
	   TransferLoging.Amount            = stof(vTransferLoging[3]);
	   TransferLoging.AmountSouce       = stof(vTransferLoging[4]);
	   TransferLoging.AmountDestination = stof(vTransferLoging[5]);
	   TransferLoging.UserName          = vTransferLoging[6];
	
	   return TransferLoging;
	}

    string _ProparTransferLogRecord(float Amount , clsBankClient DestinationClient , string UserName,
		                                   string Sebrator = "#//#")
	{
		string stTranferInfo = "";

		stTranferInfo += clsDate::GetSystemDateTimeString() + Sebrator;
		stTranferInfo += AccountNumber() + Sebrator;
		stTranferInfo += DestinationClient.AccountNumber() + Sebrator;
		stTranferInfo += to_string(Amount) + Sebrator;
		stTranferInfo += to_string(Accountbalance) + Sebrator;
		stTranferInfo += to_string(DestinationClient.Accountbalance) + Sebrator;
		stTranferInfo += UserName;

		return stTranferInfo;
	}

	void _RegisterTransFerLog(float Amount , clsBankClient DestinationClient , string UserName)
	{
		string DataLine;
		DataLine = _ProparTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);


		if (MyFile.is_open())
		{

			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

public:

	clsBankClient(enMode Mode , string FirstName, string LastName, string Emial, string Phone, string AccountNumber,
		          string PinCod, float Accountbalane) : clsPerson1(FirstName, LastName, Emial, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCod;
		_Accountbalance = Accountbalane;
	}

	struct sTransferLog
	{
		string TimeDate;
		string SourceClient;
		string DestinationClient;
		float Amount;
		float AmountSouce;
		float AmountDestination;
		string UserName;
	};

	string AccountNumber()
	{
		return _AccountNumber;
	}

	bool MarkToDelete()
	{
		return _MarkToDelete;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountbalance(float Accountbalance)
	{
		_Accountbalance = Accountbalance;
	}
	float GetAccountbalance()
	{
		return _Accountbalance;
	}
	__declspec(property(get = GetAccountbalance, put = SetAccountbalance))float Accountbalance;

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}


	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Lien;

			while (getline(MyFile, Lien))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Lien);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}
		return _GetEmptyClientOpject();
	}

	static clsBankClient Find(string AccountNumber , string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Lien;

			while (getline(MyFile, Lien))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Lien);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}
		return _GetEmptyClientOpject();
	}

	enum enSaveResults{svFildEmptyOpject = 0 , svSucceeded = 1 , svFildAccountNumberExits};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFildEmptyOpject;
			}
		}

		case enMode::UpdetMode:
		{
			_Updet();
			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExit(_AccountNumber))
			{
				return clsBankClient::svFildAccountNumberExits;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdetMode;
				return clsBankClient::svSucceeded;
			}
		}

		}
	}

	 void Deposit(double Amount)
	 {
	   _Accountbalance += Amount;
		Save();
	 }

	 bool Withdrow(double Amount)
	 {
		 if (Amount > _Accountbalance)
		 {
			 return false;
		 }
		 else
		 {
			_Accountbalance -= Amount;
			 Save();
		 }
	 }

	static bool IsClientExit(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return(!Client.IsEmpty());
	}

	static clsBankClient GetAddNweClientOpject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> vClient = _LoadClientDataFromFile();

	  for (clsBankClient &C : vClient)
	   {
		 if (C.AccountNumber() == _AccountNumber)
		   {
		      C._MarkToDelete = true;			
			  break;
		   }
	   }
		
		_SaveClientDataToFile(vClient);
		*this = _GetEmptyClientOpject();
		
		return true;
	}

	static vector<clsBankClient> GetClientList()
	{
		return _LoadClientDataFromFile();
    }

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClient = _LoadClientDataFromFile();

		double TotalBalance = 0 ;

		for (clsBankClient& Client : vClient)
		{
			TotalBalance += Client.Accountbalance;
		}

		return TotalBalance;
    }

	bool Transfer(double Amount, clsBankClient& DestinationClient , string UserName)
	{
		if (Amount > Accountbalance)
		{
			return false;
		}

		Withdrow(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransFerLog(Amount, DestinationClient, UserName);
		return true;
	}

	static vector<sTransferLog> GetTransferLogList()
	{
		fstream MyFile;
		vector<sTransferLog> vTransferLog;

		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string DataLine;
			sTransferLog TransferData;

			while (getline(MyFile, DataLine))
			{
			   TransferData = _ConvertTransferLogDataFromFile(DataLine);
			   vTransferLog.push_back(TransferData);
			}

			MyFile.close();
		}

		return vTransferLog;
	}

};

