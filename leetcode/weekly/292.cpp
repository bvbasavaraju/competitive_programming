/****************************************************
Date: May 8th, 2022
Successful submissions : 2
Time expiration : 0
Memory exhausted : 0
Not Solved : 0
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/weekly-contest-292
****************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
  Q: 2264. Largest 3-Same-Digit Number in String
*/
class Solution1_t
{
public:
  string largestGoodInteger(string num) 
  {
    int l = num.size();
    
    vector<string> nums;
    for(int i = 2; i < l; ++i)
    {
      if((num[i-2] == num[i-1]) && (num[i-1] == num[i]))
      {
        nums.push_back(num.substr(i-2, 3));
      }
    }
    
    if(nums.size() > 0)
    {
      sort(nums.begin(), nums.end());
    }
    
    return nums.empty() ? "" : nums.back();
  }
};

/*
  Q: 2265. Count Nodes Equal to Average of Subtree
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
class Solution2_t
{
private:
  int getSum(TreeNode* node, unordered_map<uintptr_t, int>& db, int& ans)
  {
    if(node == nullptr)
    {
      return 0;
    }
    
    int ls = getSum(node->left, db, ans);
    int rs = getSum(node->right, db, ans);

    int count = db[reinterpret_cast<uintptr_t>(node)];
    int sum = (node->val + ls + rs);
    int avg = sum/count;
    if(avg == node->val)
    {
      ans++;
    }
    
    return sum;
  }

  int getCount(TreeNode* node, unordered_map<uintptr_t, int>& db)
  {
    if(node == nullptr)
    {
      return 0;
    }

    int lc = getCount(node->left, db);
    int rc = getCount(node->right, db);

    int count = 1 + lc + rc;
    db[reinterpret_cast<uintptr_t>(node)] = count;
    return count;
  }

public:
  int averageOfSubtree(TreeNode* root) 
  {
    unordered_map<uintptr_t, int> db;
    getCount(root, db);

    int ans = 0;
    getSum(root, db, ans);
    
    return ans;
  }
};

/*
  Q: 2266. Count Number of Texts - not all test cases works
*/
class Solution3_t
{
public:
  int countTexts(string pk) 
  {
    const int MOD = 1e9 + 7;
    
    int l = pk.size();
    
    int ans = 0;
    for(int i = 0; i < l; ++i)
    {
      int count = 1;
      if((i+1 < l) && (pk[i] == pk[i+1]))
      {
        count++;
        if((i+2 < l) && (pk[i+1] == pk[i+2]))
        {
          count++;
        }
        
        if((i+3 < l) && ((pk[i] == '7' && (pk[i+2] == pk[i+3])) || (pk[i] == '9' && (pk[i+2] == pk[i+3]))))
        {
          count++;
        }
      }
      
      long long temp = ans + (count == 4 ? 8 : (count == 3 ? 4 : (count == 2 ? 2 : 1)));
      
      ans = (temp % MOD);
    }
    
    return ans;
  }
};

/*
  Q: 2267. Check if There Is a Valid Parentheses String Path -  time limit exceeded!
*/
class Solution4_t
{
private:
  bool isValid(const string& str)
  {
    stack<char> st;
    for(char ch : str)
    {
      if(ch == ')')
      {
        if(st.empty() || st.top() != '(')
        {
          return false;
        }
        
        st.pop();
      }
      else
      {
        st.push('(');
      }
    }
    
    return st.empty() ? true : false;
  }
public:
  bool hasValidPath(vector<vector<char>>& grid) 
  {
    int r = grid.size();
    int c = grid[0].size();
    
    vector< vector< vector<string> > > str(r, vector< vector<string> >(c));
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(i == 0 && j == 0)
        {
          str[i][j].push_back("" + string(1, grid[i][j]));
          continue;
        }
        
        if(i == 0) 
        {
          str[i][j].push_back(str[i][j-1][0] + string(1, grid[i][j]));
          continue;
        }
        
        if(j == 0)
        {
          str[i][j].push_back(str[i-1][j][0] + string(1, grid[i][j]));
          continue;
        }
        
        for(string s : str[i-1][j])
        {
          str[i][j].push_back(s + string(1, grid[i][j]));
        }
        for(string s : str[i][j-1])
        {
          str[i][j].push_back(s + string(1, grid[i][j]));
        }
        
        if(i == r-1 && j == c-1)
        {
          if(isValid(str[i][j].back()))
          {
            return true;
          }
        }
      }
    }
    
    // vector<string>& pars = str[r-1][c-1];
    // for(string s : pars)
    // {
    //   if(isValid(s))
    //   {
    //     return true;
    //   }
    // }
    
    return false;
  }
};