/****************************************************
Date: April 4th, 2021
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-235
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
  Q: 1816. Truncate Sentence
*/
class Solution1_t
{
public:
  string truncateSentence(string s, int k) 
  {
    string ans = "";
    
    size_t p = 0;
    while((p != std::string::npos) && (k > 0))
    {
      if(!ans.empty())
      {
        ans += " ";
      }
      
      k--;
      size_t temp = s.find_first_of(' ', p);
      ans += s.substr(p, temp-p);
      
      p = temp+1;
    }
    
    return ans;
  }
};

/*
  Q: 1817. Finding the Users Active Minutes
*/
class Solution2_t
{
public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
  {
    unordered_map<int, unordered_set<int> > uam;
    for(vector<int>& l : logs)
    {
      uam[l[0]].insert(l[1]);
    }
    
    vector<int> ans(k, 0);
    for(auto& u : uam)
    {
      if(u.second.size() <= k)
      {
        ans[u.second.size()-1]++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1818. Minimum Absolute Sum Difference
*/
class Solution3_t
{
public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
  {
    int l = nums1.size();
    int ans = 0;
    int maxP = -1;
    int maxDiff = 0;
    static const int MOD = 1e9 + 7;
    for(int i = 0; i < l; ++i)
    {
      int diff = abs(nums1[i] - nums2[i]);
      
      if(diff > maxDiff)
      {
        maxP = i;
        maxDiff = diff;
      }
      
      ans = (ans + diff) % MOD;
    }
    
    if(maxP >= 0)
    {
      int currDiff = abs(nums1[maxP] - nums2[maxP]);
      
      int num = nums2[maxP];
      int newDiff = currDiff;
      for(int& n : nums1)
      {
        newDiff = min(newDiff, abs(num - n));
      }
      
      ans = (ans - currDiff) % MOD;
      ans = (ans + newDiff) % MOD;
    }
    
    return ans;
  }
};

/*
  Q: 1819. Number of Different Subsequences GCDs
*/
class Solution4_t
{
public:
  int countDifferentSubsequenceGCDs(vector<int>& nums) 
  {
    int l = nums.size();
    
    for()
  }
};