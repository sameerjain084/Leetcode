/*
========================================
Problem: Palindrome Number (LC #9)
========================================

Problem Statement:
Given an integer x, return true if x is a palindrome, and false otherwise.

An integer is a palindrome when it reads the same backward as forward.

Approach Used:
Reverse Number
- If the number is negative, return false.
- Reverse the digits of the number.
- Compare the reversed number with the original number.

Complexity Analysis:
Time Complexity: O(log n)
Space Complexity: O(1)

Why This Approach?
Reversing the number allows us to directly compare it with the original,
making it simple and efficient without using extra space.

Concepts Used:
Math, Number Manipulation

Problem Link:
https://leetcode.com/problems/palindrome-number/
========================================
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        long long rev=0;
        int original =x;
        while(x>0) {
            rev = rev * 10 + x % 10;
            x/=10;
        }
        return original==rev;
        
    }
};
