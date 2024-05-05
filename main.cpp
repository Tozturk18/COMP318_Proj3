/**
 * @file main.cpp
 * @author Ozgur Tuna Ozturk (ozturk_ozgur@wheatoncollege.edu)
 * @brief This is the main file for the changeMaker program.
 * @version 0.1
 * @date 2024-05-04
 * 
 * @copyright MIT Copyright (c) 2024
 * 
 */

/* --- IMPORTS --- */
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include "changeMaker.h"
/* --- End of IMPORTS --- */

/* --- NAMESPACE --- */
using namespace std;
/* --- End of NAMESPACE --- */

/**
 * @brief This is the main function of the program.
 * It takes the user's name and the amount of tax due as input.
 * It calculates the change plan using the greedy algorithm and the dynamic programming algorithm.
 * It then prints the change plan and the total number of bills used for each algorithm.
 * 
 * @return int: 0 if the program runs successfully
 */
int main() {

    // Welcome message
    cout << "Welcome to the IR$ of Banana Republic!" << endl;

    // Get user's name
    cout << "Please enter your name:\t\t";
    std::string name;
    std::getline(std::cin, name);

    // Get tax amount
    int amount;
    bool validInput = false;    // Flag to check if the input is valid
    // Loop until the user enters a valid input
    while (!validInput) {
        cout << "What is your tax $$$ due?\t$";
        cin >> amount;

        if (cin.fail()) {
            cin.clear(); // clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
            cout << "Invalid input. Please enter a positive integer." << endl;
        } else if (amount < 0) {
            cout << "Invalid input. Please enter a positive integer." << endl;
        } else {
            validInput = true; // valid input, break the loop
        }
    }

    // Using the Greedy Approach to calculate how the tax payment shall be made
    cout << endl << "Plan 1: The Greedy Approach" << endl;

    // Print the tax due
    cout << "Tax Due:  " << amount << endl;

    // Create a ChangePlan object
    ChangePlan plan;

    // Calculate the change plan using the greedy algorithm
    vector<int> greedyChangePlan = greedyPlan(amount);

    // Reverse the order of the change plan to fit the assignment requirements
    std::reverse(greedyChangePlan.begin(), greedyChangePlan.end());
    std::reverse(plan.plan.begin(), plan.plan.end());

    // Print the greedy change plan header
    cout << "Greedy Change Plan: " << endl;
    printf("\t%10s   %4s    %10s%10s\n", "Bills", "Num", "", "Subtotal"); // Print the header

    // Print the greedy change plan results
    int subtotal = 0;
    for (int i = 0; i < greedyChangePlan.size(); i++) {
        subtotal += plan.plan[i] * greedyChangePlan[i];
        printf("\t$%9d x %4d = $%10d%10d\n", plan.plan[i], greedyChangePlan[i], plan.plan[i] * greedyChangePlan[i], subtotal);
    }

    // Print the total number of bills needed
    int total = 0;
    cout << "Total number of bills needed: ";
    for (int i = 0; i < greedyChangePlan.size(); i++) {

        // Print the last element without the plus sign
        if (i == greedyChangePlan.size() - 1) {
            cout << greedyChangePlan[i] << " = ";
        } else {
            cout << greedyChangePlan[i] << " + ";
        }

        // Calculate the total number of bills
        total += greedyChangePlan[i];
    }
    cout << total << endl;  // Print the total number of bills
    cout << endl;

    // Print a line to separate the two plans
    for (int i = 0; i < 100; i++) {
        cout << "-";
    }
    cout << endl;

    // Using the Dynamic Approach to calculate how the tax payment shall be made
    cout << "Plan 2: The Dynamic Approach" << endl;

    // Calculate the change plan using the dynamic algorithm
    vector<int> dynamicChangePlan = dynamicPlan(amount);

    // Reverse the order of the change plan to fit the assignment requirements
    std::reverse(dynamicChangePlan.begin(), dynamicChangePlan.end());


    cout << "Dynamic Change Plan: " << endl;
    printf("\t%10s   %4s    %10s%10s\n", "Bills", "Num", "", "Subtotal"); // Print the header

    // Print the greedy change plan results
    subtotal = 0;
    for (int i = 0; i < dynamicChangePlan.size(); i++) {
        subtotal += plan.plan[i] * dynamicChangePlan[i];
        printf("\t$%9d x %4d = $%10d%10d\n", plan.plan[i], dynamicChangePlan[i], plan.plan[i] * dynamicChangePlan[i], subtotal);
    }

    // Print the total number of bills needed
    total = 0;
    cout << "Total number of bills needed: ";
    for (int i = 0; i < dynamicChangePlan.size(); i++) {

        // Print the last element without the plus sign
        if (i == dynamicChangePlan.size() - 1) {
            cout << dynamicChangePlan[i] << " = ";
        } else {
            cout << dynamicChangePlan[i] << " + ";
        }

        // Calculate the total number of bills
        total += dynamicChangePlan[i];
    }
    cout << total << endl;  // Print the total number of bills
    cout << endl;

    // Print a line to separate the two plans
    for (int i = 0; i < 100; i++) {
        cout << "-";
    }
    cout << endl;

    int option;
    validInput = false;    // Flag to check if the input is valid
    // Loop until the user enters a valid input
    while (!validInput) {
    cout << "Which payment plan do you want to choose (Plan 1 or Plan 2)?" << endl;
    cin >> option;

    if (cin.fail() || (option != 1 && option != 2)) {
        cin.clear(); // clear the error flags
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
        cout << "Invalid input. Please enter 1 or 2." << endl;
    } else {
        validInput = true; // valid input, break the loop
    }
}

    // Get the current date
    time_t t = time(0);
    tm* now = localtime(&t);

    cout << "Current Date is: " << now->tm_mon+1 << "/" << now->tm_mday << "/" << now->tm_year+1900 << " ";

    // Check if the date is before or after April 14
    if ((now->tm_mon < 3) || (now->tm_mon == 3 && now->tm_mday <= 14)) {
        cout << "You are on time!!" << endl;
        cout << "Dear " << name << ", thank you for paying your tax ON TIME!" << endl;
    } else {
        cout << "You are late!!" << endl;
        cout << "Dear " << name << ", please try to pay your tax ON TIME next time!" << endl;
    }

    // Print a line to separate the two plans
    for (int i = 0; i < 100; i++) {
        cout << "-";
    }
    cout << endl;

    return 0;
}