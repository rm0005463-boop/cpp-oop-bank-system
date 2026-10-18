#pragma once
#include<iostream>
#include"clsCurrensy.h"
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"

using namespace std;
class clsFindCurrencyScreen :protected clsScreen
{
private:
 
    static void _PrintCurrencyRecordLien(clsCurrensy Currency)
    {
        cout << "\n\tCurrency Card :";
        cout << "\n___________________________________";
        cout << "\nCounrey   :" << Currency.Country();
        cout << "\nC.Code    :" << Currency.CurrenseyCode();
        cout << "\nC.Name    :" << Currency.CurrensyName();
        cout << "\nRate($) = :" << Currency.Rate();
        cout << "\n___________________________________";

    }

    static void _ShowResult(clsCurrensy Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-(\n";
            _PrintCurrencyRecordLien(Currency);
        }
        else
        {
            cout << "\nCurrency was not Found :-)\n";
        }
    }

public:
    static void FindCurrenyScrren()
    {
        _DrowScreenHeader("\tFind Curreny Screen");

        short Answer;
        cout << "\n\nFind By : [1] Code or [2] Country ?";
        cin >> Answer;

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nEnter Currency Code ?";
            CurrencyCode = clsInputValidate <string> ::ReadString();
            clsCurrensy Currency = clsCurrensy::FindByCode(CurrencyCode);
            _ShowResult(Currency);
        }
        else
        {
            string Country;
            cout << "\nEnter Country ?";
            Country = clsInputValidate <string> ::ReadString();
            clsCurrensy Currency = clsCurrensy::FindByCountry(Country);
            _ShowResult(Currency);
        }
        
    }
};

