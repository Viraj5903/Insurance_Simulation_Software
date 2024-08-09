#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "InsuranceAgreement.h"
using namespace std;

class User : public Person
{
private:
    string passwordCode;
    int year; // current year
    int count = 0;
    double totalPayoutsFromCanceledAgreements = 0; // per year
    int readInt()
    {
        int data;
        cin >> data;
        /*cin.fail() : This function returns true when an input failure occurs.
        cin.fail() detects whether the value entered fits the value defined in the variable.
        But if cin.fail() is true, it means that
        a) the entered value does not fit the variable
        b) the varialbe will not be affected
        c) the instream is still broken
        d) the entered value is still in the buffer and will be used for the next "cin >> variable"statement.*/

        /*cin.peek() : Returns the next character in the input sequence, without extracting it
        The character is left as the next character to be extracted from the stream.*/
        /*cin.ignore: The cin.ignore() function is used which is used to ignore or clear one or more characters from the input buffer.
        What are the arguments of CIN ignore ()?
        ignore()” function after the cin statement. It takes two arguments.
        One is numeric_limits stream size header to clear the buffer cache after 1st value and a compelling new line i.e. “\n”.
        So, the next variable “Str” will get the value after the user gets to the next line*/
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
    string stringCheck() // for string data validation
    {
        string str;
        bool inputValid = true;
        //cin.ignore(512, '\n'); // Clearing the buffer first
        while (inputValid)
        {
            getline(cin, str);
            if (str.empty()) // if string is null then ask user again
            {
                cout << "Please enter the character value only: ";
                inputValid = true;
            }
            else
            {
                bool check = true;
                for (int i = 0; i < str.length(); i++) // Checking every element from string whether it is alphabet or not 
                {
                    char c = str[i];
                    if (!isalpha(c) && c != ' ') // if element is not alphabet and not space then ask user again and breaking the for loop
                    {
                        check = false;
                        cout << "Please enter the character value only: ";
                        break;
                    }
                }
                if (check) // if string is not null and it only contains alphabet then it is valid input. And breaking while loop
                {
                    inputValid = false;
                }
            }
        }
        return str;
    }
    string passcodeCheck() // for string data validation
    {
        string str;
        bool inputValid = true;
        while (inputValid)
        {
            cin >> str;
            if (str.empty()) // if string is null then ask user again
            {
                cout << "Please enter the 4 digit only: ";
                inputValid = true;
            }
            else if (str.size() != 4) // if string length in not 4 then asking user again
            {
                cout << "Please enter the 4 digit only: ";
                inputValid = true;
            }
            else
            {
                bool check = true;
                for (int i = 0; i < str.length(); i++) // Checking every element from string whether it is digit or not 
                {
                    char c = str[i];
                    if (!isdigit(c)) // if element is not digit then ask user again and breaking the for loop
                    {
                        check = false;
                        cout << "Please enter the 4 digit only: ";
                        break;
                    }
                }
                if (check) // if string is not null and it only contains 4 digits then it is valid input. And breaking while loop
                {
                    inputValid = false;
                }
            }
        }
        return str;
    }

public:
    int UsertId;
    vector<InsuranceAgreement> agreements;//  creating vector of InsuranceAgreement data type
    double totalMoneyUser = 0; // total money collected by user from client
    double totalPayoutUser = 0; // per year
    User(int id, int currentYear) //Constructor
    {
        UsertId = id;
        cout << "Enter the user name: ";
        name = stringCheck();
        year = currentYear;
        cout << "Enter user passcode(in digit) 4 digits only: ";
        passwordCode = passcodeCheck();
    }

    void mainmenu() // for main menu
    {
        cout << "Enter user passcode: ";
        string passcode = passcodeCheck();
        if (passcode != passwordCode)
        {
            cout << "Incorrect passcode. Access Denied." << endl;
            return;
        }
        while (true)
        {
            menu();
            int choice = readInt();
            cout << endl;
            switch (choice)
            {
            case 0:
                return;
            case 1:
                totalMoneyDisplay();
                break;
            case 2:
                receiveNewApplications();
                break;
            case 3:
                displayInsuranceAgreements();
                break;
            case 4:
                displayFinancialBreakdown();
                break;
            case 5:
                breakInsuranceAgreements();
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
            }
            cout << endl;
        }
    }
    void menu() // for displaying menu
    {
        cout << "Current Year: " + year << endl;
        cout << "User name: " + name << endl;
        cout << "1. For displaying total money" << endl;
        cout << "2. Receive new applications" << endl;
        cout << "3. See all current insurance agreements" << endl;
        cout << "4. See financial breakdown" << endl;
        cout << "5. Break insurance agreement" << endl;
        cout << "0. Return to main menu" << endl;
        cout << "Enter your choice (1-6): ";
    }
    void totalMoneyDisplay() // for displaying total money collected by user
    {
        cout << "Total Money made by this user = " << totalMoneyUser << endl;
    }
    void receiveNewApplications() // for generating 6 different application
    {
        if (agreements.size() == 20)
        {
            cout << "User already have 20 Insurance Agreements. Reach to limit" << endl;
            return;
        }
        cout << "New Insurance applications:" << endl;
        //Generating new applications and storing it in newApplications list
        vector<InsuranceAgreement> newApplication;
        //Random random = new Random();

        for (int i = 0; i < 6; i++)
        {
            //generating new 6 objects
            InsuranceAgreement extra = InsuranceAgreement();
            newApplication.push_back(extra);
        }
        while (newApplication.size() != 0)
        {
            bool cancel = menuNewApplication(newApplication);

            if (newApplication.size() == 0)
            {
                cout << "All 6 applications are over" << endl;
                break;
            }

            if (cancel)
            {
                break;
            }
        }
    }
    /*When a vector is passed to a function, a copy of the vector is created.
    This new copy of the vector is then used in the function and thus, any changes made to the vector in the function do not affect the
    original vector.

    Passing by value keeps the original vector unchanged and doesn’t modify the original values of the vector.
    However, the above style of passing might also take a lot of time in cases of large vectors. So, it is a good idea to pass by reference.
    Passing by reference saves a lot of time and makes the implementation of the code faster.
    */

    // The vect is passed by reference and changes made here reflect in newApplication vector()
    bool menuNewApplication(vector<InsuranceAgreement>& newApplication) // for displaying generated application
    {
        //Displaying new generated applications
        for (int i = 0; i < newApplication.size(); i++)
        {
            cout << (i + 1) << ".\nClient: " << newApplication[i].client.name << endl;
            cout << "Yearly Fee: " << newApplication[i].yearlyFee << endl;
            cout << "Risk: " << newApplication[i].risk << endl;
            cout << "Insurance amount: " << newApplication[i].insuranceAmount << endl;
            cout << endl;
        }

        //Ask user to accpet an application
        int choose;
        cout << "Select an application to accept (0 to cancel): ";
        choose = readInt();
        cout << endl;

        if (choose >= 1 && choose <= newApplication.size())
        {
            agreements.push_back(newApplication.at(choose - 1));//adding the selected application in agreements list
            totalMoneyUser += newApplication[choose - 1].yearlyFee; // adding yearly Fee in total Money
            //vector_name.begin(): This function is used to point the first element of the vector.
            /*vector_name.erase(): It deletes the specified elements pointed by the iterator
            Erases third element using erase() function
            Syntax
            Consider a vector v. Syntax would be:
            v.erase(pos);
            v.erase(start_iterator,end_iterator);
            Parameter:
            pos: It defines the position of the element which is to be removed from the vector.
            (start_iterator,end_iterator) : It defines the range of the elements to be removed from the vector.
            Return value: It does not return any value.
            */
            newApplication.erase(newApplication.begin() + choose - 1); // removing the selected application from the menu 
            count++; // counting the number of clients
            return false;
        }
        else if (choose != 0)
        {
            cout << "Invalid choice." << endl;
            return false;
        }
        return true;
    }
    void displayInsuranceAgreements() //for displaying all Insurance Agreements
    {
        if (agreements.size() == 0) // if user have no agreements then can't perform this function
        {
            cout << "You have no insurance agreements." << endl;
            return;
        }

        cout << "No.\tClient\t\tYearly Fee\tRisk\tInsurance Amount\tNet Profit" << endl;;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < agreements.size(); i++)
        {
            cout << (i + 1) << "\t" + agreements[i].client.name << +"\t\t" << agreements[i].yearlyFee << "\t\t" << agreements[i].risk << "%\t" << agreements[i].insuranceAmount << "\t\t\t" << agreements[i].GetNetProfit() << endl;
        }
    }
    double payoutChance() // Randomly get which client made claim
    {
        double totalPayouts = 0;
        for (int i = 0; i < agreements.size(); i++)
        {
            if ((agreements[i].risk >= rand() % 101) && agreements[i].isClaimed == false)
            {
                agreements[i].totalPayout = agreements[i].insuranceAmount;
                totalPayouts += agreements[i].totalPayout;
                cout << "Claim Paid for " << agreements[i].client.name + ": $" << agreements[i].insuranceAmount << endl;
                totalMoneyUser -= agreements[i].totalPayout;
                agreements[i].isClaimed = true;
            }
        }
        return totalPayouts;
    }
    void displayFinancialBreakdown() //For Financial Breakdown
    {
        if (agreements.size() == 0) // if user have no agreements then can't perform this function
        {
            cout << "You have no insurance agreements." << endl;
            return;
        }
        double totalNetProfit = 0;

        totalPayoutUser += payoutChance();

        cout << "Total Payouts from Claims: $" << totalPayoutUser << endl;

        cout << "Total Payouts from Cancelled Agreement: $" << totalPayoutsFromCanceledAgreements << endl;

        cout << "Total income made : $" << totalMoneyUser << endl;

        for (int i = 0; i < agreements.size(); i++)
        {
            totalNetProfit = agreements[i].GetNetProfit();
        }
        cout << "Total breakdown of net profit per year: $" << totalNetProfit << endl;

        double averageNetProfit = totalNetProfit / count;

        cout << "Average net profit: $" << averageNetProfit << endl;
    }
    void breakInsuranceAgreements() //For break agreements
    {
        if (count == 0) // if user have no agreements then can't perform this function
        {
            cout << "You have no insurance agreements." << endl;
            return;
        }

        int choose = 0;
        while (true)
        {
            displayInsuranceAgreements();
            cout << "Enter the agreement number which you want to break (0 to cancel) :" << endl;
            choose = readInt();
            cout << endl;

            if (choose >= 1 && choose <= agreements.size())
            {
                //double breakPay = agreements[choose-1].insuranceAmount;
                totalPayoutsFromCanceledAgreements += agreements[choose - 1].yearlyFee * 10; // adding the payout in totalPayoutsFromCanceledAgreements
                totalMoneyUser -= agreements[choose - 1].yearlyFee * 10; //Removing the payout from total Money
                cout << "You have to pay " << agreements[choose - 1].yearlyFee * 10 << " to " << agreements[choose - 1].client.name << endl;
                //vector_name.begin(): This function is used to point the first element of the vector.
                /*vector_name.erase(): It deletes the specified elements pointed by the iterator
                Erases third element using erase() function
                Syntax
                Consider a vector v. Syntax would be:
                v.erase(pos);
                v.erase(start_iterator,end_iterator);
                Parameter:
                pos: It defines the position of the element which is to be removed from the vector.
                (start_iterator,end_iterator) : It defines the range of the elements to be removed from the vector.
                Return value: It does not return any value.
                */
                agreements.erase(agreements.begin() - (choose - 1)); // removing the selected application from the agreements
            }
            else if (choose == 0)
            {
                break;
            }
            else
            {
                cout << "Invalid choice." << endl;
            }
            cout << endl;
        }
    }
    void moveTimeForward(int nextYear)//for moving forward in year
    {
        totalPayoutUser += payoutChance();
        for (int i = 0; i < agreements.size(); i++)
        {
            if (agreements[i].isClaimed == true)
            {
                cout << "Paid $" << agreements[i].totalPayout << " to " << agreements[i].client.name << " for a claim on " << year << endl;
                agreements[i].isClaimed = false;
                agreements[i].totalPayout = 0;
            }
            agreements[i].nextYearlyFee();
        }
        cout << "Total amount of claims in year " << year << " from this user = " << totalPayoutUser << endl;
        cout << "Total money collected in year " << year << " from this user = " << totalMoneyUser << endl;
        totalPayoutsFromCanceledAgreements = 0;
        totalPayoutUser = 0;
        count = agreements.size();
        year = nextYear;
    }
    void yearlyFeeNext() // for increasing yearly fee for next year
    {
        for (int i = 0; i < agreements.size(); i++)
        {
            totalMoneyUser += agreements[i].yearlyFee;
        }
    }
};