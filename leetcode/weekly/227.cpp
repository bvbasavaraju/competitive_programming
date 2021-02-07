/****************************************************
Date: Feb 7th, 2021
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1  //this was corrected after looking at the discussion

link: https://leetcode.com/contest/weekly-contest-227
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
  Q: 1752. Check if Array Is Sorted and Rotated
*/
class Solution1_t
{
public:
  bool check(vector<int>& nums) 
  {
    int l = nums.size();
    
    int num_of_points = 0;
    bool is_rotated = nums[0] >= nums[l-1];
    for(int i = 1; i < l; ++i)
    {
      if(nums[i] < nums[i-1])
      {
        if(is_rotated)
        {
          num_of_points++;
          if(num_of_points > 1)
          {
            return false;
          }
        }
        else
        {
          return false;
        }
      }
    }
    
    return true;
  }
};
/*
  Q: 1753. Maximum Score From Removing Stones
*/
class Solution2_t // This one I did lot of trials. Instead of using logics! this is wrong. Should not stick to one approach!!
{
public:
  int maximumScore(int a, int b, int c) 
  {
//     int l = min({a, b, c});
//     int h = max({a, b, c});
//     int m = (a+b+c) - (h+l);
    
//     if(l+m <= h)
//     {
//       return l+m;
//     }
//     else
//     {
//       return h + min(l, (l+m-h)/2);
//     }
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    
    int ans = 0;
    while(pq.size() > 1)
    {
      int t1 = pq.top();
      pq.pop();
      
      int t2 = pq.top();
      pq.pop();
      
      ans++;
      if(t1 - 1 > 0)
      {
        pq.push(t1-1);
      }
      if(t2-1 > 0)
      {
        pq.push(t2-1);
      }
    }
    
    return ans;
  }
};

/*
  Q: 1754. Largest Merge Of Two Strings
*/
class Solution3_t
{
public:
  string largestMerge(string word1, string word2) 
  {
      
  }
};

/*
  Q: 1755. Closest Subsequence Sum
*/
class Solution4_t
{
public:
  int minAbsDifference(vector<int>& nums, int goal) 
  {
      
  }
};