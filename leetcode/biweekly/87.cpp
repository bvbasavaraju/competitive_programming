/****************************************************
Date: Sept 17th, 2022
Successful submissions : 0
Successful submissions after timeout : 2
Time expiration : 0
Memory exhausted : 0
Not Solved : 2
Incomplete Solution : 0
Wrong Answer/ Partial result : 1
Solved looking at solutions : 1

link: https://leetcode.com/contest/biweekly-contest-87
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2409. Count Days Spent Together
*/
class Solution1_t
{
public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) 
  {
    static const vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    string start = max(arriveAlice, arriveBob) ;
    string end = min(leaveAlice, leaveBob);
    
    int ans = 0;
    if(end < start)
    {
      return ans;
    }
    
    int startMonth = (start[0] - '0') * 10 + (start[1] - '0');
    int startDate = (start[3] - '0') * 10 + (start[4] - '0');
    
    int endMonth = (end[0] - '0') * 10 + (end[1] - '0');
    int endDate = (end[3] - '0') * 10 + (end[4] - '0');
    
    //std::cout << startDate << "-" << startMonth << " " << endDate << "-" << endMonth << std::endl;
    for(int i = startMonth; i < endMonth; ++i)
    {
      ans += days[i];
    }
    
    ans = ans + endDate - startDate + 1;
    
    return ans;
  }
};

/*
  Q: 2410. Maximum Matching of Players With Trainers
*/
class Solution2_t
{
public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
  {
    priority_queue<int, vector<int>, greater<int>> ability;
    for(int p : players)
    {
      ability.push(p);
    }
    
    priority_queue<int, vector<int>, greater<int>> capacity;
    for(int t : trainers)
    {
      capacity.push(t);
    }
    
    int ans = 0;
    while(!capacity.empty() && !ability.empty())
    {
      if(capacity.top() >= ability.top())
      {
        ans++;
        ability.pop();
      }
      
      capacity.pop();
    }
    
    return ans;
  }
};

/*
  Q: 2411. Smallest Subarrays With Maximum Bitwise OR - still wrong answer
*/
class Solution3_t
{
public:
  vector<int> smallestSubarrays(vector<int>& nums) 
  {
    int maxi = 0;
    for(int n : nums)
    {
      maxi |= n;
    }
    
    int l = nums.size();
    vector<int> ans(l, 0);
    
    int p = 0;
    int val = 0;
    for(int i = 0; i < l; ++i)
    {
      while(val != maxi && p < l)
      {
        val |= nums[p];
        p++;
      }
      
      ans[i] = p - i;
      
      val = val & (~nums[i]);
    }
    
    return ans;
  }
};

/*
  Q: 2412. Minimum Money Required Before Transactions - solved after looking at the solution
*/
class Solution4_t
{
public:
  long long minimumMoney(vector<vector<int>>& transactions) 
  {    
    long long ans = 0;
    int maxi = 0;
    int l = transactions.size();
    for(vector<int> tx : transactions)
    {
      maxi = max(maxi, min(tx[0], tx[1]));
      ans += max(tx[0] - tx[1], 0);
    }
    
    return ans + maxi;
  }
};