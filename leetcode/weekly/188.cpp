/****************************************************
Date: May 10th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-188
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
  Q: 1441. Build an Array With Stack Operations
*/
class Solution1_t
{
public:
  vector<string> buildArray(vector<int>& target, int n) 
  {
    int l = target.size();
    
    int num = 1;    
    vector<string> ans;
    
    for(int i = 0; i < l; ++i)
    {
      if(target[i] != num)
      {
        while(target[i] != num)
        {
          ans.push_back("Push");
          ans.push_back("Pop");
          num++;
        }

      }
      
      ans.push_back("Push");
      num++;
    }
    
    while(target[l-1] == n && num <= n)
    {
      ans.push_back("Push");
      num++;
    }
      
    
    return ans;
  }
};

/*
  Q: 1442. Count Triplets That Can Form Two Arrays of Equal XOR
*/
class Solution2_t
{
public:
  int countTriplets(vector<int>& arr) 
  {
    int l = arr.size();
    if(l < 2)
    {
      return 0;
    }
    
    for(int i = 1; i < l; i++)
    {
      arr[i] ^= arr[i-1];
    }
    
    int ans = 0;
    for(int i = 0; i < l - 1; ++i)
    {
      for(int k = i + 1; k < l; ++k)
      {
        for(int j = i + 1; j <= k; ++j)
        {
          int a = (i == 0) ? arr[j - 1] : arr[j - 1] ^ arr[i - 1];
          int b = arr[k] ^ arr[j - 1];
          
          if(a == b)
            ans++;
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1443. Minimum Time to Collect All Apples in a Tree
*/
class Solution3_t
{
public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
  {
      
  }
};

/*
  Q: 1444. Number of Ways of Cutting a Pizza
*/
class Solution4_t
{
public:
  int ways(vector<string>& pizza, int k) 
  {
      
  }
};