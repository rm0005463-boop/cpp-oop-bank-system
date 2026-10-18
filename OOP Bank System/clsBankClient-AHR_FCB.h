#pragma once
#include<iostream>
#include"clsPerson1.h"
#include<vector>
#include<string>
#include"clsString.h"
#include<fstream>

using namespace std;

class clsBankClient : public clsPerson1
{
private:

	enum enMode {enEmptey = 0 , enUpdet = 1};
	enMode _Mode;

	string _PinCode;
	string _AccontNumber;
	float  _Accountbalance;

	static clsBankClient _ConvertLineToClientOPject(string Line , string Seberator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seberator);

		return clsBankClient(enMode::enUpdet, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stoi(vClientData[6]));
	}
	static clsBankClient _GetEmptyClientOpject()
	{
		return clsBankClient(enMode::enEmptey, "", "", "", "", "", "", 0);
	}


public:
	
	clsBankClient(enMode Mode , string FirstName , string LastName ,string Emial , string Phone , string AccountNumber , string PinCode , float Accountbalance):
		         clsPerson1(FirstName , LastName , Emial , Phone)
	{
		_Mode = Mode;
		_AccontNumber = AccountNumber;
		_PinCode = PinCode;
		_Accountbalance = Accountbalance;

	}

	string AccountNumber()
	{
		return _AccontNumber;
	}

	void SetAccountBalance(float Accountbalance)
	{
		_Accountbalance = Accountbalance;
	}
	float GetAccountbalance()
	{
		return _Accountbalance;
	}
	__declspec(property(get = GetAccountbalance, put = SetAccountBalance)) float Accountbalance;


	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	bool IsEmpty()
	{
		return (_Mode == enMode::enEmptey);
	}
	void Print()
	{
		cout << "\n\tClient Card";
		cout << "\n____________________________";
		cout << "\nFirst Name     :" << FirstName;
		cout << "\nLast Name      :" << LastName;
		cout << "\nFull Name      :" << FullName();
		cout << "\nEmial          :" << Emial;
		cout << "\nPhone          :" << Phone;
		cout << "\nAcount Number  :" << _AccontNumber;
		cout << "\nPinCode :" << _PinCode;
		cout << "\nAccount Balance :" << _Accountbalance;
		cout << "\n____________________________";

	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("ClientData.txt", ios::in);

		if (MyFile.is_open())
		{
			string Lien;
			while (getline(MyFile, Lien))
			{
				clsBankClient Client = _ConvertLineToClientOPject(Lien);
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
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("ClientData.txt", ios::in);

		if (MyFile.is_open())
		{
			string Lien;
			while (getline(MyFile, Lien))
			{
				clsBankClient Client = _ConvertLineToClientOPject(Lien);
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

	bool IsClientExet(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

};

