/****************************************************
Date: June 13th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-28
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
  Q: 1475. Final Prices With a Special Discount in a Shop
*/
class Solution1_t
{
public:
  vector<int> finalPrices(vector<int>& prices) 
  {
    int l = prices.size();
    
    for(int i = 0; i < l - 1; ++i)
    {
      for(int j = i + 1; j < l; ++j)
      {
        if(prices[j] <= prices[i])
        {
          prices[i] -= prices[j];
          break;
        }
      }
    }
    
    return prices;
  }
};

/*
  Q: 1476. Subrectangle Queries
*/
/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
class SubrectangleQueries 
{
private:
  int r;
  int c;
  vector<vector<int>> mat;  
public:
  SubrectangleQueries(vector<vector<int>>& rectangle) 
  {
    mat = rectangle;
    r = mat.size();
    c = mat[0].size();
  }

  void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) 
  {    
    int i_max = min(row2, r);
    int j_max = min(col2, c);
    
    for(int i = max(row1, 0); i <= i_max; ++i)
    {
      for(int j = max(col1, 0); j <= j_max; ++j)
      {
        mat[i][j] = newValue;
      }
    }
  }

  int getValue(int row, int col) 
  {
    return mat[row][col];
  }
};

/*
  Q: 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
*/
class Solution3_t
{
public:
  int minSumOfLengths(vector<int>& arr, int target) 
  {
    int l = arr.size();
    
    int sp = 0;
    int sum = 0;
    
    vector<int> lengthTargetSum;
    for(int i = 0; i < l; ++i)
    {
      //#if 0
      int temp = sum + arr[i];
      if(temp >= sum)
      {
        sum = temp;
        if(temp > target)
        {
          sum -= arr[sp];
          sp++;
          /*if(sum == target)
          {
            lengthTargetSum.push_back(i - sp);
            sp = i;
            sum = arr[sp];
            //sum -= arr[sp];
            //sp++;
          }
          else
          {
            sp++;
          }*/
        }
      }
      else
      {
        sum -= arr[sp];
        sp++;
        /*if(sum == target)
        {
          lengthTargetSum.push_back(i - sp);
          sp = i;
          sum = arr[sp];
          //sum -= arr[sp];
          //sp++;
        }
        else
        {
          sp++;
        }*/
      }
      //#endif
      
      //sum += arr[i];
      if(sum == target)
      {
        lengthTargetSum.push_back(i - sp + 1);
        sp = i + 1;
        sum = 0;
        //sp = i;
        //sum = arr[sp];
        //sum -= arr[sp];
        //sp++;
      }
    }
    
    if(lengthTargetSum.size() < 2)
    {
      return -1;
    }
    
    if(lengthTargetSum.size() > 2)
    {
      sort(lengthTargetSum.begin(), lengthTargetSum.end());
    }
    
    // for(auto x : lengthTargetSum)
    // {
    //   printf("%d, ", x);
    // }
    // printf("\n");
    
    return lengthTargetSum[0] + lengthTargetSum[1];
  }
};

/*
  Q: 5421. Allocate Mailboxes
*/
class Solution4_t
{
public:
  int minDistance(vector<int>& houses, int k) 
  {
      
  }
};