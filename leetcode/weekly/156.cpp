/****************************************************
Date: September 29, 2019
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1 

link: https://leetcode.com/contest/weekly-contest-156
****************************************************/

/*
    Q: Unique Number of Occurrences

    Given an array of integers arr,
    write a function that returns true if and only if the number of occurrences of each value in the array is unique.

    Ex:
    Input: arr = [1,2,2,1,1,3]
    Output: true
    Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

    Input: arr = [1,2]
    Output: false  

    Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
    Output: true
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution1_t
{
private:
    std::map<int, int> numWithCount;

    void AddToSet(int num)
    {
        bool found = false;

        std::map<int, int>::iterator it = numWithCount.find(num);
        if (it != numWithCount.end())
        {
            it->second++;
        }
        else
        {
            numWithCount.insert(std::make_pair(num, 0));
        }
    }

    bool HasDuplicates(void)
    {
        std::map<int, int>::iterator it = numWithCount.begin();
        while (it != numWithCount.end())
        {
            int num = it->first;
            int count = it->second;
            numWithCount.erase(it);

            for (std::map<int, int>::iterator it2 = numWithCount.begin(); it2 != numWithCount.end(); it2++)
            {
                if (it2->second == count)
                {
                    return true;
                }
            }

            it = numWithCount.begin();
        }

        return false;
    }

public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        if (arr.size() <= 0)
        {
            false;
        }

        for (int i : arr)
        {
            AddToSet(i);
        }

        return (HasDuplicates() != true);
    }
};

// int main()
// {
//     vector<int> input = {1, 2, 2, 1, 1, 3};
//     Solution1_t s;
//     bool hasUniqueOccurrance = s.uniqueOccurrences(input);

//     return 0;
// }

/*
    Q: Get Equal Substrings Within Budget

    You are given two strings s and t of the same length. You want to change s to t.
    Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is,
    the absolute difference between the ASCII values of the characters.

    You are also given an integer maxCost.

    Return the maximum length of a substring of s that can be changed to be the same as 
    the corresponding substring of twith a cost less than or equal to maxCost.

    If there is no substring from s that can be changed to its corresponding substring from t, return 0.

    Ex:
    Input: s = "abcd", t = "bcdf", cost = 3
    Output: 3
    Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.

    Input: s = "abcd", t = "cdef", cost = 3
    Output: 1
    Explanation: Each charactor in s costs 2 to change to charactor in t, so the maximum length is 1.

    Input: s = "abcd", t = "acde", cost = 0
    Output: 1
    Explanation: You can't make any change, so the maximum length is 1.

    Note:
    1 <= s.length, t.length <= 10^5
    0 <= maxCost <= 10^6
    s and t only contain lower case English letters.
*/

class Solution2_t
{
private:
    int GetEqualSubStringLength(int startPos, string s, string t, int maxCost)
    {
        int count = s.length();
        int retVal = 0;

        const char *sCStr = s.c_str();
        const char *tCStr = t.c_str();

        for (int i = startPos; i < count; i++)
        {
            char sChar = sCStr[i];
            char tChar = tCStr[i];

            int diff = sChar - tChar;
            if (diff < 0)
            {
                diff = diff * -1;
            }

            if ((diff > maxCost) || (diff == 0))
            {
                continue;
            }
            else
            {
                maxCost = maxCost - diff;
                retVal++;
            }
        }

        return retVal;
    }

public:
    int equalSubstring(string s, string t, int maxCost)
    {
        if (maxCost == 0)
        {
            return 1;
        }

        if (s.length() != t.length())
        {
            return 0;
        }

        // int retVal = 0;
        // for (int i = 0; i < s.length(); i++)
        // {
        //     int maxLength = GetEqualSubStringLength(i, s, t, maxCost);
        //     if (maxLength > retVal)
        //     {
        //         retVal = maxLength;
        //     }
        // }

        // return retVal;

        int count = s.length();
        int retVal = 0;

        const char *sCStr = s.c_str();
        const char *tCStr = t.c_str();

        for (int i = 0; i < count; i++)
        {
            char sChar = sCStr[i];
            char tChar = tCStr[i];

            int diff = sChar - tChar;
            if (diff < 0)
            {
                diff = diff * -1;
            }

            if ((diff > maxCost) || (diff == 0))
            {
                continue;
            }
            else
            {
                maxCost = maxCost - diff;
                retVal++;
            }
        }

        return retVal;
    }
};

int main()
{
    Solution2_t s;

    printf("\nMax Length is: %d: ", s.equalSubstring("abcd", "bcdf", 3));        //Expected 3
    printf("\nMax Length is: %d: ", s.equalSubstring("abcd", "cdef", 3));        //Expected 1
    printf("\nMax Length is: %d: ", s.equalSubstring("abcd", "acde", 0));        //Expected 1
    printf("\nMax Length is: %d: ", s.equalSubstring("krrgw", "zjxss", 19));     //Expected 2
    printf("\nMax Length is: %d: ", s.equalSubstring("pxezla", "loewbi", 25));   //Expected 4
    printf("\nMax Length is: %d: ", s.equalSubstring("jzmhzdq", "rymuemg", 17)); //expected is 3

    return 0;
}

/*
    Q: Remove All Adjacent Duplicates in String II

    Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and 
    removing them causing the left and the right side of the deleted substring to concatenate together.

    We repeatedly make k duplicate removals on s until we no longer can.

    Return the final string after all such duplicate removals have been made.

    It is guaranteed that the answer is unique.

    Ex:
    Input: s = "abcd", k = 2
    Output: "abcd"
    Explanation: There's nothing to delete.

    Input: s = "deeedbbcccbdaa", k = 3
    Output: "aa"
    Explanation: 
    First delete "eee" and "ccc", get "ddbbbdaa"
    Then delete "bbb", get "dddaa"
    Finally delete "ddd", get "aa"

    Input: s = "pbbcggttciiippooaais", k = 2
    Output: "ps"

    Note:
    1 <= s.length <= 10^5
    2 <= k <= 10^4
    s only contains lower case English letters.
*/

#include <list>

class Solution3_1
{
private:
    list<string> subStrings;

    void AddToList(char letter)
    {
        string subString;
        subString.append(&letter, 1);
        subStrings.push_back(subString);
    }

    void InsertOrAppendToList(char letter)
    {
        if (subStrings.size() <= 0)
        {
            AddToList(letter);
            return;
        }

        string subStrAtTop = subStrings.back();
        int position = subStrAtTop.find_first_of(letter);
        if (position >= 0)
        {
            subStrings.pop_back();
            subStrAtTop.append(&letter, 1);
            subStrings.push_back(subStrAtTop);
        }

        else
        {
            AddToList(letter);
        }
    }

    void PrepareList(string s)
    {
        const char *strInCStr = s.c_str();
        subStrings.clear();
        for (int i = 0; i < s.size(); i++)
        {
            InsertOrAppendToList(strInCStr[i]);
        }
    }

    void Remove(int count, bool &hasSubStrOfGivenCount)
    {
        hasSubStrOfGivenCount = false;
        list<string>::iterator it;
        for (it = subStrings.begin(); it != subStrings.end(); it++)
        {
            string &subString = *it;
            if (subString.length() >= count)
            {
                hasSubStrOfGivenCount = true;
                subString.erase(0, count);
            }
        }
    }

    void GetString(string &str)
    {
        list<string>::iterator it;
        for (it = subStrings.begin(); it != subStrings.end(); it++)
        {
            str.append(*it);
        }
    }

public:
    string removeDuplicates(string s, int k)
    {
        bool hasSubStrOfGivenCount = true;
        while (hasSubStrOfGivenCount)
        {
            PrepareList(s);
            Remove(k, hasSubStrOfGivenCount);
            s.erase();
            GetString(s);
        }

        return s;
    }
};

// int main()
// {
//     Solution3_1 s;

//     string str1 = "abcd";
//     str1 = s.removeDuplicates(str1, 2);

//     string str2 = "deeedbbcccbdaa";
//     str2 = s.removeDuplicates(str2, 3);

//     string str3 = "pbbcggttciiippooaais";
//     str3 = s.removeDuplicates(str3, 2);

//     string str4 = "";
//     str4 = s.removeDuplicates(str4, 4);

//     return 0;
// }

/*
    Q : Minimum Moves to Reach Target with Rotations

    https://leetcode.com/contest/weekly-contest-156/problems/minimum-moves-to-reach-target-with-rotations/

    In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). 
    The grid has empty cells represented by zeros and blocked cells represented by ones. 
    The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).

    In one move the snake can:
        +  Move one cell to the right if there are no blocked cells there. 
            This move keeps the horizontal/vertical position of the snake as it is.
        +  Move down one cell if there are no blocked cells there. 
            This move keeps the horizontal/vertical position of the snake as it is.
        +  Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. 
            In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).
        +  Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. 
            In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).

    Return the minimum number of moves to reach the target.

    If there is no way to reach the target, return -1.

    Ex:
    Input: grid = [[0,0,0,0,0,1],
               [1,1,0,0,1,0],
               [0,0,0,0,1,1],
               [0,0,1,0,1,0],
               [0,1,1,0,0,0],
               [0,1,1,0,0,0]]
    Output: 11
    Explanation:
    One possible solution is [right, right, rotate clockwise, right, down, down, down, down, rotate counterclockwise, right, down]

    Input: grid = [[0,0,1,1,1,1],
               [0,0,0,0,1,1],
               [1,1,0,0,0,1],
               [1,1,1,0,0,1],
               [1,1,1,0,0,1],
               [1,1,1,0,0,0]]
    Output: 9

    Note:
    2 <= n <= 100
    0 <= grid[i][j] <= 1
    It is guaranteed that the snake starts at empty cells.
*/

class Solution4_t
{
public:
    int minimumMoves(vector<vector<int>> &grid)
    {
    }
};