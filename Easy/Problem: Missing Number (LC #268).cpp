/*
========================================
Problem: Missing Number (LC #268)
========================================

Problem Statement:
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Approach Used:
Mathematical Formula (Sum of First n Numbers)
- Calculate the expected sum of numbers from 0 to n using:
  n * (n + 1) / 2
- Compute the actual sum of elements in the array.
- The missing number is the difference between expected sum and actual sum.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)

Why This Approach?
Using the mathematical formula allows us to find the missing number efficiently
without sorting or extra space.

Concepts Used:
Arrays, Math

Problem Link:
https://leetcode.com/problems/missing-number/
========================================
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
       int actualsum =0;
       int expectedsum = n*(n+1)/2;
       for(int num:nums) {
        actualsum+=num;
       } 
       return expectedsum - actualsum;
    }
};
