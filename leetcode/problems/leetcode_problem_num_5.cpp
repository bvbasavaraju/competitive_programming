/*
    5. Longest Palindromic Substring

    Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

    Example 1:
    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.
    
    Input: "cbbd"
    Output: "bb"
*/

#include <iostream>
#include <string>

using namespace std;
class Solution
{
private:
    bool IsPalindrome(const string &source, int firstIndex, int lastIndex, string &result)
    {
        bool retVal = true;
        int f = firstIndex;
        int l = lastIndex;
        while (f <= l)
        {
            if (source[f] != source[l])
            {
                retVal = false;
                break;
            }

            f++;
            l--;
        }

        if (retVal)
        {
            result = source.substr(firstIndex, (lastIndex - firstIndex + 1));
        }

        return retVal;
    }

public:
    string longestPalindrome(string s)
    {
        string retVal;
        int l = s.size();
        for (int i = 0; i < l; i++)
        {
            for (int j = (i + 1); j < l; j++)
            {
                if (s[i] == s[j])
                {
                    string subStr;
                    if (IsPalindrome(s, i, j, subStr))
                    {
                        retVal = (retVal.size() >= subStr.size()) ? retVal : subStr;
                    }
                }
            }

            if (retVal.size() == l)
            {
                break;
            }
        }

        if (retVal.empty() && (l > 0))
        {
            retVal = s.substr(0, 1);
        }

        return retVal;
    }
};