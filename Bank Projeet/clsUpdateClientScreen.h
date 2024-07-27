#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter AccountBalance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

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
   static void ShowUpdateClientScreen()
    {
       if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
       {
           return;
       }

       _DrawScreenHeader("\t   Update Client Screen");

        string AccountNumber;

        cout << "\nPlease Enter Client AccountNumber : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!(clsBankClient::IsClientExist(AccountNumber)))
        {
            cout << "\nAccountNumber is not found, choose another one ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        char Answer;
        cout << "\nAre you sure you want to update this client y/n? ";
        cin >> Answer;

        if (tolower(Answer) == 'y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";

            _ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResults;
            SaveResults = Client1.Save();

            switch (SaveResults)
            {
            case clsBankClient::svFaildEmptyObject:
                cout << "\nError Account was not save because it is Empty :-(";
                break;
            case clsBankClient::svSucceeded:
                cout << "\nAccount Updated Successfully :-)";
                _PrintClient(Client1);
                break;
            }
        }
    }
};

