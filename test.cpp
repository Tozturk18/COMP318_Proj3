/**
 * @file test.c
 * @author Ozgur Tuna Ozturk (ozturk_ozgur@wheatoncollege.edu)
 * @brief This is the test file for the changeMaker program.
 * It tests the greedyPlan and dynamicPlan functions in the changeMaker.cpp file.
 * Uses Google Test framework for testing.
 * You can add more test conditions below...
 * @version 0.1
 * @date 2024-05-04
 * 
 * @copyright MIT Copyright (c) 2024
 * 
 */

/* --- IMPORTS --- */
#include <gtest/gtest.h>
#include "changeMaker.h"
#include <chrono>
/* --- End of IMPORTS --- */

// Test for greedyPlan function
TEST(GreedyPlanTest, TestGreedyPlan) {
    // Test cases
    std::vector<std::pair<int, std::vector<int>>> testCases = {
        {123456, {41, 6, 4, 5, 0, 1}},      // Expected result for $123456 is {1:41, 101:6, 701:4, 5001:5, 320001:0, 95000:1}
        {5000, {93, 0, 7, 0, 0, 0}},        // Expected result for $5000 is {1:93, 101:0, 701:7, 5001:0, 320001:0, 95000:0}
        {10000, {92, 0, 7, 1, 0, 0}},       // Expected result for $10000 is {1:92, 101:0, 701:7, 5001:1, 320001:0, 95000:0}
        {15000, {91, 0, 7, 2, 0, 0}},       // Expected result for $15000 is {1:91, 101:0, 701:7, 5001:2, 320001:0, 95000:0}
        {20000, {90, 0, 7, 3, 0, 0}},       // Expected result for $20000 is {1:90, 101:0, 701:7, 5001:3, 320001:0, 95000:0}
        {25000, {89, 0, 7, 4, 0, 0}},       // Expected result for $25000 is {1:89, 101:0, 701:7, 5001:4, 320001:0, 95000:0}
        {96003, {100, 2, 1, 0, 0, 1}}       // Expected result for $96003 is {1:100, 101:2, 701:1, 5001:0, 320001:0, 95000:1}
    };

    // Test each case
    for (const auto& testCase : testCases) {
        auto start = std::chrono::high_resolution_clock::now(); // Start the timer
        std::vector<int> result = greedyPlan(testCase.first);   // Run the function
        auto end = std::chrono::high_resolution_clock::now();   // End the timer
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); // Calculate the duration
        EXPECT_EQ(result, testCase.second); // Check if the result is correct
        std::cout << "TestGreedyPlan took " << duration.count() << " microseconds for $" << testCase.first <<".\n"; // Print the duration
    }
}

// Test for dynamicPlan function
TEST(DynamicPlanTest, TestDynamicPlan) {
    // Test cases
    std::vector<std::pair<int, std::vector<int>>> testCases = {
        {123456, {42, 3, 3, 5, 3, 0}},      // Expected result for $123456 is {1:42, 101:3, 701:3, 5001:5, 320001:3, 95000:0}
        {5000, {93, 0, 7, 0, 0, 0}},        // Expected result for $5000 is {1:93, 101:0, 701:7, 5001:0, 320001:0, 95000:0}
        {10000, {92, 0, 7, 1, 0, 0}},       // Expected result for $10000 is {1:92, 101:0, 701:7, 5001:1, 320001:0, 95000:0}
        {15000, {91, 0, 7, 2, 0, 0}},       // Expected result for $15000 is {1:91, 101:0, 701:7, 5001:2, 320001:0, 95000:0}
        {20000, {90, 0, 7, 3, 0, 0}},       // Expected result for $20000 is {1:90, 101:0, 701:7, 5001:3, 320001:0, 95000:0}
        {25000, {89, 0, 7, 4, 0, 0}},       // Expected result for $25000 is {1:89, 101:0, 701:7, 5001:4, 320001:0, 95000:0}
        {96003, {0, 0, 0, 0, 3, 0}}         // Expected result for $96003 is {1:0, 101:0, 701:0, 5001:0, 320001:3, 95000:0}
    };

    // Test each case
    for (const auto& testCase : testCases) {
        auto start = std::chrono::high_resolution_clock::now(); // Start the timer
        std::vector<int> result = dynamicPlan(testCase.first);
        auto end = std::chrono::high_resolution_clock::now();   // End the timer
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); // Calculate the duration
        EXPECT_EQ(result, testCase.second);
        std::cout << "TestDynamicPlan took " << duration.count() << " microseconds for $" << testCase.first <<".\n"; // Print the duration
    }
}

// Entry point for the program
int main(int argc, char **argv) {
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);
    // Run tests
    return RUN_ALL_TESTS();
}
