#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;
class clsTransferLogScreen : protected clsScreen
{
private:
    static void _PrintTransferLogToRecordLien(clsBankClient::sTransferLog TransferLog)
    {
        cout << "| " << setw(20) << left << TransferLog.TimeDate;
        cout << "|" << left << setw(15) << TransferLog.SourceClient;
        cout << "|" << left << setw(15) << TransferLog.DestinationClient;
        cout << "|" << left << setw(10) << TransferLog.Amount;
        cout << "|" << left << setw(18) << TransferLog.AmountSouce;
        cout << "|" << left << setw(18) << TransferLog.AmountDestination;
        cout << "|" << left << setw(12) << TransferLog.UserName <<"|";
    }     

public:
   static void ShowTranferLogScreen()
    {

        vector<clsBankClient::sTransferLog> vTranferLog = clsBankClient::GetTransferLogList();
        string Title = "\t Transfer Log List Screen";

        string SubTitle = "\t    (" + to_string(vTranferLog.size()) + ") Record(s).";

        _DrowScreenHeader(Title, SubTitle);


        cout  << "\n\n|_________________________________________________________________";
        cout << "___________________________________________________\n" << endl;

        cout << "| " << left << setw(20) << "Date/Time";
        cout << "|" << left << setw(15) << "S.AccountNumber";
        cout << "|" << left << setw(15) << "D.AccountNumber";
        cout << "|" << left << setw(10) << "Amount";
        cout << "|" << left << setw(18) << "S.AccountBalance";
        cout << "|" << left << setw(18) << "D.AccountBalance";
        cout << "|" << left << setw(12) << "UserName    |";

        cout << "\n|_________________________________________________________________";
        cout << "___________________________________________________\n" << endl;

        if (vTranferLog.size() == 0)
        {
            cout << "\n\nRegister Login Invalid In the";
        }

        for (clsBankClient::sTransferLog &Recort : vTranferLog)
        {
            _PrintTransferLogToRecordLien(Recort);
            cout << endl;
        }

       cout << "_________________________________________________________________";
        cout << "____________________________________________________\n" << endl;

    }

};                                          

