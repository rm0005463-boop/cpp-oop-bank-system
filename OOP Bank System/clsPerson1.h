#pragma once
#include<iostream>

using namespace std;

class clsPerson1
{
private:
	string _FirstName;
	string _LastName;
	string _Emial;
	string _Phone;

public:

	clsPerson1(string FirsName, string LastName , string Emial , string Phone)
	{
		_FirstName = FirsName;
		_LastName = LastName;
		_Emial = Emial;
		_Phone = Phone;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName))string LastName;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void SetEmial(string Emial)
	{
		_Emial = Emial;
	}
	string GetEmial()
	{
		return _Emial;
	}
	__declspec(property(get = GetEmial, put = SetEmial)) string Emial;


	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

};

