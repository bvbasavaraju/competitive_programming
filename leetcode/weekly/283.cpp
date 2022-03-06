/****************************************************
Date: Mar 6th, 2022
Successful submissions : 1
Time expiration : 1
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-283
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
  Q: 2194. Cells in a Range on an Excel Sheet
*/
class Solution1_t
{
public:
  vector<string> cellsInRange(string s) 
  {
    vector<string> ans;
    for(int c = s[0]; c <= s[3]; ++c)
    {
      string col(1, c);
      for(int r = s[1]; r <= s[4]; ++r)
      { 
        string row(1, r);
        ans.push_back(col + row);
      }
    }
    
    return ans;
  }
};

/*
  Q: 2195. Append K Integers With Minimal Sum - time limit exceeded
*/
class Solution2_t
{
public:
  long long minimalKSum(vector<int>& nums, int k) 
  {
    /* time limit exceeded
    unordered_map<int, int> freq;
    for(int n : nums)
    {
      freq[n]++;
    }
    
    int i = 1;
    long long ans = 0;
    while(k > 0)
    {
      while(freq[i] != 0)
      {
        i++;
      }
      
      ans += i;
      i++;
      k--;
    }
    
    return ans;*/
    /* mem limit exceeded
    vector<int> all_nums(1e9+1, 0);
    for(int n : nums)
    {
      all_nums[n]++;
    }
    
    long long ans = 0;
    for(int i = 1; i <= 1e9; ++i)
    {
      if(all_nums[i] == 0)
      {
        ans += i;
        k--;
        
        if(k <= 0)
        {
          break;
        }
      }
    }
    
    return ans;*/
  }
};

/*
  Q: 2196. Create Binary Tree From Descriptions - yet to complete
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
class Solution3_t
{
public:
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
  {
    unordered_set<int> childNodes;
    unordered_map<int, TreeNode*> nodes;
    for(vector<int> desc : descriptions)
    {
      TreeNode* p = nullptr;
      if(nodes.count(desc[0]) == 0)
      {
        p = new TreeNode(desc[0]);
        nodes[desc[0]] = p;
      }
      else
      {
        p = nodes[desc[0]];
      }

      TreeNode* c = nullptr;
      if(nodes.count(desc[1]) == 0)
      {
        c = new TreeNode(desc[1]);
        nodes[desc[1]] = c;
      }
      else
      {
        c = nodes[desc[1]];
      }
      
      if(desc[2] == 1)
      {
        p->left = c;
      }
      else
      {
        p->right = c;
      }

      childNodes.insert(desc[1]);
    }
    
    TreeNode* root = nullptr;
    for(vector<int> desc : descriptions)
    {
      if(childNodes.count(desc[1]) == 0)
      {
        root = nodes[desc[1]]; 
      }
    }
    
    return root;
  }
};

/*
  Q: 2197. Replace Non-Coprime Numbers in Array - yet to solve  
*/
class Solution4_t
{
public:
  vector<int> replaceNonCoprimes(vector<int>& nums) 
  {
      
  }
};