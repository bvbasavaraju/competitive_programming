/****************************************************
Date: Feb 21th, 2021
Successful submissions : 2
Time expiration : 1
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-229
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
  Q: 1768. Merge Strings Alternately
*/
class Solution1_t
{
public:
  string mergeAlternately(string word1, string word2) 
  {
    int l = min(word1.size(), word2.size());
    
    int i = 0;
    string ans = "";
    for(;i < l; ++i)
    {
      ans += word1[i];
      ans += word2[i];
    }
    
    if(i < word1.size())
    {
      ans += word1.substr(i);
    }
    if(i < word2.size())
    {
      ans += word2.substr(i);
    }
    
    return ans;
  }
};

/*
  Q: 1769. Minimum Number of Operations to Move All Balls to Each Box - should be optimized!
*/
class Solution2_t
{
public:
  vector<int> minOperations(string boxes) 
  {
    int l = boxes.size();
    
    vector<int> ballPos;
    for(int i = 0; i < l; ++i)
    {
      if(boxes[i] == '1')
      {
        ballPos.push_back(i);
      }
    }
    
    vector<int> ans(l, 0);
    for(int i = 0; i < l; ++i)
    {
      int posDiff = 0;
      for(int p : ballPos)
      {
        posDiff += abs(i-p);
      }
      ans[i] = posDiff;
    }
    
    return ans;
  }
};

/*
  Q: 1770. Maximum Score from Performing Multiplication Operations - tme limit exceeded
*/
class Solution3_t
{
private:
  int getMax(vector<int>& m, int p, deque<int> nums, int& ans)
  {
    if(p >= m.size())
    {
      return 0;
    }
    
    deque<int> nums_ = nums;
    
    int val1 = m[p] * nums_.front();
    nums_.pop_front();
    val1 += getMax(m, p+1, nums_, ans);
    
    int val2 = m[p] * nums.back();
    nums.pop_back();
    val2 += getMax(m, p+1, nums, ans);
    
    int retVal = max(val1, val2);
    ans = max(ans, retVal);
    
    return retVal;
  }
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) 
  {
    int ans = 0;
    
    deque<int> dq(nums.begin(), nums.end());
    getMax(multipliers, 0, dq, ans);
    
    return ans;
  }
};

/*
  Q: 1771. Maximize Palindrome Length From Subsequences
*/

class Solution 
{
public:
  int longestPalindrome(string word1, string word2) 
  {
      
  }
};