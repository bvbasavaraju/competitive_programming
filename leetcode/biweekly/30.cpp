/****************************************************
Date: July 11, 2020
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-30
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
  Q: 1507. Reformat Date
*/
class Solution1_t
{
public: 
  string reformatDate(string date) 
  {
        map<string, string> month;
    month["Jan"] = "01";
    month["Feb"] = "02"; 
    month["Mar"] = "03";
    month["Apr"] = "04";
    month["May"] = "05";
    month["Jun"] = "06";
    month["Jul"] = "07";
    month["Aug"] = "08";
    month["Sep"] = "09";
    month["Oct"] = "10";
    month["Nov"] = "11";
    month["Dec"] = "12";
    
    string ans = "";
    int l = date.size();
    
    string y = date.substr(l-4, 4);
    ans += y + "-";
    
    string m = date.substr(l-4-4, 3);
    ans += month[m] + "-";
    
    int i = 0;
    string d;
    while(true)
    {
      if(date[i] >= '0' && date[i] <= '9')
      {
        d += date[i];
      }
      else
      {
        break;
      }
      i++;
    }
    
    ans += d.size() == 2 ? d : "0" + d;
    
    return ans;
  }
};

/*
  Q: 1508. Range Sum of Sorted Subarray Sums
*/
class Solution2_t
{
private:
  const int MOD = 1e9 + 7;
  void getSum(vector<int>& nums, int p, int l, vector<int>& sums)
  {
    int sum = 0;
    for(int i = p; i < l; ++i)
    {
      sum = (sum + nums[i]) % MOD;
      sums.push_back(sum);
    }
  }
  
public:
  int rangeSum(vector<int>& nums, int n, int left, int right) 
  {
    int l = nums.size();
    
    vector<int> sums;
    for(int i = 0; i < l; ++i)
    {
      getSum(nums, i, l, sums);
    }
    
    sort(sums.begin(), sums.end());
    
    int ans = 0;
    for(int i = left-1; i < right; ++i)
    {
      ans = (ans % MOD) + (sums[i] % MOD) ;
    }
    
    return ans;
  }
};

/*
  Q: 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
*/
class Solution3_t
{
public:
  int minDifference(vector<int>& nums) 
  {    
    int l = nums.size();
    if(l < 5)
    {
      return 0;
    }
    
    int min_pos = l - 3 - 1;
    
    int ans = INT_MAX;
    sort(nums.begin(), nums.end());
    for(int i = 0; i <= 3; ++i)
    {
      ans = min(ans, nums[min_pos + i] - nums[i]);
    }
    
    return ans;
  }
};

/*
  Q: 1510. Stone Game IV
*/
class Solution4_t
{
public:
    bool winnerSquareGame(int n) 
    {
        
    }
};