/****************************************************
Date: Sept 12th

link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3453/
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
    Q: Combination Sum III

    Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

    Only numbers 1 through 9 are used.
    Each number is used at most once.
    Return a list of all possible valid combinations. The list must not contain the same combination twice, 
    and the combinations may be returned in any order.

    Example 1:
        Input: k = 3, n = 7
        Output: [[1,2,4]]
        Explanation:
        1 + 2 + 4 = 7
        There are no other valid combinations.

    Example 2:
        Input: k = 3, n = 9
        Output: [[1,2,6],[1,3,5],[2,3,4]]
        Explanation:
        1 + 2 + 6 = 9
        1 + 3 + 5 = 9
        2 + 3 + 4 = 9
        There are no other valid combinations.

    Example 3:
        Input: k = 4, n = 1
        Output: []
        Explanation: There are no valid combinations. [1,2,1] is not valid because 1 is used twice.

    Example 4:
        Input: k = 3, n = 2
        Output: []
        Explanation: There are no valid combinations.

    Example 5:
        Input: k = 9, n = 45
        Output: [[1,2,3,4,5,6,7,8,9]]
        Explanation:
        1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
        ​​​​​​​There are no other valid combinations.
    
    Constraints:
        2 <= k <= 9
        1 <= n <= 60
*/
class Solution
{
private:
    void getCombination(int k, int n, int val, vector<int> &comb, vector<vector<int>> &ans)
    {
        if (k == 0 && n == 0)
        {
            ans.push_back(comb);
            return;
        }

        if (k < 0 || n < 0)
        {
            return;
        }

        for (int i = val; i <= 9; ++i)
        {
            comb.push_back(i);
            getCombination(k - 1, n - i, i + 1, comb, ans);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> comb;
        vector<vector<int>> ans;
        getCombination(k, n, 1, comb, ans);

        return ans;
    }
};