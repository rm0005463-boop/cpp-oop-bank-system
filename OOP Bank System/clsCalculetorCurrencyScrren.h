#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrensy.h"
#include"clsInputValidate.h"
#include"clsString.h"

using namespace std;
class clsCalculetorCurrencyScrren :protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrensy Currency , string Titel)
    {
        cout << "\n" <<Titel;
        cout << "\n___________________________________";
        cout << "\nCounrey   :" << Currency.Country();
        cout << "\nC.Code    :" << Currency.CurrenseyCode();
        cout << "\nC.Name    :" << Currency.CurrensyName();
        cout << "\nRate($) = :" << Currency.Rate();
        cout << "\n___________________________________\n\n";

    }

    static clsCurrensy _GetCurrency(string Masseg)
    {
        string  CurrencyCode;

        cout << Masseg;
        CurrencyCode = clsInputValidate <string> ::ReadString();

        while (!clsCurrensy::IsCurrencyExit(CurrencyCode))
        {
            cout << "\nCurrency is not found , choose anther one : ";
            CurrencyCode = clsInputValidate <string> ::ReadString();
        }

        clsCurrensy Currency1 = clsCurrensy::FindByCode(CurrencyCode);

        return Currency1;
    }

    static float _ReadAmount()
    {

        float Amount;
        cout << "\nEnter Amount To Exchang :";
        Amount = clsInputValidate <float> ::ReadfloatNumber();

        return Amount;
    }


    static void _PrintCalculationResult(float Amount , clsCurrensy Currency1 , clsCurrensy Currency2)
    {
      
        _PrintCurrencyCard(Currency1, "Convert From");

        float AmountToUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.CurrenseyCode()
            << "  = " << AmountToUSD << " " << "USD";

        if (clsString::UpperAllString(Currency2.CurrenseyCode()) == "USD")
        {
            return;
        }

        cout << "\n\nConverting From USD:\n";
        _PrintCurrencyCard(Currency2, "To");

        float AmountInCurrencyTo = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.CurrenseyCode()
            << "  = " << AmountInCurrencyTo << " " << Currency2.CurrenseyCode();

    }

public:

   static void ShowCalculetorCurrencyScreen()
    {
       char Answer = 'y';

       while (Answer == 'Y' || Answer == 'y')
       {
           system("cls");
           _DrowScreenHeader("\tCalculetor Currency Screen");

          
           clsCurrensy Currency1 = _GetCurrency("\nEnter Currency1 Carde :");
           clsCurrensy Currency2 = _GetCurrency("\nEnter Currency2 Carde :");
           float Amount = _ReadAmount();


           _PrintCalculationResult(Amount , Currency1 , Currency2);

           cout << "\n\ndo you want to perform anther calculation ? y/n ?";
           cin >> Answer;
       } 

    }

};

