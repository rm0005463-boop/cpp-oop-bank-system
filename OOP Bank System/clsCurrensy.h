#pragma once
#include<iostream>
#include<vector>
#include"clsString.h"
#include<string>
#include<fstream>

using namespace std;
class clsCurrensy
{ 
private:
	enum enMode{EmptyMode = 0 , UpdetMode = 1};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrensy _ConvertLineToCurrencyOpject(string Line , string Seberator = "#//#")
	{
		vector<string> vCurrencyData = clsString::Split(Line, Seberator);

		return clsCurrensy(enMode::UpdetMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));

	}

	static string _ConvertCurrencyOpjectToLine(clsCurrensy Currency ,string Seberator = "#//#")
	{
		string stCurrencyData;
		stCurrencyData += Currency.Country() + Seberator;
		stCurrencyData += Currency.CurrenseyCode() + Seberator;
		stCurrencyData += Currency.CurrensyName() + Seberator;
		stCurrencyData += to_string(Currency._Rate);

		return stCurrencyData;
	}

	static vector<clsCurrensy> _LoadCurrencyDataFromFile()
	{
		vector<clsCurrensy> vCurrencyData;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		string Line;

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsCurrensy CurrenceyData = _ConvertLineToCurrencyOpject(Line);
				vCurrencyData.push_back(CurrenceyData);
			}

			MyFile.close();
		}

		return vCurrencyData;
	}

	static clsCurrensy _GetEmptyCurrencyOpject()
	{
		return clsCurrensy(enMode::EmptyMode, "", "", "", 0);
	}

	void _SavetCurrencyToFile(vector<clsCurrensy> vCurrencyData)
	{
		
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsCurrensy& CurrencyData : vCurrencyData)
			{
				Line = _ConvertCurrencyOpjectToLine(CurrencyData);
				MyFile << Line << endl;
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrensy> _vCurrencyData = _LoadCurrencyDataFromFile();
		for (clsCurrensy &C : _vCurrencyData)
		{
			if (C.CurrenseyCode() == CurrenseyCode())
			{
				C = *this;
				break;
			}
		}

		_SavetCurrencyToFile(_vCurrencyData);
	}

public:
	clsCurrensy(enMode Mode, string Country, string CurrensyCode, string CurrensyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrensyCode;
		_CurrencyName = CurrensyName;
		_Rate = Rate;
	}

	string Country()
	{
		return _Country;
	}

	string CurrenseyCode()
	{
		return _CurrencyCode;
	}

	string CurrensyName()
	{
		return _CurrencyName;
	}

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrensy FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrensy CurrencyData = _ConvertLineToCurrencyOpject(Line);

				if (CurrencyData.CurrenseyCode() == CurrencyCode)
				{
					MyFile.close();
					return CurrencyData;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyOpject();
	}

	static clsCurrensy FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);
		string Line;

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsCurrensy CurrencyData = _ConvertLineToCurrencyOpject(Line);
				if ((clsString::UpperAllString(CurrencyData._Country)) == Country)
				{
					MyFile.close();
					return CurrencyData;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyOpject();
	}

	static bool IsCurrencyExit(string CurrencyCode)
	{
		clsCurrensy Currency = clsCurrensy::FindByCode(CurrencyCode);
		return(!Currency.IsEmpty());
	}

	static vector<clsCurrensy> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return((float)Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrensy Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (clsString::UpperAllString(Currency2.CurrenseyCode()) == "USD")
		{
			return Amount;
		}

		return (float(AmountInUSD * Currency2.Rate()));
	}
};

