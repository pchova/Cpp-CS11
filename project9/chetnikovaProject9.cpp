/*  Polina Chetnikova
    CS11 LBCC
    Project 9 - Enter a Roman Numeral and returns an int
    Use of Constructors and OOP
    10 August 2025
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string strToUpper(string str);

//Class Declaration
class romanType {
    private:
        //data members
        int M = 1000;
        int D = 500;
        int C = 100;
        int L = 50;
        int X = 10;
        int V = 5;
        int I = 1;
        string userInput;
        int romanSum;

    public:
        //constructor 1
        romanType() {
            userInput = "";
            romanSum = 0;
        }

        //constructor 2
        romanType(string in) {
            userInput = in;
            romanSum = 0;
        }

        /*  function romanType() displays the original user input and 
            the number converted into roman numerals
        */
        void show() {
        cout << userInput << " converted to a number is " << romanSum << endl;
        }

        /* getter functions return the int for each numeral */
        int getM() { return M; }
        int getD() { return D; }
        int getC() { return C; }
        int getL() { return L; }
        int getX() { return X; }
        int getV() { return V; }
        int getI() { return I; }

        /*  function getUserInput() is a getter function and returns the 
            original userInput
        */
        string getUserInput() {
            return userInput;
        }

        /*  function getRomanSum() is a getter function and returns the int 
            variable romanSum 
        */
        int getRomanSum(){
            return romanSum;
        }

        /*  function setUserInput() is a setter function and sets the 
            user input to the userInput variable in romanType class 
        */
        void setUserInput(string input) {
            userInput = input;
        }

        /* function addRomanSum() accepts an int and adds it to romanSum */
        void addRomanSum(int num) {
            romanSum += num;
        }
        
        void convertRomanToNum();
        int getNumber(char let);
};

/*  function convertNumToRoman() takes user input (a string)
    and adds number to the variable romanSum
*/
void romanType::convertRomanToNum() {
    string input = strToUpper(getUserInput());

    for (int i = 0; i < input.length(); i++) {
        int a = getNumber(input[i]);

        if (a == -1) {
            cout << "Error: " << input[i] << " is not a Roman numeral." << endl;
            return;
        } else if (i + 1 < input.length()) {
            int b = getNumber(input[i+1]);

            if (a < b) {
                int c = b - a;
                addRomanSum(c);
                i++;
            } else {
                addRomanSum(a);
            }
        } else {
            addRomanSum(a);
        }
    }
}

/*  function getNumber() returns the integer for corresponding 
    Roman Numeral
*/
int romanType::getNumber(char let) {
    switch (let) {
        case 'M': {
            return getM();
        }
        case 'D': {
            return getD();
        }
        case 'C': {
            return getC();
        }
        case 'L': {
            return getL();
        }
        case 'X': {
            return getX();
        }
        case 'V': {
            return getV();
        }
        case 'I': {
            return getI();
        }
        default: return -1;
    }
}

/*  function strToUpper() accepts a string
    and returns it in all upper case
*/
string strToUpper(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }

    /* for (char &ch : str) {
        ch = toupper(ch);
    } */

    return str;
}

int main() {
    //Get User Input
    string input;
    cout << "Enter a number in Roman Numerals: ";
    cin >> input;

    //Create object
    romanType myNum(input);

    //Call function to convert roman numeral to a numerical number
    myNum.convertRomanToNum();

    //Display original and converted number
    myNum.show(); 

    return 0;
}