/****************************************************
Date: Oct 2nd

link: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3481/
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
    Q: Combination Sum
    
    Given an array of distinct integers candidates and a target integer target, 
    return a list of all unique combinations of candidates where the chosen numbers sum to target. 
    You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. 
    Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    Example 1:
        Input: candidates = [2,3,6,7], target = 7
        Output: [[2,2,3],[7]]
        Explanation:
            2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
            7 is a candidate, and 7 = 7.
            These are the only two combinations.

    Example 2:
        Input: candidates = [2,3,5], target = 8
        Output: [[2,2,2,2],[2,3,3],[3,5]]

    Example 3:
        Input: candidates = [2], target = 1
        Output: []

    Example 4:
        Input: candidates = [1], target = 1
        Output: [[1]]

    Example 5:
        Input: candidates = [1], target = 2
        Output: [[1,1]]

    Constraints:
        1 <= candidates.length <= 30
        1 <= candidates[i] <= 200
        All elements of candidates are distinct.
        1 <= target <= 500
*/

class Solution
{
private:
    bool getComb(vector<int> &candidates, int target, int p, int sum, int l, vector<int> &combs, vector<vector<int>> &ans)
    {
        if ((target < 0) || (p < 0) || (p >= l))
        {
            return false;
        }

        if (target == 0)
        {
            return true;
        }

        for (int i = p; i < l; ++i)
        {
            int c = candidates[i];

            combs.push_back(c);
            if (getComb(candidates, target - c, i, sum + c, l, combs, ans))
            {
                ans.push_back(combs);
            }

            combs.pop_back();
        }

        return false;
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        if ((candidates.size() == 0) || (candidates[0] > target))
        {
            return {};
        }

        vector<int> combs;
        vector<vector<int>> ans;
        getComb(candidates, target, 0, 0, candidates.size(), combs, ans);

        return ans;
    }
};