/**
 * @file changeMaker.cpp
 * @author Ozgur Tuna Ozturk (ozturk_ozgur@wheatoncollege.edu)
 * @brief This is the implementation file for the changeMaker.h file.
 * It contains the implementations of the functions in the changeMaker.h file such as
 * greedyPlan function and dynamicPlan function.
 * @version 0.1
 * @date 2024-05-04
 * 
 * @copyright MIT Copyright (c) 2024
 * 
 */

/* --- IMPORTS --- */
#include "changeMaker.h"
#include <vector>
/* --- End of IMPORTS --- */

/**
 * @brief This function calculates the change plan using the greedy algorithm.
 * It takes the amount of change as input and returns  the number of bills of each denomination.
 * It calculates the change plan by using the largest denomination that is less than or equal to the remaining amount.
 * 
 * @param amount The amount of change that needs to be made
 * @return A vector of integers that represents the the number of bills of each denomination
 */
std::vector<int> greedyPlan(int amount) {

    // Create a ChangePlan object
    ChangePlan billsPlan;

    // Initialize a vector to store the number of each bill
    std::vector<int> numBills(billsPlan.plan.size(),0);

    // While there is still amount left
    while (amount > 0) {
        // If the amount is greater than or equal to the value of the largest bill
        if (amount >= billsPlan.plan[5]) {
            numBills[5]++;  // Use the largest bill
            amount -= billsPlan.plan[5];  // Subtract the value of the largest bill from the amount
        } 
        // If the amount is greater than or equal to the value of the second largest bill
        else if (amount >= billsPlan.plan[4]) {
            numBills[4]++;  // Use the second largest bill
            amount -= billsPlan.plan[4];  // Subtract the value of the second largest bill from the amount
        } 
        // Repeat for the rest of the bills
        else if (amount >= billsPlan.plan[3]) {
            numBills[3]++;
            amount -= billsPlan.plan[3];
        } else if (amount >= billsPlan.plan[2]) {
            numBills[2]++;
            amount -= billsPlan.plan[2];
        } else if (amount >= billsPlan.plan[1]) {
            numBills[1]++;
            amount -= billsPlan.plan[1];
        } 
        // If the amount is less than the value of the second smallest bill
        else {
            numBills[0] = amount;  // Use the smallest bill for the remaining amount
            amount = 0;  // Set the amount to 0
        }
    }

    // Return the change plan
    return numBills;
}

/**
 * @brief This function calculates the change plan using the dynamic programming algorithm.
 * It takes the amount of change as input and returns the number of bills of each denomination.
 * It calculates the change plan by using the smallest number of coins possible.
 * 
 * @param amount The amount of change that needs to be made
 * @return A vector of integers that represents the the number of bills of each denomination
 */
std::vector<int> dynamicPlan(int amount) {

    // Create a ChangePlan object
    ChangePlan billsPlan;

    // Get the number of different bill denominations
    int numDenominations = billsPlan.plan.size();

    // Initialize a dp array with maximum values. dp[i] will store the minimum number of bills needed to make change for amount i.
    std::vector<int> dp(amount + 1, INT_MAX);

    // Initialize a 2D array to keep track of the count of each bill denomination for each amount.
    std::vector<std::vector<int> > count(amount + 1, std::vector<int>(numDenominations, 0));

    // Base case: 0 bills are needed for 0 amount
    dp[0] = 0;

    // Bottom-up dynamic programming approach
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < numDenominations; ++j) {
            // If the current amount can be made by using the j-th bill denomination
            // and the number of bills needed is less than the current minimum
            if (i - billsPlan.plan[j] >= 0 && dp[i - billsPlan.plan[j]] + 1 < dp[i]) {
                // Update the minimum number of bills needed
                dp[i] = dp[i - billsPlan.plan[j]] + 1;

                // Update the count of each bill denomination
                count[i] = count[i - billsPlan.plan[j]];
                count[i][j]++;
            }
        }
    }

    // Update the total number of bills needed
    billsPlan.totalBills = dp[amount];

    // Return the count of each bill denomination for the given amount
    return count[amount];
  }