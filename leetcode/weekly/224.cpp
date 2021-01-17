/****************************************************
Date: Jan 17th, 2021
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-224
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
  Q: 1725. Number Of Rectangles That Can Form The Largest Square
*/
class Solution1_t
{
public:
  int countGoodRectangles(vector<vector<int>>& rectangles) 
  {
    int l = rectangles.size();
    vector<int> sides;
    
    int ans = 0;
    int largest_side = INT_MIN;
    for(vector<int>& rect : rectangles)
    {
      int side = min(rect[0], rect[1]);
      
      if(side > largest_side)
      {
        ans = 1;
        largest_side = side;
      }
      else if(side == largest_side)
      {
        ans++;
      }
      
      sides.push_back(side);
    }
    
    return ans;
  }
};

/*
  Q: 1726. Tuple with Same Product
*/
class Solution2_t
{
public:
  int tupleSameProduct(vector<int>& nums) 
  {
    int l = nums.size();
    unordered_map<int, int> product_freq;
    for(int i = 0; i < l; ++i)
    {
      for(int j = 0; j < l; ++j)
      {
        if(i == j)
        {
          continue;
        }
        
        int p = nums[i] * nums[j];
        
        product_freq[p]++;
      }
    }
    
    int ans = 0;
    for(auto pf : product_freq)
    {       
      int pairs = pf.second / 2;
      if(pairs == 2)
      {
        ans++;
      }
      else if(pairs > 2)
      {
        ans += ((pairs * (pairs-1)) >> 1);  //nc2
      }
    }
    
    return (ans * 8);
  }
};

/*
  Q: 1727. Largest Submatrix With Rearrangements - not complete!
*/
class Solution3_t
{
public:
  int largestSubmatrix(vector<vector<int>>& matrix) 
  {
    for(vector<int>& row : matrix)
    {
      sort(row.begin(), row.end());
    }
    
    int r = matrix.size();
    int c = matrix[0].size();
    
    int ans = 0;
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if((i == 0 && j == 0) || (matrix[i][j] == 0))
        {
          continue;
        }
        
        if(i == 0)
        {
          matrix[i][j] += matrix[i][j-1];
        }
        else if(j == 0)
        {
          matrix[i][j] += matrix[i-1][j];
        }
        else
        {
          
        }
        
        ans = max(ans, matrix[i][j]);
      }
    }
    
    return ans;
  }
};

/*
  Q: 1728. Cat and Mouse II
*/
class Solution4_t
{
public:
  bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) 
  {
      
  }
};