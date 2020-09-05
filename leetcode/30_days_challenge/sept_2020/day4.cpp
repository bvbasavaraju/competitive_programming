/****************************************************
Date: Sept 4th

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
    Q: Partition Labels

    A string S of lowercase English letters is given. We want to partition this string into as many parts as possible 
    so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

    Example 1:
        Input: S = "ababcbacadefegdehijhklij"
        Output: [9,7,8]
        Explanation:
            The partition is "ababcbaca", "defegde", "hijhklij".
            This is a partition so that each letter appears in at most one part.
            A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
    

    Note:
        S will have length in range [1, 500].
        S will consist of lowercase English letters ('a' to 'z') only.
*/
class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> freq(26, 0);

        for (int l : S)
        {
            freq[l - 'a']++;
        }

        int l = S.size();
        vector<int> ans;
        vector<int> p;
        unordered_set<int> str;
        for (int i = 0; i < l; ++i)
        {
            int ch = S[i];

            if (str.size() == 0 && i > 0)
            {
                if (p.size() > 0)
                {
                    ans.push_back(i - p.back());
                }
                else
                {
                    ans.push_back(i);
                }
                p.push_back(i);
            }

            freq[ch - 'a']--;
            if (freq[ch - 'a'] == 0)
            {
                str.erase(ch);
            }
            else
            {
                str.insert(ch);
            }
        }

        if (p.size() > 0)
        {
            ans.push_back(l - p.back());
        }
        else
        {
            ans.push_back(l);
        }

        return ans;
    }
};