/****************************************************
Date: Feb 2, 2020
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-174
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
    Q:  1341. The K Weakest Rows in a Matrix
*/

class Solution1_t
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &m, int k)
    {
        int r = m.size();
        int c = m[0].size();

        map<int, int> sc;
        for (int i = 0; i < r; ++i)
        {
            sc[i] = 0;
            for (int j = 0; j < c; ++j)
            {
                if (m[i][j] > 0)
                {
                    sc[i]++;
                }
            }
        }

        vector<pair<int, int>> result;
        auto it = sc.begin();
        while (it != sc.end())
        {
            result.push_back(make_pair(it->first, it->second));
            it++;
        }

        sort(result.begin(), result.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) -> bool {
            if ((p1.second < p2.second) || ((p1.second == p2.second) && (p1.first < p2.first)))
            {
                return true;
            }

            return false;
        });

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(result[i].first);
        }

        return ans;
    }
};

/*
    Q:  1342. Reduce Array Size to The Half
*/
class Solution2_t
{
public:
    int minSetSize(vector<int> &a)
    {
        int l = a.size();
        map<int, int> m;
        for (int i = 0; i < l; ++i)
        {
            m[a[i]]++;
        }

        vector<int> sizes;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            sizes.push_back(it->second);
        }

        sort(sizes.begin(), sizes.end());

        int ans = 0;
        int s = 0;
        for (int i = sizes.size() - 1; i >= 0; --i)
        {
            //printf("s = %d, size = %d, ans = %d", s, sizes[i], ans);
            if (s + sizes[i] >= l / 2)
            {
                ans++;
                break;
            }

            s += sizes[i];
            ans++;
        }

        return ans;
    }
};

/*
    Q:  1343. Maximum Product of Splitted Binary Tree
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
    int treeSum;
    long long result = 0;

    void GetTreeSum(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        treeSum += root->val;
        GetTreeSum(root->left);
        GetTreeSum(root->right);
    }

    int GetMaxProductSum(TreeNode *n)
    {
        if (!n)
        {
            return 0;
        }

        long long sumLeft = GetMaxProductSum(n->left);
        long long sumRight = GetMaxProductSum(n->right);

        result = max({result, (treeSum - sumLeft) * sumLeft, (treeSum - sumRight) * sumRight});

        return sumLeft + sumRight + n->val;
    }

public:
    int maxProduct(TreeNode *root)
    {
        int mod = 1e9 + 7;
        GetTreeSum(root);
        GetMaxProductSum(root);
        return result % mod;
    }
};

/*
    Q:  1344. Jump Game V -  not solved!!
*/