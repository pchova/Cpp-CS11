/*  Polina Chetnikova
    Project 8 - Structs
    CS11 Summer 2025 - LBCC
    3 August 2025
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;

//Struct
struct menuItemType {
    string menuItem;
    double menuPrice;
};

//Function Prototypes
void getData(menuItemType menuList[]);
void showMenu(menuItemType menuList[], menuItemType myOrder[], int& itemCount);
void printCheck(menuItemType myOrder[], int itemCount);

/* Main function */
int main() {
    int itemCount = 0;
    struct menuItemType menuList[8];
    struct menuItemType myOrder[8];

    getData(menuList);
    showMenu(menuList, myOrder, itemCount);
    printCheck(myOrder, itemCount);

    return 0;
}

/*  Function getData() - this function loads the data into
    the array menuList
*/
void getData(menuItemType menuList[]) {
    string item;
    string price;

    //read data from the file
    ifstream input("menu-data.txt");
    if (!input) {
        cerr << "Failed to open file." << endl;
        return;
    }

    for(int i = 0; i < 8; i++) {
        getline(input, item);
        replace(item.begin(), item.end(), '_', ' ');
        menuList[i].menuItem = item;

        getline(input, price);
        menuList[i].menuPrice = stod(price);
    }

    input.close();
}


/*  Function showMenu() - this function shows the different items
    on the menu and tells the user how to select items
*/
void showMenu(menuItemType menuList[], menuItemType myOrder[], int& itemCount) {
    int orderNum = int();
    bool flag = true;

    cout << "Breakfast Menu" << endl;
    cout << fixed << setprecision(2);
    for(int i = 0; i < 8; i++){
        cout << (i + 1) << ". " << left << setw(20) << menuList[i].menuItem << menuList[i].menuPrice << endl;
    }

    cout << endl;
    cout << "Max items per order is 8 items. Please input each number one at a time. " << endl;
    cout << "Please type the number for the item you'd like to order: ";
    cin >> orderNum;

    if (orderNum < 1 || orderNum > 8) {
        cout << "Invalid item number. Please try again." << endl;
        cout << "Please type the number for the item you'd like to order: ";
        cin >> orderNum;
    }


    myOrder[itemCount].menuItem = menuList[orderNum-1].menuItem;
    myOrder[itemCount].menuPrice = menuList[orderNum-1].menuPrice;

    cout << myOrder[itemCount].menuItem << "\t\t" << myOrder[itemCount].menuPrice << endl;
    cout << endl;

    itemCount++;

    while (flag) {
        if (itemCount >= 8) {
            cout << "You've reached the maximum of 8 items. Calculating check...\n";
            break;
        }

        string choice;
        cout << "Do you want to order another item? (y/n): ";
        cin >> choice;

        if (choice == "y" || choice == "Y" || choice == "yes") {
            cout << "Please type in the number for the item you'd like to order: ";
            cin >> orderNum;

            if (orderNum < 1 || orderNum > 8) {
                cout << "Invalid item number. Please try again.\n";
                cout << endl;
                continue;   //this skips to next loop iteration
            }


            if (itemCount < 8) {
                myOrder[itemCount].menuItem = menuList[orderNum-1].menuItem;
                myOrder[itemCount].menuPrice = menuList[orderNum-1].menuPrice;

                cout << myOrder[itemCount].menuItem << "\t\t" << myOrder[itemCount].menuPrice << endl;
                cout << endl;

                itemCount++;
            }

            if (itemCount >= 8) {
                cout << "You've reached the maximum of 8 items.\n";
                break;
            }

        } else if (choice == "n" || choice == "N" || choice == "no") {
            flag = false;
            cout << "Thank you for your order. Calculating check...." << endl;;
        }
        else {
            flag = false;
            cout << "Invalid choice. Calculating check.... " << endl;
        }
    }
}

/*  Function printCheck() - this function calculates and prints the check,
    including a 5% tax.
*/
void printCheck(menuItemType myOrder[], int itemCount){
    double sum = 0.0;
    double tax = 0.0;

    cout << endl;
    cout << "Welcome to Polina's Restaurant" << endl;
    for (int i = 0; i < itemCount; i++) {
        cout << left << setw(20) << myOrder[i].menuItem << right << setw(10) << "$" << myOrder[i].menuPrice << endl;

        sum += myOrder[i].menuPrice;
    }

    tax = sum * .05;

    cout << left << setw(20) << "Tax" << right << setw(10) << "$" << tax << endl;
    cout << left << setw(20) << "Amount Due" << right << setw(10) << "$" << sum << endl;
}