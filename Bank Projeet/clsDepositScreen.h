#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsDepositScreen : protected clsScreen
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
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t   Deposit Screen");

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
		cout << "\nPlease enter deposit amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer;
		cout << "\nAre you sure you want to do this transaction? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Client.Deposit(Amount);

			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNewBalance Is: " << Client.AccountBalance;

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}

};

