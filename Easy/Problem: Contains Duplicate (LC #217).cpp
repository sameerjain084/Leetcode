/*
========================================
Problem: Contains Duplicate (LC #217)
========================================

Problem Statement:
Given an integer array nums, return true if any value appears at least twice
in the array, and return false if every element is distinct.

Approach Used:
Sorting
- Sort the array in non-decreasing order.
- Traverse the array and compare adjacent elements.
- If any two consecutive elements are equal, a duplicate exists.

Complexity Analysis:
Time Complexity: O(n log n)
Space Complexity: O(1) (ignoring sorting space)

Why This Approach?
Sorting brings duplicate elements next to each other, making it easy to detect
duplicates in a single pass.

Concepts Used:
Arrays, Sorting

Problem Link:
https://leetcode.com/problems/contains-duplicate/
========================================
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};
