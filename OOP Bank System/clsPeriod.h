#pragma once
#include<iostream>
#include"clsDate.h"

using namespace std;

class clsPeriod
{
public:
	clsDate StartDate;
	clsDate EndDate;

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}

	static bool IsOverlapPeriods(clsPeriod Period1 , clsPeriod Period2)
	{
		if (clsDate::CombertDate(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompert::Befor || clsDate::CombertDate(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompert::After)
			return false;
		else
		{
			return true;
		}
	}
	bool IsOverLapWith(clsPeriod Period)
	{
		return IsOverlapPeriods(*this, Period);
	}

	static short PeriodLengthInDays(clsPeriod Period, bool IncludeEndDate = false)
	{
		return clsDate::GetDiffranceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
	}
	short PeriodLengthInDays(bool IncludEndDay = false)
	{
		return  PeriodLengthInDays(*this, IncludEndDay);
	}

	static bool IsDateInPiroid(clsDate Date, clsPeriod Period)
	{
		return !(clsDate::CombertDate(Date, Period.StartDate) == clsDate::enDateCompert::Befor || clsDate::CombertDate(Date,Period.EndDate) == clsDate::enDateCompert::After);
	}

	static short CountOverlapDays(clsPeriod Period1,clsPeriod Period2)
	{
		short CountDays = 0;
		short Period1Lenght = PeriodLengthInDays(Period1 , true);
		short Period2Lenght = PeriodLengthInDays(Period2, true);

		if (!IsOverlapPeriods(Period1,Period2))
			return 0;


		if (Period1Lenght < Period2Lenght)
		{
			while (clsDate::IsDate1BeforDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateInPiroid(Period1.StartDate, Period2))
					CountDays++;

				Period1.StartDate = clsDate::AddOnDay(Period1.StartDate);
			}
		}
		else
		{
			while (clsDate::IsDate1BeforDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateInPiroid(Period2.StartDate, Period1))
					CountDays++;

				Period2.StartDate = clsDate::AddOnDay(Period2.StartDate);
			}
		}
		return CountDays;
	}
	short CountOverlapDays(clsPeriod Period)
	{
		return CountOverlapDays(*this, Period);
	}

	void Print()
	{
		cout << "Period Start:";
		StartDate.Print();

		cout << "Period End ";
		EndDate.Print();
	}

};

