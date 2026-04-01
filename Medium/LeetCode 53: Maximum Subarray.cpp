/*
========================================
Problem: Maximum Subarray (LC #53)
========================================

Problem Statement:
Given an integer array nums, find the contiguous subarray (containing at least
one number) which has the largest sum and return its sum.

Approach Used:
Kadane’s Algorithm
- Maintain a running sum of the current subarray.
- Add each element to the current sum.
- Update the maximum subarray sum at each step.
- If the current sum becomes negative, reset it to 0.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)

Why This Approach?
Kadane’s Algorithm efficiently finds the maximum subarray sum in a single pass
by discarding subarrays with negative sums that cannot contribute to the
optimal solution.

Concepts Used:
Arrays, Dynamic Programming, Greedy Strategy

Problem Link:
https://leetcode.com/problems/maximum-subarray/
========================================
*/

lass Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum=0,totalsum=INT_MIN;
        for(int val:nums) {
            currentsum+=val;
            totalsum=max(currentsum,totalsum);
            if(currentsum<0) {
                currentsum=0;
            }
        }
        return totalsum ;
    }
};
