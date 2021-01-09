/****************************************************
Date: Oct 5th

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
    Q: Insert into a Binary Search Tree

    You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
    Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

    Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. 
    You can return any of them.

    Example 1:
        Input: root = [4,2,7,1,3], val = 5
        Output: [4,2,7,1,3,5]
        Explanation: Another accepted tree is:

    Example 2:
        Input: root = [40,20,60,10,30,50,70], val = 25
        Output: [40,20,60,10,30,50,70,null,null,25]

    Example 3:
        Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
        Output: [4,2,7,1,3,5]

    Constraints:
        + The number of nodes in the tree will be in the range [0, 104].
        + -108 <= Node.val <= 108
        + All the values Node.val are unique.
        + -108 <= val <= 108
        + It's guaranteed that val does not exist in the original BST.
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
    void getNodeToInsert(TreeNode *node, int val, TreeNode *&prev_node)
    {
        if (node == NULL)
        {
            return;
        }

        prev_node = node;
        if (node->val > val)
        {
            getNodeToInsert(node->left, val, prev_node);
        }
        else
        {
            getNodeToInsert(node->right, val, prev_node);
        }
    }

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *prev_node = NULL;
        getNodeToInsert(root, val, prev_node);

        TreeNode *node = new TreeNode(val);
        if (prev_node == NULL)
        {
            root = node;
        }
        else if (prev_node->val > val)
        {
            prev_node->left = node;
        }
        else
        {
            prev_node->right = node;
        }

        return root;
    }
};