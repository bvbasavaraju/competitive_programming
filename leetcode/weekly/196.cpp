/****************************************************
Date: July 5th, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-196
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
  Q: 1502. Can Make Arithmetic Progression From Sequence
*/
class Solution1_t
{
public:
  bool canMakeArithmeticProgression(vector<int>& arr) 
  {
    int l = arr.size();
    
    sort(arr.begin(), arr.end());
    
    int diff = arr[0] - arr[1];
    for(int i = 1; i < (l-1); ++i)
    {
      int d = arr[i] - arr[i+1];
      if(diff != d)
      {
        return false;
      }
    }
    
    return true;
  }
};

/*
  Q: 1503. Last Moment Before All Ants Fall Out of a Plank
*/
class Solution2_t
{
public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) 
  {
    
  }
};

/*
  Q: 1504. Count Submatrices With All Ones - Not solved 
*/
class Solution3_t
{
private:
  int countMatrix(vector<vector<int>>& mat, int r, int c, int p, int q, int sum)
  {
    int ans = 0;
    vector<vector<int>> dp(r, vector<int>(c, 0));
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        
      }
    }
    
    return ans;
  }
public:
  int numSubmat(vector<vector<int>>& mat) 
  {
    int r = mat.size();
    int c = mat[0].size();
    
    int ans = 0;
    
  }
};

/*
  Q: 1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits
*/
class Solution4_t
{
public:
    string minInteger(string num, int k) 
    {
        
    }
};