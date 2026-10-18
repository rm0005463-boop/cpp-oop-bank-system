#pragma once
#include<iostream>
#include<vector>

using namespace std;

class clsString
{
private:
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}


	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Lenght(string St)
	{
		return St.length();
	}
	short Lenght()
	{
		return _Value.length();
	}

	//Count Word 
	static short CountWords(string St)
	{
		short Pos = 0;
		string Delimt = " ";
		string sWord;
		int Counter = 0;

		while ((Pos = St.find(Delimt)) != std::string::npos)
		{
			sWord = St.substr(0, Pos);

			if (sWord != " ")
			{
				Counter++;
			}

			St.erase(0, Pos + Delimt.length());
		}
		if (St != "")
		{
			Counter++;
		}
		return Counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}


	//Problem[23] : Print First Leter Of Each Word.
	static void PrintFirstLeterOfEachWord(string St)
	{
		bool IsFirstLeter = true;

		for (int i = 0; i < St.length(); i++)
		{
			if (St[i] != ' ' && IsFirstLeter)
			{
				cout << St[i] << endl;
			}

			IsFirstLeter = ((St[i] == ' ') ? true : false);
		}
	}
	void PrintFirstLeterOfEachWord()
	{
		PrintFirstLeterOfEachWord(_Value);
	}


	//Problem[24] : Upper First Leter Of Each Word.
	static string UpperFirstLeterOfEachWord(string St)
	{
		bool IsFirstLeter = true;

		for (int i = 0; i < St.length(); i++)
		{
			if (St[i] != ' ' && IsFirstLeter)
			{
				St[i] = toupper(St[i]);
			}
			IsFirstLeter = ((St[i] == ' ') ? true : false);
		}

		return St;
	}
	void UpperFirstLeterOfEachWord()
	{
		_Value = UpperFirstLeterOfEachWord(_Value);
	}


	//Problem[25] : Lower First Leter Of Each Word.
	static string LowerFirstLeterOfEachWord(string St)
	{
		bool IsFiretLeter = true;

		for (int i = 0; i < St.length(); i++)
		{
			if (St[i] != ' ' && IsFiretLeter)
			{
				St[i] = tolower(St[i]);
			}
			IsFiretLeter = ((St[i] == ' ') ? true : false);
		}

		return St;
	}
	void LowerFirstLeterOfEachWord()
	{
		_Value = LowerFirstLeterOfEachWord(_Value);
	}


	//Problem[26] : Lower Leter Of Each Word.
	static string UpperAllString(string St)
	{
		for (int i = 0; i < St.length(); i++)
		{
			St[i] = toupper(St[i]);
		}
		return St;
	}
	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}


	//Problem[26] : Lower Leter Of Each Word.
	static string LowerAllString(string St)
	{
		for (int i = 0; i < St.length(); i++)
		{
			St[i] = tolower(St[i]);
		}
		return St;
	}
	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}


	//Problem[27] : Invert Letter case.
	static char InvertLeterCase(char Char1)
	{
		return isupper(Char1) ? tolower(Char1) : toupper(Char1);
	}


	//Problem[28] : Invert All String Letter case.
	static string InvertAllStringLeterCase(string St)
	{
		for (int i = 0; i < St.length(); i++)
		{
			St[i] = InvertLeterCase(St[i]);
		}
		return St;
	}
	void InvertAllStringLeterCase()
	{
		_Value = InvertAllStringLeterCase(_Value);
	}


	//Problem[29] : Count Capital And Small Leters In String.
	enum enWhatToCount { SmallLeter = 0, CapitalLetter = 1, All = 2 };

	short CountLetters(string St, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return St.length();
		}


		short Count = 0;

		for (int i = 0; i < St.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetter && isupper(St[i]))
			{
				Count++;
			}

			if (WhatToCount == enWhatToCount::SmallLeter && islower(St[i]))
			{
				Count++;
			}
		}

		return Count;

	}

	static short CountCapitalLeter(string St)
	{
		short Count = 0;

		for (int i = 0; i < St.length(); i++)
		{
			if (isupper(St[i]))
			{
				Count++;
			}
		}
		return Count;
	}
	short CountCapitalLeter()
	{
		return CountCapitalLeter(_Value);
	}

	static short CountSmallLeter(string St)
	{
		short Count = 0;

		for (int i = 0; i < St.length(); i++)
		{
			if (islower(St[i]))
			{
				Count++;
			}
		}
		return Count;
	}
	short CountSmallLeter()
	{
		return CountSmallLeter(_Value);
	}


	//Problem[30] : Count Letter.
	short CountChractorLetter(string St, char Char1)
	{
		short Count = 0;

		for (int i = 0; i < St.length(); i++)
		{
			if (Char1 == St[i])
			{
				Count++;
			}
		}
		return Count;
	}
	void CountChractorLetter(string St)
	{
		char Char1;

		cout << "Please Enter a Charater ?";
		cin >> Char1;

		cout << "\nLetter " << Char1 << " Count :" << CountChractorLetter(St, Char1);
	}
	void CountChractorLetter()
	{
		CountChractorLetter(_Value);
	}

	//Problem[31] : Count Caplital and SmallLetter.
	static short CounSpecificLetter(string St, char Letter, bool IsMacth = true)
	{
		short Count = 0;

		for (short i = 0; i < St.length(); i++)
		{
			if (IsMacth)
			{
				if (St[i] == Letter)
				{
					Count++;
				}
			}
			else
			{
				if (tolower(St[i]) == tolower(Letter))
				{
					Count++;
				}
			}
		}

		return Count;
	}
	void PrintCounSpecificLetter(string St)
	{
		char Letter;

		cout << "Please Enter a Charater ?";
		cin >> Letter;

		cout << "\nLetter \'" << Letter << "\' Count :" << CounSpecificLetter(St, Letter);
		cout << "\nLetter \'" << Letter << "\' or \'" << InvertLeterCase(Letter) << "\' Count :" << CounSpecificLetter(St, Letter, false);

	}
	void PrintCounSpecificLetter()
	{
		PrintCounSpecificLetter(_Value);
	}


	//Problem[32] : Vowel Letter.
	static bool IsVowel(char Ch)
	{
		Ch = tolower(Ch);
		return ((Ch == 'a') || (Ch == 'u') || (Ch == 'o') || (Ch == 'i') || (Ch == 'e'));
	}
	void VowelLetter()
	{
		char Letter;
		cout << "Please Enter a Charater ?";
		cin >> Letter;

		if (IsVowel(Letter))
		{
			cout << "Yes Letter \'" << Letter << "\' is a Vowel";
		}
		else
		{
			cout << "No Letter \'" << Letter << "\' is not a Vowel";
		}

	}


	//Problem[33] :Count Vowel Letter.
	static short CountVowels(string St)
	{
		int Count = 0;

		for (short i = 0;i < St.length();i++)
		{
			if (IsVowel(St[i]))
			{
				Count++;
			}
		}
		return Count;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}



	//Problem[34] :Print Vowel Letter in String.
	void PrintVowelLetterInString(string St)
	{
		for (short i = 0; i < St.length(); i++)
		{
			if (IsVowel(St[i]))
			{
				cout << St[i] << "  ";
			}
		}
	}
	void PrintVowelLetterInString()
	{
		PrintVowelLetterInString(_Value);
	}


	//Problem[35] :Print Each Word.
	static void PrintEachWordInString(string St)
	{
		short Pos = 0;
		string Delimet = " ";
		string sWord;

		while ((Pos = St.find(Delimet)) != std::string::npos)
		{
			sWord = St.substr(0, Pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			St.erase(0, Pos + Delimet.length());

		}

		if (St != "")
		{
			cout << St << endl;
		}
	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}


	//Problem[36] :Count Word In String.
	static short CountWordInString(string St)
	{
		short Pos = 0;
		string Delimet = " ";
		string sWord;
		short Count = 0;

		while ((Pos = St.find(Delimet)) != std::string::npos)
		{
			sWord = St.substr(0, Pos);
			if (sWord != "")
			{
				Count++;
			}
			St.erase(0, Pos + Delimet.length());

		}

		if (St != "")
		{
			Count++;
		}
		return Count;
	}
	short CountWordInString()
	{
		return CountWordInString(_Value);
	}


	//Problem[37] :Split String.
	static vector<string> Split(string St, string Delimt)
	{
		vector<string> vString;

		string sWord;
		short Pos;

		while ((Pos = St.find(Delimt)) != std::string::npos)
		{
			sWord = St.substr(0, Pos);

			// if (sWord != "")
		  // {
		        vString.push_back(sWord);
			//}

			St.erase(0, Pos + Delimt.length());
		}
		if (St != "")
		{
			vString.push_back(St);
		}
		return vString;
	}
	vector<string> Split(string Delimt)
	{
		return  Split(_Value, Delimt);
	}

	//Problem[38] :Trim Left and Trim Right.
	static string TrimLeft(string St)
	{
		for (short i = 0; i < St.length(); i++)
		{
			if (St[i] != ' ')
			{
				return St.substr(i, St.length() - i);
			}
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TriimRight(string St)
	{
		for (short i = St.length() - 1; i >= 0; i--)
		{
			if (St[i] != ' ')
			{
				return St.substr(0, i + 1);
			}
		}
		return "";
	}
	void TriimRight()
	{
		_Value = TriimRight(_Value);
	}

	static string Trim(string St)
	{
		return TrimLeft(TriimRight(St));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}


	//Problem[39] :Join String.
	static string JoinString(vector<string> vString, string Delimt)
	{
		string S1;

		for (string& S : vString)
		{
			S1 = S1 + S + Delimt;
		}
		return S1.substr(0, S1.length() - Delimt.length());
	}

	//Problem[40] :Join String OverLoding.
	static string JoinString(string arrString[], short Linght, string Delimt)
	{
		string S1 = "";

		for (short i = 0;i < Linght;i++)
		{
			S1 = S1 + arrString[i] + Delimt;
		}
		return S1.substr(0, S1.length() - Delimt.length());
	}


	//Problem[41] :Revers Words In String.
	string ReversWordsInString(string St)
	{
		vector<string> vString;
		string S2;

		vString = Split(St, " ");
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 = S2 + *iter + " ";
		}
		S2 = S2.substr(0, S2.length() - 1);

		return S2;
	}
	void ReversWordsInString()
	{
	  _Value = ReversWordsInString(_Value);
	}


	//Problem[42] :Replace Word In String Using Built In Function.
	static string ReplaceWordIndStringUsingBuiltInFunction(string St, string StringToReplace, string sReplaceTo)
	{
		short Pos = 0;
		Pos = St.find(StringToReplace);

		while (Pos != std::string::npos)
		{
			St = St.replace(Pos, StringToReplace.length(), sReplaceTo);

			Pos = St.find(StringToReplace);
		}
		return St;
	}
	void ReplaceWordIndStringUsingBuiltInFunction(string StringToReplace, string sReplaceTo)
	{
		_Value = ReplaceWordIndStringUsingBuiltInFunction(_Value, StringToReplace, sReplaceTo);
	}

	//Problem[43] :Replace Word In String Using Split.
	string ReplaceWord(string St, string StringToReplace, string sReplaceTo, bool IsMatchcase = true)
	{
		vector<string> vString = Split(St, " ");
		for (string& sWord : vString)
		{
			if (IsMatchcase)
			{
				if (sWord == StringToReplace)
				{
					sWord = sReplaceTo;
				}
			}
			else
			{
				if (LowerAllString(sWord) == LowerAllString(StringToReplace))
				{
					sWord = sReplaceTo;
				}
			}
		}
		return JoinString(vString, " ");
	}
	void ReplaceWord(string StringToReplace, string sReplaceTo, bool IsMatchcase = true)
	{
		_Value =  ReplaceWord(_Value, StringToReplace, sReplaceTo, IsMatchcase);
	}

	//Problem[44] :Remove All Punctuation In String.
	static string RemovePunctuation(string St)
	{
		string S1;

		for (short i = 0;i < St.length();i++)
		{
			if (!ispunct(St[i]))
			{
				S1 += St[i];
			}
		}
		return S1;
	}
	void RemovePunctuation()
	{
		_Value = RemovePunctuation(_Value);
	}


};

