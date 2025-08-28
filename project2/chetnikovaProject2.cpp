#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //create variables 
    int id = int();
    string firstName = string();
    string lastName = string();
    string grade = string();
    double cs11 = double();
    double cs12 = double();
    double cs22 = double();
    double totalScore;
    double averageScore;

    //get user input and assign value to variables
    cout << "Student ID: ";
    cin >> id;

    cout << "First Name: ";
    cin >> firstName;

    cout << "Last Name: ";
    cin >> lastName;

    cout << "CS11 Score: ";
    cin >> cs11;

    cout << "CS12 Score: ";
    cin >> cs12;

    cout << "CS22 Score: ";
    cin >> cs22;

    //calculate average and total scores for the classes
    totalScore = (cs11 + cs12 + cs22);
    averageScore = totalScore / 3;

    //if-else loop to calculate average grade 
    if (averageScore >= 90) {
        grade = "A";
    } else if (averageScore < 90 && averageScore >= 80) {
        grade = "B";
    } else if (averageScore < 80 && averageScore >= 70) {
        grade = "C";
    } else if (averageScore < 70 && averageScore >= 60) {
        grade = "C";
    } else if (averageScore < 60) {
        grade = "D";
    } else {
        cout << "Grade could not be determined." << endl;
    }

    //display all user input, setting average grade to 2 decimal places
    cout << "=====================" << endl;
    cout << "Student Grading System (SGS)" << endl;
    cout << "Long Beach City College" << endl;
    cout << "Author: Polina Chetnikova" << endl;
    cout << "29 June 2025" << endl;

    cout << "=====================" << endl;
    cout << "ID: " << id << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Total: " << totalScore << endl;
    cout << "Average: " << fixed << setprecision(2) << averageScore << "%" << endl;
    cout << "Grade: " << grade << endl;
    cout << "Congratulations on your achievements!" << endl;
    cout << "=====================" << endl;

    return 0;
}
