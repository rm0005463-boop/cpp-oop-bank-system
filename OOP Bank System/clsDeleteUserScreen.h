#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace  std;

class clsDeleteUserScreen : protected clsScreen
{
private:
    static void _PrintUsre(clsUser User)
    {
        cout << "\n\tUser Card";
        cout << "\n_____________________________";
        cout << "\nFirst Name    :" << User.FirstName;
        cout << "\nLast Name     :" << User.LastName;
        cout << "\nFull Name     :" << User.FullName();
        cout << "\nEmial         :" << User.Emial;
        cout << "\nPhone         :" << User.Phone;
        cout << "\nUserName      :" << User.UserName;
        cout << "\nPasssWord     :" << User.PassWord;
        cout << "\nPermission    :" << User.Permission;
        cout << "\n_____________________________";
    }

public:

    static void ShowDeleteClientScreen()
    {
        string UserName;

        _DrowScreenHeader("\t Delete User Screen");

        cout << "\nPleas Enter UserName :";
        UserName = clsInputValidate <string> ::ReadString();

        while (!clsUser::IsUserExit(UserName))
        {
            cout << "\nUserName is not fount , choose agin :";
            UserName = clsInputValidate <string> ::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUsre(User);

        char Answer = 'n';

        cout << "\n\nAre you sure you want to Delet this User y/n :";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted successly:-)";
                _PrintUsre(User);
            }
            else
            {
                cout << "\nErorr User was not deleted \n";
            }
        }
    }

};

