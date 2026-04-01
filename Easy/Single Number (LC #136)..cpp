/*
=====================================
Problem: Single Number (LC #136)
=====================================

Problem Statement:
Given a non-empty array of integers nums, every element appears exactly twice
except for one element which appears exactly once. Find that single element
and return it.

You must implement a solution with linear runtime complexity and use only
constant extra space.

Approach Used:
Bit Manipulation (XOR)
- Initialize ans = 0.
- Traverse through the array and XOR each element with ans.
- Since a ^ a = 0, duplicate elements cancel out.
- Since a ^ 0 = a, the remaining value is the single number.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)

Why This Approach?
XOR operation efficiently eliminates duplicate elements and retains the
unique element, making it the most optimal solution.

Concepts Used:
Bit Manipulation, XOR Operation

Problem Link:
https://leetcode.com/problems/single-number/
=====================================
*/

class Solution {
public:
    int singleNumber(vector<int> &nums) {
     int ans =0 ;
     for(int val :nums) {
         ans=ans^val;
     }
     return ans;
    }
};
