/****************************************************
Date: Jan 11, 2020
Successful submissions : 0
Time expiration : 
Not Solved : 4
Wrong Answer/ Partial result : 

Note: On vacation. to hometown

link: https://leetcode.com/contest/biweekly-contest-17
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
    Q:  1313. Decompress Run-Length Encoded List - solved
*/
class Solution1_t
{
public:
    vector<int> decompressRLElist(vector<int> &n)
    {
        int l = n.size();
        vector<int> r;
        for (int i = 0; i < l; i = i + 2)
        {
            for (int j = 0; j < n[i]; ++j)
            {
                r.push_back(n[i + 1]);
            }
        }

        return r;
    }
};

/*
    Q:  1314. Matrix Block Sum - not solved
*/
class Solution2_t
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
    {
    }
};

/*
    Q:  1315. Sum of Nodes with Even-Valued Grandparent - solved
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
private:
    int GetGrandChildSum(TreeNode *n)
    {
        int sum = 0;
        if (n != NULL)
        {
            if (n->left != NULL)
            {
                if (n->left->left != NULL)
                {
                    sum += n->left->left->val;
                }
                if (n->left->right != NULL)
                {
                    sum += n->left->right->val;
                }
            }

            if (n->right != NULL)
            {
                if (n->right->left != NULL)
                {
                    sum += n->right->left->val;
                }
                if (n->right->right != NULL)
                {
                    sum += n->right->right->val;
                }
            }
        }

        return sum;
    }

public:
    int sumEvenGrandparent(TreeNode *r)
    {
        if (r == NULL)
        {
            return 0;
        }

        queue<TreeNode *> q;
        q.push(r);

        int sum = 0;
        while (!q.empty())
        {
            printf("%d,", q.size());

            TreeNode *r_ = q.front();
            q.pop();

            if (r_->val % 2 == 0)
            {
                sum += GetGrandChildSum(r_);
            }

            if (r_->left != NULL)
            {
                q.push(r_->left);
            }
            if (r_->right != NULL)
            {
                q.push(r_->right);
            }
        }

        return sum;
    }
};

/*
    Q:  1316. Distinct Echo Substrings - Not solved
*/
class Solution4_t
{
private:
public:
    int distinctEchoSubstrings(string text)
    {
    }
};