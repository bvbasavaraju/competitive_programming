/****************************************************
Date: Sept 18th, 2022
Successful submissions : 0
Successful submissions after timeout : 3
Time expiration : 1 (solved after looking at solution)
Memory exhausted : 0
Not Solved : 2
Incomplete Solution : 0
Wrong Answer/ Partial result : 0
Solved looking at solutions : 0

link: https://leetcode.com/contest/weekly-contest-311
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2413. Smallest Even Multiple
*/
class Solution1_t
{
public:
  int smallestEvenMultiple(int n) 
  {
    int ans = n;
    for(; ans <= n*2; ans <<= 1)
    {
      if(ans%2 == 0 && (ans%n == 0))
      {
        break;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2414. Length of the Longest Alphabetical Continuous Substring
*/
class Solution2_t
{
public:
  int longestContinuousSubstring(string s) 
  {    
    int p = 0;
    int ans = 1;
    int l = s.size();
    for(int i = 1; i < l; ++i)
    {
      if((s[i] - s[i-1]) != 1)
      {
        p = i;
        continue;
      }
      
      ans = max(ans, (i - p + 1));
    }
    
    return ans;
  }
};

/*
  Q: 2415. Reverse Odd Levels of Binary Tree
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
private:
  void collect(TreeNode* node, int level, vector<stack<int>>& vals)
  {
    if(node == nullptr)
    {
      return;
    }
    
    if(level > vals.size())
    {
      stack<int> st;
      st.push(node->val);
      
      vals.push_back(st);
    }
    else
    {
      vals[level-1].push(node->val);
    }
    
    collect(node->left, level+1, vals);
    collect(node->right, level+1, vals);
  }
  
  void reverse(TreeNode* node, int level, vector<stack<int>>& vals)
  {
    if(node == nullptr)
    {
      return;
    }

    reverse(node->left, level+1, vals);
    reverse(node->right, level+1, vals);
    
    if(level % 2 != 0)
    {
      node->val = vals[level].top();
      vals[level].pop();
    }

  }
  
public:
  TreeNode* reverseOddLevels(TreeNode* root) 
  {
    vector< stack<int> > vals;
    
    collect(root, 1, vals);
    reverse(root, 0, vals);
    
    return root;
  }
};

/*
  Q: 2416. Sum of Prefix Scores of Strings - initial solution giving TLE. after looking at solution, solved it correctly
*/
class Solution4_t
{
private:
  
  struct Node_t
  {
    Node_t* nodes[26];
    int count;
  };
  
  class Trie_t
  {
    Node_t* root;
  public:
    Trie_t()
    {
      root = new Node_t();
    }
    
    void insert(const string& word)
    {
      Node_t* node = root;
      
      for(char ch : word)
      {
        if(node->nodes[ch - 'a'] == nullptr)
        {
          node->nodes[ch - 'a'] = new Node_t();
        }
        
        node = node->nodes[ch - 'a'];
        node->count++;
      }
    }
    
    int getCount(const string& word)
    {
      Node_t* node = root;
      
      int count = 0;
      for(char ch : word)
      {
        if(node->nodes[ch - 'a'] == nullptr)
        {
          break;
        }
        
        node = node->nodes[ch-'a'];
        count += node->count;
      }
      
      return count;
    }
  };
  
public:
  vector<int> sumPrefixScores(vector<string>& words) 
  {
    Trie_t trie;
    
    for(const string& word : words)
    {
      trie.insert(word);
    }
    
    vector<int> ans;
    for(const string& word : words)
    {
      ans.push_back(trie.getCount(word));
    }
    
    return ans;
  }
};