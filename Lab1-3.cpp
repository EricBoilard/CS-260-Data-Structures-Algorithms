//============================================================================
// Name        : Lab1-3.cpp
// Author      : Eric Boilard
// Course/Date : CS-260 Data Structures and Algorithms 3/5/21
// Project #   : 1
// Description : This lab runs a program that displays a menu to the user. When the menu is displayed there are 3 options,
// 1 to enter a bid, 2 to display the bid, and 9 to exit. The user should be able to enter a bid, display it, and exit the
// program successfully.
//============================================================================

#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

double strToDouble(string str, char ch); //Declaring strToDouble

// FIXME (1): Define a data structure to hold bid information together as a single unit of storage.
struct Bid {              //Defined a data structure called Bid
	string title;         // Initiated variables for each data type that will be entered
	string fund;
	string vehicle;
	double amount;
};

// FIXME (4): Display the bid values passed in data structure
/**
 * Display the bid information
 *
 * @param ?type? data structure containing the bid info
 */
void displayBid(Bid bid) {
    cout << "Title: " << bid.title << endl; //menu displays new values for all variables in Bid
    cout << "Fund: " << bid.fund << endl;
    cout << "Vehicle: " << bid.vehicle << endl;
    cout << "Bid Amount: " << bid.amount << endl;

    return;
}

// FIXME (3): Store input values in data structure
/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */
Bid getBid() {
    Bid someBid;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, someBid.title); //value is assigned to title from bid through Bid someBid

    cout << "Enter fund: ";
    cin >> someBid.fund; //value is assigned to fund in Bid

    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, someBid.vehicle); //value is assigned to vehicle in Bid

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    someBid.amount = strToDouble(strAmount, '$'); //value is assigned to amount in bid and then converted

    return someBid;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


/**
 * The one and only main() method
 */
int main() {

    // FIXME (2): Declare instance of data structure to hold bid information
	Bid theBid;

    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;           // This menu is checking to see what the input is using a loop
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // FIXME (5): Complete the method calls then test the program
        switch (choice) {
            case 1:
            	theBid = getBid(); //Calls the getBid function which obtains the choices of the user
                break;
            case 2:
                displayBid(theBid); //Calls the displayBid method
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
