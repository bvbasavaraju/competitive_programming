/****************************************************
Date: Sept 8th

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
    Q: Sum of Root To Leaf Binary Numbers

        You are given the root of a binary tree where each node has a value 0 or 1.  
        Each root-to-leaf path represents a binary number starting with the most significant bit.  
        For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

        For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
        Return the sum of these numbers. The answer is guaranteed to fit in a 32-bits integer.

        Example 1:
            Input: root = [1,0,1,0,1,0,1]
            Output: 22
            Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
        
        Example 2:
            Input: root = [0]
            Output: 0

        Example 3:
            Input: root = [1]
            Output: 1
        
        Example 4:
            Input: root = [1,1]
            Output: 3
        
        Constraints:
            The number of nodes in the tree is in the range [1, 1000].
            Node.val is 0 or 1.

        Hide Hint #1  
            Find each path, then transform that path to an integer in base 10.
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
    void collectNums(TreeNode *node, int num, int &ans)
    {
        if (node == NULL)
        {
            return;
        }

        num = (num << 1) | (node->val & 0x01);
        if (node->left == NULL && node->right == NULL)
        {
            ans += num;
        }
        else
        {
            collectNums(node->left, num, ans);
            collectNums(node->right, num, ans);
        }
    }

public:
    int sumRootToLeaf(TreeNode *root)
    {
        int ans = 0;
        collectNums(root, 0, ans);

        return ans;
    }
};