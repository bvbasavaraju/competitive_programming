/****************************************************
Date: May 1st, 2022
Successful submissions : 2
Time expiration : 0
Memory exhausted : 0
Not Solved : 0
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/weekly-contest-291
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2259. Remove Digit From Number to Maximize Result
*/
class Solution1_t
{
public:
  string getString(string number, int pos)
  {
    string ans = number.substr(0, pos);
    if(pos+1 < number.size())
    {
      ans += number.substr(pos+1);
    }
    
    return ans;
  }
public:
  string removeDigit(string number, char digit) 
  {
    int l = number.size();
    
    int i = 0;
    string ans;
    for(i = 0; i < l; ++i)
    {
      if(number[i] == digit)
      {
        if(ans.empty())
        {
          ans = getString(number, i);
        }
        else
        {
          ans = max(ans, getString(number, i));
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 2260. Minimum Consecutive Cards to Pick Up
*/
class Solution2_t
{
public:
  int minimumCardPickup(vector<int>& cards) 
  {
    unordered_map<int, vector<int> > pos;
    
    int i = 0;
    int ans = INT_MAX;
    for(int c : cards)
    {
      if(pos[c].size() > 0)
      {
        ans = min(ans, i - pos[c].back() + 1);
      }
      pos[c].push_back(i);
      i++;
    }
    
    return ans == INT_MAX ? -1 : ans;
  }
};

/*
  Q: 2261. K Divisible Elements Subarrays - wrong answer!!
*/
class Solution3_t
{
public:
  int countDistinct(vector<int>& nums, int k, int p) 
  {
    int l = nums.size();
    
    int ans = 0;
    for(int i = 0; i < l; ++i)
    {
      int j = 0;
      int count = 0;
      for(j = i; j < l; ++j)
      {
        if(nums[j] % p == 0)
        {
          count++;
        }
        
        if(count == k)
        {
          break;
        }
      }
      
      ans += (j-i + 1);
    }
    
    return ans;
  }
};

/*
  Q: 2262. Total Appeal of A String - wrong answer!
*/
class Solution4_t
{
public:
  long long appealSum(string s) 
  {
    long long ans = 0;
    int l = s.size();
    for(int i = 1; i <= l; ++i)
    {
      for(int j = 0; j < l; ++j)
      {
        int k = j;
        int count = 0;
        int freq[26] = {0};
        while((count < i) && (k < l))
        {
          freq[s[k]-'a']++;
          if(freq[s[k]-'a'] == 1)
          {
            ans++;
          }
          count++;
          k++;
        }
      }
    }
    
    return ans;
  }
};