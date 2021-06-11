// Item Shipping Calculator.cpp
// Darren Cronover

//libraries to include
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

//declare constants
const int WIDTH = 50;
const string STR1 = "ITCS 2530 - Programming Assignment for week #3\n";
const string STR2 = "Please enter the item name (no spaces)";
const string STR3 = "Is the item fragile? (y=yes/n=no)";
const string STR4 = "Please enter your order total";
const string STR5 = "Please enter destination. (usa/can/aus/saturn)";
const string STR6 = "Your item is";
const string STR7 = "Your shipping cost is";
const string STR8 = "Your are shipping to";
const string STR9 = "Your total shipping costs are";
const string STR10 = "Thank you!";


int main()
{
    //create the variable and open the file
    fstream writeFile;
    writeFile.open("Order.txt", ios::out); // write mode

    //declare variables
    string itemName;
    string isFragile;
    float fOrderTotal;
    string destination;
    float fShippingCost = 0.0;
    float fTCost;

    //use format manipulators to beautify the console
    cout << setfill('.') << setw(WIDTH) << ' ' << endl; // fills the spaces with asterisks
    cout << setprecision(2) << fixed;

    cout << STR1;
    cout << setw(WIDTH) << ' ' << endl;
    cout << "\n";

    //subtracts the string length from the width to keep the alignment pretty
    cout << STR2 << setw(WIDTH - STR2.length()) << ":";
    cin >> itemName;
    //transforms the string into uppercase
    transform(itemName.begin(), itemName.end(), itemName.begin(), toupper);

    cout << STR3 << setw(WIDTH - STR3.length()) << ":";
    cin >> isFragile;
    transform(isFragile.begin(), isFragile.end(), isFragile.begin(), toupper);
    
    // if the input is not y/Y or n/N, the program exits.
    if (isFragile != "Y" and isFragile != "N") {
        cout << "\n";
        cout << "Invalid entry, exiting" << endl;
        writeFile << "\n";
        writeFile << "Invalid entry, exiting" << endl;
        system("pause");
        return 0;
    }

    cout << STR4 << setw(WIDTH - STR4.length()) << ":";
    cin >> fOrderTotal;

    cout << STR5 << setw(WIDTH - STR5.length()) << ":";
    cin >> destination;
    transform(destination.begin(), destination.end(), destination.begin(), toupper);

    if (destination != "AUS" and destination != "USA" and destination != "CAN" and destination != "SATURN") {
        cout << "\n";
        cout << "Invalid entry, exiting" << endl;
        system("pause");
        return 0;
    }
    //determines the shipping cost based on the order total $ and order destination
    if (fOrderTotal < 150.0) {
        if (fOrderTotal > 100.0) {
            if (destination == "USA") {
                fShippingCost = 12.0;
            }
            if (destination == "CAN") {
                fShippingCost = 15.0;
            }
            if (destination == "AUS") {
                fShippingCost = 17.0;
            }
            if (destination == "SATURN") {
                fShippingCost = 150.0;
            }
        }
        else if (fOrderTotal > 50.0) {
            if (destination == "USA") {
                fShippingCost = 9.0;
            }
            if (destination == "CAN") {
                fShippingCost = 12.0;
            }
            if (destination == "AUS") {
                fShippingCost = 14.0;
            }
            if (destination == "SATURN") {
                fShippingCost = 100.0;
            }
        }
        else {
            if (destination == "USA") {
                fShippingCost = 6.0;
            }
            if (destination == "CAN") {
                fShippingCost = 8.0;
            }
            if (destination == "AUS") {
                fShippingCost = 10.0;
            }
            if (destination == "SATURN") {
                fShippingCost = 75.0;
            }
        }
    }
    //adds 2 to the shipping cost of the item is fragile
    if (isFragile == "Y") {
        fShippingCost = fShippingCost + 2.0;
    }

    fTCost = fShippingCost + fOrderTotal;
    
    //output the results to the code window, the "1 +" is added to account for the $ displayed before certain values
    cout << "\n";
    cout << STR6 << setw(WIDTH - STR6.length() - itemName.length()) << "." << itemName << endl;
    cout << STR7 << setw(1 + WIDTH - STR7.length() - itemName.length()) << "$" << fShippingCost << endl;
    cout << STR8 << setw(WIDTH - STR8.length() - itemName.length()) << "." << destination << endl;
    cout << STR9 << setw(1 + WIDTH - STR9.length() - itemName.length()) << "$" << fTCost << endl;
    cout << "\n";
    cout << setfill('-') << setw(WIDTH) << STR10 << endl;

    //output the results to the file
    writeFile << STR6 << setw(WIDTH - STR6.length() - itemName.length()) << "." << itemName << endl;
    writeFile << STR7 << setw(1 + WIDTH - STR7.length() - itemName.length()) << "$" << fShippingCost << endl;
    writeFile << STR8 << setw(WIDTH - STR8.length() - itemName.length()) << "." << destination << endl;
    writeFile << STR9 << setw(1 + WIDTH - STR9.length() - itemName.length()) << "$" << fTCost << endl;
    writeFile << "\n";
    writeFile << setfill('-') << setw(WIDTH) << STR10 << endl;
    
    //close the file
    writeFile.close();

    system("pause");
    return 0;
}
