/****************************************************
Date: Oct 2nd, 2022
Successful submissions : 0
Successful submissions after timeout : 3
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Incomplete Solution : 0
Wrong Answer/ Partial result : 0
Solved looking at solutions : 0

link: https://leetcode.com/contest/weekly-contest-313
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2427. Number of Common Factors
*/
class Solution1_t
{
public:
  int commonFactors(int a, int b) 
  {
    int mini = min(a, b);
    int maxi = max(a, b);
    
    int ans = 1;
    for(int i = 2; i <= mini; ++i)
    {
      if((mini % i == 0) && (maxi % i == 0))
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2428. Maximum Sum of an Hourglass
*/
class Solution2_t
{
public:
  int maxSum(vector<vector<int>>& grid) 
  {
    int ans = 0;
    
    int r = grid.size();
    int c = grid[0].size();
    
    vector<vector<int>> sumGrid(r, vector<int>(c, 0));
    
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(i == 0)
        {
          sumGrid[i][j] = grid[i][j];
          continue;
        }
        
        sumGrid[i][j] = grid[i][j] + sumGrid[i-1][j];
        if(i > 2)
        {
          sumGrid[i][j] -= grid[i-3][j];
        }
        
        if(i < 2 || j < 2)
        {
          continue;
        }
        
        int sum = sumGrid[i][j] + sumGrid[i][j-1] + sumGrid[i][j-2] - grid[i-1][j] - grid[i-1][j-2];
        ans = max(ans, sum);
      }
    }
    
    return ans;
  }
};

/*
  Q: 2429. Minimize XOR - need to submit to check if all test passes!! no internet as of now!!
*/
class Solution3_t
{
public:
  int minimizeXor(int num1, int num2) 
  {
    int count = 0;
    while(num2 > 0)
    {
      if(num2 & 0x01)
      {
        count++;
      }
      
      num2 >>= 1;
    }
    
    string num1InStr = "";
    while(num1 > 0)
    {
      num1InStr = ((num1 & 0x01) ? "1" : "0") + num1InStr;
      
      num1 >>= 1;
    }
    
    int ans = 0;
    int l = num1InStr.size();
    for(int i = 0; i < l; ++i)
    {
      ans <<= 1;
      if(count > 0)
      {
        if(num1InStr[i] == '1')
        {
          num1InStr[i] = '0';
          count--;
          ans |= 0x01;
        }
      }
    }
    
    while(count > 0)
    {
      for(int b = 0; b < 32; ++b)
      {
        if(ans & (1 << b))
        {
          continue;
        }
        
        ans |= (1 << b);
        break;
      }
      count--;
    }
    
    return ans;
  }
};

/*
  Q: 2430. Maximum Deletions on a String
*/
class Solution4_t
{
public:
  int deleteString(string s) 
  {
    
  }
};

int main()
{
  Solution3_t s3;
  s3.minimizeXor(25, 72);

  return 0;
}