/****************************************************
Date: Oct 16th, 2022
Successful submissions : 0
Successful submissions after timeout : 3
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Incomplete Solution : 0
Wrong Answer/ Partial result : 0
Solved looking at solutions : 0

link: https://leetcode.com/contest/weekly-contest-315
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2441. Largest Positive Integer That Exists With Its Negative
*/
class Solution1_t
{
  typedef enum types_t
  {
    none = -1,
    neg = 0,
    pos = 1,
    both = 2
  };
  
public:
  int findMaxK(vector<int>& nums) 
  {
    vector<types_t> pairs(1001, none);
    for(int n : nums)
    {
      if(n < 0)
      {
        pairs[-n] = pairs[-n] == none ? neg : (pairs[-n] == pos ? both : pairs[-n]);
      }
      else
      {
        pairs[n] = pairs[n] == none ? pos : (pairs[n] == neg ? both : pairs[n]);
      }
    }
    
    for(int i = 1000; i > 0; --i)
    {
      if(pairs[i] == both)
      {
        return i;
      }
    }
    
    return -1;
  }
};

/*
  Q: 2442. Count Number of Distinct Integers After Reverse Operations
*/
class Solution2_t
{
public:
  int countDistinctIntegers(vector<int>& nums) 
  {
    unordered_set<int> uniques;
    for(int n : nums)
    {
      uniques.insert(n);
      
      string ns = std::to_string(n);
      
      reverse(ns.begin(), ns.end());
      int n_ = stoi(ns);
      
      uniques.insert(n_);
    }
    
    return uniques.size();
  }
};

/*
  Q: 2443. Sum of Number and Its Reverse
*/
class Solution3_t
{
private:
  bool isReverseSumMatches(int n, int num)
  {
    string ns = std::to_string(n);
    reverse(begin(ns), end(ns));
    int n_ = stoi(ns);
      
    return (n + n_ == num);
  }
public:
  bool sumOfNumberAndReverse(int num) 
  {
    for(int i = 0; i <= (num/2 + 1); ++i)
    {
      if(isReverseSumMatches(i, num) || isReverseSumMatches(num-i, num))
      {
        return true;
      }
    }
    
    return false;
  }
};

/*
  Q: 2444. Count Subarrays With Fixed Bounds - incomplete
*/
class Solution4_t
{
public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) 
  {
    vector<int> minPos;
    vector<int> maxPos;
    
    for(int i = 0; i < nums.size(); ++i)
    {
      int n = nums[i];
      if(n == minK)
      {
        minPos.push_back(i);
      }
      
      if(n == maxK)
      {
        maxPos.push_back(i);
      }
    }
    
    return 0;
  }
};