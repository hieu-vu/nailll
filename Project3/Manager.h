#pragma once
#include "Employee.h"
class Manager :
    public Employee
{
public:
    double Salaryperhour;
    static void addEmployeeManager(json& employeeInfo, string id, string type, string name, string birthday, string address, double Salaryperhour)
    {
        json newEmployee = json::object({ {"id", id}, {"type", type}, {"name", name}, {"birthday", birthday}, {"address", address}, {"Salaryperhour", Salaryperhour} });
        employeeInfo.insert(employeeInfo.end(), newEmployee);
    }
    static double getSalaryperhourbyID(string id)
    {
        double temp = 0;
        for (unsigned int i = 0; i < employeeInfo.size(); i++)
        {
            if (employeeInfo[i]["id"] == id)
                temp = employeeInfo[i]["Salaryperhour"].get<double>();
        }
        return temp;
    }
};

