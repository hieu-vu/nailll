#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "ThirdParty/json.hpp"
#include <fstream>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <vector>

using json = nlohmann::json;
using namespace std;

static bool flag1 = true;
static string temp_id, temp_date;
static double coefficient_nail = 0.6;

static json payroll = json::array();
static json employeeInfo = json::array();

//ifstream readlogin("Files/loginInfo.txt");
//json loginInfo = json::parse(readlogin);

void welcome_menu();
void login_menu();
void main_menu();
void employee_menu();
void add_employee_menu();
void display_employee_menu();
void remove_employee_menu();
void update_employee_detail();
void update_employee_menu();
void search_employee_menu();
void payroll_menu();
void payroll_input_menu();
void nail_menu();
void manager_menu();
void cal_salary_menu();
void changepassword_menu();
