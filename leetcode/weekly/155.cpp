/****************************************************
Date: September 22, 2019
Successful submissions : 0
Time expiration : 2
Not Solved : 2

link: https://leetcode.com/contest/weekly-contest-155
****************************************************/
/*
    Q :Minimum Absolute Difference
    Given an array of distinct integers arr, find all pairs of elements with the minimum 
    absolute difference of any two elements. 

    Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

    + a, b are from arr
    + a < b
    + b - a equals to the minimum absolute difference of any two elements in arr

    Ex:
        Input: arr = [4,2,1,3]
        Output: [[1,2],[2,3],[3,4]]
        Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.

        Input: arr = [1,3,6,10,15]
        Output: [[1,3]]

        Input: arr = [3,8,-10,23,19,-4,-14,27]
        Output: [[-14,-10],[19,23],[23,27]]

    Contraints:
        2 <= arr.length <= 10^5
        -10^6 <= arr[i] <= 10^6
*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
class Solution1
{
private:
    int InsersionSort(vector<int> &input)
    {
        int loopCount = input.size();
        if (loopCount <= 0)
        {
            return -1;
        }

        for (int i = 0; i < (loopCount - 1); i++)
        {
            for (int j = (i + 1); j > 0; j--)
            {
                if (input[j] < input[j - 1])
                {
                    swap(input[j], input[j - 1]);
                }
                else
                {
                    break;
                }
            }
        }
        return 0;
    }

    int GetDifference(int num1, int num2)
    {
        int retVal = 0;
        if (num1 > num2)
        {
            retVal = num1 - num2;
        }
        else
        {
            retVal = num2 - num1;
        }

        if (retVal < 0)
        {
            retVal = retVal * -1;
        }

        return retVal;
    }

    int GetMinAbsDiff(vector<int> &arr, int &index1, int &index2)
    {
        int retVal = INT_MAX;
        for (int i = 0; i < (arr.size() - 1); i++)
        {
            int minDiff = GetDifference(arr[i], arr[i + 1]);
            if (minDiff < retVal)
            {
                retVal = minDiff;
                index1 = i;
                index2 = i + 1;
            }
        }

        return retVal;
    }

    void GetNextMinAbsDiffArray(vector<int> &arr, int startIndex, int endIndex, int indexToExclude, int minAbsDiff, vector<int> &result)
    {
        if ((startIndex < endIndex) && !arr.empty() && (startIndex != indexToExclude))
        {
            int diff = GetDifference(arr[startIndex], arr[endIndex]);
            if (diff != minAbsDiff)
            {
                return;
            }

            result = {arr[startIndex], arr[endIndex]};
        }
    }

public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> retVal;
        int sortResult = InsersionSort(arr);
        if (sortResult < 0)
        {
            return retVal;
        }

        int minAbsDiffIndex1 = 0;
        int minAbsDiffIndex2 = 1;
        int minAbsDiff = GetMinAbsDiff(arr, minAbsDiffIndex1, minAbsDiffIndex2);

        vector<int> data = {arr[minAbsDiffIndex1], arr[minAbsDiffIndex2]};
        retVal.push_back(data);
        for (int i = 0; i < (arr.size() - 1); i++)
        {
            vector<int> data_;
            GetNextMinAbsDiffArray(arr, i, (i + 1), minAbsDiffIndex1, minAbsDiff, data_);
            if (data_.empty())
            {
                continue;
            }

            retVal.push_back(data_);
        }

        return retVal;
    }
};

// int main()
// {
//     //vector<int> arr = {4, 2, 1, 3};
//     //vector<int> arr = {1, 3, 6, 10, 15};
//     //vector<int> arr = {3, 8, -10, 23, 19, -4, -14, 27};
//     vector<int> arr = {40, 11, 26, 27, -20};

//     Solution1 s;
//     vector<vector<int>> result = s.minimumAbsDifference(arr);

//     return 0;
// }

/*
    Q: Ugly Number III

    Write a program to find the n-th ugly number.
    Ugly numbers are positive integers which are divisible by a or b or c.

    Ex: 
        Input: n = 3, a = 2, b = 3, c = 5
        Output: 4
        Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.

        Input: n = 4, a = 2, b = 3, c = 4
        Output: 6
        Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 12... The 4th is 6.

        Input: n = 5, a = 2, b = 11, c = 13
        Output: 10
        Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.

        Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
        Output: 1999999984

    Contstraints:
        1 <= n, a, b, c <= 10^9
        1 <= a * b * c <= 10^18
        It's guaranteed that the result will be in range [1, 2 * 10^9]

    Solution approach: (Theoretical - Still needs to be implemented and tested)
    1. Sort given dividents in an ascending order. such that a < b < c
    2. Count numbers divisible by 'a' till it reaches 'b'. It will be => b/a. See if it crosses the count. If so return 'a' * nth num
    3. Count numbers divisible by 'a' till it reaches 'c' from 'b'. that is => (c - b)/ a.
    4. Count numbers divisible by 'b' till it reaches 'c'. that is => c/b.
    5. Till 'c' is reached count will be sum of (count from step 2) + (count from step 4 * 3). If that number is greater than nth numer,
        then nth number is between 'c' and 'b'
    6. if number is beyond c, then do an incremental steps from counts generated from steps 2 and 5.

    Note: Till 'c', product of 'a' and 'b' has been counted for (c / (a*b)) times. So subtract that from the result
*/
#include <thread>
#include <mutex>
#include <atomic>

class Solution2
{
private:
    int InsersionSort(vector<int> &input)
    {
        int loopCount = input.size();
        if (loopCount <= 0)
        {
            return -1;
        }

        for (int i = 0; i < (loopCount - 1); i++)
        {
            for (int j = (i + 1); j > 0; j--)
            {
                if (input[j] < input[j - 1])
                {
                    swap(input[j], input[j - 1]);
                }
                else
                {
                    break;
                }
            }
        }
        return 0;
    }

public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        int uglyNumCount = 0;
        vector<int> nums = {a, b, c};
        int errorCode = InsersionSort(nums);
        if (errorCode < 0)
        {
            return 0;
        }

        a = nums[0];
        b = nums[1];
        c = nums[2];

        // Below approach works. But time complexity is very poor!! So, need to improve as mentioned in Solution approach
        int startNum = a;
        int gapBetweenFirst2 = b / a;
        if (gapBetweenFirst2 > 1)
        {
            if (gapBetweenFirst2 >= n)
            {
                return (gapBetweenFirst2 * a);
            }
            else
            {
                uglyNumCount = gapBetweenFirst2;
                startNum = (gapBetweenFirst2 * a);
            }
        }

        int retVal = startNum + 1;
        for (int i = startNum; uglyNumCount < n; i++)
        {
            if ((i % a) == 0)
            {
                uglyNumCount++;
            }
            else if ((i % b) == 0)
            {
                uglyNumCount++;
            }
            else if ((i % c) == 0)
            {
                uglyNumCount++;
            }

            if (uglyNumCount == n)
            {
                retVal = i;
            }
        }

        return retVal;
    }
};

int main()
{
    Solution2 s2;
    int nthUglyNum1 = s2.nthUglyNumber(3, 2, 3, 5);
    int nthUglyNum2 = s2.nthUglyNumber(4, 2, 3, 4);
    int nthUglyNum3 = s2.nthUglyNumber(5, 2, 11, 13);
    int nthUglyNum4 = s2.nthUglyNumber(1000000000, 2, 217983653, 336916467);

    return 0;
}

/*
    Q: Smallest String With Swaps
    You are given a string s, and an array of pairs of indices in the string pairs where,
    pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

    You can swap the characters at any pair of indices in the given pairs any number of times.
    Return the lexicographically smallest string that s can be changed to after using the swaps

    Ex:
        Input: s = "dcab", pairs = [[0,3],[1,2]]
        Output: "bacd"
        Explaination: 
        Swap s[0] and s[3], s = "bcad"
        Swap s[1] and s[2], s = "bacd"

        Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
        Output: "abcd"
        Explaination: 
        Swap s[0] and s[3], s = "bcad"
        Swap s[0] and s[2], s = "acbd"
        Swap s[1] and s[2], s = "abcd"

        Input: s = "cba", pairs = [[0,1],[1,2]]
        Output: "abc"
        Explaination: 
        Swap s[0] and s[1], s = "bca"
        Swap s[1] and s[2], s = "bac"
        Swap s[0] and s[1], s = "abc"

    Constraints:
        1 <= s.length <= 10^5
        0 <= pairs.length <= 10^5
        0 <= pairs[i][0], pairs[i][1] < s.length
        s only contains lower case English letters.
*/

class Solution3
{
private:
    int GetSwappedStringOnlyIfSmaller(vector<int> pair, string &s, bool &isSwapped)
    {
        isSwapped = false;

        string retVal;
        int pos1 = pair[0];
        int pos2 = pair[1];
        if (s.empty() || ((s.length() - 1) < pos1) || ((s.length() - 1) < pos2))
        {
            return -1;
        }

        if (pos1 == pos2)
        {
            return 0;
        }

        string swappedString = s;

        char letter = swappedString.at(pos1);
        swappedString.at(pos1) = swappedString.at(pos2);
        swappedString.at(pos2) = letter;

        if (swappedString < s)
        {
            s = swappedString;
            isSwapped = true;
        }

        return 0;
    }

    int GetSmallestStringWithSwaps(string s, vector<vector<int>> &pairs, int pairStartPosition, string &smallest)
    {
        for (int i = pairStartPosition; i < pairs.size(); i++)
        {
            bool isSwapped;
            int errorCode = GetSwappedStringOnlyIfSmaller(pairs[i], s, isSwapped);
            if (errorCode < 0)
            {
                return errorCode;
            }

            errorCode = GetSmallestStringWithSwaps(s, pairs, (pairStartPosition + 1), smallest);
            if (errorCode < 0)
            {
                return -1;
            }

            if (s < smallest)
            {
                smallest = s;
            }
        }

        return 0;
    }

    int GetSmallestStringWithSwaps(string &s, vector<vector<int>> &pairs, bool &repeatAgain)
    {
        for (int i = 0; i < pairs.size(); i++)
        {
            bool isSwapped;
            int swapResult = GetSwappedStringOnlyIfSmaller(pairs[i], s, isSwapped);
            if (swapResult < 0)
            {
                return swapResult;
            }

            if (isSwapped)
            {
                repeatAgain = true;
                string branchedSmallestStr = s;
                int result = GetSmallestStringWithSwaps(s, pairs, (i + 1), branchedSmallestStr);
                if (result < 0)
                {
                    return -1;
                }

                if (branchedSmallestStr < s)
                {
                    s = branchedSmallestStr;
                }
            }
        }

        return 0;
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        string emptyStr;
        bool repeatAgain = false;
        do
        {
            repeatAgain = false;
            if (GetSmallestStringWithSwaps(s, pairs, repeatAgain) < 0)
            {
                return emptyStr;
            }
        } while (repeatAgain);

        return s;
    }
};

// int main()
// {
//     Solution3 s3;

//     vector<vector<int>> pairs1 = {{0, 3}, {1, 2}};
//     string result1 = s3.smallestStringWithSwaps("dcab", pairs1);
//     printf("\nResult1 : %s", result1.c_str());

//     vector<vector<int>> pairs2 = {{0, 3}, {1, 2}, {0, 2}};
//     string result2 = s3.smallestStringWithSwaps("dcab", pairs2);
//     printf("\nResult2 : %s", result2.c_str());

//     vector<vector<int>> pairs3 = {{0, 1}, {1, 2}};
//     string result3 = s3.smallestStringWithSwaps("cba", pairs3);
//     printf("\nResult3 : %s", result3.c_str());

//     return 0;
// }

/*
    Q: Sort Items by Groups Respecting Dependencies
    There are n items each belonging to zero or one of m groups where group[i] is the group that,
    the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. 
    The items and the groups are zero indexed. A group can have no item belonging to it.

    Return a sorted list of the items such that:
    + The items that belong to the same group are next to each other in the sorted list.
    + There are some relations between these items where beforeItems[i] is a list containing 
        all the items that should come before the i-th item in the sorted array (to the left of the i-th item).

    Return any solution if there is more than one solution and return an empty list if there is no solution.

    Ex:
        Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
        Output: [6,3,4,1,5,2,0,7]

        Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
        Output: []
        Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.

    Constraints:
        1 <= m <= n <= 3*10^4
        group.length == beforeItems.length == n
        -1 <= group[i] <= m-1
        0 <= beforeItems[i].length <= n-1
        0 <= beforeItems[i][j] <= n-1
        i != beforeItems[i][j]
        beforeItems[i] does not contain duplicates elements.
*/

class Solution4
{
public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
    }
};