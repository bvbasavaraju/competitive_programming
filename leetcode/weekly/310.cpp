/****************************************************
Date: Sept 11th, 2022
Successful submissions : 0
Successful submissions after timeout : 2
Time expiration : 0
Memory exhausted : 0
Not Solved : 2
Incomplete Solution : 0
Wrong Answer/ Partial result : 0
Solved looking at solutions : 0

link: https://leetcode.com/contest/weekly-contest-310
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2404. Most Frequent Even Element
*/
class Solution1_t
{
public:
  int mostFrequentEven(vector<int>& nums) 
  {
    map<int, int> freq;
    for(int n : nums)
    {
      if(n % 2 == 0)
      {
        freq[n]++;
      }
    }
    
    if(freq.size() == 0)
    {
      return -1;
    }
    
    map<int, set<int>> frequent;
    for(auto it = freq.begin() ; it != freq.end(); ++it)
    {
      frequent[it->second].insert(it->first);
    }
    
    auto it = frequent.end();
    it--;
    return *it->second.begin();
  }
};

/*
  Q: 2405. Optimal Partition of String
*/
class Solution2_t
{
public:
  int partitionString(string s) 
  {
    vector<int> freq(26, 0);
    
    int ans = 0;
    int start = 0;
    int l = s.size();
    for(int i = 0; i < l; ++i)
    {
      freq[s[i] - 'a']++;
      if(freq[s[i] - 'a'] > 1)
      {
        ans++;
   
        while(start < i)
        {
          freq[s[start] - 'a']--;
          start++;
        }
      }
    }
    
    return start < l ? ans+1 : ans;
  }
};

/*
  Q: 2406. Divide Intervals Into Minimum Number of Groups
*/
class Solution3_t
{
public:
  int minGroups(vector<vector<int>>& intervals) 
  {
    
  }
};

/*
  Q: 2407. Longest Increasing Subsequence II
*/
class Solution4_t
{
public:
  int lengthOfLIS(vector<int>& nums, int k) 
  {
      
  }
};