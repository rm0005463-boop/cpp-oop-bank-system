#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsScreen.h"
#include"clsCurrensy.h"

using namespace std;
class clsCurrencyListScreen : protected clsScreen
{
private:
    static void _PrintCurrencyRecordLien(clsCurrensy Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "|" << left << setw(15) << Currency.CurrenseyCode();
        cout << "|" << left << setw(40) << Currency.CurrensyName();
        cout << "|" << left << setw(8) << Currency.Rate() << "|";
    }

public:

    static void ShowCurrencyList()
    {
        vector<clsCurrensy>vCurrency = clsCurrensy::GetCurrenciesList();
        string Title = "\tCurrency List Screen";

        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency(s).";

        _DrowScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\n\t________________________________________________";
        cout << "___________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "|" << left << setw(15) << "Curreny Code";
        cout << "|" << left << setw(40) << "Currency Name";
        cout << "|" << left << setw(8) << "Rate($) |";

        cout << setw(8) << left << "" << "\n\t______________________________________________";
        cout << "_____________________________________________________\n" << endl;


        if (vCurrency.size() == 0)
        {
            cout << "\n\nNo Currencies Invalid In the system";
        }

        for (clsCurrensy & Currency : vCurrency)
        {
            _PrintCurrencyRecordLien(Currency);
            cout << endl;
        }

        cout << setw(8) << left << "" << "_______________________________________________________";
        cout << "____________________________________________\n" << endl;

    }
};

