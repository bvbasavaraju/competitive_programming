/****************************************************
Date: Oct 22nd

link: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3505/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
    Q: Minimum Depth of Binary Tree

    Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    
    Note: A leaf is a node with no children.

    Example 1:
        Input: root = [3,9,20,null,null,15,7]
        Output: 2

    Example 2:
        Input: root = [2,null,3,null,4,null,5,null,6]
        Output: 5
    
    Constraints:
        The number of nodes in the tree is in the range [0, 105].
        -1000 <= Node.val <= 1000
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
    void depth(TreeNode *node, int d, int &ans)
    {
        if (node == NULL)
        {
            return;
        }

        d++;

        if ((node->left == NULL) && (node->right == NULL))
        {
            ans = min(ans, d);
        }

        depth(node->left, d, ans);
        depth(node->right, d, ans);
    }

public:
    int minDepth(TreeNode *root)
    {
        int ans = INT_MAX;
        depth(root, 0, ans);

        return ans == INT_MAX ? 0 : ans;
    }
};