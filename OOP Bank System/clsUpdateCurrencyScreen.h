#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrensy.h"
#include"clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyScreen :protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrensy Currency)
    {
        cout << "\n\tCurrency Card :";
        cout << "\n___________________________________";
        cout << "\nCounrey   :" << Currency.Country();
        cout << "\nC.Code    :" << Currency.CurrenseyCode();
        cout << "\nC.Name    :" << Currency.CurrensyName();
        cout << "\nRate($) = :" << Currency.Rate();
        cout << "\n___________________________________";

    }

    static float _ReadNewRate()
    {
        float NewRate;
      
        cout << "\nEnter New Rate : ";
        NewRate = clsInputValidate <float> ::ReadfloatNumber();

        return NewRate;
    }

public:
    static void ShowUpdateCurrencyScrren()
    {
        _DrowScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode;
        cout << "\n\nPlease Enter Currency Code ? ";
        CurrencyCode = clsInputValidate <string> ::ReadString();


        while (!clsCurrensy::IsCurrencyExit(CurrencyCode))
        {
            cout << "\nCurrency is not found , choose anther one : ";
            CurrencyCode = clsInputValidate <string> ::ReadString();
        }


        clsCurrensy Currency = clsCurrensy::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);


            char Answer = 'n';
            cout << "\n\nAre you sure you want to update rate this country ? y/n ?";
            cin >> Answer;

            if (Answer == 'Y' || Answer == 'y')
            {
               
                cout << "\n\nUpdate Currency Rate :";
                cout << "\n______________________________";
               
                Currency.UpdateRate(_ReadNewRate());

                cout << "\nCurrency Rate Update Successfuly :-(";
                _PrintCurrency(Currency);
            }
        
    }
};

