#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrencyListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCalculetorCurrencyScrren.h"

using namespace std;

class clsCurrencyMainScreen : protected clsScreen
{
private:
  enum enCurrencyMenuoOption{eListCurrency = 1 , eFindCurrency = 2 , eUpdateRate = 3 , eCalculateCurrency = 4 , eMainMenuo = 5};
  
  static void _GoBakeToCurrencyMenuo()
  {
	  cout << setw(37) << left << "" << "\nPrasue Any Key To Bake Currency Menuo....";
	  system("pause > 0");

	  ShowCurrencyMainScreen();
  }

  static void _ShowCurrencyListScrren()
  {
	  //cout << "\nCurrency List Will Be Hear";
	  clsCurrencyListScreen::ShowCurrencyList();
  }

  static void _FindCurrencyScrren()
  {
	  //cout << "\nFind Currency Will Be Hear";
	  clsFindCurrencyScreen::FindCurrenyScrren();
  }
  
  static void _UpdateCurrencyScrren()
  {
	 //cout << "\nUpdate Curreny Will Be Hear";
	  clsUpdateCurrencyScreen::ShowUpdateCurrencyScrren();
  }

  static void _CalculetCurrencyScreen()
  {
	 //cout << "\nCalculet Currency Will Be Hear";
	  clsCalculetorCurrencyScrren::ShowCalculetorCurrencyScreen();
  }

  static short _ReadCurrencyMenuoOption()
  {
	  short Choose;
	  cout << setw(37) << left << "" << "Choose what do you want to do ? [1 To 5] ?";
	  Choose = clsInputValidate <int> ::ReadNumberBetween(1, 5);
	  return Choose;
  }

  static void _PerformCurrencyMenuoOption(enCurrencyMenuoOption CurrencyMenuoOptin)
  {
	  switch (CurrencyMenuoOptin)
	  {
	  case enCurrencyMenuoOption::eListCurrency:
	  {
		  system("cls");
		  _ShowCurrencyListScrren();
		  _GoBakeToCurrencyMenuo();
		  break;
	  }

	  case enCurrencyMenuoOption::eFindCurrency:
	  {
		  system("cls");
		  _FindCurrencyScrren();
		  _GoBakeToCurrencyMenuo();
		  break;
	  }

	  case enCurrencyMenuoOption::eUpdateRate:
	  {
		  system("cls");
		  _UpdateCurrencyScrren();
		  _GoBakeToCurrencyMenuo();
		  break;
	  }

	  case enCurrencyMenuoOption::eCalculateCurrency:
	  {
		  system("cls");
		  _CalculetCurrencyScreen();
		  _GoBakeToCurrencyMenuo();
		  break;
	  }

	  case enCurrencyMenuoOption::eMainMenuo:
	  {
		  //cout << "\nMain Menuo Will be hear";
	  }

	  }
  }

public:
  static void ShowCurrencyMainScreen()
  {
	  system("cls");
	  _DrowScreenHeader("\t  Main Screen\n");


	  cout << "\n\t\t\t\t    =============================================\n";
	  cout << "\n\t\t\t\t\t  Currency Exchange Main Scrren\n";
	  cout << "\n\t\t\t\t    =============================================\n";
	  cout << setw(37) << left << "" << "\t[1] List Currency.\n";
	  cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
	  cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
	  cout << setw(37) << left << "" << "\t[4] Currency Calcoletor.\n";
	  cout << setw(37) << left << "" << "\t[5] Main Menuo.\n";
	  cout << "\n\t\t\t\t   =============================================\n";

	  _PerformCurrencyMenuoOption((enCurrencyMenuoOption)_ReadCurrencyMenuoOption());
  }
};

