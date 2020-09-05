/****************************************************
Date: Sept 1st

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
    Q: Largest Time for Given Digits

    Given an array of 4 digits, return the largest 24 hour time that can be made.
    The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, 
    a time is larger if more time has elapsed since midnight.

    Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

    Example 1:
        Input: A = [1,2,3,4]
        Output: "23:41"
    
    Example 2:
        Input: A = [5,5,5,5]
        Output: ""
    
    Example 3:
        Input: A = [0,0,0,0]
        Output: "00:00"
    
    Example 4:
        Input: A = [0,0,1,0]
        Output: "10:00"
    
    Constraints:
        arr.length == 4
        0 <= arr[i] <= 9
*/

class Solution
{
private:
    void appendMins(string &ans, vector<int> &f)
    {
        for (int m = 5; m >= 0; --m)
        {
            if (f[m] > 0)
            {
                for (int i = 9; i >= 0; --i)
                {
                    if (f[i] > 0)
                    {
                        if (i == m && f[i] <= 1)
                        {
                            continue;
                        }

                        ans += std::to_string(m);
                        ans += std::to_string(i);
                        f[m]--;
                        f[i]--;

                        return;
                    }
                }
            }
        }
    }

    void addHours(string &ans, vector<int> &f)
    {
        int hl = 2;
        if ((f[9] + f[8] + f[7] + f[6]) > 1)
        {
            hl = 1;
        }

        for (int h = hl; h >= 0; --h)
        {
            int ul = (h == 2) ? 3 : 9;
            if (f[h] > 0)
            {
                for (int i = ul; i >= 0; --i)
                {
                    if (f[i] > 0)
                    {
                        if (i == h && f[i] <= 1)
                        {
                            continue;
                        }

                        ans += std::to_string(h);
                        ans += std::to_string(i);
                        ans += ":";
                        f[h]--;
                        f[i]--;

                        return;
                    }
                }
            }
        }
    }

public:
    string largestTimeFromDigits(vector<int> &arr)
    {
        vector<int> f(10, 0);
        for (int n : arr)
        {
            f[n]++;
        }

        string ans = "";
        addHours(ans, f);
        appendMins(ans, f);

        return ans.size() != 5 ? "" : ans;
    }
};