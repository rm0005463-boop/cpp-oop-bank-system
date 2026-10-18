#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUtil.h"

using namespace std;

class clsTotalBalancesScreen :protected clsScreen
{

private:
  static void _PrintClientRecordBalanceLien(clsBankClient Client)
  {
    cout << setw(20) << left << "" << "|" << left << setw(15) << Client.AccountNumber();
    cout << "|" << left << setw(20) << Client.FullName();
    cout << "|" << left << setw(12) << Client.Accountbalance << "     |";
  }

public:
static void ShowTotalBalanceScreen()
{
   
    vector<clsBankClient>vClient = clsBankClient::GetClientList();

    string Title = "\tBalance List Screen";
    string SubTitle = "\t    (" + to_string(vClient.size()) + ") Client(s).";


    _DrowScreenHeader(Title, SubTitle);


    cout << setw(20) << left << "" << "\n\n\t\t    |___________________________";
    cout << "___________________________|\n";

    cout << setw(20) << left << "" << "|" << left << setw(15) << "AccountNumber";
    cout << "|" << left << setw(20) << "Client Name";
    cout << "|" << left << setw(12) << "Acountbalnce     |";

    cout << setw(20) << left << "" << "\n\t\t    |____________________________";
    cout << "__________________________|\n" ;

    if (vClient.size() == 0)
    {
        cout << "\n\nClient Invalid In the";
    }

    double TotalBalances= clsBankClient::GetTotalBalances();

    for (clsBankClient& C : vClient)
    {
        _PrintClientRecordBalanceLien(C);
        cout << endl;
    }

    cout << setw(20) << left << "" << "|_____________________________";
    cout << "_________________________|\n";

    cout << "\nTotal Balance :" << TotalBalances;
    cout << "\n Number to tixt :(" << clsUtil::NumberToText(TotalBalances) <<")";
}


};

