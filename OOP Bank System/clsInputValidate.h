#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"
#include"clsPerson1.h"

using namespace std;

template <class TypName>
class clsInputValidate
{

public:

	static TypName IsNumberBetween(TypName Num, TypName From, TypName To)
	{
		return Num >= From && Num <= To;
	}

	static TypName IsDateBetween(TypName Date, TypName DateFrom, TypName DateTo)
	{
		if (clsDate::IsDate1AfterDate2(Date, DateTo) || clsDate::IsDate1EqualDat2(Date, DateTo) &&
			clsDate::IsDate1BeforDate2(Date, DateFrom) || clsDate::IsDate1EqualDat2(Date, DateFrom))
		{
			return true;
		}

		if (clsDate::IsDate1AfterDate2(Date, DateFrom) || clsDate::IsDate1EqualDat2(Date, DateFrom) &&
			clsDate::IsDate1BeforDate2(Date, DateTo) || clsDate::IsDate1EqualDat2(Date, DateTo))
		{
			return true;
		}

		return false;
	}

	static TypName ReadNumber(string ErorrMasseg = "Invalid  Number , Enter Agine:")
	{
		int Number;
	
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErorrMasseg << endl;
		}
		return Number;
	}

	static TypName ReadNumberBetween(TypName From, TypName To, string ErorrMasseg = "Number is not withen reang, Enter a nother Number :\n")
	{
		int Number = ReadNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErorrMasseg << endl;
			Number = ReadNumber();
		}
    
		return Number;
	}

	static TypName IsValidDate(TypName Date)
	{
		return clsDate::IsValiedDate(Date);
	}
	
	static TypName ReadString()
	{
		string St;

	   getline(cin >> ws, St);
	  return St;
	}

	static TypName ReadfloatNumber()
	{
		float Number;
		cin >> Number;
		return Number;
	}

};

