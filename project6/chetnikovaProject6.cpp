/*  Polina Chetnikova
    Project 7 - Barcode Simulator 
    CS11 Summer 2025 - LBCC
    20 July 2025
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/* Prototypes */
int setZipcode();
int sumDigits(int zipcode);
void parse(int y, int x);
void displayBarcode(int x);

/*  Main function calls setZipcode() for user input
    Calculates the sum of all nums from the zipcode with sumDigits()
    Finds the correction digit
    Prints the zipcode with parse()
*/
int main() {
    //get a zipcode from the user
    int userInput = setZipcode();

    //calculate the correction digit
    int sum = sumDigits(userInput);
    int correctionDigit = (10 - (sum % 10)) % 10;
    
    //parse each int within the zipcode 
    parse(userInput, correctionDigit);

    return 0;
}

/*  setZipcode is a function that does not accept any parameters.
    when called, it asks the user for a zipcode and returns it 
*/
int setZipcode(){
    int zipcode = int();
    cout << "Enter a US zipcode: ";
    cin >> zipcode;

    return zipcode;
}

/* sumDigits is a function that accepts one int parameter for a zipcode
    and adds all the numbers in the zipcode together - 
    returns the sum
*/
int sumDigits(int zip) {
    int sum = 0;

    while(zip > 0) { 
        sum += zip % 10;
        zip = zip / 10;
    }

    return sum;
}

/*  parse is a void function that accepts two int parameters and prints out the 
    entire barcode for a zipcode - 
    does not return anything
*/
void parse(int zip, int correctionDigit) {
    cout << "|";

    //convert zip to string otherwise it will display backwards if parse the int
    string strZip = to_string(zip);

    for (char ch : strZip) {
        //ASCII shortcut - char - '0' = ASCII numerical code, only works for int 0-9
        int digit = ch - '0';
        displayBarcode(digit);
    }

    displayBarcode(correctionDigit);
    cout << "|";
}

/*  displayBarcode is a void function that accepts one int parameter and 
    prints part of a barocde depending on the switch statement - 
    does not return anything
*/
void displayBarcode (int x) {
    switch (x) {
        case 1:
            cout << ":::||";
            break;
        case 2:
            cout << "::|:|";
            break;
        case 3:
            cout << "::||:";
            break;
        case 4:
            cout << ":|::|";
            break;
        case 5:
            cout << ":|:|:";
            break;
        case 6:
            cout << ":||::";
            break;
        case 7:
            cout << "|:::|";
            break;
        case 8:
            cout << "|::|:";
            break;
        case 9:
            cout << "|:|::";
            break;
        case 0:
            cout << "||:::";
            break;
    }
}