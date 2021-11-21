//#include <iostream>
//#include <string>
//#include <iomanip>
//#include "ThirdParty/json.hpp"
//#include <fstream>
//#include <cstring>
//#include <windows.h>
//#include <ctime>
//#include <vector>
//
//using json = nlohmann::json;
//using namespace std;
//
//bool flag1 = true;
//
//string temp_id, temp_date;
//double coefficient_nail = 0.6;
//
//json payroll = json::array();
//json employeeInfo = json::array();
//
//ifstream readlogin("Files/loginInfo.txt");
//json loginInfo = json::parse(readlogin);
//
//void payroll_menu();
//void searchInfo(string, int);
//int checkTypebyID(string);
//double calSalary(string, string, string, json);
//void main_menu();
//void employee_menu();
//
//void checkFormatDate(string date){
//    
//}
//
//void changepassword_menu()
//{
//    cout << "******************CHANGE PASSWORD MENU ****************" << endl;
//    cout << "Enter old password: ";
//    string oldPass, newPass;
//    cin >> oldPass;
//    cout << "Enter new password: ";
//    cin >> newPass;
//    if (oldPass == loginInfo["password"].get<string>())
//    {
//        loginInfo["password"] = newPass;
//        ofstream writelogin("loginInfo.txt"); //chay xong chuong trinh moi ghi ra file
//        writelogin << setw(4) << loginInfo;
//        cout << "Change password successfully!" << endl;
//        main_menu();     
//    }
//    else
//    {
//        cout << "Incorrect old password, exited, haha!" << endl;
//        main_menu();
//    }
//}
//
//void addSubPayroll_Manager(json &payroll, string date, json employee)
//{
//    json sub_payroll = json::object({{"date", date}, {"employee", employee}});
//    payroll.insert(payroll.end(), sub_payroll);
//}
//double getSalaryperhourbyID(string id)
//{
//    double temp = 0;
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//    {
//        if (employeeInfo[i]["id"] == id)
//            temp = employeeInfo[i]["Salaryperhour"].get<double>();
//    }
//    return temp;
//}
//int calculate(string s)
//{
//    int total = 0;
//    vector<int> signs(2, 1);
//    for (unsigned int i = 0; i < s.size(); i++)
//    {
//        char c = s[i];
//        if (c >= '0')
//        {
//            int number = 0;
//            while (i < s.size() && s[i] >= '0')
//                number = 10 * number + s[i++] - '0';
//            total += signs.back() * number;
//            signs.pop_back();
//            i--;
//        }
//        else if (c == ')')
//            signs.pop_back();
//        else if (c != ' ')
//            signs.push_back(signs.back() * (c == '-' ? -1 : 1));
//    }
//    return total;
//}
//void addEmployee(json &employee, string id, double salary)
//{
//
//    json newEmployee = json::object({{"id", id}, {"salary", salary}});
//    employee.insert(employee.end(), newEmployee);
//}
//void addSubPayroll(json &payroll, string date, double income, json employee)
//{
//
//    json sub_payroll = json::object({{"date", date}, {"income", income}, {"employee", employee}});
//    payroll.insert(payroll.end(), sub_payroll);
//}
//void updateName(json &employeeInfo, string id, string s)
//{
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//        if (employeeInfo[i]["id"] == id)
//            employeeInfo[i]["name"] = s;
//}
//void updateAddress(json &employeeInfo, string id, string s)
//{
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//        if (employeeInfo[i]["id"] == id)
//            employeeInfo[i]["address"] = s;
//}
//void updateBirthday(json &employeeInfo, string id, string s)
//{
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//        if (employeeInfo[i]["id"] == id)
//            employeeInfo[i]["birthday"] = s;
//}
//void stringtocharArray(string s, char *c)
//{
//    strcpy_s(c,20, s.c_str());
//}
//double total_income(string start_date, string end_date, json payroll)
//{
//    double total_income = 0;
//    char cstart_date[20];
//    char cend_date[20];
//    stringtocharArray(start_date, cstart_date);
//    stringtocharArray(end_date, cend_date);
//    for (unsigned int i = 0; i < payroll.size(); i++)
//    {
//        char cpayroll_date[20];
//        stringtocharArray(payroll[i]["date"].get<string>(), cpayroll_date);
//        if (strcmp(cstart_date, cpayroll_date) <= 0 && strcmp(cpayroll_date, cend_date) <= 0)
//            total_income += payroll[i]["income"].get<double>();
//    }
//
//    return total_income;
//}
//double total_profit(string start_date, string end_date, json payroll)
//{
//    double total_profit = 0, total_salary = 0;
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//        total_salary += calSalary(employeeInfo[i]["id"].get<string>(), start_date, end_date, payroll);
//    total_profit = total_income(start_date, end_date, payroll) - total_salary;
//    return total_profit;
//}
//double calSalary(string id, string start_date, string end_date, json payroll)
//{
//    double salary = 0;
//    char cstart_date[20];
//    char cend_date[20];
//    stringtocharArray(start_date, cstart_date);
//    stringtocharArray(end_date, cend_date);
//    for (unsigned int i = 0; i < payroll.size(); i++)
//    {
//        char cpayroll_date[20];
//        stringtocharArray(payroll[i]["date"], cpayroll_date);
//        if (strcmp(cstart_date, cpayroll_date) <= 0 && strcmp(cpayroll_date, cend_date) <= 0)
//        {
//            for (unsigned int j = 0; j < payroll[i]["employee"].size(); j++)
//            {
//                if (payroll[i]["employee"][j]["id"] == id)
//                {
//                    salary += payroll[i]["employee"][j]["salary"].get<double>();
//                    break;
//                }
//            }
//        }
//    }
//
//    return salary;
//}
//void checkInputDate(string date)
//{
//    time_t curr_time;
//    struct tm curr_tm;
//    char date_string[20];
//     string date = "2021-11-08";
//    char cdate[20];
//    strcpy_s(cdate, 20,date.c_str());
//    time(&curr_time);
//    localtime_s(&curr_tm, &curr_time);
//    strftime(date_string, 20, "%Y-%m-%d", &curr_tm);
//    if (strcmp(cdate, date_string) > 0)
//    {
//        cout << "Invalid date";
//        Sleep(1000);
//        system("cls");
//        payroll_menu();
//    }
//}
//void nail_menu()
//{
//    cout << "******************PAYROLL INPUT FOR NAIL TECHNICIAN MENU****************" << endl;
//    cout << "Enter money (split + by each receipt, unit $), no space between words : ";
//    string smoney, stips;
//    double money, tips;
//    cin >> smoney;
//    money = calculate(smoney);
//    cout << "Enter tips (split + by each receipt, unit $), no space between words : ";
//    cin >> stips;
//    tips = calculate(stips);
//
//    double salary = coefficient_nail * money + tips;
//
//    int dathem = 0;
//    for (unsigned int i = 0; i < payroll.size(); i++)
//    {
//        if (temp_date == payroll[i]["date"].get<string>())
//        {
//            addEmployee(payroll[i]["employee"], temp_id, salary);
//            payroll[i]["income"] = payroll[i]["income"].get<double>() + money + tips;
//            dathem = 1;
//            break;
//        }
//    }
//    if (dathem == 0)
//    {
//        json employee = json::array();
//        addEmployee(employee, temp_id, salary);
//        addSubPayroll(payroll, temp_date, money + tips, employee);
//         employee.clear();
//    }
//    payroll_menu();
//}
//void manager_menu()
//{
//    cout << "******************PAYROLL INPUT FOR MANAGER MENU****************" << endl;
//    cout << "Enter hours/day (unit hour) : ";
//    double hours;
//    cin >> hours;
//    double salary = getSalaryperhourbyID(temp_id) * hours;
//     //addEmployee(employee, temp_id, salary);
//    int dathem = 0;
//    for (unsigned int i = 0; i < payroll.size(); i++)
//    {
//        if (temp_date == payroll[i]["date"].get<string>())
//        {
//            addEmployee(payroll[i]["employee"], temp_id, salary);
//            dathem = 1;
//            break;
//             payroll_menu();
//        }
//    }
//    if (dathem == 0)
//    {
//        double income = 0;
//        json employee = json::array();
//        addEmployee(employee, temp_id, salary);
//        addSubPayroll(payroll, temp_date, income, employee);
//         employee.clear();
//    }
//    payroll_menu();
//}
//
//void cal_salary_menu()
//{
//    cout << "******************CALCULATE SALARY AND PROPIT MENU ****************" << endl;
//    cout << "Enter Start Date (Format yyyy-mm-dd): ";
//    string start_date, end_date;
//    cin >> start_date;
//    cout << "Enter End Date (Format yyyy-mm-dd): ";
//    cin >> end_date;
//     system("cls");
//
//    double totalincome = total_income(start_date, end_date, payroll);
//    cout << "Total Income (unit $): " << totalincome << endl;
//    cout << "Profit (unit $): " << total_profit(start_date, end_date, payroll) << endl;
//    cout << "Salary for each employee: " << endl;
//    cout << left << setw(14) << "ID" << left << setw(14) << "Salary" << endl;
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//        cout << left << setw(14) << employeeInfo[i]["id"].get<string>() << left << setw(14) << calSalary(employeeInfo[i]["id"].get<string>(), start_date, end_date, payroll) << endl;
//    cout << "Enter 0 to exit: ";
//    string choice;
//    cin >> choice;
//    if (choice == "0")
//    {
//        cout << "Exit" << endl;
//        Sleep(1000);
//        system("cls");
//        payroll_menu();
//    }
//}
//
//void payroll_input_menu()
//{
//    cout << "******************PAYROLL INPUT MENU****************" << endl;
//    cout << "Enter Date (Format yyyy-mm-dd): ";
//    string date, id;
//    cin >> date;
//    checkInputDate(date);
//    cout << "Enter Employee id: ";
//    cin >> id;
//    temp_id = id;
//    temp_date = date;
//    searchInfo(id, 2);
//
//    if (checkTypebyID(id) == 1)
//    {
//        system("cls");
//        nail_menu();
//    }
//    else
//    {
//        system("cls");
//        manager_menu();
//    }
//}
//void payroll_menu()
//{
//    ofstream myfile("Files/payroll.txt");
//    myfile << setw(3) << payroll;
//    myfile.close();
//
//    cout << "******************PAYROLL MANAGEMENT MENU****************" << endl;
//    cout << "[1]   :Input payroll for employee." << endl;
//    cout << "[2]   :Calculate salary and profit." << endl;
//    cout << "[0]   :Exit." << endl;
//    cout << "Enter your choice (integer): ";
//    int choice;
//    cin >> choice;
//
//    switch (choice)
//    {
//    case 1:
//        system("cls");
//        payroll_input_menu();
//        break;
//    case 2:
//        system("cls");
//        cal_salary_menu();
//        break;
//    case 0:
//        system("cls");
//        main_menu();
//        break;
//    default:
//        break;
//    }
//}
//void displayInfo(string id, int flag)
//{
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//    {
//        if (employeeInfo[i]["id"] == id)
//        {
//            cout
//                << left
//                << setw(12)
//                << employeeInfo[i]["id"].get<string>()
//                << left
//                << setw(22)
//                << employeeInfo[i]["name"].get<string>()
//                << left
//                << setw(22)
//                << employeeInfo[i]["address"].get<string>()
//                << left
//                << setw(22)
//                << employeeInfo[i]["birthday"].get<string>()
//                << left
//                << setw(22)
//                << employeeInfo[i]["type"].get<string>();
//            if (flag == 1)
//                cout << endl;
//            if (flag == 2 && employeeInfo[i]["type"] == "Manager")
//                cout << left << setw(16) << employeeInfo[i]["Salaryperhour"].get<double>();
//        }
//    }
//}
//void removeEmployee(json &employeeInfo, string id)
//{
//    int dem = 0;
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//        if (employeeInfo[i]["id"] == id)
//        {
//            employeeInfo.erase(i);
//            dem = 1;
//        }
//
//    if (dem == 1)
//        cout << "Remove Successfully." << endl;
//    if (dem == 0)
//        cout << "System doesnt include this id, remove failed." << endl;
//}
//void addEmployeeNail(json &employeeInfo, string id, string type, string name, string birthday, string address)
//{
//    json newEmployee = json::object({{"id", id}, {"type", type}, {"name", name}, {"birthday", birthday}, {"address", address}});
//    employeeInfo.insert(employeeInfo.end(), newEmployee);
//}
//void addEmployeeManager(json &employeeInfo, string id, string type, string name, string birthday, string address, double Salaryperhour)
//{
//    json newEmployee = json::object({{"id", id}, {"type", type}, {"name", name}, {"birthday", birthday}, {"address", address}, {"Salaryperhour", Salaryperhour}});
//    employeeInfo.insert(employeeInfo.end(), newEmployee);
//}
//class employee1
//{
//public:
//    int type=0;
//    string id, fullname, address, birthday;
//};
//class manager : public employee1
//{
//public:
//    double Salaryperhour=0;
//};
//int checkTypebyID(string id)
//{
//    int t = 0;
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//    {
//        if (employeeInfo[i]["id"] == id)
//            if (employeeInfo[i]["type"] == "Manager")
//            {
//                t = 0;
//                break;
//            }
//            else
//            {
//                t = 1;
//                break;
//            }
//    }
//    return t;
//}
//int checkIDduplicate(string id, json employeeInfo)
//{
//    int result = 0;
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//        if (id == employeeInfo[i]["id"].get<string>())
//            result = 1;
//    return result;
//}
//void searchInfo(string id, int flag)
//{
//    int dem = 0;
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//        if (employeeInfo[i]["id"] == id)
//            dem += 1;
//    if (dem == 0 && flag != 2)
//    {
//        cout << "System doesnt include this ID." << endl;
//        Sleep(1000);
//        system("cls");
//        employee_menu();
//    }
//    if (dem == 0 && flag == 2)
//    {
//        cout << "Invalid employee " << endl;
//        Sleep(1000);
//        system("cls");
//        payroll_menu();
//    }
//}
//void login_menu();
//
//void display_employee_menu()
//{
//    cout
//        << left
//        << setw(12)
//        << "ID"
//        << left
//        << setw(22)
//        << "Full name"
//        << left
//        << setw(22)
//        << "Address"
//        << left
//        << setw(22)
//        << "Birthday"    
//        << left
//        << setw(22)
//        << "Type" << endl;
//    for (unsigned int i = 0; i < employeeInfo.size(); i++)
//        displayInfo(employeeInfo[i]["id"], 1);
//    cout << "Number of employee: " << employeeInfo.size() << endl;
//    cout << "Enter 0 to exit: ";
//    string choice;
//    cin >> choice;
//    while (true)
//    {
//        if (choice == "0")
//        {
//            system("cls");
//            employee_menu();
//        }
//        else
//            cin >> choice;
//    }
//}
//void add_employee_menu()
//{
//    employee1 e;
//    cout << "******************ADD NEW EMPLOYEE MENU****************" << endl;
//    cout << "Enter Employee Type (0: Nail Technician, 1: Manager):";
//    cin >> e.type;
//    while (true)
//    {
//        cout << "Enter Employee ID:";
//        cin >> e.id;
//        if (checkIDduplicate(e.id, employeeInfo) == 1)
//        {
//            int choice;
//            cout << "Duplicate ID, choice 0 to exit, 1 to continue: ";
//            cin >> choice;
//            if (choice == 0)
//            {
//                system("cls");
//                employee_menu();
//            }
//            if (choice == 1)
//                continue;
//        }
//        break;
//    }
//
//    cout << "Enter Employee Name:";
//    cin.ignore();
//    getline(cin, e.fullname);
//    cout << "Enter Employee Address:";
//     cin.ignore();
//    getline(cin, e.address);
//    cout << "Enter Employee BirthDay (Format yyyy-mm-dd):";
//    cin >> e.birthday;
//    if (e.type == 1)
//    {
//        manager em;
//        string type = "Manager";
//        cout << "Enter Salary per hour (unit $):";
//        cin >> em.Salaryperhour;
//        addEmployeeManager(employeeInfo, e.id, type, e.fullname, e.birthday, e.address, em.Salaryperhour);
//    }
//    else
//    {
//        string type = "Nail Technician";
//        addEmployeeNail(employeeInfo, e.id, type, e.fullname, e.birthday, e.address);
//    };
//    system("cls");
//    employee_menu();
//}
//void remove_employee_menu()
//{
//    string id;
//    cout << "******************REMOVE EMPLOYEE MENU****************" << endl;
//    cout << "Enter Employee ID: ";
//    cin >> id;
//    removeEmployee(employeeInfo, id);
//    Sleep(1000);
//    system("cls");
//    employee_menu();
//}
//void update_employee_detail()
//{
//    while (true)
//    {
//        cout << "******************UPDATE EMPLOYEE MENU****************" << endl;
//        cout << "[1]   :Update Name. " << endl;
//        cout << "[2]   :Update Address. " << endl;
//        cout << "[3]   :Update Day of Birth." << endl;
//        cout << "[0]   :Exit." << endl;
//        cout << "Enter your choice (integer): ";
//        int choice;
//        cin >> choice;
//        string s;
//         string n = "name", a = "address", b = "birthday";
//        switch (choice)
//        {
//        case 0:
//            system("cls");
//            employee_menu();
//            break;
//        case 1:
//            system("cls");
//            cout << "******************UPDATE EMPLOYEE MENU****************" << endl;
//            cout << "Enter new employee name: ";
//             cin >> s;
//            cin.ignore();
//            getline(cin, s);
//            updateName(employeeInfo, temp_id, s);
//            break;
//        case 2:
//            system("cls");
//            cout << "******************UPDATE EMPLOYEE MENU****************" << endl;
//            cout << "Enter new employee address: ";
//            cin.ignore();
//             cin >> s;
//            getline(cin, s);
//            updateAddress(employeeInfo, temp_id, s);
//            break;
//        case 3:
//            system("cls");
//            cout << "******************UPDATE EMPLOYEE MENU****************" << endl;
//            cout << "Enter new employee birthday (Format yyyy-mm-dd): ";
//            cin >> s;
//             cin.ignore();
//             getline(cin, s);
//            updateBirthday(employeeInfo, temp_id, s);
//            break;
//        default:
//            break;
//        }
//    }
//}
//void update_employee_menu()
//{
//    string id;
//    cout << "******************UPDATE EMPLOYEE MENU****************" << endl;
//    cout << "Enter Employee ID: ";
//    cin >> id;
//    temp_id = id;
//    searchInfo(id, 1);
//    system("cls");
//    update_employee_detail();
//}
//void search_employee_menu()
//{
//    cout << "******************SEARCH EMPLOYEE MENU****************" << endl;
//    cout << "Enter Employee ID: ";
//    string id;
//    cin >> id;
//    searchInfo(id, 1);
//    cout
//        << left
//        << setw(12)
//        << "ID"
//        << left
//        << setw(22)
//        << "Full name"
//        << left
//        << setw(22)
//        << "Address"
//        << left
//        << setw(22)
//        << "Birthday"
//        << left
//        << setw(22)
//        << "Type";
//    if (checkTypebyID(id) == 0)
//        cout
//            << left
//            << setw(22)
//            << "Salary/hours ($)" << endl;
//    else
//        cout << endl;
//    displayInfo(id, 2);
//    cout << endl;
//    cout << "Enter 0 to exit: ";
//    string choice;
//    cin >> choice;
//    if (choice == "0")
//    {
//        system("cls");
//        employee_menu();
//    }
//    else
//        cin >> choice;
//}
//
//void employee_menu()
//{
//    int choice;
//    cout << "******************EMPLOYEE MANAGEMENT MENU****************" << endl;
//    cout << "[1]   :Print all employee's information." << endl;
//    cout << "[2]   :Add new employee." << endl;
//    cout << "[3]   :Remove an employee by id." << endl;
//    cout << "[4]   :Update information an employee by id." << endl;
//    cout << "[5]   :Search information an employee by id." << endl;
//    cout << "[0]   :Exit." << endl;
//    cout << "Enter your choice (integer):";
//    cin >> choice;
//    switch (choice)
//    {
//    case 0:
//        system("cls");
//        main_menu();
//        break;
//    case 1:
//        system("cls");
//        display_employee_menu();
//        break;
//    case 2:
//        system("cls");
//        add_employee_menu();
//        break;
//    case 3:
//        system("cls");
//        remove_employee_menu();
//        break;
//    case 4:
//        system("cls");
//        update_employee_menu();
//        break;
//    case 5:
//        system("cls");
//        search_employee_menu();
//        break;
//    default:
//        break;
//    }
//}
//
//void main_menu()
//{
//    int choice;
//    cout << "******************MAIN MENU****************" << endl;
//    cout << "[1]   :Go to Employee Management." << endl;
//    cout << "[2]   :Go to Payroll Management." << endl;
//    cout << "[3]   :Change password." << endl;
//    cout << "[0]   :Exit." << endl;
//    cout << "Enter your choice (integer):";
//    cin >> choice;
//    switch (choice)
//    {
//    case 1:
//        system("cls");
//        employee_menu();
//        break;
//    case 0:
//        system("cls");
//        login_menu();
//        break;
//    case 2:
//        system("cls");
//        payroll_menu();
//        break;
//    case 3:
//        system("cls");
//        changepassword_menu();
//    default:
//        break;
//    }
//}
//void welcome_menu();
//void check(string u, string p)
//{
//    if (u == loginInfo["username"].get<string>() && p == loginInfo["password"].get<string>())
//    {
//        cout << "Login success" << endl;
//        Sleep(1000);
//        system("cls");
//        main_menu();
//    }
//    else
//    {
//        cout << "Incorrect username or password." << endl;
//        Sleep(1000);
//        system("cls");
//        welcome_menu();
//    }
//}
//void login_menu()
//{
//    cout << "******************LOGIN MENU****************" << endl;
//    cout << "Username: ";
//    string u, p;
//    cin >> u;
//    cout << "Password: ";
//    cin >> p;
//    check(u, p);
//}
//void welcome_menu()
//{
//    int choice;
//    cout << "WELCOME SPA MANAGEMENT SYSTEM MENU !" << endl;
//    cout << "MENU:" << endl;
//    cout << "[1]. Login" << endl;
//    cout << "[0]. Exit" << endl;
//    cout << "Enter your choice(integer): ";
//    cin >> choice;
//    switch (choice)
//    {
//    case 1:
//        system("cls");
//        login_menu();
//        break;
//    case 0:
//        cout << "Exit";
//        Sleep(1000);
//        flag1 = false;
//        break;
//    default:
//        break;
//    }
//}
//
//int main()
//{
//    while (true)
//    {
//        welcome_menu();
//        if (!flag1)
//            break;
//    }
//
//    ofstream ofs("employeeInfo.txt");
//    ofs << setw(3) << employeeInfo;
//    return 0;
//}