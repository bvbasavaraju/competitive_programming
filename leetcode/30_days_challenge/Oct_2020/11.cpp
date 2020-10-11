/****************************************************
Date: Oct 11th

link: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3488/
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
    Q: Remove Duplicate Letters

    Given a string s, remove duplicate letters so that every letter appears once and only once. 
    You must make sure your result is the smallest in lexicographical order among all possible results.

    Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

    Example 1:
        Input: s = "bcabc"
        Output: "abc"
    
    Example 2:
        Input: s = "cbacdcbc"
        Output: "acdb"

    Constraints:
        1 <= s.length <= 104
        s consists of lowercase English letters.

    Hide Hint #1  
        Greedily try to add one missing character. How to check if adding some character will not cause problems ? 
        Use bit-masks to check whether you will be able to complete the sub-sequence if you add the character at some index i.
*/

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> ch_freq(26, 0);
        for (int ch : s)
        {
            ch_freq[ch - 'a']++;
        }

        string ans;
        for (char ch : s)
        {
            while (!ans.empty() && (ans.back() > ch) && (ch_freq[ans.back() - 'a'] > 0) && (ans.find(ch) == std::string::npos))
            {
                ans.pop_back();
            }

            if (ans.find(ch) == std::string::npos)
            {
                ans.push_back(ch);
            }

            ch_freq[ch - 'a']--;
        }

        return ans;
    }
};