#pragma once
#include"Menu.h"
class Date {
	string date;
public:
    static void checkFormatDate(string date) {
        if (date.length() != 10) cout << "Nhap sai format!" << endl;
	}
    static void checkInputDate(string date)
    {
        time_t curr_time;
        struct tm curr_tm;
        char date_string[20];
        // string date = "2021-11-08";
        char cdate[20];
        strcpy_s(cdate, 20, date.c_str());
        time(&curr_time);
        localtime_s(&curr_tm, &curr_time);
        strftime(date_string, 20, "%Y-%m-%d", &curr_tm);
        if (strcmp(cdate, date_string) > 0)
        {
            cout << "Invalid date";
            Sleep(1000);
            system("cls");
            payroll_menu();
        }
    }
};