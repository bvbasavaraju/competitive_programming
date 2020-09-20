/****************************************************
Date: Sept 7th

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
    Q: Word Pattern

    Given a pattern and a string s, find if s follows the same pattern.
    Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

    Example 1:
        Input: pattern = "abba", s = "dog cat cat dog"
        Output: true
    
    Example 2:
        Input: pattern = "abba", s = "dog cat cat fish"
        Output: false

    Example 3:
        Input: pattern = "aaaa", s = "dog cat cat dog"
        Output: false

    Example 4:
        Input: pattern = "abba", s = "dog dog dog dog"
        Output: false

    Constraints:
        1 <= pattern.length <= 300
        pattern contains only lower-case English letters.
        1 <= s.length <= 3000
        s contains only lower-case English letters and spaces ' '.
        s does not contain any leading or trailing spaces.
        All the words in s are separated by a single space.
*/
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<int, vector<int>> pat_pos;

        int pos = 0;
        for (int ch : pattern)
        {
            pat_pos[ch].push_back(pos++);
        }

        vector<string> sub_strs;
        unordered_map<string, vector<int>> sub_strs_pos;

        int l = s.size();
        string str = "";
        int wcount = 0;
        for (int i = 0; i < l; ++i)
        {
            if (s[i] == ' ')
            {
                sub_strs.push_back(str);
                sub_strs_pos[str].push_back(wcount++);
                str = "";
            }
            else
            {
                str += s[i];
            }
        }

        if (str.size() > 0)
        {
            sub_strs.push_back(str);
            sub_strs_pos[str].push_back(wcount++);
            str = "";
        }

        for (auto it : pat_pos)
        {
            vector<int> &pat_p = it.second;
            if (pat_p[0] >= sub_strs.size())
            {
                return false;
            }

            vector<int> &w_p = sub_strs_pos[sub_strs[pat_p[0]]];
            if (pat_p != w_p)
            {
                return false;
            }
        }

        return true;
    }
};