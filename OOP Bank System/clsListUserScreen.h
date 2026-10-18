#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;

class clsListUserScreen : protected clsScreen
{
private:
    static void PrintUserRecordLien(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
        cout << "|" << left << setw(20) << User.FullName();
        cout << "|" << left << setw(12) << User.Phone;
        cout << "|" << left << setw(20) << User.Emial;
        cout << "|" << left << setw(10) << User.PassWord;
        cout << "|" << left << setw(12) << User.Permission << "  |";
    }

public:

    static void ShowUsertList()
    {

        vector<clsUser>vUser = clsUser::GetUserList();
        string Title = "\t User List Screen";

        string SubTitle = "\t    (" + to_string(vUser.size()) + ") User(s).";

        _DrowScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\n\t_______________________________________________________";
        cout << "____________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
        cout << "|" << left << setw(20) << "Full Name";
        cout << "|" << left << setw(12) << "Phone";
        cout << "|" << left << setw(20) << "Emial";
        cout << "|" << left << setw(10) << "PassWord";
        cout << "|" << left << setw(12) << "Permission  |";

        cout << setw(8) << left << "" << "\n\t_________________________________________________________";
        cout << "__________________________________________\n" << endl;


        if (vUser.size() == 0)
        {
            cout << "\n\nClient Invalid In the";
        }

        for (clsUser& User : vUser)
        {
            PrintUserRecordLien(User);
            cout << endl;
        }

        cout << setw(8) << left << "" << "_______________________________________________________";
        cout << "____________________________________________\n" << endl;

    }

};
