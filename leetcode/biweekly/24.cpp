/****************************************************
Date: April 18, 2020
Successful submissions : 2
Time expiration : 
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-24
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
  Q: 1413. Minimum Value to Get Positive Step by Step Sum
*/

class Solution1_t
{
public:
  int minStartValue(vector<int>& nums) 
  {
    int ans = 0;
    int sum = 0;
    
    for(int n : nums)
    {
      sum += n;
      ans = min(ans, sum);
    }
    
    return abs(ans) + 1;
  }
};

/*
  Q: 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
*/

class Solution2_t
{
private:
  int findClosestNumber(vector<int>& nums, int n)
  {
    int l = 0;
    int h = nums.size() - 1;
    
    int ans = 0;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      if(nums[m] == n)
      {
        return m;
      }
      
      if(nums[m] > n)
      {
        h = m - 1;
      }
      else
      {
        ans = m;
        l = m + 1;
      }
    }
    
    return ans;
  }
public:
  int findMinFibonacciNumbers(int k) 
  {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    int l = nums.size();
    while(nums.back() < k)
    {
      nums.push_back(nums[l-1] + nums[l-2]);
      l++;
    }
    
    if(nums.back() == k)
    {
      return 1;
    }
    
    nums.pop_back();
    
    int ans = 1;
    int sum = k - nums.back();
    while (sum > 0)
    {
      ans++;
      int p = findClosestNumber(nums, sum);
      sum -= nums[p];
    }
    
    return ans;
  }
};

/*
  Q: 1415. The k-th Lexicographical String of All Happy Strings of Length n
*/
class Solution3_t
{
public:
    string getHappyString(int n, int k) 
    {
        
    }
};

/*
  Q: 1416. Restore The Array - incomplete solution
*/

class Solution4_t
{
/*private:
  int */
public:
  int numberOfArrays(string s, int k) 
  {
    int max_digits = 0;
    int n = k;
    while(n > 0)
    {
      max_digits++;
      n /= 10;
    }
    
    int p = 0;
    vector<string> strs;
    while(p < s.size())
    {
      strs.push_back(s.substr(p, max_digits));
      p += max_digits;
      
      if(stoi(strs.back()) == 0)
      {
        return 0;
      }
    }
    
    //TODO
  }
};