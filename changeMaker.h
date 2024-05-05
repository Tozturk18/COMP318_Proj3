/**
 * @file changeMaker.h
 * @author Ozgur Tuna Ozturk (ozturk_ozgur@wheatoncollege.edu)
 * @brief This is the header file for the changeMaker.cpp file. 
 * It contains the function prototypes for the functions in the changeMaker.cpp file such as
 * greedyPlan function and dynamicPlan function. This header file also defines a class called ChangePlan.
 * @version 0.1
 * @date 2024-05-04
 * 
 * @copyright MIT Copyright (c) 2024
 * 
 */

#ifndef CHANGEMAKER_H

#define CHANGEMAKER_H

#include <vector>

/**
 * @brief This class is used to store the change plan that is calculated by the greedyPlan and dynamicPlan functions.
 * It contains the number of bills of each denomination that is used to make the change and the total number of bills used.
 * 
 */
class ChangePlan {
    public:
        std::vector<int> plan = {1, 101, 701, 5001, 32001, 95000};  // number of bills of each denomination
        int totalBills = 0;                                         // total number of bills used
};

/**
 * @brief This function calculates the change plan using the greedy algorithm.
 * It takes the amount of change as input and returns  the number of bills of each denomination.
 * It calculates the change plan by using the largest denomination that is less than or equal to the remaining amount.
 * 
 * @param amount The amount of change that needs to be made
 * @return A vector of integers that represents the the number of bills of each denomination
 */
std::vector<int> greedyPlan(int amount);

/**
 * @brief This function calculates the change plan using the dynamic programming algorithm.
 * It takes the amount of change as input and returns the number of bills of each denomination.
 * It calculates the change plan by using the smallest number of coins possible.
 * 
 * @param amount The amount of change that needs to be made
 * @return A vector of integers that represents the the number of bills of each denomination
 */
std::vector<int> dynamicPlan(int amount);

#endif // CHANGEMAKER_H
