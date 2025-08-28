/* 
    Polina Chetnikova
    Project 5 - Read data from an ASCII file and output into new file
    Long Beach City College
    CS11
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    //declare variables
    string item = string();
    double qty = double();
    double unitCost = double();
    double itemTotal = double();
    double inventoryTotal = 0;

    //ASCII box characters and formatting
    char upperLeft = 218;
    char upperRight = 191;
    char lowerLeft = 192;
    char lowerRight = 217;

    char dash = 45;
    int dashCount = 70;
    string repeatDash(dashCount, dash);

    char star = 42;
    int starsCount = 60;
    string repeatStar(starsCount, star);

    //open existing file for reading
    ifstream input;
    input.open("dataset.txt");

    //open new file for writing
    ofstream output;
    output.open("outputFile.txt");
    output << upperLeft << repeatDash << upperRight << endl;
    output << "|" << right << setw(65) << repeatStar << right << setw(6) << "|" << endl;
    output << "|"  << right << setw(61) << ("Inventory Report for Jane Doe International Hardware") <<
        right << setw(10) << "|" << endl;
    output << "|" << right << setw(65) << repeatStar << right << setw(6) << "|" << endl;
    output << "|" << right << setw(71) << "|" << endl;
    output << "|" << right << setw(9) << "ITEM" << right << setw(20) << "NUMBER OF UNITS" <<
        right << setw(18) << "UNIT COST ($)" <<  right << setw(20) << "TOTAL VALUE ($)" <<
        right << setw(4) << "|" << endl;

    //print header
    cout << upperLeft << repeatDash << upperRight << endl;
    cout << "|" << right << setw(65) << repeatStar << right << setw(6) << "|" << endl;
    cout << "|"  << right << setw(61) << ("Inventory Report for Jane Doe International Hardware") <<
        right << setw(10) << "|" << endl;
    cout << "|" << right << setw(65) << repeatStar << right << setw(6) << "|" << endl;
    cout << "|" << right << setw(71) << "|" << endl;
    cout << "|" << right << setw(9) << "ITEM" << right << setw(20) << "NUMBER OF UNITS" <<
        right << setw(18) << "UNIT COST ($)" <<  right << setw(20) << "TOTAL VALUE ($)" <<
        right << setw(4) << "|" << endl;

    //while loop goes through the entire file and prints each line
    while(!input.eof()) {
        //assign data from file
        input >> item >> qty >> unitCost;
        itemTotal = qty * unitCost;
        inventoryTotal += itemTotal;

        //print file contents
        cout << fixed;
        cout << "|     " << left << setw(6) << item << setprecision(0) << right << setw(12) << qty <<
            setprecision(2) << right << setw(19) << unitCost << 
            setprecision(2) << right << setw(20) << itemTotal <<
            right << setw(9) << "|" << endl;

        //write data to new file
        output << fixed;
        output << "|     " << left << setw(6) << item << setprecision(0) << right << setw(12) << qty <<
            setprecision(2) << right << setw(19) << unitCost << 
            setprecision(2) << right << setw(20) << itemTotal <<
            right << setw(9) << "|" << endl;
    }

    //Print inventory total
    cout << "|" << right << setw(71) << "|" << endl;
    cout << "|" << right << setw(24) << "Inventory Total ($)" << right << setw(38) << inventoryTotal <<
        right << setw(9) << "|" << endl;
    cout << lowerLeft << repeatDash << lowerRight << endl;

    //Write inventory total to file
    output << "|" << right << setw(71) << "|" << endl;
    output << "|" << right << setw(24) << "Inventory Total ($)" << right << setw(38) << inventoryTotal <<
        right << setw(9) << "|" << endl;
    output << lowerLeft << repeatDash << lowerRight << endl;

    //close the file
    output.close();
    return 0;
}