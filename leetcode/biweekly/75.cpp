/****************************************************
Date: April 2nd, 2022
Successful submissions : 2
Time expiration : 1
Not Solved : 0
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-75
****************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
  Q: 2220. Minimum Bit Flips to Convert Number
*/
class Solution1_t
{
public:
  int minBitFlips(int start, int goal) 
  {
    int xored = start ^ goal;
    
    int ans = 0;
    while(xored > 0)
    {
      if(xored & 0x01)
      {
        ans++;
      }
      
      xored >>= 1;
    }
    
    return ans;
  }
};

/*
  Q: 2221. Find Triangular Sum of an Array
*/
class Solution2_t
{
public:
  int triangularSum(vector<int>& nums) 
  {
    int l = nums.size();
    
    int count = l;
    while(count > 0)
    {
      for(int i = 0; i < count-1; ++i)
      {
        nums[i] = (nums[i] + nums[i+1]) % 10;
      }
      
      count--;
    }
    
    return nums[0];
  }
};

/*
  Q: 2222. Number of Ways to Select Buildings - partial answer
*/
class Solution3_t
{
public:
  long long numberOfWays(string s) 
  {
    int l = s.size();
    
    vector<char> what;
    vector<long long> count;
    
    long long oc = s[0] == '0' ? 0 : 1;
    long long zc = s[0] == '0' ? 1 : 0;
    for(int i = 1; i < l; ++i)
    {
      if(s[i-1] != s[i])
      {
        count.push_back(oc == 0 ? zc : oc);
        what.push_back(oc == 0 ? 'Z' : 'O');
        oc = 0;
        zc = 0;
      }
      
      if(s[i] == '0')
      {
        zc++;
      }
      else
      {
        oc++;
      }
    }

    if((zc > 0) || (oc > 0))
    {
      count.push_back(oc == 0 ? zc : oc);
      what.push_back(oc == 0 ? 'Z' : 'O');
    }

    l = what.size();
    if(l < 3)
    {
      return 0;
    }
    
    long long ans = 0;
    for(int i = 0; i < l-2; ++i)
    {
      ans += (count[i] * count[i+1] * count[i+2]);
    }
    
    return ans;
  }
};

/*
  Q: 2223. Sum of Scores of Built Strings TLE
*/
class Solution4_t
{
private:
  int getCount(const string& s1, const string& s2)
  {
    int l = min(s1.size(), s2.size());

    int ans = 0;
    for(int i = 0; i < l; ++i)
    {
      if(s1[i] != s2[i])
      {
        break;
      }

      ans++;
    }

    return ans;
  }
public:
  long long sumScores(string s) 
  {
    int l = s.size();
    
    long long ans = 0;
    for(int i = 0; i < l; ++i)
    {
      string str1 = s.substr(l-1-i);
      string p = s.substr(0, min(i+1, static_cast<int>(str1.size())));
      
      ans += getCount(str1, p);
    }
    
    return ans;
  }
};