#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

#include <iomanip>

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOptions
	{
		eDposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6
	};

	static short _ReadTransactionsMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _ShowDepositScreen()
	{
		//cout << "\n Show Deposit Screen Will Be Here ";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\n Show Withdraw Screen Will Be Here ";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "\n Show TotalBalance Screen Will Be Here ";
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackToTansactionsMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";

		system("pause > 0");
		ShowTansactionsMenue();
	}

	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case clsTransactionsScreen::eDposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTansactionsMenue();
			break;
			system("cls");
		}
		case clsTransactionsScreen::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTansactionsMenue();
			break;
		}
		case clsTransactionsScreen::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTansactionsMenue();
			break;
		}
		case clsTransactionsScreen::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTansactionsMenue();
			break;
		}
		case clsTransactionsScreen::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTansactionsMenue();
			break;
		}
		case clsTransactionsScreen::eShowMainMenue:
		{
			// do nothing here
		}
		}
	}


public:
	static void ShowTansactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMainMenueOption());
	}

};

