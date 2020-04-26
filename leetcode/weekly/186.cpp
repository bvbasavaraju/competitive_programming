/****************************************************
Date: April 26th, 2020
Successful submissions : 1
Time expiration : 1
Not Solved : 0
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-186
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: 1422. Maximum Score After Splitting a String
*/
class Solution1_t 
{
public:
  int maxScore(string s) 
  {
    int total_one_count = 0;
    for(char ch : s)
    {
      if(ch == '1')
      {
        total_one_count++;
      }
    }
    
    int ans = 0;
    int zero_count = 0;
    int one_count = total_one_count;
    
    int l = s.size();
    for(int i = 0; i < l - 1; i++)
    {
      char ch = s[i];
      if(ch == '0')
      {
        zero_count++;
      }
      else
      {
        one_count--;
      }
      
      ans = max(ans, (zero_count + one_count));
    }
    
    
    return ans;
  }
};

/*
  Q: 1423. Maximum Points You Can Obtain from Cards
*/
class Solution2_t
{
public:
  int maxScore(vector<int>& cardPoints, int k) 
  {
    int sum_s = 0;
    int l = cardPoints.size();
    for(int i = 0; i < k; i++)
    {
      sum_s += cardPoints[i];
    }
    
    if(l == k)
    {
      return sum_s;
    }
    
    int sum_e = 0;
    int ans = sum_s;
    int pos_s = k - 1;
    int pos_e = l - 1;
    for(int i = 0; i < k; ++i)
    {
      sum_s -= cardPoints[pos_s--];
      sum_e += cardPoints[pos_e--];
      ans = max(ans, sum_s + sum_e);
    }
    
    return ans;
  }
};

/*
  Q: 1424. Diagonal Traverse II - My algorithm solution time limit exceeded! But After checking at the other solution. able to solve!
*/
class Solution3_t
{
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
  {
    if(nums.empty())
    {
      return {};
    }

    //Below code is after checking for solution in Discussion!!
    int r = nums.size();
    int max_col_length = 0;
    int final_length = 0;
    unordered_map<int, vector<int> > diag_nums;
    for(int i = r - 1; i >=0; --i)
    {
      int c = nums[i].size();
      for(int j = 0; j < c; ++j)
      {
        diag_nums[i + j].push_back(nums[i][j]);
      }
      max_col_length = max(max_col_length, c);
      final_length += c;
    }

    int p = 0;
    vector<int> ans(final_length);
    for(int i = 0; i < r + max_col_length; ++i)
    {
      for(int v : diag_nums[i])
      {
        ans[p++] = v;
      }
    }

    return ans;
    /*  //Below code exceeded the time limit. Time optimization can be improved!!
    if(nums.empty())
    {
      return {};
    }
    
    vector<int> ans;
    int r = nums.size();
    int max_col_length = 0;
    unordered_map<int, int> row_pos;
    for(int i = 0; i < r; ++i)
    {      
      max_col_length = max(max_col_length, static_cast<int>(nums[i].size()));
      
      int row = i;
      int col = 0;
      while(row >= 0)
      {
        if(row_pos.count(row) > 0)
        {
          col = row_pos[row];
        }
        row_pos[row] = col + 1; // next run it should be next column!
        
        if(col < nums[row].size())
        {
          ans.push_back(nums[row][col]);
        }

        row--;
      }
    }
    
    for(int i = 0; i < max_col_length; ++i)
    {
      int row = r - 1;
      int col = 1;
      while(row >= 0)
      {
        col = row_pos[row];
        row_pos[row] = col + 1; // next run it should be next column!

        if(col < nums[row].size())
        {
          ans.push_back(nums[row][col]);
        }

        row--;
      }
    }
    return ans;*/
  }
};

/*
  Q: 1425. Constrained Subset Sum
*/
class Solution4_t
{
public:
  int constrainedSubsetSum(vector<int>& nums, int k) 
  {
  }
};