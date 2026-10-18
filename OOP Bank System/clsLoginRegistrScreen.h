#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"Global.h"
#include"clsDate.h"
#include"clsUser.h"
#include"clsString.h"

using namespace std;
class clsLoginRegistrScreen : protected clsScreen 
{
private:

    static void PrintLoginRegisterRecordLien(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
        cout << setw(20) << left << "" << "| " << setw(20) << left << LoginRegisterRecord.Time;
        cout << "|" << left << setw(15) << LoginRegisterRecord.UserName;
        cout << "|" << left << setw(10) << LoginRegisterRecord.PassWord;
        cout << "|" << left << setw(12) << LoginRegisterRecord.Permission << "|";
    }

public:
    static void ShowLoginRegisterListScreen()
    {

        if (!CheckAccessRight(clsUser::enPermission::pShowLoginInRegister))
        {
            return;
        }


        vector<clsUser::stLoginRegisterRecord>vLoginRegister = clsUser::GetLoginRegiserList();
        string Title = "\t Login Register List Screen";

        string SubTitle = "\t    (" + to_string(vLoginRegister.size()) + ") Record(s).";

        _DrowScreenHeader(Title, SubTitle);


        cout << setw(20) << left << "" << "\n\n\t\t    _______________________";
        cout << "________________________________________\n" << endl;

        cout << setw(20) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "|" << left << setw(15) << "UserName";
        cout << "|" << left << setw(10) << "PassWord";
        cout << "|" << left << setw(12) << "Permission  |";


        cout << setw(20) << left << "" << "\n\t\t    _______________________";
        cout << "________________________________________\n" << endl;

        if (vLoginRegister.size() == 0)
        {
            cout << "\n\nRegister Login Invalid In the";
        }

        for (clsUser::stLoginRegisterRecord &Record: vLoginRegister)
        {
            PrintLoginRegisterRecordLien(Record);

            cout << endl;
        }

        cout << setw(20) << left << "" << "_______________________";
        cout << "________________________________________\n" << endl;

    }


};

