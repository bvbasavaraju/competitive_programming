/****************************************************
Date: June 21st

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3368/
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
private:
    vector<int> nums;

    bool collectNums(TreeNode *node, int &num)
    {
        if (node == NULL)
        {
            return true;
        }

        num = num * 10;
        num += node->val;

        bool reachedLeftEnd = collectNums(node->left, num);
        //num.pop_back();
        bool reachedRightEnd = collectNums(node->right, num);
        //num.pop_back();

        if (reachedLeftEnd && reachedRightEnd)
        {
            nums.push_back(num);
            num = num / 10;
        }
        return false;
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int num = 0;
        collectNums(root, num);

        int ans = 0;
        for (int &n : nums)
        {
            printf("%d\n", n);
            ans += n;
        }

        return ans;
    }
};

int main()
{
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        Solution s;
        int ans = s.sumNumbers(root);
    }

    return 0;
}