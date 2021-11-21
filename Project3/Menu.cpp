#include"Menu.h"
#include"Date.h"
#include"Employee.h"
#include"Login.h"
#include"Manager.h"
#include"NailTechnician.h"
#include"Payroll.h"

void welcome_menu()
{
    int choice;
    cout << "WELCOME SPA MANAGEMENT SYSTEM MENU !" << endl;
    cout << "MENU:" << endl;
    cout << "[1]. Login" << endl;
    cout << "[0]. Exit" << endl;
    cout << "Enter your choice(integer): ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        login_menu();
        break;
    case 0:
        cout << "Exit";
        Sleep(1000);
        flag1 = false;
        break;
    default:
        break;
    }
}
void login_menu()
{
    cout << "******************LOGIN MENU****************" << endl;
    cout << "Username: ";
    string u, p;
    cin >> u;
    cout << "Password: ";
    cin >> p;
    Login l;
    l.check(u, p);
}
void main_menu()
{
    int choice;
    cout << "******************MAIN MENU****************" << endl;
    cout << "[1]   :Go to Employee Management." << endl;
    cout << "[2]   :Go to Payroll Management." << endl;
    cout << "[3]   :Change password." << endl;
    cout << "[0]   :Exit." << endl;
    cout << "Enter your choice (integer):";
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        employee_menu();
        break;
    case 0:
        system("cls");
        login_menu();
        break;
    case 2:
        system("cls");
        payroll_menu();
        break;
    case 3:
        system("cls");
        changepassword_menu();
    default:
        break;
    }
}
void employee_menu()
{
    int choice;
    cout << "******************EMPLOYEE MANAGEMENT MENU****************" << endl;
    cout << "[1]   :Print all employee's information." << endl;
    cout << "[2]   :Add new employee." << endl;
    cout << "[3]   :Remove an employee by id." << endl;
    cout << "[4]   :Update information an employee by id." << endl;
    cout << "[5]   :Search information an employee by id." << endl;
    cout << "[0]   :Exit." << endl;
    cout << "Enter your choice (integer):";
    cin >> choice;
    switch (choice)
    {
    case 0:
        system("cls");
        main_menu();
        break;
    case 1:
        system("cls");
        display_employee_menu();
        break;
    case 2:
        system("cls");
        add_employee_menu();
        break;
    case 3:
        system("cls");
        remove_employee_menu();
        break;
    case 4:
        system("cls");
        update_employee_menu();
        break;
    case 5:
        system("cls");
        search_employee_menu();
        break;
    default:
        break;
    }
}
void add_employee_menu()
{
    Employee e;
    cout << "******************ADD NEW EMPLOYEE MENU****************" << endl;
    cout << "Enter Employee Type (0: Nail Technician, 1: Manager):";
    cin >> e.type;
    while (true)
    {
        cout << "Enter Employee ID:";
        cin >> e.id;
        if (e.checkIDduplicate(e.id, employeeInfo) == 1)
        {
            int choice;
            cout << "Duplicate ID, choice 0 to exit, 1 to continue: ";
            cin >> choice;
            if (choice == 0)
            {
                system("cls");
                employee_menu();
            }
            if (choice == 1)
                continue;
        }
        break;
    }

    cout << "Enter Employee Name:";
    cin.ignore();
    getline(cin, e.fullname);
    cout << "Enter Employee Address:";
    // cin.ignore();
    getline(cin, e.address);
    cout << "Enter Employee BirthDay (Format yyyy-mm-dd):";
    cin >> e.birthday;
    if (e.type == 1)
    {
        Manager em;
        string type = "Manager";
        cout << "Enter Salary per hour (unit $):";
        cin >> em.Salaryperhour;
        Manager::addEmployeeManager(employeeInfo, e.id, type, e.fullname, e.birthday, e.address, em.Salaryperhour);
    }
    else
    {
        string type = "Nail Technician";
        NailTechnician::addEmployeeNail(employeeInfo, e.id, type, e.fullname, e.birthday, e.address);
    };
    system("cls");
    employee_menu();
}
void display_employee_menu()
{
    cout
        << left
        << setw(12)
        << "ID"
        << left
        << setw(22)
        << "Full name"
        << left
        << setw(22)
        << "Address"
        << left
        << setw(22)
        << "Birthday"
        << left
        << setw(22)
        << "Type" << endl;
    for (unsigned int i = 0; i < employeeInfo.size(); i++)
        Employee::displayInfo(employeeInfo[i]["id"], 1);
    cout << "Number of employee: " << employeeInfo.size() << endl;
    cout << "Enter 0 to exit: ";
    string choice;
    cin >> choice;
    while (true)
    {
        if (choice == "0")
        {
            system("cls");
            employee_menu();
        }
        else
            cin >> choice;
    }
}
void remove_employee_menu()
{
    string id;
    cout << "******************REMOVE EMPLOYEE MENU****************" << endl;
    cout << "Enter Employee ID: ";
    cin >> id;
    Employee::removeEmployee(employeeInfo, id);
    Sleep(1000);
    system("cls");
    employee_menu();
}
void update_employee_detail()
{
    while (true)
    {
        cout << "******************UPDATE EMPLOYEE MENU****************" << endl;
        cout << "[1]   :Update Name. " << endl;
        cout << "[2]   :Update Address. " << endl;
        cout << "[3]   :Update Day of Birth." << endl;
        cout << "[0]   :Exit." << endl;
        cout << "Enter your choice (integer): ";
        int choice;
        cin >> choice;
        string s;
        // string n = "name", a = "address", b = "birthday";
        switch (choice)
        {
        case 0:
            system("cls");
            employee_menu();
            break;
        case 1:
            system("cls");
            cout << "******************UPDATE EMPLOYEE MENU****************" << endl;
            cout << "Enter new employee name: ";
            // cin >> s;
            cin.ignore();
            getline(cin, s);
            Employee::updateName(employeeInfo, temp_id, s);
            break;
        case 2:
            system("cls");
            cout << "******************UPDATE EMPLOYEE MENU****************" << endl;
            cout << "Enter new employee address: ";
            cin.ignore();
            // cin >> s;
            getline(cin, s);
            Employee::updateAddress(employeeInfo, temp_id, s);
            break;
        case 3:
            system("cls");
            cout << "******************UPDATE EMPLOYEE MENU****************" << endl;
            cout << "Enter new employee birthday (Format yyyy-mm-dd): ";
            cin >> s;
            // cin.ignore();
            // getline(cin, s);
            Employee::updateBirthday(employeeInfo, temp_id, s);
            break;
        default:
            break;
        }
    }
}
void update_employee_menu()
{
    string id;
    cout << "******************UPDATE EMPLOYEE MENU****************" << endl;
    cout << "Enter Employee ID: ";
    cin >> id;
    temp_id = id;
    Employee::searchInfo(id, 1);
    system("cls");
    update_employee_detail();
}
void search_employee_menu()
{
    cout << "******************SEARCH EMPLOYEE MENU****************" << endl;
    cout << "Enter Employee ID: ";
    string id;
    cin >> id;
    Employee::searchInfo(id, 1);
    cout
        << left
        << setw(12)
        << "ID"
        << left
        << setw(22)
        << "Full name"
        << left
        << setw(22)
        << "Address"
        << left
        << setw(22)
        << "Birthday"
        << left
        << setw(22)
        << "Type";
    if (Employee::checkTypebyID(id) == 0)
        cout
        << left
        << setw(22)
        << "Salary/hours ($)" << endl;
    else
        cout << endl;
    Employee::displayInfo(id, 2);
    cout << endl;
    cout << "Enter 0 to exit: ";
    string choice;
    cin >> choice;
    if (choice == "0")
    {
        system("cls");
        employee_menu();
    }
    else
        cin >> choice;
}
void nail_menu()
{
    cout << "******************PAYROLL INPUT FOR NAIL TECHNICIAN MENU****************" << endl;
    cout << "Enter money (split + by each receipt, unit $), no space between words : ";
    string smoney, stips;
    double money, tips;
    cin >> smoney;
    money = Payroll::calculate(smoney);
    cout << "Enter tips (split + by each receipt, unit $), no space between words : ";
    cin >> stips;
    tips = Payroll::calculate(stips);

    double salary = coefficient_nail * money + tips;

    int dathem = 0;
    for (unsigned int i = 0; i < payroll.size(); i++)
    {
        if (temp_date == payroll[i]["date"].get<string>())
        {
            Payroll::addEmployee(payroll[i]["employee"], temp_id, salary);
            payroll[i]["income"] = payroll[i]["income"].get<double>() + money + tips;
            dathem = 1;
            break;
        }
    }
    if (dathem == 0)
    {
        json employee = json::array();
        Payroll::addEmployee(employee, temp_id, salary);
        Payroll::addSubPayroll(payroll, temp_date, money + tips, employee);
        // employee.clear();
    }
    payroll_menu();
}
void manager_menu()
{
    cout << "******************PAYROLL INPUT FOR MANAGER MENU****************" << endl;
    cout << "Enter hours/day (unit hour) : ";
    double hours;
    cin >> hours;
    double salary = Manager::getSalaryperhourbyID(temp_id) * hours;
    // addEmployee(employee, temp_id, salary);
    int dathem = 0;
    for (unsigned int i = 0; i < payroll.size(); i++)
    {
        if (temp_date == payroll[i]["date"].get<string>())
        {
            Payroll::addEmployee(payroll[i]["employee"], temp_id, salary);
            dathem = 1;
            break;
            // payroll_menu();
        }
    }
    if (dathem == 0)
    {
        double income = 0;
        json employee = json::array();
        Payroll::addEmployee(employee, temp_id, salary);
        Payroll::addSubPayroll(payroll, temp_date, income, employee);
        // employee.clear();
    }
    payroll_menu();
}

void cal_salary_menu()
{
    cout << "******************CALCULATE SALARY AND PROPIT MENU ****************" << endl;
    cout << "Enter Start Date (Format yyyy-mm-dd): ";
    string start_date, end_date;
    cin >> start_date;
    cout << "Enter End Date (Format yyyy-mm-dd): ";
    cin >> end_date;
    // system("cls");

    double totalincome = Payroll::total_income(start_date, end_date, payroll);
    cout << "Total Income (unit $): " << totalincome << endl;
    cout << "Profit (unit $): " << Payroll::total_profit(start_date, end_date, payroll) << endl;
    cout << "Salary for each employee: " << endl;
    cout << left << setw(14) << "ID" << left << setw(14) << "Salary" << endl;
    for (unsigned int i = 0; i < employeeInfo.size(); i++)
        cout << left << setw(14) << employeeInfo[i]["id"].get<string>() << left << setw(14) << Payroll::calSalary(employeeInfo[i]["id"].get<string>(), start_date, end_date, payroll) << endl;
    cout << "Enter 0 to exit: ";
    string choice;
    cin >> choice;
    if (choice == "0")
    {
        cout << "Exit" << endl;
        Sleep(1000);
        system("cls");
        payroll_menu();
    }
}

void payroll_input_menu()
{
    cout << "******************PAYROLL INPUT MENU****************" << endl;
    cout << "Enter Date (Format yyyy-mm-dd): ";
    string date, id;
    cin >> date;
    Date::checkInputDate(date);
    cout << "Enter Employee id: ";
    cin >> id;
    temp_id = id;
    temp_date = date;
    Employee::searchInfo(id, 2);

    if (Employee::checkTypebyID(id) == 1)
    {
        system("cls");
        nail_menu();
    }
    else
    {
        system("cls");
        manager_menu();
    }
}
void payroll_menu()
{
    ofstream myfile("Files/payroll.txt");
    myfile << setw(3) << payroll;
    myfile.close();

    cout << "******************PAYROLL MANAGEMENT MENU****************" << endl;
    cout << "[1]   :Input payroll for employee." << endl;
    cout << "[2]   :Calculate salary and profit." << endl;
    cout << "[0]   :Exit." << endl;
    cout << "Enter your choice (integer): ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        payroll_input_menu();
        break;
    case 2:
        system("cls");
        cal_salary_menu();
        break;
    case 0:
        system("cls");
        main_menu();
        break;
    default:
        break;
    }
}
void changepassword_menu()
{
    cout << "******************CHANGE PASSWORD MENU ****************" << endl;
    cout << "Enter old password: ";
    string oldPass, newPass;
    cin >> oldPass;
    cout << "Enter new password: ";
    cin >> newPass;
    Login l;
    if (oldPass == l.loginInfo["password"].get<string>())
    {
        l.loginInfo["password"] = newPass;
        ofstream writelogin("loginInfo.txt"); //chay xong chuong trinh moi ghi ra file
        writelogin << setw(4) << l.loginInfo;
        cout << "Change password successfully!" << endl;
        main_menu();
    }
    else
    {
        cout << "Incorrect old password, exited, haha!" << endl;
        main_menu();
    }
}