#include <iostream>
#include <ctime>
#include <vector>
#include "User.h"
using namespace std;

//Main Program
int UserIDSsequence = 1; // for user Id
int currentYear;// for system year
double totalMoneyCompany = 0;
vector<User> users;

/*time_t is a data type in C++ that is used to represent time values as a count of seconds since the Epoch.
The Epoch is typically defined as January 1, 1970, 00:00:00 UTC.
time_t is defined in the <ctime> header file and is a signed integer type.
It is usually implemented as a 32-bit or 64-bit integer, depending on the platform.
To get the current time as a time_t value, you can use the time() function, which is also defined in the <ctime> header file.
The time() function returns the current time as a time_t value, which you can store in a variable or use directly in your code.
Here's an example of how to use time_t and time() to get the current time:

#include <ctime>
#include <iostream>

int main() {
    time_t now = time(nullptr);
    std::cout << "The current time is: " << now << std::endl;
    return 0;
}
In this example, the time() function is called with a nullptr argument, which tells it to return the current time.
The resulting time_t value is stored in the now variable and printed to the console.
tm is a C++ struct type that represents a calendar time broken down into its components, such as year, month, day, hour, minute, and second.
The tm struct is defined in the <ctime> header file.
Here's the definition of the tm struct:

struct tm {
  int tm_sec;   // seconds after the minute (0 to 60)
  int tm_min;   // minutes after the hour (0 to 59)
  int tm_hour;  // hours since midnight (0 to 23)
  int tm_mday;  // day of the month (1 to 31)
  int tm_mon;   // months since January (0 to 11)
  int tm_year;  // years since 1900
  int tm_wday;  // days since Sunday (0 to 6)
  int tm_yday;  // days since January 1 (0 to 365)
  int tm_isdst; // Daylight Saving Time flag (-1, 0, or 1)
};

The tm struct is used in conjunction with functions that convert between time_t values and calendar time components.
For example, the gmtime() and localtime() functions both take a time_t value and return a pointer to a tm struct that represents the
corresponding calendar time in either Coordinated Universal Time (UTC) or the local time zone, respectively.
Here's an example of how to use tm with gmtime() to get the current UTC time:

#include <ctime>
#include <iostream>

int main() {
    time_t now = time(nullptr);
    tm* utc_time = gmtime(&now);
    std::cout << "The current UTC time is: "
              << utc_time->tm_hour << ":" << utc_time->tm_min << ":" << utc_time->tm_sec << std::endl;
    return 0;
}
In this example, the gmtime() function is called with the now variable, which contains the current time as a time_t value.
The resulting tm struct is then used to print the current UTC time to the console.
*/

void currentyear()
{
    time_t now = time(0);
    tm local_time;
    localtime_s(&local_time, &now);
    currentYear = local_time.tm_year + 1900;
}

int readInt()
{
    int data;
    cin >> data;
    while (cin.fail() || cin.peek() != '\n' || data < 0)
    {
        cin.clear();
        cin.ignore(512, '\n');
        cout << "Please enter the positive integer: ";
        cin >> data;
    }
    cin.ignore(512, '\n');
    return data;
}
void menu() // for displaying menu
{
    cout << "Current Year: " << currentYear << endl;
    cout << "1. For a new user" << endl;
    cout << "2. For display user details" << endl;
    cout << "3. For display insurance agreement" << endl;
    cout << "4. For display total money made by insurance company" << endl;
    cout << "5. For moving forward by one year" << endl;
    cout << "0. For exit" << endl;
    cout << "Enter you choice: ";
}

void newUser() // for creating new user
{
    users.push_back(User(UserIDSsequence, currentYear));
    UserIDSsequence++;
}
void displayUser() // for displaying user details
{
    if (users.size() == 0) // if there is no user then can't perform this function
    {
        cout << "No user entered yet." << endl;
        return;
    }
    for (int i = 0; i < users.size(); i++)
    {
        cout << "User ID: " << (i + 1) << " \t" << "User Name: " << users[i].name << endl;
    }
}
void userAgreement() // for displaying user agreement menu
{
    if (users.size() == 0) // if there is no user then can't perform this function
    {
        cout << "No user entered yet" << endl;
        return;
    }
    displayUser();
    cout << "\nEnter the user ID of which you want to see insurance agreements (0 for exit): ";
    int user = 0;
    while (true)
    {
        user = readInt();
        if (user >= 1 && user <= users.size())
        {
            break;
        }
        else if (user == 0)
        {
            return;
        }
        else
        {
            cout << "Please enter valid user ID: ";
        }
    }
    users[user - 1].mainmenu();
}
void totalMoneyCal() // for calculate total money made by company
{
    totalMoneyCompany = 0;
    for (int i = 0; i < users.size(); i++)
    {
        totalMoneyCompany += users[i].totalMoneyUser;
    }
}
void movingForward() // for moving forward by one year
{
    cout << "Report of year " << currentYear << endl;
    currentYear++;
    for (int i = 0; i < users.size(); i++)
    {
        cout << "For user " + users[i].name << endl;
        users[i].moveTimeForward(currentYear);
    }
    totalMoneyCal();
    cout << "\nTotal Money made by insurance company in year " << (currentYear - 1) << " is = " << totalMoneyCompany << endl;
    for (int i = 0; i < users.size(); i++)
    {
        users[i].yearlyFeeNext();
    }
    cout << "\nMoving time forward to year: " << currentYear << endl;
}
int main()
{
    currentyear();
    cout << "Insurance Buying Software" << endl;
    bool loop = true;
    while (loop)
    {
        menu();
        int choose = readInt();
        switch (choose)
        {
        case 0:
            return 0;
        case 1:
            newUser();
            break;
        case 2:
            displayUser();
            break;
        case 3:
            userAgreement();
            break;
        case 4:
            totalMoneyCal();
            cout << "Total Money made by insurance company " << totalMoneyCompany << endl;
            break;
        case 5:
            movingForward();
            break;
        default:
            cout << "Invalid option." << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}
