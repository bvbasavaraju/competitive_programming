/****************************************************
Date: Sept 3rd

link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3448/
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

using namespace std;

/*
    Q: Repeated Substring Pattern

    Given a non-empty string check if it can be constructed by taking a substring of it and 
    appending multiple copies of the substring together. You may assume the given string consists 
    of lowercase English letters only and its length will not exceed 10000.

    Example 1:
        Input: "abab"
        Output: True
        Explanation: It's the substring "ab" twice.

    Example 2:
        Input: "aba"
        Output: False

    Example 3:
        Input: "abcabcabcabc"
        Output: True
        Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

class Solution
{
private:
    bool patternCanBeRepeated(const string &sub, const string &str)
    {
        int sl = sub.size();
        int l = str.size();

        if (l % sl != 0)
        {
            return false;
        }

        int m = l / sl;
        for (int i = 0; i < m; ++i)
        {
            string s = str.substr(i * sl, sl);
            if (s != sub)
            {
                return false;
            }
        }

        return true;
    }

public:
    bool repeatedSubstringPattern(string s)
    {
        int l = s.size();

        string sub = "";
        for (int i = 0; i < l / 2; ++i)
        {
            sub += s[i];
            if (patternCanBeRepeated(sub, s))
            {
                return true;
            }
        }

        return false;
    }
};