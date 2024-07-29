#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsString.h"

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:
    struct stLoginRegisterRecord
	{
		string Date;
		string UserName;
		string Password;
		string Permissions;
	};

	static stLoginRegisterRecord _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		stLoginRegisterRecord LoginRegisterRecord;
		LoginRegisterRecord.Date = vUserData[0];
		LoginRegisterRecord.UserName = vUserData[1];
		LoginRegisterRecord.Password = vUserData[2];
		LoginRegisterRecord.Permissions = vUserData[3];

		return LoginRegisterRecord;

	}

	static vector<stLoginRegisterRecord> GetLoginRecord()
	{
		vector<stLoginRegisterRecord> vLoginRecord;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{

				stLoginRegisterRecord User = _ConvertLinetoUserObject(Line);

				vLoginRecord.push_back(User);
			}

			MyFile.close();
		}

		return vLoginRecord;
	}

	static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
	}
public:
	static void ShowLoginRegisterListScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
		{
			return;
		}

		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else

			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
			{

				PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

