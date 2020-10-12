/****************************************************
Date: Oct 12th

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
    Q: Buddy Strings

    Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

    Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping 
    the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

    Example 1:
        Input: A = "ab", B = "ba"
        Output: true
        Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.
    
    Example 2:
        Input: A = "ab", B = "ab"
        Output: false
        Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.
    
    Example 3:
        Input: A = "aa", B = "aa"
        Output: true
        Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.
    
    Example 4:
        Input: A = "aaaaaaabc", B = "aaaaaaacb"
        Output: true
    
    Example 5:
    Input: A = "", B = "aa"
    Output: false

    Constraints:
        0 <= A.length <= 20000
        0 <= B.length <= 20000
        A and B consist of lowercase letters.
*/
class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        int l = A.size();
        if (l != B.size())
        {
            return false;
        }

        int p1 = -1;
        int p2 = -1;
        bool dup_chars = false;
        vector<int> freq(26, 0);
        for (int i = 0; i < l; ++i)
        {
            if (A[i] != B[i])
            {
                if ((p1 > 0) && (p2 > 0))
                {
                    return false;
                }

                if (p1 < 0)
                {
                    p1 = i;
                }
                else if (p2 < 0)
                {
                    p2 = i;
                }
            }

            freq[A[i] - 'a']++;
            if (freq[A[i] - 'a'] >= 2)
            {
                dup_chars = true;
            }
        }

        if ((p1 < 0) || (p2 < 0))
        {
            if ((A == B) && (dup_chars == true))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int ch = A[p1];
        A[p1] = A[p2];
        A[p2] = ch;

        return (A == B);
    }
};