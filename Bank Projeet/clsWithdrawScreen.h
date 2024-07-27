#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen 
{
private:
	static void _PrintClient(clsBankClient& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPinCode    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}

public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t   Withdraw Screen");

		cout << "\nPlease Enter Account Number? ";
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] is not found, Choose another one: ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		double Amount;
		cout << "\nPlease enter withdarw amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer;
		cout << "\nAre you sure you want to do this transaction? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			if(Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdrawed Successfully.\n";
				cout << "\nNewBalance Is: " << Client.AccountBalance;
			}
			else
			{
				cout << "\nCannot Withdraw, Insuffecient Balance? ";
				cout << "\nAmount To Withdraw is: " << Amount << endl;
				cout << "Your Balance is: " << Client.AccountBalance << endl;
			}

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}

};

