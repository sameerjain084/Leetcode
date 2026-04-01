/*
========================================
Problem: Majority Element (LC #169)
========================================

Problem Statement:
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Approach Used:
Boyer–Moore Voting Algorithm
- Maintain a candidate element and a frequency counter.
- If the frequency becomes 0, choose the current element as the new candidate.
- If the current element matches the candidate, increment frequency.
- Otherwise, decrement frequency.
- The final candidate will be the majority element.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)

Why This Approach?
Since the majority element appears more than n/2 times, it will always remain
as the final candidate after canceling out all other elements.

Concepts Used:
Arrays, Greedy Strategy, Voting Algorithm

Problem Link:
https://leetcode.com/problems/majority-element/
========================================
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq=0,ans=0;
        for(int i=0;i<n;i++) {
            if (freq==0) {
                ans=nums[i];
            }
            if(ans==nums[i]) {
                freq++;
            } else {
                freq--;
            }
        }
       return ans;

    }
};
