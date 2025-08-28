#include <iostream>
using namespace std;

int main() 
{
    //declared variables
    int employeeID;
    double hoursWorked;
    double ratePerHour;
    double grossSalary;

    //get user input for all variables
    cout << "Please enter your employee ID: ";
    cin >> employeeID;

    cout << "Enter hours worked: ";
    cin >> hoursWorked;

    cout << "Enter the hourly rate: ";
    cin >> ratePerHour;

    //calculate salary per week
    grossSalary = hoursWorked * ratePerHour;

    cout << "\n* * * * * * * * * * * * * * * * * * * *" << endl;
    
    //print all information on a newline
    cout << "Author's Name: Polina Chetnikova" << endl;
    cout << "Program Name: chetnikovaProject1.cpp" << endl;
    cout << "Date: 22 June 2025" << endl;
    cout << "College: Long Beach City College (LBCC)" << endl;

    cout << "\nEmployee Salary Records\n" << endl;

    cout << "Employee ID: " << employeeID << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Rate per Hour: " << ratePerHour << endl;
    cout << "Gross Salary: $" << grossSalary << " / week\n" << endl;

    return 0;
}