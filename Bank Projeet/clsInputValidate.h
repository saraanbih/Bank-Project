#pragma once
#include <iostream>
#include "clsDate.h"
#include <string>
#include "clsString.h"

using namespace std;

class clsInputValidate
{
public:
	


	static bool IsNumberBetween(int Number,int From, int To)
	{
		return (Number >= From) && (Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From) && (Number <= To);
	}

	static bool IsNumberBetween(float Number, float Var1, float Var2)
	{
		return (Number >= Var1) && (Number <= Var2);
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		return (clsDate::IsDate1AfterDate2(Date, DateFrom) && clsDate::IsDate1BeforeDate2(Date, DateTo))
			|| (clsDate::IsDate1AfterDate2(Date, DateTo) && clsDate::IsDate1BeforeDate2(Date, DateFrom))
			|| (clsDate::IsDate1EqualDate2(Date, DateFrom)) || (clsDate::IsDate1EqualDate2(Date, DateTo));
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{

		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{

		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};


