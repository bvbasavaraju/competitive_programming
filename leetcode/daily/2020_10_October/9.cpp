/****************************************************
Date: Oct 9th

link: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3488/
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
    Q: Serialize and Deserialize BST

    Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or 
    memory buffer, or transmitted across a network connection link to be reconstructed later in the same or 
    another computer environment.

    Design an algorithm to serialize and deserialize a binary search tree. 
    There is no restriction on how your serialization/deserialization algorithm should work. 
    You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to 
    the original tree structure.

    The encoded string should be as compact as possible.

    Example 1:
        Input: root = [2,1,3]
        Output: [2,1,3]

    Example 2:
        Input: root = []
        Output: []
    
    Constraints:
        The number of nodes in the tree is in the range [0, 104].
        0 <= Node.val <= 104
        The input tree is guaranteed to be a binary search tree.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
private:
    void collect(TreeNode *node, string &data)
    {
        if (node == NULL)
        {
            data += "-1;";
            return;
        }

        data += std::to_string(node->val) + ";";
        collect(node->left, data);
        collect(node->right, data);
    }

    TreeNode *Create(queue<int> &vals)
    {
        int val = vals.front();
        vals.pop();

        if (val < 0)
        {
            return NULL;
        }

        TreeNode *node = new TreeNode(val);
        node->left = Create(vals);
        node->right = Create(vals);

        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans;
        collect(root, ans);

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int s = 0;
        int p = 0;
        int l = data.size();

        queue<int> vals;
        while ((p < l - 1) && (s < l))
        {
            p = data.find_first_of(';', p);
            string n = data.substr(s, p - s);
            int num = stoi(n);

            vals.push(num);

            s = p + 1;
            p++;
        }

        return Create(vals);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;