/****************************************************
Date: October 12, 2019
Successful submissions : 1
Time expiration :
Not Solved : 1
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/weekly-contest-160
****************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

/*  Q: 1237. Find Positive Integer Solution for a Given Equation
*/

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution1_t
{
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
    {
        vector<vector<int>> retVal;
        for (int x = 1; x <= 1000; x++)
        {
            for (int y = 1; y <= 1000; y++)
            {
                if (customfunction.f(x, y) == z)
                {
                    vector<int> pair;
                    pair.push_back(x);
                    pair.push_back(y);

                    retVal.push_back(pair);
                }
            }
        }

        return retVal;
    }
};

/*  Q: 1238. Circular Permutation in Binary Representation
*/

class Solution2_t
{
public:
    vector<int> circularPermutation(int n, int start)
    {
    }
};

/*  Q: 1239. Maximum Length of a Concatenated String with Unique Characters
*/

class Solution3_t
{
private:
    bool isUnique(const string &s)
    {
        int l = s.size();
        map<int, int> charCount;
        for (int i = 0; i < l; i++)
        {
            charCount[s[i]]++;
            if (charCount[s[i]] > 1)
            {
                return false;
            }
        }

        return true;
    }

    void ConcatinateOnlyIfCharsAreUnique(const string &s1, const string &s2, string &retVal)
    {
        int l = s2.length();
        for (int i = 0; i < l; i++)
        {
            if (s1.find(s2[i]) != std::string::npos)
            {
                retVal = s1;
                return;
            }
        }

        retVal = s1 + s2;
    }

public:
    int maxLength(vector<string> &arr)
    {
        sort(arr.begin(), arr.end(), [](const string &s1, const string &s2) -> bool { if(s1.length() < s2.length()) {return false;} return true; });

        int retVal = 0;
        int l = arr.size();

        for (int i = 0; i < l; i++)
        {
            if (!isUnique(arr[i]))
            {
                continue;
            }

            string s1 = arr[i];
            string concatStr = arr[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (!isUnique(arr[j]))
                {
                    continue;
                }
                ConcatinateOnlyIfCharsAreUnique(s1, arr[j], concatStr);
                s1 = concatStr;
            }

            retVal = max(retVal, static_cast<int>(concatStr.size()));
        }

        return retVal;
    }
};

/*  Q: 1240. Tiling a Rectangle with the Fewest Squares
*/
class Solution4_t
{
public:
    int tilingRectangle(int n, int m)
    {
        int retVal = 1 << 30;
        int count = 0;

        int subVal = min(n, m);
        while (subVal > 1)
        {
            bool first = true;
            while ((n >= 1) || (m >= 1))
            {
                count++;
                if (m > n)
                {
                    m -= n;
                }
                else if (n > m)
                {
                    n -= m;
                }
                else
                {
                    if (n > 1)
                    {
                        n -= 1;
                    }
                    else if (m > 1)
                    {
                        m -= 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            subVal = min(subVal, (max(m, n) / 2 - 1));
        }

        retVal = min(retVal, count);

        return retVal;
    }
};

int main()
{
    {
    }
    return 0;
}