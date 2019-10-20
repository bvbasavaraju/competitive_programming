/****************************************************
Date: October 4, 2019
Successful submissions : 0
Time expiration : 0
Not Solved : 4                          // On vacation in Maldives solving on 9th October
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-157
****************************************************/

/*
    Q: Play with Chips
    There are some chips, and the i-th chip is at position chips[i].

    You can perform any of the two following types of moves any number of times (possibly zero) on any chip:

    Move the i-th chip by 2 units to the left or to the right with a cost of 0.
    Move the i-th chip by 1 unit to the left or to the right with a cost of 1.
    There can be two or more chips at the same position initially.

    Return the minimum cost needed to move all the chips to the same position (any position).

    Ex:
    Input: chips = [1,2,3]
    Output: 1
    Explanation: Second chip will be moved to positon 3 with cost 1.
                        First chip will be moved to position 3 with cost 0. Total cost is 1.

    Input: chips = [2,2,2,3,3]
    Output: 2
    Explanation: Both fourth and fifth chip will be moved to position two with cost 1. Total minimum cost will be 2.

    Note:
    1 <= chips.length <= 100
    1 <= chips[i] <= 10^9
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution1_t
{
public:
    int minCostToMoveChips(vector<int> &chips)
    {
        //int totalLength = chips.size();

        return chips.size() / 2;
    }
};

/*
    Q: Longest Arithmetic Subsequence of Given Difference
    Given an integer array arr and an integer difference, 
    return the length of the longest subsequence in arr which is an arithmetic sequence such that 
    the difference between adjacent elements in the subsequence equals difference.

    ex:
    Input: arr = [1,2,3,4], difference = 1
    Output: 4
    Explanation: The longest arithmetic subsequence is [1,2,3,4].

    Input: arr = [1,3,5,7], difference = 1
    Output: 1
    Explanation: The longest arithmetic subsequence is any single element.

    Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
    Output: 4
    Explanation: The longest arithmetic subsequence is [7,5,3,1].

    Note:
    1 <= arr.length <= 10^5
    -10^4 <= arr[i], difference <= 10^4
*/

class Solution2_t
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
    }
};

/*
    Q: Path with Maximum Gold

    In a gold mine grid of size m * n, each cell in this mine has an integer representing 
    the amount of gold in that cell, 0 if it is empty.

    Return the maximum amount of gold you can collect under the conditions:

    Every time you are located in a cell you will collect all the gold in that cell.
    From your position you can walk one step to the left, right, up or down.
    You can't visit the same cell more than once.
    Never visit a cell with 0 gold.
    You can start and stop collecting gold from any position in the grid that has some gold.

    Ex:
    Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
    Output: 24
    Explanation:
    [[0,6,0],
    [5,8,7],
    [0,9,0]]
    Path to get the maximum gold, 9 -> 8 -> 7.

    Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
    Output: 28
    Explanation:
    [[1,0,7],
    [2,0,6],
    [3,4,5],
    [0,3,0],
    [9,0,20]]
    Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

    Note:
    1 <= grid.length, grid[i].length <= 15
    0 <= grid[i][j] <= 100
    There are at most 25 cells containing gold.
*/

class Solution3_t
{
public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
    }
};

/*
    Q: Count Vowels Permutation

    Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

    Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
    Each vowel 'a' may only be followed by an 'e'.
    Each vowel 'e' may only be followed by an 'a' or an 'i'.
    Each vowel 'i' may not be followed by another 'i'.
    Each vowel 'o' may only be followed by an 'i' or a 'u'.
    Each vowel 'u' may only be followed by an 'a'.
    Since the answer may be too large, return it modulo 10^9 + 7.

    Ex:
    Input: n = 1
    Output: 5
    Explanation: All possible strings are: "a", "e", "i" , "o" and "u".

    Input: n = 2
    Output: 10
    Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".

    Input: n = 5
    Output: 68

    Note:
    1 <= n <= 2 * 10^4
*/

#include <map>

class Solution4_t
{
private:
    const int ONE_BILLION_AND_SEVEN;
    map<int, int> aCount;
    map<int, int> eCount;
    map<int, int> iCount;
    map<int, int> oCount;
    map<int, int> uCount;

    int countVowelPermutation(int &currentCount, char ch, int reqCount)
    {
        if (reqCount < 0)
        {
            return 0;
        }

        if (reqCount == 0)
        {
            return 1;
        }

        switch (ch)
        {
        case 'a':
            //return (currentCount + countVowelPermutation(currentCount, 'e', (reqCount - 1)));
            {
                int retVal = 0;

                map<int, int>::iterator it = aCount.find(reqCount);
                if (it != aCount.end())
                {
                    retVal = it->second;
                }
                else
                {
                    retVal = (currentCount + countVowelPermutation(currentCount, 'e', (reqCount - 1))) % ONE_BILLION_AND_SEVEN;
                    aCount.insert(std::make_pair(reqCount, retVal));
                }

                return static_cast<int>(retVal);
            }
            break;

        case 'e':
            //return (currentCount + countVowelPermutation(currentCount, 'a', (reqCount - 1)) + countVowelPermutation(currentCount, 'i', (reqCount - 1)));
            {
                int retVal = 0;

                map<int, int>::iterator it = eCount.find(reqCount);
                if (it != eCount.end())
                {
                    retVal = it->second;
                }
                else
                {
                    retVal = (currentCount + countVowelPermutation(currentCount, 'a', (reqCount - 1)) + countVowelPermutation(currentCount, 'i', (reqCount - 1))) % ONE_BILLION_AND_SEVEN;
                    eCount.insert(std::make_pair(reqCount, retVal));
                }

                return static_cast<int>(retVal);
            }
            break;

        case 'i':
            //return (currentCount + countVowelPermutation(currentCount, 'a', (reqCount - 1)) + countVowelPermutation(currentCount, 'e', (reqCount - 1)) + countVowelPermutation(currentCount, 'o', (reqCount - 1)) + countVowelPermutation(currentCount, 'u', (reqCount - 1)));
            {
                int retVal = 0;

                map<int, int>::iterator it = iCount.find(reqCount);
                if (it != iCount.end())
                {
                    retVal = it->second;
                }
                else
                {
                    retVal = (currentCount + countVowelPermutation(currentCount, 'a', (reqCount - 1)) + countVowelPermutation(currentCount, 'e', (reqCount - 1)) + countVowelPermutation(currentCount, 'o', (reqCount - 1)) + countVowelPermutation(currentCount, 'u', (reqCount - 1))) % ONE_BILLION_AND_SEVEN;
                    iCount.insert(std::make_pair(reqCount, retVal));
                }

                return static_cast<int>(retVal);
            }
            break;

        case 'o':
            //return (currentCount + countVowelPermutation(currentCount, 'i', (reqCount - 1)) + countVowelPermutation(currentCount, 'u', (reqCount - 1)));
            {
                int retVal = 0;

                map<int, int>::iterator it = oCount.find(reqCount);
                if (it != oCount.end())
                {
                    retVal = it->second;
                }
                else
                {
                    retVal = (currentCount + countVowelPermutation(currentCount, 'i', (reqCount - 1)) + countVowelPermutation(currentCount, 'u', (reqCount - 1))) % ONE_BILLION_AND_SEVEN;
                    oCount.insert(std::make_pair(reqCount, retVal));
                }

                return static_cast<int>(retVal);
            }
            break;

        case 'u':
            //return (currentCount + countVowelPermutation(currentCount, 'a', (reqCount - 1)));
            {
                int retVal = 0;

                map<int, int>::iterator it = uCount.find(reqCount);
                if (it != uCount.end())
                {
                    retVal = it->second;
                }
                else
                {
                    retVal = (currentCount + countVowelPermutation(currentCount, 'a', (reqCount - 1))) % ONE_BILLION_AND_SEVEN;
                    uCount.insert(std::make_pair(reqCount, retVal));
                }

                return static_cast<int>(retVal);
            }
            break;

        default:
            return 0;
        }
    }

public:
    Solution4_t()
        : ONE_BILLION_AND_SEVEN(1000000000 + 7)
    {
    }

    int countVowelPermutation(int n)
    {
        int retVal = 0;

        int aPermCount = 0;
        int ePermCount = 0;
        int iPermCount = 0;
        int oPermCount = 0;
        int uPermCount = 0;
        retVal = countVowelPermutation(aPermCount, 'a', (n - 1));
        retVal += countVowelPermutation(ePermCount, 'e', (n - 1));
        retVal += countVowelPermutation(iPermCount, 'i', (n - 1));
        retVal += countVowelPermutation(oPermCount, 'o', (n - 1));
        retVal += countVowelPermutation(uPermCount, 'u', (n - 1));

        return static_cast<int>(retVal % ONE_BILLION_AND_SEVEN);
    }
};

int main(void)
{
    Solution4_t s;
    printf("\nVowel permutation count for length %d is: %d", 1, s.countVowelPermutation(1));
    printf("\nVowel permutation count for length %d is: %d", 2, s.countVowelPermutation(2));
    printf("\nVowel permutation count for length %d is: %d", 3, s.countVowelPermutation(3));
    printf("\nVowel permutation count for length %d is: %d", 4, s.countVowelPermutation(4));
    printf("\nVowel permutation count for length %d is: %d", 5, s.countVowelPermutation(5));
    printf("\nVowel permutation count for length %d is: %d", 144, s.countVowelPermutation(144)); //TODO: Logic Failing here!!
    return 0;
}