/****************************************************
Date: April 11th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3293/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
    Q:  Diameter of Binary Tree
    Given a binary tree, you need to compute the length of the diameter of the tree.
    The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
    This path may or may not pass through the root.

    Example:
    Given a binary tree
             1
            / \
           2   3
          / \     
        4   5    
    Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

    Note: The length of path between two nodes is represented by the number of edges between them.
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    int ans = 0;

    int height(TreeNode *n)
    {
        if (n == NULL)
        {
            return 0;
        }

        return 1 + max(height(n->left), height(n->right));
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int l_height = height(root->left);
        int r_height = height(root->right);

        int l_diameter = diameterOfBinaryTree(root->left);
        int r_diameter = diameterOfBinaryTree(root->right);

        return max(l_height + r_height, max(l_diameter, r_diameter));
    }
};