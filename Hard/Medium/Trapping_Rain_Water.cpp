
/*
========================================
Problem: Trapping Rain Water (LC #42)
========================================

Problem Statement:
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it can trap after raining.

Approach Used:
Prefix Maximum Arrays
- Precompute the maximum height to the left of each index.
- Precompute the maximum height to the right of each index.
- Water trapped at index i = min(leftMax[i], rightMax[i]) - height[i]
- Sum the trapped water for all indices.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(n)

Why This Approach?
Water trapped at any index depends on the minimum of the tallest bars on its
left and right. Precomputing these values allows efficient calculation
in linear time.

Concepts Used:
Arrays, Prefix Maximum, Dynamic Programming

Problem Link:
https://leetcode.com/problems/trapping-rain-water/
========================================
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax[20000], rightmax[20000];

        leftmax[0] = height[0];
        rightmax[n - 1] = height[n - 1];

        for(int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        for(int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }

        int watertrapped = 0;
        for(int i = 0; i < n; i++) {
            int currwater = min(leftmax[i], rightmax[i]) - height[i];
            if(currwater > 0) {
                watertrapped += currwater;
            }
        }

        return watertrapped;
    }
};
