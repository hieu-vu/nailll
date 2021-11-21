#pragma once
#include"Menu.h"

class Payroll
{
public:
    static int calculate(string s)
    {
        int total = 0;
        vector<int> signs(2, 1);
        for (unsigned int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c >= '0')
            {
                int number = 0;
                while (i < s.size() && s[i] >= '0')
                    number = 10 * number + s[i++] - '0';
                total += signs.back() * number;
                signs.pop_back();
                i--;
            }
            else if (c == ')')
                signs.pop_back();
            else if (c != ' ')
                signs.push_back(signs.back() * (c == '-' ? -1 : 1));
        }
        return total;
    }
    static void addEmployee(json& employee, string id, double salary)
    {

        json newEmployee = json::object({ {"id", id}, {"salary", salary} });
        employee.insert(employee.end(), newEmployee);
    }
    static void addSubPayroll(json& payroll, string date, double income, json employee)
    {

        json sub_payroll = json::object({ {"date", date}, {"income", income}, {"employee", employee} });
        payroll.insert(payroll.end(), sub_payroll);
    }
    static void stringtocharArray(string s, char* c)
    {
        strcpy_s(c, 20, s.c_str());
    }
    static double total_income(string start_date, string end_date, json payroll)
    {
        double total_income = 0;
        char cstart_date[20];
        char cend_date[20];
        stringtocharArray(start_date, cstart_date);
        stringtocharArray(end_date, cend_date);
        for (unsigned int i = 0; i < payroll.size(); i++)
        {
            char cpayroll_date[20];
            stringtocharArray(payroll[i]["date"].get<string>(), cpayroll_date);
            if (strcmp(cstart_date, cpayroll_date) <= 0 && strcmp(cpayroll_date, cend_date) <= 0)
                total_income += payroll[i]["income"].get<double>();
        }

        return total_income;
    }
    static double total_profit(string start_date, string end_date, json payroll)
    {
        double total_profit = 0, total_salary = 0;
        for (unsigned int i = 0; i < employeeInfo.size(); i++)
            total_salary += calSalary(employeeInfo[i]["id"].get<string>(), start_date, end_date, payroll);
        total_profit = total_income(start_date, end_date, payroll) - total_salary;
        return total_profit;
    }
    static double calSalary(string id, string start_date, string end_date, json payroll)
    {
        double salary = 0;
        char cstart_date[20];
        char cend_date[20];
        stringtocharArray(start_date, cstart_date);
        stringtocharArray(end_date, cend_date);
        for (unsigned int i = 0; i < payroll.size(); i++)
        {
            char cpayroll_date[20];
            stringtocharArray(payroll[i]["date"], cpayroll_date);
            if (strcmp(cstart_date, cpayroll_date) <= 0 && strcmp(cpayroll_date, cend_date) <= 0)
            {
                for (unsigned int j = 0; j < payroll[i]["employee"].size(); j++)
                {
                    if (payroll[i]["employee"][j]["id"] == id)
                    {
                        salary += payroll[i]["employee"][j]["salary"].get<double>();
                        break;
                    }
                }
            }
        }

        return salary;
    }
};
