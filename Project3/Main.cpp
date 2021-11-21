#include"Menu.h"

int main()
{
    while (true)
    {
        welcome_menu();
        if (!flag1)
            break;
    }

    ofstream ofs("Files/employeeInfo.txt");
    ofs << setw(3) << employeeInfo;
    return 0;
}