/****************************************************
Date: December 22, 2019
Successful submissions : 1
Time expiration : 1
Not Solved : 2
Wrong Answer/ Partial result : 

Note: I was at my native as my vacation!

link: https://leetcode.com/contest/biweekly-contest-168 
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
    Q: 1295. Find Numbers with Even Number of Digits
*/
class Solution1_t
{
public:
    int findNumbers(vector<int> &nums)
    {
        int retVal = 0;
        int l = nums.size();
        for (int i = 0; i < l; i++)
        {
            int n = nums[i];
            int c = 0;
            while (n != 0)
            {
                c++;
                n = n / 10;
            }

            if ((c > 0) && ((c % 2) == 0))
            {
                retVal++;
            }
        }

        return retVal;
    }
};

/*
    Q: 1296. Divide Array in Sets of K Consecutive Numbers
*/
class Solution2_t
{
private:
    bool AddToBag(int n, vector<int> &bag)
    {
        int l = bag.size();
        if ((l > 0) && (bag[l - 1] == n))
        {
            printf("Duplicate [%d] found", n);
            return false;
        }

        bag.push_back(n);
        return true;
    }

public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        int l = nums.size();
        if ((l % k) != 0)
        {
            return false;
        }

        sort(nums.begin(), nums.end());

        vector<vector<int>> groups;
        for (int i = 0; i < l; i++)
        {
            int gl = groups.size();
            if ((gl > 0) && (groups[gl - 1][0] == nums[i]))
            {
                groups[gl - 1].push_back(nums[i]);
            }
            else
            {
                vector<int> b;
                b.push_back(nums[i]);
                groups.push_back(b);
            }
        }

        vector<vector<int>> bags;
        while (groups.size() > 0)
        {
            int i = 0;
            vector<int> b;
            while (b.size() < k)
            {
                if ((groups.size() <= i) || (groups[i].size() <= 0))
                {
                    return false;
                }
                else
                {
                    //printf("%d, ",groups[i][0]);
                    b.push_back(groups[i][0]);
                    if (groups[i].size() == 1)
                    {
                        groups.erase(groups.begin() + i);
                    }
                    else
                    {
                        groups[i].pop_back();
                        i++;
                    }

                    int bl = b.size();
                    if ((bl > 1) && (b[bl - 1] != (b[bl - 2] + 1)))
                    {
                        return false;
                    }
                }
            }
            //printf("\n");
            bags.push_back(b);
        }

        return true;
    }
};

/*
    Q:  1297. Maximum Number of Occurrences of a Substring
*/
class Solution3_t
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
    }
};

/*
    Q: 1298. Maximum Candies You Can Get from Boxes
*/
class Solution4_t
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
    }
};