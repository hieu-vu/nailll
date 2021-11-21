#pragma once
#include"Menu.h"

class Login {
	public:
	string u, p;
	ifstream readlogin;
	Login() : readlogin("Files/loginInfo.txt") {}
	json loginInfo = json::parse(readlogin);
	void check(string u, string p)
	{
		if (u == loginInfo["username"].get<string>() && p == loginInfo["password"].get<string>())
		{
			cout << "Login success" << endl;
			Sleep(1000);
			system("cls");
			main_menu();
		}
		else
		{
			cout << "Incorrect username or password." << endl;
			Sleep(1000);
			system("cls");
			welcome_menu();
		}
	}
};