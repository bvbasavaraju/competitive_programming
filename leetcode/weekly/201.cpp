/****************************************************
Date: aug 9nd, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-201
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
  Q: 1544. Make The String Great
*/
class Solution 
{
private:
  bool isGoodString(string& s, string& possible_good_str) 
  {
    int l = s.size();
    bool retVal = true;
    bool add_to_letter = true;
    for(int i = 0; i < l; ++i)
    {
      add_to_letter = true;
      if((i < l - 1) && s[i] != s[i+1])
      {
        int one = std::tolower(s[i]);
        int two = std::tolower(s[i+1]);
        if(one == two)
        {
          ++i;
          retVal = false;
          add_to_letter = false;
        }
      }
      
      if(add_to_letter == true)
      {
        possible_good_str += s[i];
      }
    }
    
    if(possible_good_str.empty() && retVal == true)
    {
      possible_good_str = s;
    }
    
    return retVal;
  }
  
public:
  string makeGood(string s) 
  {
    string ans = "";
    if(!s.empty())
    {
      while(!isGoodString(s, ans))
      {
        s = ans;
        ans = "";
      }
    }
    
    return ans;
  }
};

/*
  Q: 1545. Find Kth Bit in Nth Binary String
*/
class Solution 
{
public:
    char findKthBit(int n, int k) 
    {
        
    }
};

/*
  Q: 1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
*/
class Solution 
{
public:
    int maxNonOverlapping(vector<int>& nums, int target) 
    {
        
    }
};

/*
  Q: 1547. Minimum Cost to Cut a Stick
*/
class Solution 
{
public:
    int minCost(int n, vector<int>& cuts) 
    {
        
    }
};