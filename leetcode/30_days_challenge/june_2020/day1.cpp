/****************************************************
Date: June 1st

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3347/
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
    Q: Invert Binary Tree

    Invert a binary tree.

    Example:

        Input:
             4
           /   \
          2     7
         / \   / \
        1  3 6   9

        Output:
             4
           /   \
          7     2
         / \   / \
        9  6 3   1
    
    Trivia:
    
    This problem was inspired by this original tweet by Max Howell:
    Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

class Solution
{
private:
    TreeNode *invert(TreeNode *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        TreeNode *left = invert(node->left);
        TreeNode *right = invert(node->right);

        node->left = right;
        node->right = left;

        return node;
    }

public:
    TreeNode *invertTree(TreeNode *root)
    {
        return invert(root);
    }
};