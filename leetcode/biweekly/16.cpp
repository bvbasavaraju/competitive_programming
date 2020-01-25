/****************************************************
Date: December 28, 2019
Successful submissions : 1
Time expiration : 
Not Solved : 3
Wrong Answer/ Partial result : 

link: https://leetcode.com/contest/biweekly-contest-16
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
    Q: 1299. Replace Elements with Greatest Element on Right Side
*/
class Solution1_t
{
public:
    vector<int> replaceElements(vector<int> &a1)
    {
        int l = a1.size();
        for (int i = 0; i < (l - 1); i++)
        {
            a1[i] = *max_element((a1.begin() + i + 1), a1.end());
        }

        a1[l - 1] = -1;

        return a1;
    }
};

/*
    Q: 1300. Sum of Mutated Array Closest to Target
*/
class Solution2_t
{
public:
    int findBestValue(vector<int> &arr, int target)
    {
    }
};

/*
    Q:  1302. Deepest Leaves Sum
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution3_t
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
    }
};

/*
    Q:  1301. Number of Paths with Max Score
*/

class Solution4_t
{
public:
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
    }
};