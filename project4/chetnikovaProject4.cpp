/*  Polina Chetnikova
    Project 4 - Calculate Quadratic Formula
    LBCC - CS11 , Professor Tahir Aziz
    6 July 2025
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
    //declare variables
    int a = int();
    int b = int();
    int c = int();
    string fname = string();
    string lname = string();

    //get user input - name and coefficients for equation
    cout << "Polina Chetnikova - ";
    cout << endl;
    cout << "This program will provide solutions for an equation of the form " << endl; 
    cout << "A*x^2 + B*x + C = 0" << endl;
    cout << "where A, B, and C are integers, and A is not equal to zero." << endl;
    cout << endl;

    //get user input for 3 variables and assign to a,b,c
    cout << "Enter A, C, and C: ";
    cin >> a >> b >> c;

    /* Calculations. First determine if a is non-zero number */
    if (a == 0) {
        cout << "No solutions shall be calculated for a leading coefficient of 0!" << endl;
    } else if ( a != 0 ) {
        // if A does not equal zero, calculate the discriminant
        double discriminant = (pow(b, 2.0) - (4*a*c));

        // calculate quadratic formula
        double solution1 = (-b + sqrt(discriminant)) / (2*a);
        double solution2 = (-b - sqrt(discriminant)) / (2*a);

        if (discriminant > 0) {
            // if discriminant is positive: # of solutions = 2. (real)
            cout << "\nThe two real solutions are: " << endl;
            cout << "x = " << scientific << setprecision(4) << solution1 << " and ";
            cout << "x = " << scientific << setprecision(4) << solution2 << endl;

        } else if (discriminant == 0) {
            // if discriminant is zero: # of solutions = 1. (real)
            cout << "\nThe one real solution is: ";
            cout << "x = " << scientific << setprecision(4) << solution1 << endl;

        } else if (discriminant < 0) {
            // if discriminant is negative: # of solutions = 2. (imaginary)
            double disSquared = discriminant * -1;
            double num1 = static_cast<double>(-b) / (2*a);
            double num2 = static_cast<double>(sqrt(disSquared)) / (2*a);
            
            // display solutions 
            cout << "\nThe two imaginary solutions are: " << endl;
            cout << "x = " << scientific << setprecision(4) << num1 << " + (" << num2 << ")*I and" << endl;
            cout << "x = " << scientific << setprecision(4) << num1 << " - (" << num2 << ")*I" << endl;

        } else {
            cout << "error in quadratic calculation.";
        }
    } else {
        cout << "Equation could not be determined." << endl;
    }

    system("pause");
    return 0;
}