/****************************************************
Date: July 1st

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/
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
    Q:  Detect Capital

    Given a word, you need to judge whether the usage of capitals in it is right or not.
    We define the usage of capitals in a word to be right when one of the following cases holds:
        + All letters in this word are capitals, like "USA".
        + All letters in this word are not capitals, like "leetcode".
        + Only the first letter in this word is capital, like "Google".

    Otherwise, we define that this word doesn't use capitals in a right way.

    Example 1:
        Input: "USA"
        Output: True

    Example 2:
        Input: "FlaG"
        Output: False

    Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        unordered_map<int, int> freq;
        for (auto ch : word)
        {
            freq[ch]++;
        }

        int count = 0;
        for (int i = 'A'; i <= 'Z'; ++i)
        {
            count += freq[i];
        }

        return (count == 0 || count == word.size()) ? true : (((count == 1) && (word[0] - 'A' <= 26)) ? true : false);
    }
};