#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;

public:
	Date()
	{
		month = 0;
		day = 0;
		year = 0;
	}

	string altMonth()
	{
		if (month == 1)
			return "January";
		else if (month == 2)
			return "February";
		else if (month == 3)
			return "March";
		else if (month == 4)
			return "April";
		else if (month == 5)
			return "May";
		else if (month == 6)
			return "June";
		else if (month == 7)
			return "July";
		else if (month == 8)
			return "August";
		else if (month == 9)
			return "September";
		else if (month == 10)
			return "October";
		else if (month == 11)
			return "November";
		else if (month == 12)
			return "December";
	}

	void print1()
	{
		cout << month << "/" << day << "/" << year;
	}

	void print2()
	{
		cout << altMonth() << " " << day << ", " << year;
	}

	void print3()
	{
		cout << day << " " << altMonth() << " " << year;
	}

	Date Date::operator++()
	{
		day++;
		if (day > 30)
		{
			month++;
			day = 1;
		}
		if (month == 30)
		{
			month = 1;
			year++;
		}
	}

	Date Date::operator--()
	{
		day--;
		if (day == 0)
		{
			day = 30;
			month--;
		}
		if (month == 0)
		{
			month = 12;
			year--;
		}
	}

	Date operator-(const Date date1)
	{
		return (date1.month - month) * 30 + (date1.day - day) + (date1.year - year) * 365;
	}

	ostream &operator<<(ostream &strm, const Date &date)
	{
		strm << date.print2();
		return strm;
	}

	istream &operator>>(istream $strm, Date &date)
	{
		bool error = true;
		int check;
		cout << "Month: ";
		strm >> check;
		if (check > 0 || check < 13)
			date.month = check;
		cout << "Day: ";
		strm >> check;
		if (check > 0 || check < 32)
			date.day = check;
		cout << "Year: ";
		strm >> date.year;
		return strm;
	}

	int main()
	{
		Date calendar();
		Date NewYears();
		cin >> calendar;
		cin >> NewYears;
		cout << calendar;
		calendar++;
		cout << calendar;
		NewYears--;
		cout << NewYears;
		cout << (calendar-NewYears);

		return 0;
	}
}