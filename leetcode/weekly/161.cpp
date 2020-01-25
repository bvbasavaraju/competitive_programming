/****************************************************
Date: November 3rd, 2019
Successful submissions : 2
Time expiration :
Not Solved : 4  (tired, but too mch tired from outings. So Couldn't solve single problem!)
Wrong Answer/ Partial result : 

link: https://leetcode.com/contest/weekly-contest-161
****************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

/*
    Q: 1247. Minimum Swaps to Make Strings Equal

    You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. 
    Your task is to make these two strings equal to each other. 
    You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].

    Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.

    Example 1:
    Input: s1 = "xx", s2 = "yy"
    Output: 1
    Explanation: 
    Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
    
    Example 2: 
    Input: s1 = "xy", s2 = "yx"
    Output: 2
    Explanation: 
    Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
    Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
    Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
    
    Example 3:
    Input: s1 = "xx", s2 = "xy"
    Output: -1

    Example 4:
    Input: s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
    Output: 4

    Constraints:
    1 <= s1.length, s2.length <= 1000
    s1, s2 only contain 'x' or 'y'.
*/

class Solution_t
{
public:
    int minimumSwap(string s1, string s2)
    {
    }
};

/*
    Q: 1248. Count Number of Nice Subarrays

    Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.
    Return the number of nice sub-arrays.

    Example 1:
    Input: nums = [1,1,2,1,1], k = 3
    Output: 2
    Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

    Example 2:
    Input: nums = [2,4,6], k = 1
    Output: 0
    Explanation: There is no odd numbers in the array.
    
    Example 3:
    Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
    Output: 16

    Constraints:
    1 <= nums.length <= 50000
    1 <= nums[i] <= 10^5
    1 <= k <= nums.length
*/

class Solution2_t
{
private:
    int OddNumCount(const vector<int> &nums)
    {
        int retVal = 0;
        for (int i : nums)
        {
            if (i % 2 != 0)
            {
                retVal++;
            }
        }

        return retVal;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        if (OddNumCount(nums) < k) //initially compared with '!='
        {
            return 0;
        }

        int retVal = 0;
        int count = nums.size();
        for (int i = 0; i < count; i++)
        {
            int currentOddCount = 0;
            int startOddNumPos = -1;
            for (int j = i; j < count; j++)
            {
                if ((nums[j] % 2) != 0)
                {
                    if (startOddNumPos < 0)
                    {
                        startOddNumPos = j;
                    }
                    currentOddCount++;
                }

                if (currentOddCount != k)
                {
                    continue;
                }

                //retVal += j - startOddNumPos + 1;  2. this was default calculation
                if (i == startOddNumPos)
                {
                    retVal++;
                }
                else
                {
                    retVal += j - startOddNumPos + 1;
                    printf("i = %d, j = %d, startOddNumPos = %d, retVal = %d\n", i, j, startOddNumPos, retVal);
                    i = startOddNumPos - 1; // 4. -1 was missing
                }

                break; // 3. this was missing
            }
        }

        return retVal;
    }
};

/*
    Q: 1249. Minimum Remove to Make Valid Parentheses

    Given a string s of '(' , ')' and lowercase English characters. 

    Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
    Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

    Example 1:
    Input: s = "lee(t(c)o)de)"
    Output: "lee(t(c)o)de"
    Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

    Example 2:
    Input: s = "a)b(c)d"
    Output: "ab(c)d"

    Example 3:
    Input: s = "))(("
    Output: ""
    Explanation: An empty string is also valid.

    Example 4:
    Input: s = "(a(b(c)d)"
    Output: "a(b(c)d)"

    Constraints:
    1 <= s.length <= 10^5
    s[i] is one of  '(' , ')' and lowercase English letters.
*/

class Solution3_t
{
public:
    string minRemoveToMakeValid(string s)
    {
        string retVal = s;
        int l = s.length();
        vector<int> openPos;
        vector<int> closePos;
        for (int i = 0; i < l; i++)
        {
            if (s[i] == '(')
            {
                openPos.push_back(i);
            }
            else if (s[i] == ')')
            {
                closePos.push_back(i);
            }
        }

        int openPosCount = openPos.size();
        int closePosCount = closePos.size();
        if (openPosCount == 0)
        {
            return "";
        }

        if (closePosCount == 0)
        {
            return "";
        }

        for (int i = 0; i < closePosCount; i++)
        {
            if (closePos[i] <= openPos[0])
            {
                retVal.erase(closePos[i], 1);
                closePos.erase(closePos.begin() + i);
                closePosCount--;
                i--;
            }
            else
            {
                break;
            }
        }

        for (int i = openPosCount; i > 0; i--)
        {
            if (openPos[i] >= closePos[closePosCount - 1])
            {
                retVal.erase(openPos[i], 1);
                openPos.erase(openPos.begin() + i);
                openPosCount--;
                i--;
            }
        }

        if (openPosCount == 0)
        {
            return "";
        }

        if (closePosCount == 0)
        {
            return "";
        }

        if (openPosCount > closePosCount)
        {
            retVal.erase(openPos[0], 1);
            openPos.erase(openPos.begin());
        }
        else if (closePosCount > openPosCount)
        {
            retVal.erase(closePos[0], 1);
            closePos.erase(closePos.begin());
        }

        return retVal;
    }
};

/*
    Q: 1250. Check If It Is a Good Array

    Given an array nums of positive integers. Your task is to select some subset of nums, 
    multiply each element by an integer and add all these numbers.
    The array is said to be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.

    Return True if the array is good otherwise return False.

    Example 1:
    Input: nums = [12,5,7,23]
    Output: true
    Explanation: Pick numbers 5 and 7.
    5*3 + 7*(-2) = 1

    Example 2:
    Input: nums = [29,6,10]
    Output: true
    Explanation: Pick numbers 29, 6 and 10.
    29*1 + 6*(-3) + 10*(-1) = 1

    Example 3:
    Input: nums = [3,6]
    Output: false

    Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
*/
class Solution4_t
{
public:
    bool isGoodArray(vector<int> &nums)
    {
    }
};

int main()
{
    {
        Solution3_t s3;
        printf("%s\n", s3.minRemoveToMakeValid("lee(t(c)o)de)").c_str());
        printf("%s\n", s3.minRemoveToMakeValid("a)b(c)d").c_str());
        printf("%s\n", s3.minRemoveToMakeValid("))((").c_str());
        printf("%s\n", s3.minRemoveToMakeValid("(a(b(c)d)").c_str());
    }
    return 0;
}