#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    //declare global variables
    double FEDERAL_INCOME_TAX = 0.15;
    double STATE_INCOME_TAX = 0.035;
    double SOCIAL_SEC_TAX = 0.0575;
    double MEDICARE_TAX = 0.0275;
    double PENSION_TAX = 0.05;
    double HEALTH_INSURANCE = 75;

    //undeclared variables
    string firstName = string();
    string lastName = string();
    double grossIncome = double();
    double netPay = double();

    /* Get User Input */
    cout << "Please enter your first name: ";
    cin >> firstName;

    cout << "Please enter your last name: ";
    cin >> lastName;

    cout << "Enter your monthly gross income: ";
    cin >> grossIncome;

    /* Calculate taxes and deductions */
    //FIND HOW MUCH of each tax is going to be taken out in $ form,
    //based on grossIncome
    double federalTax = grossIncome * FEDERAL_INCOME_TAX;
    double stateTax = grossIncome * STATE_INCOME_TAX;
    double ssTax = grossIncome * SOCIAL_SEC_TAX;
    double medicareTax = grossIncome * MEDICARE_TAX;
    double pensionTax = grossIncome * PENSION_TAX;

    //calculate net pay;
    netPay = grossIncome - (federalTax + stateTax + ssTax + medicareTax + pensionTax + HEALTH_INSURANCE);

    /* Display Output in Terminal */
    cout << fixed << setprecision(2);
    cout << endl;
    cout << firstName << " " << lastName << endl;
    cout << "Gross Amount: ............ $" << std::right << std::setw(8) << grossIncome << endl;
    cout << "Federal Tax: ............. $" << std::right << std::setw(8) << federalTax << endl;
    cout << "State Tax: ............... $" << std::right << std::setw(8) << stateTax << endl;
    cout << "Social Security Tax: ..... $" << std::right << std::setw(8) << ssTax << endl;
    cout << "Medicare/Medicaid Tax: ... $" << std::right << std::setw(8) << medicareTax << endl;
    cout << "Pension Plan: ............ $" << std::right << std::setw(8) << pensionTax << endl;
    cout << "Health Insurance: ........ $" << std::right << std::setw(8) << HEALTH_INSURANCE << endl;
    cout << "Net Pay: ................. $" << std::right << std::setw(8) << netPay << endl;

    /* Display Output into a Text File */
    ofstream outputFile;
    outputFile.open("outputProject3.txt");
    
    outputFile << firstName << " " << lastName << std::endl;
    outputFile << "Gross Amount: ............ $" << std::right << std::setw(8) << fixed << setprecision(2) << grossIncome << std::endl;
    outputFile << "Federal Tax: ............. $" << std::right << std::setw(8) << fixed << setprecision(2) << federalTax << std::endl;
    outputFile << "State Tax: ............... $" << std::right << std::setw(8) << fixed << setprecision(2) << stateTax << std::endl;
    outputFile << "Social Security Tax: ..... $" << std::right << std::setw(8) << fixed << setprecision(2) << ssTax << std::endl;
    outputFile << "Medicare/Medicaid Tax: ... $" << std::right << std::setw(8) << fixed << setprecision(2) << medicareTax << std::endl;
    outputFile << "Pension Plan: ............ $" << std::right << std::setw(8) << fixed << setprecision(2) << pensionTax << std::endl;
    outputFile << "Health Insurance: ........ $" << std::right << std::setw(8) << fixed << setprecision(2) << HEALTH_INSURANCE << std::endl;
    outputFile << "Net Pay: ................. $" << std::right << std::setw(8) << fixed << setprecision(2) << netPay << std::endl;

    outputFile.close();

    return 0;
}
