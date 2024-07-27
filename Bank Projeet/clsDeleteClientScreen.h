#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;


class clsDeleteClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
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

public:
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("\t Delete Client Screen");

		    string AccountNumber;
		
		    cout << "\nplease Enter Account Number: ";
		    AccountNumber = clsInputValidate::ReadString();
		
		    while (!(clsBankClient::IsClientExist(AccountNumber)))
		    {
		        cout << "\nAccountNumber is not found, Choose another one: ";
		        AccountNumber = clsInputValidate::ReadString();
		    }
		
		    clsBankClient DeleteClient = clsBankClient::Find(AccountNumber);
			_PrintClient(DeleteClient);
		
		    char Answer;
		    cout << "\nAre you sure you want to delete this client y/n? ";
		    cin >> Answer;
		
		    if (tolower(Answer) == 'y')
		    {
		        if (DeleteClient.Delete())
		        {
		            cout << "\nClient Deleted Successfully :-)\n";
		
					_PrintClient(DeleteClient);
		        }
		        else
		        {
		            cout << "\nError Client Was not Deleted\n";
		        }
		    }
		
	}


};

