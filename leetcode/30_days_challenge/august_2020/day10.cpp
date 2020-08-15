/****************************************************
Date: July 10th

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
    Q: Excel Sheet Column Number

    Given a column title as appear in an Excel sheet, return its corresponding column number.

    For example:
        A -> 1
        B -> 2
        C -> 3
        ...
        Z -> 26
        AA -> 27
        AB -> 28 
        ...
    
    Example 1:
        Input: "A"
        Output: 1
    
    Example 2:
        Input: "AB"
        Output: 28
    
    Example 3:
        Input: "ZY"
        Output: 701
 
    Constraints:
        1 <= s.length <= 7
        s consists only of uppercase English letters.
        s is between "A" and "FXSHRXW".
*/

class Solution
{
public:
    int titleToNumber(string s)
    {
        int l = s.size();
        int ans = 0;
        long long base = 1;
        for (int i = l - 1; i >= 0; --i)
        {
            ans += (base * (s[i] - 'A' + 1));
            if (base > 0)
            {
                base *= 26;
            }
        }

        return ans;
    }
};