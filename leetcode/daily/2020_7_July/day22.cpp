/****************************************************
Date: July 22nd

link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/
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
    Q: Binary Tree Zigzag Level Order Traversal
    Given a binary tree, return the zigzag level order traversal of its nodes' values.
    (ie, from left to right, then right to left for the next level and alternate between).

    For example:
        Given binary tree [3,9,20,null,null,15,7],
             3
            / \
           9  20
               /  \
            15   7
        
        return its zigzag level order traversal as:
            [
            [3],
            [20,9],
            [15,7]
            ]
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void getNodes(TreeNode *node, int depth, vector<vector<int>> &result)
    {
        if (node == NULL)
        {
            return;
        }

        if (result.size() >= depth)
        {
            result[depth - 1].push_back(node->val);
        }
        else
        {
            vector<int> data;
            data.push_back(node->val);
            result.push_back(data);
        }

        getNodes(node->left, depth + 1, result);
        getNodes(node->right, depth + 1, result);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        getNodes(root, 1, ans);

        int dir = 1;
        for (auto &a : ans)
        {
            if (dir % 2 == 0)
            {
                reverse(a.begin(), a.end());
            }
            dir++;
        }

        return ans;
    }
};