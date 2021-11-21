
#include "Employee.h"
class NailTechnician :
    public Employee
{
public:
    static void addEmployeeNail(json& employeeInfo, string id, string type, string name, string birthday, string address)
    {
        json newEmployee = json::object({ {"id", id}, {"type", type}, {"name", name}, {"birthday", birthday}, {"address", address} });
        employeeInfo.insert(employeeInfo.end(), newEmployee);
    }
};
