/****************************************************
Date: Jan 31st, 2021
Successful submissions : 2
Time expiration : 0
Not Solved : 0
Wrong Answer/ Partial result : 1  //this was corrected after looking at the discussion

link: https://leetcode.com/contest/weekly-contest-226
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
  Q: 1742. Maximum Number of Balls in a Box
*/
class Solution1_t
{
public:
  int countBalls(int lowLimit, int highLimit) 
  {    
    int ans = INT_MIN;
    unordered_map<int, int> box;
    for(int i = lowLimit; i <= highLimit; ++i)
    {
      int sum = 0;
      
      int num = i;
      while(num > 0)
      {
        sum += num%10;
        num /= 10;
      }
      
      box[sum]++;
      ans = max(ans, box[sum]);
    }
    
    return ans;
  }
};

/*
  Q: 1743. Restore the Array From Adjacent Pairs
*/
class Solution2_t
{
public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
  {
    int l = adjacentPairs.size();
    
    unordered_map<int, vector<int>> vertex;
    for(vector<int>& ap : adjacentPairs)
    {
      vertex[ap[0]].push_back(ap[1]);
      vertex[ap[1]].push_back(ap[0]);
    }
    
    int start;
    for(auto it : vertex)
    {
      if(it.second.size() == 1)
      {
        start = it.first;
      }
    }
    
    vector<int> ans(l+1);
    
    ans[0] = start;
    for(int i = 1; i <= l; ++i)
    {
      vector<int>& v = vertex[start];
      
      int next = v[0];
      if(v.size() == 2)
      {
        next = ((i > 1) && (v[0] != ans[i-2])) ? v[0] : v[1];
      }
      
      ans[i] = next;
      start = next;
    }
    
    return ans;
  }
};

/*
  Q: 1744. Can You Eat Your Favorite Candy on Your Favorite Day? - after looking at discussion
*/
class Solution3_t
{
public:
  vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) 
  {    
    vector<long long> candiesSum;
    long long sum = 0;
    for(int& count : candiesCount)
    {
      sum += count;
      candiesSum.push_back(sum);
    }
    
    int l = queries.size();
    
    vector<bool> ans;
    for(int i = 0; i < l; ++i)
    {
      long long ft = queries[i][0];
      long long fd = queries[i][1];
      long long limit = queries[i][2];
      
      if((fd + 1) * limit > (ft == 0? 0:candiesSum[ft-1]) &&  candiesSum[ft] >= (fd+1) * 1)
      {
        ans.push_back(true);
      }
      else
      {
        ans.push_back(false);
      }
    }
    
    return ans;
  }
};

/*
  Q: 1745. Palindrome Partitioning IV
*/

class Solution4_t
{
public:
  bool checkPartitioning(string s) 
  {
      
  }
};