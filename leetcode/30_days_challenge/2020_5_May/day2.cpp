/****************************************************
Date: May 2nd

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/
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
    Q: Jewels and Stones
    You're given strings J representing the types of stones that are jewels, and S representing the stones you have.
    Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

    The letters in J are guaranteed distinct, and all characters in J and S are letters.
    Letters are case sensitive, so "a" is considered a different type of stone from "A".

    Example 1:
        Input: J = "aA", S = "aAAbbbb"
        Output: 3

    Example 2:
        Input: J = "z", S = "ZZ"
        Output: 0

    Note:
        S and J will consist of letters and have length at most 50.
        The characters in J are distinct.

   Hide Hint #1  
        For each stone, check if it is a jewel.
*/

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        //Fastest solution!! O(J.size() + S.size())
        unordered_set<int> j;
        for (auto ch : J)
        {
            j.insert(ch);
        }

        int ans = 0;
        for (auto ch : S)
        {
            if (j.count(ch) > 0)
            {
                ans++;
            }
        }

        return ans;

        /* time complexity O(mlongm + nlogn + m * n)
        sort(J.begin(), J.end());
        sort(S.begin(), S.end());
        
        int r = J.size() + 1;a
        int c = S.size() + 1;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        
        for(int i = 1; i < r; ++i)
        {
        for(int j = 1; j < c; ++j)
        {
            int to_add = J[i-1] == S[j-1] ? 1 : 0;
            
            dp[i][j] = to_add + max(dp[i-1][j], dp[i][j-1]);
        }
        }
        
        return dp[r-1][c-1];*/
    }
};