/****************************************************
Date: April 4, 2020
Successful submissions : 2
Time expiration : 
Not Solved : 1
Wrong Answer/ Partial result : 1

Note: First time hard problem has been solved!!

link: https://leetcode.com/contest/biweekly-contest-23
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
  Q:  1399. Count Largest Group - Solved!!
*/

class Solution1_t
{
public:
  int countLargestGroup(int n) 
  {
    unordered_map<int, int> sum_size;
    unordered_map<int, int> digit_sum;
    
    for(int i = 1; i <= n; i++)
    {
      int sum = 0;
      if(digit_sum.count(i) == 0)
      {
        string s = std::to_string(i);
        
        for(char ch : s)
        {
          sum += ch - '0';
        }
        
        digit_sum[i] = sum;
      }
      else
      {
        sum = digit_sum[i];
      }
      
      sum_size[sum]++;
    }
    
    int l = 0;
    int ans = 0;
    for(auto& p : sum_size)
    {
      if(p.second > l)
      {
        l = p.second;
        ans = 1;
      }
      else if(p.second == l)
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q:  1400. Construct K Palindrome Strings - Solved looking at discussion!!
  Note: Initially submitted answer was wrong. Looked at discussion and understood approach and solved!!
*/

class Solution2_t
{
public:
  bool canConstruct(string s, int k) 
  {
    int l = s.size();
    if(l < k)
    {
      return false;
    }
    else if(l == k)
    {
      return true;
    }
    
    unordered_map<int, int> count;
    for(char ch : s)
    {
      count[ch-'0']++;
    }
    
    if(count.size() == k)
    {
      return true;
    }
    
    int num_of_odd_chars = 0;
    for(auto& p : count)
    {
      if(p.second % 2 != 0)
      {
        num_of_odd_chars++;
      }
    }
    
    return (num_of_odd_chars <= k);
  }
};

/*
  Q:  1401. Circle and Rectangle Overlapping
*/
class Solution3_t
{
public:
  bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) 
  {

  }
};

/*
  Q:  1402. Reducing Dishes - first time hard problem solved!!
*/
class Solution4_t
{
public:
  int maxSatisfaction(vector<int>& s) 
  {
    sort(s.begin(), s.end());
    
    int l = s.size();
    
    int t_sum = 0;
    int p_loop_sum = 0;
    int ans = 0;
    
    for(int i = l - 1; i >= 0; i--)
    {
      p_loop_sum += s[i];
      t_sum += p_loop_sum;

      ans = max(ans, t_sum);

      //printf("t_sum = %d, p_loop_sum = %d, ans = %d\n", t_sum, p_loop_sum, ans);
    }
    
    return ans;
  }
};