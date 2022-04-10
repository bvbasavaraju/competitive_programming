/****************************************************
Date: April 10th, 2022
Successful submissions : 0
Time expiration : 0
Memory exhausted : 0
Not Solved : 4
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-288
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2231. Largest Number After Digit Swaps by Parity - solved after looking in discussion
*/
class Solution1_t
{
private:
  
public:
  int largestInteger(int num) 
  {
    string nums = std::to_string(num);
    
    priority_queue<int> o;
    priority_queue<int> e;
    
    for(char ch : nums)
    {
      if((ch - '0') % 2 == 0)
      {
        e.push(ch-'0');
      }
      else
      {
        o.push(ch-'0');
      }
    }
    
    int ans = 0;
    for(char ch : nums)
    {
      if((ch - '0') % 2 == 0)
      {
        ans = (ans * 10) + e.top();
        e.pop();
      }
      else
      {
        ans = (ans * 10) + o.top();
        o.pop();
      }
    }
    
    return ans;
  }
};

/*
  Q: 2232. Minimize Result by Adding Parentheses to Expression - yet to complete
*/
class Solution2_t
{
public:
  string minimizeResult(string expression) 
  {
    vector<pair<int, int>> l;
    vector<pair<int, int>> r;
    
    bool plusFound = false;
    for(char ch : expression)
    {
      if(ch == '+')
      {
        plusFound = true;
        continue;
      }
      
      if(plusFound)
      {
        
      }
      else
      {
          
      }
    }
  }
};

/*
  Q: 2233. Maximum Product After K Increments - solved after looking in discussion
*/
class Solution3_t
{
public:
  int maximumProduct(vector<int>& nums, int k) 
  {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int n : nums)
    {
      pq.push(n);
    }
    
    while(k > 0)
    {
      int n = pq.top();
      pq.pop();
      
      n++;
      k--;
      pq.push(n);
    }
    
    long long ans = 1;
    int mod = 1e9 + 7;
    while(!pq.empty())
    {
      ans = (ans * pq.top()) % mod;
      pq.pop();
    }
    
    return static_cast<int>(ans % mod);
  }
};

/*
  Q: 2234. Maximum Total Beauty of the Gardens
*/
class Solution4_t
{
public:
  long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) 
  {

  }
};