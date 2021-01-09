/****************************************************
Date: July 11th

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3417/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>
#include <set>

using namespace std;

/*
    Q: Longest Palindrome

    Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
    This is case sensitive, for example "Aa" is not considered a palindrome here.

    Note:
        Assume the length of given string will not exceed 1,010.

    Example:
        Input:
        "abccccdd"

    Output:
        7

    Explanation:
        One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<int, int> freq;
        for (auto ch : s)
        {
            freq[ch]++;
        }

        int even_count = 0;
        int odd_count = 0;
        bool add_one = false;
        for (auto it = freq.begin(); it != freq.end(); ++it)
        {
            if (it->second % 2 == 0)
            {
                even_count += it->second;
            }
            else
            {
                add_one = true;
                odd_count += (it->second - 1);
            }
        }

        return (add_one != false) ? even_count + odd_count + 1 : even_count;
    }
};