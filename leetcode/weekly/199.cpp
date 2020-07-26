/****************************************************
Date: July 26th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-198
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

using namespace std;

/*
  Q: 1528. Shuffle String
*/

class Solution1_t
{
public:
  string restoreString(string s, vector<int>& indices) 
  {
    string ans = s;
    
    int l = indices.size();
    for(int i = 0; i < l; ++i)
    {
      ans[indices[i]] = s[i];
    }
    
    return ans;
  }
};

/*
  Q: 1529. Bulb Switcher IV
*/
class Solution2_t
{
public:
  int minFlips(string target) 
  {
    int ans = 0;
    int l = target.size();
    
    if(l <= 0)
    {
      return ans;
    }
    
    ans = target[0] == '1' ? ans+1 : ans;
    for(int i = 1; i < l; ++i)
    {
      ans = target[i] != target[i-1] ? ans+1 : ans;
    }
    
    return ans;
  }
};

/*
  Q: 1530. Number of Good Leaf Nodes Pairs
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
    int countPairs(TreeNode* root, int distance) 
    {
        
    }
};
/*
  Q: 1531. String Compression II - need to complete
*/

class Solution4_t
{
public:
  int getLengthOfOptimalCompression(string s, int k) 
  {
    int l = s.size();
    if(l <= 0)
    {
      return 0;
    }
    
    int count = 1;
    int pCh = s[0];
    int run_str = s[0];
    
    unordered_map<int, int> pos_len;
    for(int i = 1; i < l; ++i)
    {
      if(pCh != s[i])
      {
        run_str += (count > 1) ? to_string(count) : "";
        pCh = s[i];
        count = 1;
        run_str += s[i];
      }
      else
      {
        count++;
      }
    }
    
    
  }
};