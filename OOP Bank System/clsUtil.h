#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"


using namespace std;
class clsUtil
{
public:
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int randnumb = rand() % (To - From + 1) + From;
		return randnumb;
	}

	enum enCharTyp { CapitalLetters = 1, SmallLetters = 2, Digit = 3, SpecialChracter = 4, MixChars = 5 };

	static char GetRandomChractor(enCharTyp Typ)
	{
		if (Typ == enCharTyp::MixChars)
		{
			Typ = enCharTyp(RandomNumber(1, 3));
		}

		switch (Typ)
		{

		case enCharTyp::SmallLetters:
		{
			return char(RandomNumber(97, 122));
			break;
		}

		case enCharTyp::CapitalLetters:
		{
			return char(RandomNumber(65, 90));
			break;
		}

		case enCharTyp::SpecialChracter:
		{
			return char(RandomNumber(33, 47));
			break;
		}

		case enCharTyp::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}

		case enCharTyp::MixChars:
		{
			return char(RandomNumber(60, 122));
			break;
		}

		default:
			return char(RandomNumber(65, 90));
			break;
		}
	}

	static string GenerateWord(enCharTyp Typ, short Length)
	{
		string Word = "";

		for (short i = 0; i < Length; i++)
		{
			Word = Word + GetRandomChractor(Typ);
		}

		return Word;
	}

	static string GenerateKey(enCharTyp Typ)
	{
		string Key = "";

		Key = Key + GenerateWord(Typ, 4) + "_";
		Key = Key + GenerateWord(Typ, 4) + "_";
		Key = Key + GenerateWord(Typ, 4) + "_";
		Key = Key + GenerateWord(Typ, 4);
	
		return Key;
	}

	static void GenerateKeys(enCharTyp Typ , short Lengh)
	{
		for (short i = 0; i <Lengh ; ++i)
		{
			cout << " Key [" << i << "]:" << GenerateKey(Typ) << endl;
		}
	}

	static int Swap(int& Num1, int& Num2)
	{
		int Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;

		return Num1, Num2;
	}
	
	static bool Swap(bool& Num1, bool& Num2)
	{
		bool Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;

		return Num1, Num2;
	}

	static char Swap(char& Num1, char& Num2)
	{
		char Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;

		return Num1, Num2;
	}

	static double Swap(double& Num1, double& Num2)
	{
		double Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;

		return Num1, Num2;
	}

	static string Swap(string& St1, string& St2)
	{
		string Temp;
		Temp = St1;
		St1 = St2;
		St2 = Temp;

		return St1, St2;
	}

	static void Swap(clsDate &Date1 , clsDate &Date2)
	{
		clsDate::SwapDates(Date1, Date2);
	}

	static void SuffleArr(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
	    }
	}

	static void SuffleArr(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static void FillArrayWithRandomNumber(int arr[], int Lenth, int From , int To)
	{
		for (int i = 0; i < Lenth; i++)
		    arr[i] = RandomNumber(From , To);
		
	}

	static void FillArrayWithRandomWord(string arr[], int Lenth, enCharTyp Typ, int Lenth2)
	{
		for (int i = 0; i < Lenth; i++)
			arr[i] = GenerateWord(Typ, Lenth2);
	}

	static void FillArrayWithRandomKey(string arr[], int Lenth, enCharTyp Typ)
	{
		for (int i = 0; i < Lenth; i++)
			arr[i] = GenerateKey(Typ);
	}

	static string Tabs(int NumberOfTabe)
	{
		string T;

		for (short i = 1; i <= NumberOfTabe; i++)
		{
			T += "\t";
		}
		return T;
	}

	static string ReadText()
	{
		string Text; 

		cout << "Please enter Text?\n";
		getline(cin, Text);             

		return Text;
	}

	static string EncryptText(string Text, short EncryptionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text; 
	}

	static string DecryptText(string Text, short EncryptionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text; 
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

};

