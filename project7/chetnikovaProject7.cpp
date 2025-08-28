/*  Polina Chetnikova
    Project 7 - Strings and Arrays
    CS11 Summer 2025 - LBCC
    27 July 2025
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

// Function Prototypes
void calculatePercentages(int votes[], double percentages[], int sum);
int findWinner(double percentages[]);
void printData(string names[], int votes[], double percentages[], int sum);

int main() {
    string name = string();
    int vote = int();
    int sum = 0;

    string names[5];
    int votes[5] = {0};
    double percentages[5] = {0.0};

    // Read data from file
    ifstream input("votes-data.txt");
    if (!input) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    int i = 0;
    while (input >> name >> vote && i < 5) {
        names[i] = name;
        votes[i] = vote;
        sum += vote;
        i++;
    }
    input.close();

    // Calculate percentages
    calculatePercentages(votes, percentages, sum);

    // Find the winner
    int topIndex = findWinner(percentages);

    // Print all results
    printData(names, votes, percentages, sum);

    // Print winner
    cout << "\nThe winner of the election is " << names[topIndex] << ".\n";

    return 0;
}

/* Functions */
void calculatePercentages(int votes[], double percentages[], int sum) {
    for (int j = 0; j < 5; j++) {
        double perVotes = (static_cast<double>(votes[j]) / sum) * 100;
        percentages[j] = round(perVotes * 100.0) / 100.0;
    }
}

int findWinner(double percentages[]) {
    int topIndex = 0;
    for (int j = 1; j < 5; j++) {
        if (percentages[j] > percentages[topIndex]) {
            topIndex = j;
        }
    }
    return topIndex;
}

void printData(string names[], int votes[], double percentages[], int sum) {
    cout << left << setw(15) << "Candidate"
         << left << setw(20) << "Votes Received"
         << left << setw(20) << "% of Total Votes" << endl << endl;

    for (int i = 0; i < 5; i++) {
        cout << left << setw(20) << names[i]
             << left << setw(13) << votes[i]
             << right << setw(12) << fixed << setprecision(2) << percentages[i] << endl;
    }

    cout << "\n" << left << setw(20) << "Total"
         << left << setw(13) << sum << endl;
}







/* #include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

//Prototypes
void calculatePercentages();
int findWinner();
void printData();


int main() {
    string name = string();
    int vote = int();
    int total = int();
    int sum = 0;

    string names[5] = {""};
    int votes[5] = {0};
    double percentages[5] = {0.0};

    //open file for reading
    ifstream input;
    input.open("votes-data.txt");

    int i = 0;
    while(input >> name >> vote && i < 5) {
        sum += vote;

        names[i] = name;
        votes[i] = vote;

        i++;
    }

    //calculate percentage of votes
    for (int j = 0; j < 5; j++) {
    double perVotes = (static_cast<double>(votes[j]) / sum) * 100;
    percentages[j] = round(perVotes * 100.0) / 100.0;
    }

    //find winner with the most votes
    int topIndex = 0;
    for (int j = 1; j < 5; j++) {
        if (percentages[j] > percentages[topIndex]) {
            topIndex = j;
        }
    }


    //Print the data from the file
    cout << left << setw(15) << "Candidate" << left << setw(20) << "Votes Recieved" << left << setw(20) << "% of Total Votes" << endl;

    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << left << setw(20) << names[i] << left << setw(13) << votes[i] << 
            right << setw(12) << fixed << setprecision(2) << percentages[i] << endl; 
    }

    cout << left << setw(20) << "Total" << left << setw(13) << sum << endl;
    cout << endl;
    cout << "The winner of the election is " << names[topIndex] << "." << endl;


    input.close();
    return 0;
}
 */

