#pragma once
#pragma warning (disable : 4996)

#include<iostream>
#include<string>
#include"clsString.h"


using namespace std;
class clsDate
{
private:
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;


public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
		
	}
	clsDate(string Date)
	{
		vector<string> vString = clsString::Split(Date, "/");

		_Day = stoi(vString[0]);
		_Month = stoi(vString[1]);
		_Year = stoi(vString[2]);

	}
	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(short DateOrderInYear, short Year)
	{

		short MonthDays = 0;
		short ReminigDate = DateOrderInYear;

		_Year = Year;
		_Month = 1;

		while (true)
		{
			MonthDays = NumberOfDayInMonth(_Month, _Year);

			if (ReminigDate > MonthDays)
			{
				ReminigDate -= MonthDays;
				_Month++;
			}
			else
			{
				_Day = ReminigDate;
				break;
			}
		}

	}

	void SetDay(int Day)
	{
		_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay))short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth))short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear))short Year;

	void Print()
	{
		cout << DateToString() << endl;
	}

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return (clsDate(Day, Month, Year));
	}

	static bool IsLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDayInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDayInAYear()
	{
		return NumberOfDayInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDayInAYear(Year) * 24;
	}
	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	static short NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	short  NumberOfMinutesInAYear()
	{
		return  NumberOfMinutesInAYear(_Year);
	}

	static short NumberOfSecondInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}
	short  NumberOfSecondInAYear()
	{
		return  NumberOfSecondInAYear(_Year);
	}

	static short NumberOfDayInMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
		{
			return 0;
		}

		int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return ((Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1]);
	}
	short NumberOfDayInMonth()
	{
		return NumberOfDayInMonth(_Month, _Year);
	}

	static short NumberOfHoursInAMonth(short Month, short Year)
	{
		return NumberOfDayInMonth(Month, Year) * 24;
	}
	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Month, _Year);
	}

	static short NumberOfMinutesInAMonth(short Month, short Year)
	{
		return NumberOfHoursInAMonth(Month, Year) * 60;
	}
	short NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Month, _Year);
	}

	static short NumberOfSecondInAMonth(short Month, short Year)
	{
		return NumberOfMinutesInAMonth(Month, Year) * 60;
	}
	short NumberOfSecondInAMonth()
	{
		return  NumberOfSecondInAMonth(_Month, _Year);
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	static string DayshortName(short DayOfWeekOrder)
	{
		string arrDayName[] = { "sun","Mon","Tus","Wed","Thr","Fri","Sat" };

		return arrDayName[DayOfWeekOrder];
	}

	static string DayshortName(short Day, short Month, short Year)
	{
		string arrDayName[] = { "sun","Mon","Tus","Wed","Thr","Fri","Sat" };

		return arrDayName[DayOfWeekOrder(Day, Month, Year)];
	}
	string DayshortName()
	{
		string arrDayName[] = { "sun","Mon","Tus","Wed","Thr","Fri","Sat" };

		return arrDayName[DayOfWeekOrder(_Day, _Month, _Year)];
	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan","Feb","Mar","Apr","May",
							  "Jun","Jul","Aug","Seb","Oct",
								"Nov","Des" };

		return (Months[MonthNumber - 1]);
	}
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCliender(short Month, short Year)
	{
		int NumberOfDay;
		int current = DayOfWeekOrder(1, Month, Year);
		NumberOfDay = NumberOfDayInMonth(Month, Year);

		printf("\n___________________%s____________________\n\n", MonthShortName(Month).c_str());

		printf("  Sun  Mon  Tus  Wed  Thr  Fri  Sat\n");

		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDay; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n_________________________________________\n");
	}
	void PrintMonthCliender()
	{
		PrintMonthCliender(_Month, _Year);
	}

	static void PrintYearCliender(short Month, short Year)
	{
		printf("\n__________________________________________\n\n");
		printf("            Calender - %d\n", Year);
		printf("__________________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCliender(i, Year);
		}
	}
	void PrintYearCliender()
	{
		PrintYearCliender(_Month, _Year);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._Day == NumberOfDayInMonth(Date._Month, Date._Year));
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	static clsDate AddOnDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Year++;
				Date._Month = 1;
				Date._Day = 1;
			}
			else
			{
				Date._Month++;
				Date._Day = 1;
			}
		}
		else
		{
			Date._Day++;
		}
		return Date;
	}
	void AddOneDay()
	{
		*this = AddOnDay(*this);
	}

	static bool IsDate1BeforDate2(clsDate Date1, clsDate Date2)
	{
		return ((Date1._Year < Date2._Year) ? true : (Date1._Year == Date2._Year) ? ((Date1._Month < Date2._Month) ? true : (Date1._Month == Date2._Month) ? ((Date1._Day < Date2._Day) ? true : false) : false) : false);
	}
	bool IsDateBeforDate2(clsDate Date)
	{
		return IsDate1BeforDate2(*this, Date);
	}

	static short DaysFromTheBeggingOfTheYear(short Day, short Month, short Year)
	{
		int TotalDays = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDayInMonth(i, Year);
		}

		TotalDays += Day;

		return TotalDays;
	}
	short DaysFromTheBeggingOfTheYear()
	{
		return DaysFromTheBeggingOfTheYear(_Day, _Month, _Year);
	}

	static clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
	{
		clsDate Date;

		short MonthDays = 0;
		short ReminigDate = DayOrderInYear;

		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDayInMonth(Date.Month, Year);

			if (ReminigDate > MonthDays)
			{
				ReminigDate -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = ReminigDate;
				break;
			}
		}
		return Date;
	}

	void AddDays(short Days)
	{
		short ReminingDays = Days + DaysFromTheBeggingOfTheYear(_Day, _Month, _Year);
		short MonthDays = 0;

		_Month = 1;

		while (true)
		{
			MonthDays = NumberOfDayInMonth(_Month, _Year);
			if (ReminingDays > MonthDays)
			{
				ReminingDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;
				}
			}
			else
			{
				_Day = ReminingDays;
				break;
			}
		}
	}

	static bool IsDate1EqualDat2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}
	bool IsDateEqualDat2(clsDate Date)
	{
		return IsDate1EqualDat2(*this, Date);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate._Day = Date1._Day;
		TempDate._Month = Date1._Month;
		TempDate._Year = Date1._Year;

		Date1._Day = Date2._Day;
		Date1._Month = Date2._Month;
		Date1._Year = Date2._Year;

		Date2._Day = TempDate._Day;
		Date2._Month = TempDate._Month;
		Date2._Year = TempDate._Year;
	}

	static int GetDiffranceInDays(clsDate Date1, clsDate Date2, bool IncloudEndDay = false)
	{
		int Days = 0;
		int FlagSwapValu = 1;

		if (!IsDate1BeforDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			FlagSwapValu = -1;
		}


		while (IsDate1BeforDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOnDay(Date1);
		}
		return IncloudEndDay ? ++Days * FlagSwapValu : Days * FlagSwapValu;
	}
	int GetDiffranceInDays(clsDate Date, bool IncloudEndDay = false)
	{
		return GetDiffranceInDays(*this, Date, IncloudEndDay);
	}

	static short CalculateMyAge(clsDate DateBirth)
	{
		return GetDiffranceInDays(DateBirth, clsDate::GetSystemDate(), true);
	}

	static clsDate IncreasDateByOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = AddOnDay(Date);
		}
		return Date;
	}
	void IncreasDateByOneWeek()
	{
		IncreasDateByOneWeek(*this);
	}

	static clsDate IncreasDateByXWeek(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreasDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreasDateByXWeek(short Weeks)
	{
		IncreasDateByXWeek(Weeks, *this);
	}

	static clsDate IncreasDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 12)
		{
			Date.Year++;
			Date.Month = 1;
		}
		else
		{
			Date.Month++;
		}

		short NumberOfDayInCurrntMonth = NumberOfDayInMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDayInCurrntMonth)
		{
			Date.Day = NumberOfDayInCurrntMonth;
		}
		return Date;
	}
	void IncreasDateByOneMonth()
	{
		IncreasDateByOneMonth(*this);
	}

	static clsDate IncreasDateByXMonth(short Month, clsDate& Date)
	{
		for (short i = 1; i <= Month; i++)
		{
			Date = IncreasDateByOneMonth(Date);
		}
		return Date;
	}
	void IncreasDateByXMonth(short Month)
	{
		IncreasDateByXMonth(Month, *this);
	}

	static clsDate IncreasDateByOneYear(clsDate& Date)
	{
		Date.Year++;
		return Date;
	}
	void IncreasDateByOneYear()
	{
		IncreasDateByOneYear(*this);
	}

	static clsDate IncreasDateByXYear(short Year, clsDate& Date)
	{
		Date.Year += Year;
		return Date;
	}
	void IncreasDateByXYear(short Year)
	{
		IncreasDateByXYear(Year, *this);
	}

	static clsDate IncreasDateByOneDecate(clsDate &Date)
	{
		Date.Year += 10;
		return Date;
	}
	void IncreasDateByOneDecate()
	{
		IncreasDateByOneDecate(*this);
	}

	static clsDate IncreasDateByXDecate(short Decate , clsDate& Date)
	{
		Date.Year += Decate * 10;
		return Date;
	}
	void IncreasDateByXDecate(short Decate)
	{
		IncreasDateByXDecate(Decate , *this);
	}

	static clsDate IncreasDateByOneCentury(clsDate& Date)
	{
		Date.Year += 100;
		return Date;
	}
	void IncreasDateByOneCentury()
	{
		IncreasDateByOneCentury(*this);
	}

	static clsDate IncreasDateByOneMellenium(clsDate& Date)
	{
		Date.Year += 1000;
		return Date;
	}
	void IncreasDateByOneMellenium()
	{
		IncreasDateByOneMellenium(*this);
	}

	static clsDate DecreaseDateByOneDate(clsDate Date)
	{

		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Day = 31;
				Date._Month = 12;
				Date._Year--;
			}
			else
			{
				Date._Day = NumberOfDayInMonth(Date._Month, Date._Year);
				Date._Month--;
			}
		}
		else
		{
			Date._Day--;
		}
		return Date;
	}
	void DecreaseDateByOneDate()
	{
		DecreaseDateByOneDate(*this);
	}

	static clsDate DecreasDateByOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDate(Date);
		}
		return Date;
	}
	void DecreasDateByOneWeek()
	{
		DecreasDateByOneWeek(*this);
	}

	static clsDate DecreasDateByXWeek(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreasDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreasDateByXWeek(short Weeks)
	{
		DecreasDateByXWeek(Weeks, *this);
	}

	static clsDate DecreasDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 1)
		{
			Date.Year--;
			Date.Month = 12;
		}
		else
		{
			Date.Month--;
		}

		short NumberOfDayInCurrntMonth = NumberOfDayInMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDayInCurrntMonth)
		{
			Date.Day = NumberOfDayInCurrntMonth;
		}
		return Date;
	}
	void DecreasDateByOneMonth()
	{
		DecreasDateByOneMonth(*this);
	}

	static clsDate DecreasDateByXMonth(short Month, clsDate& Date)
	{
		for (short i = 1; i <= Month; i++)
		{
			Date = DecreasDateByOneMonth(Date);
		}
		return Date;
	}
	void DecreasDateByXMonth(short Month)
	{
		DecreasDateByXMonth(Month, *this);
	}

	static clsDate DecreasDateByOneYear(clsDate& Date)
	{
		Date.Year--;
		return Date;
	}
	void DecreasDateByOneYear()
	{
		DecreasDateByOneYear(*this);
	}

	static clsDate DecreasDateByXYear(short Year, clsDate& Date)
	{
		Date.Year -= Year;
		return Date;
	}
	void DecreasDateByXYear(short Year)
	{
		DecreasDateByXYear(Year, *this);
	}

	static clsDate DecreasDateByOneDecate(clsDate& Date)
	{
		Date.Year -= 10;
		return Date;
	}
	void DecreasDateByOneDecate()
	{
		DecreasDateByOneDecate(*this);
	}

	static clsDate DecreasDateByXDecate(short Decate, clsDate& Date)
	{
		Date.Year -= Decate * 10;
		return Date;
	}
	void DecreasDateByXDecate(short Decate)
	{
		DecreasDateByXDecate(Decate, *this);
	}

	static clsDate DecreasDateByOneCentury(clsDate& Date)
	{
		Date.Year -= 100;
		return Date;
	}
	void DecreasDateByOneCentury()
	{
		DecreasDateByOneCentury(*this);
	}

	static clsDate DecreasDateByOneMellenium(clsDate& Date)
	{
		Date.Year -= 1000;
		return Date;
	}
	void DecreasDateByOneMellenium()
	{
		DecreasDateByOneMellenium(*this);
	}

	static short DayOfWeekOrder(clsDate Date)
	{
		return DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return (DayOfWeekOrder(Date) == 6);
	}
	bool IsEndOfWeek()
	{
		return  IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		return (DayOfWeekOrder(Date) == 6 || (DayOfWeekOrder(Date) == 5));
	}
	bool IsWeekEnd()
	{
		return  IsWeekEnd(*this);
	}

	static bool IsBusnessDay(clsDate Date)
	{
		return (!IsWeekEnd(Date));
	}
	bool IsBusnessDay()
	{
		return  IsBusnessDay(*this);
	}

	static short DayUntilEndOfWeek(clsDate Date)
	{
		return (6 - DayOfWeekOrder(Date));
	}
	short DayUntilEndOfWeek()
	{
		return DayUntilEndOfWeek(*this);
	}

	static short DaysUntilEndOfMonth(clsDate Date)
	{
		clsDate EndOfMonth;
		EndOfMonth._Day = NumberOfDayInMonth(Date._Month, Date._Year);
		EndOfMonth._Month = Date._Month;
		EndOfMonth._Year = Date._Year;

		return (GetDiffranceInDays(Date, EndOfMonth, true));
	}
	short DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(*this);
	}

	static short DaysUntilEndOfYear(clsDate Date)	{
		clsDate EndOfYear;
		EndOfYear._Day = 31;
		EndOfYear._Month = 12;
		EndOfYear._Year = Date._Year;

		return (GetDiffranceInDays(Date, EndOfYear, true));
	}
	short DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}

	static short CalculateBusnessDay(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;


		while (IsDate1BeforDate2(DateFrom, DateTo))
		{
			if (IsBusnessDay(DateFrom))
			{
				DaysCount++;
			}
			DateFrom = AddOnDay(DateFrom);
		}

		return DaysCount;
	}

	static int CalculateVactionDay(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusnessDay(DateFrom, DateTo);
	}

	static clsDate CalculateVacationReturnDate(short VacationDays, clsDate DateFrom)
	{
		short WeekEndCount = 0;

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = AddOnDay(DateFrom);
		}


		for (short i = 1; i <= VacationDays + WeekEndCount; i++)
		{
			if (IsWeekEnd(DateFrom))
				WeekEndCount++;

			DateFrom = AddOnDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = AddOnDay(DateFrom);
		}

		return DateFrom;
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualDat2(Date1, Date2));
	}
	bool IsDateAfterDate2(clsDate Date)
	{
		return IsDate1AfterDate2(*this, Date);
	}

	enum enDateCompert { Befor = -1, Equal = 0, After = 1 };

	static enDateCompert CombertDate(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforDate2(Date1, Date2))
			return enDateCompert::Befor;

		if (IsDate1EqualDat2(Date1, Date2))
			return enDateCompert::Equal;

		return enDateCompert::After;
	}

	static bool IsValiedDate(clsDate Date)
	{
		short NumberOfDays = NumberOfDayInMonth(Date._Month, Date._Year);

		if (Date._Month < 1 || Date._Month > 12)
			return false;

		if (Date._Day < 1 || Date._Day > NumberOfDays)
			return false;

		return true;
	}
	bool IsValid()
	{
		return IsValiedDate(*this);
	}

	static clsDate StringToDate(string StDate)
	{
		clsDate Date;

		vector<string> vString = clsString::Split(StDate, "/");

		Date._Day = stoi(vString[0]);
		Date._Month = stoi(vString[1]);
		Date._Year = stoi(vString[2]);

		return Date;
	}

	static string DateToString(clsDate Date, string Delimet = "/")
	{
		string ToString;

		ToString += to_string(Date.Day) + Delimet;
		ToString += to_string(Date.Month) + Delimet;
		ToString += to_string(Date.Year);

		return ToString;
	}
	string DateToString()
	{
		return DateToString(*this);
	}

	static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormatToDateString = "";
		FormatToDateString = clsString::ReplaceWordIndStringUsingBuiltInFunction(DateFormat, "dd", to_string(Date._Day));
		FormatToDateString = clsString::ReplaceWordIndStringUsingBuiltInFunction(FormatToDateString, "mm", to_string(Date._Month));
		FormatToDateString = clsString::ReplaceWordIndStringUsingBuiltInFunction(FormatToDateString, "yyyy", to_string(Date._Year));

		return FormatToDateString;
	}

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Min, Sec;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		Hour = now->tm_hour;
		Min = now->tm_min;
		Sec = now->tm_sec;

		return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) +
			" _ " + to_string(Hour) + ":" + to_string(Min) + ":" + to_string(Sec);
	}

};

