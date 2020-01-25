/****************************************************
Date: November 10th, 2019
Successful submissions : 2
Time expiration :
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-163
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
    Q: 1260. Shift 2D Grid
*/

class Solution1_t
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int r = grid.size();
        int c = grid[0].size();

        if (((r * c) == 1) || ((r * c) == k))
        {
            return grid;
        }
        else
        {
            while ((r * c) < k)
            {
                k = k - (r * c);
            }
        }

        vector<int> s(r * c);
        int p = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                s[p++] = grid[i][j];
                //printf("%d, ", s[p - 1]);
            }
        }

        //printf("\n");
        int l = s.size();
        vector<int> t(k);
        int k_ = k;
        while (k_ > 0)
        {
            t[k_ - 1] = s[l - 1];
            //printf("%d,", t[k_ - 1]);
            l--;
            k_--;
        }

        //printf("\n");
        l = s.size();
        for (int i = (l - 1); i >= k; i--)
        {
            s[i] = s[i - k];
            //printf("%d, ", s[i]);
        }
        for (int i = 0; i < k; i++)
        {
            s[i] = t[i];
            //printf("%d, ", s[i]);
        }

        p = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                grid[i][j] = s[p++];
            }
        }

        return grid;
    }
};

/*
    Q: 1261. Find Elements in a Contaminated Binary Tree
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

class FindElements_t
{
private:
    map<int, bool> m;
    void BuildLeft(TreeNode *n, int val)
    {
        int v = 2 * val + 1;

        m[v] = true;
        n->val = val;

        if (n->left != nullptr)
        {
            BuildLeft(n->left, v);
        }
        if (n->right != nullptr)
        {
            BuildRight(n->right, v);
        }
    }

    void BuildRight(TreeNode *n, int val)
    {
        int v = 2 * val + 2;

        m[v] = true;
        n->val = v;

        if (n->left != nullptr)
        {
            BuildLeft(n->left, v);
        }
        if (n->right != nullptr)
        {
            BuildRight(n->right, v);
        }
    }

public:
    FindElements_t(TreeNode *root)
    {
        if (root->left != nullptr)
        {
            BuildLeft(root->left, 0);
        }
        if (root->right != nullptr)
        {
            BuildRight(root->right, 0);
        }
    }

    bool find(int target)
    {
        return m.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

/*
    Q: 1262. Greatest Sum Divisible by Three - >Wrong answer
*/

class Solution2_t
{
public:
    int maxSumDivThree(vector<int> &n)
    {
        int l = n.size();
        int sum = 0;
        for (int i = 0; i < l; i++)
        {
            sum += n[i];
        }

        if ((sum % 3) == 0)
        {
            return sum;
        }

        printf("%d\n", sum);

        sort(n.begin(), n.end());
        int as = 0;
        for (int i = 0; i < l; i++)
        {
            if (((sum - n[i]) % 3) == 0)
            {
                return sum - n[i];
            }

            for (j = (i + 1); j < l; j++)
            {
                if (((sum - n[i] - n[j]) % 3) == 0)
                {
                    return sum - n[i] - n[j];
                }
            }

            else if (((sum - as) % 3) == 0)
            {
                return sum - as;
            }
            as += n[i];
        }

        return 0;
    }
};

/*
    Q: 1263. Minimum Moves to Move a Box to Their Target Location
*/
class Solution3_t
{
public:
    int minPushBox(vector<vector<char>> &grid)
    {
    }
};