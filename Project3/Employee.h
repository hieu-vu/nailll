#pragma once
#include"Menu.h"

class Employee
{
public:
	int type = 0;
	string id, fullname, address, birthday;
    static void displayInfo(string id, int flag)
    {
        for (unsigned int i = 0; i < employeeInfo.size(); i++)
        {
            if (employeeInfo[i]["id"] == id)
            {
                cout
                    << left
                    << setw(12)
                    << employeeInfo[i]["id"].get<string>()
                    << left
                    << setw(22)
                    << employeeInfo[i]["name"].get<string>()
                    << left
                    << setw(22)
                    << employeeInfo[i]["address"].get<string>()
                    << left
                    << setw(22)
                    << employeeInfo[i]["birthday"].get<string>()
                    << left
                    << setw(22)
                    << employeeInfo[i]["type"].get<string>();
                if (flag == 1)
                    cout << endl;
                if (flag == 2 && employeeInfo[i]["type"] == "Manager")
                    cout << left << setw(16) << employeeInfo[i]["Salaryperhour"].get<double>();
            }
        }
    }
    static void removeEmployee(json& employeeInfo, string id)
    {
        int dem = 0;
        for (unsigned int i = 0; i < employeeInfo.size(); i++)
            if (employeeInfo[i]["id"] == id)
            {
                employeeInfo.erase(i);
                dem = 1;
            }

        if (dem == 1)
            cout << "Remove Successfully." << endl;
        if (dem == 0)
            cout << "System doesnt include this id, remove failed." << endl;
    }
    static void updateName(json& employeeInfo, string id, string s)
    {
        for (unsigned int i = 0; i < employeeInfo.size(); i++)
            if (employeeInfo[i]["id"] == id)
                employeeInfo[i]["name"] = s;
    }
    static void updateAddress(json& employeeInfo, string id, string s)
    {
        for (unsigned int i = 0; i < employeeInfo.size(); i++)
            if (employeeInfo[i]["id"] == id)
                employeeInfo[i]["address"] = s;
    }
    static void updateBirthday(json& employeeInfo, string id, string s)
    {
        for (unsigned int i = 0; i < employeeInfo.size(); i++)
            if (employeeInfo[i]["id"] == id)
                employeeInfo[i]["birthday"] = s;
    }
    static void searchInfo(string id, int flag)
    {
        int dem = 0;
        for (unsigned int i = 0; i < employeeInfo.size(); i++)
            if (employeeInfo[i]["id"] == id)
                dem += 1;
        if (dem == 0 && flag != 2)
        {
            cout << "System doesnt include this ID." << endl;
            Sleep(1000);
            system("cls");
            employee_menu();
        }
        if (dem == 0 && flag == 2)
        {
            cout << "Invalid employee " << endl;
            Sleep(1000);
            system("cls");
            payroll_menu();
        }
    }
    static int checkTypebyID(string id)
    {
        int t = 0;
        for (unsigned int i = 0; i < employeeInfo.size(); i++)
        {
            if (employeeInfo[i]["id"] == id)
                if (employeeInfo[i]["type"] == "Manager")
                {
                    t = 0;
                    break;
                }
                else
                {
                    t = 1;
                    break;
                }
        }
        return t;
    }
    static int checkIDduplicate(string id, json employeeInfo)
    {
        int result = 0;
        for (unsigned int i = 0; i < employeeInfo.size(); i++)
            if (id == employeeInfo[i]["id"].get<string>())
                result = 1;
        return result;
    }
};  

