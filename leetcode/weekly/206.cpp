/****************************************************
Date: Sept 13th, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1
link: https://leetcode.com/contest/weekly-contest-206
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
  Q: 1582. Special Positions in a Binary Matrix
*/
class Solution1_t
{
private:
  bool isColumnSpecial(vector<vector<int>>& mat, int total_rows, int c)
  {
    int count = 0;
    for(int i = 0; i < total_rows; ++i)
    {
      if(mat[i][c] == 1)
      {
        count++;
      }
      
      if(count > 1)
      {
        return false;
      }
    }
    
    return (count == 1);
  }
public:
  int numSpecial(vector<vector<int>>& mat) 
  {
    int r = mat.size();
    int c = mat[0].size();
    
    int ans = 0;
    for(int i = 0; i < r; ++i)
    {
      int count = 0;
      int column = -1;
      for(int j = 0; j < c; ++j)
      {
        if(mat[i][j] == 1) 
        {
          count++;
          column = j;
        }
      }
      
      if((count == 1) && (column >= 0 && column < c) && isColumnSpecial(mat, r, column))
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1583. Count Unhappy Friends
*/
class Solution2_t
{
public:
  int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) 
  {
    int ans = 0;
    for(vector<int>& p : pairs)
    {
      int x = p[0];
      int y = p[1];
      
      vector<int>& p1pref = preferences[p1];
      for(int pref : p1pref)
      {
        
      }
      if(preferences[p1][0] != p2)
      {
        ans++;
      }
      if(preferences[p2][0] != p1)
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1584. Min Cost to Connect All Points
*/
class Solution3_t
{
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        
    }
};

/*
  Q: 1585. Check If String Is Transformable With Substring Sort Operations
*/
class Solution4_t
{
public:
    bool isTransformable(string s, string t) 
    {
        
    }
};