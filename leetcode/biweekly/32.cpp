/****************************************************
Date: August 8th, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-32
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
  Q: 1539. Kth Missing Positive Number
*/
class Solution1_t
{
public:
  int findKthPositive(vector<int>& arr, int k) 
  {
    unordered_set<int> a;
    for(int v : arr)
    {
      a.insert(v);
    }
    
    vector<int> missing;
    for(int i = 1; i <= 2000; ++i)
    {
      if(a.find(i) == a.end())
      {
        missing.push_back(i);
          
        if( missing.size() >= k)
        {
          break;
        }
      }
    }
    
    return missing[k-1];
  }
};

/*
  Q: 1540. Can Convert String in K Moves - yet to complete
*/

class Solution2_t
{
public:
  bool canConvertString(string s, string t, int k) 
  {
    unordered_set<int> diffs;
    if(s.size() != t.size())
    {
      return false;
    }
    
    int l = s.size();
    for(int i = 0; i < l; ++i)
    {
      int d = abs(s[i] - t[i]);
      if(d > 0)
      {
        diffs.insert(d);
      }
    }
    
    
  }
};

/*
  Q: 1541. Minimum Insertions to Balance a Parentheses String
*/
class Solution3_t
{
public:
  int minInsertions(string s) 
  {
      
  }
};

/*
  Q: 1542. Find Longest Awesome Substring
*/

class Solution4_t 
{
public:
    int longestAwesome(string s) 
    {
        
    }
};