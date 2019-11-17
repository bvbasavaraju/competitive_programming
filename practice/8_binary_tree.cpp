/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
namespace practice
{

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_t
{
private:
    stack<TreeNode *> s;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

public:
    vector<int> PreOrderTraversal(TreeNode *root)
    {
        vector<int> retVal;
        while (!s.empty() || (root != nullptr))
        {
            if (root != nullptr)
            {
                retVal.push_back(root->val);

                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();
                s.pop();

                root = root->right;
            }
        }

        return retVal;
    }

    vector<int> InOrderTraversal(TreeNode *root)
    {
        vector<int> retVal;

        while (!s.empty() || (root != nullptr))
        {
            if (root != nullptr)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();
                s.pop();

                if (root != nullptr)
                {
                    retVal.push_back(root->val);
                }

                root = root->right;
            }
        }

        return retVal;
    }

    vector<int> PostOrderTraversal(TreeNode *root)
    {
        vector<int> retVal;

        if (root == nullptr)
        {
            return retVal;
        }

        s1.push(root);
        TreeNode *n;
        while (!s1.empty())
        {
            n = s1.top();
            s1.pop();
            s2.push(n);

            if (n->left != nullptr)
            {
                s1.push(n->left);
            }
            if (n->right != nullptr)
            {
                s1.push(n->right);
            }
        }

        while (!s2.empty())
        {
            n = s2.top();
            s2.pop();

            if (n != nullptr)
            {
                retVal.push_back(n->val);
            }
        }

        return retVal;
    }
};

} //namespace practice