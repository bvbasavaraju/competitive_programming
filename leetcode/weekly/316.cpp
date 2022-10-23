/****************************************************
Date: Oct 23rd, 2022
Successful submissions : 0
Successful submissions after timeout : 1
Time expiration : 0
Memory exhausted : 0
Not Solved : 3
Incomplete Solution : 0
Wrong Answer/ Partial result : 0
Solved looking at solutions : 0

link: https://leetcode.com/contest/weekly-contest-316
****************************************************/
#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2446. Determine if Two Events Have Conflict
*/
class Solution1_t
{
private:
  int getHours(const string& time)
  {
    int ans = (time[0] - '0') * 10;
    ans += (time[1] - '0');
    
    return ans;
  }
  
  int getMins(const string& time)
  {
    int ans = (time[3] - '0') * 10;
    ans += (time[4] - '0');
    
    return ans;
  }
    
public:
  bool haveConflict(vector<string>& event1, vector<string>& event2) 
  {
    int s1_hours = getHours(event1[0]);
    int s1_mins = getMins(event1[0]);
    
    int e1_hours = getHours(event1[1]);
    int e1_mins = getMins(event1[1]);
    
    int s2_hours = getHours(event2[0]);
    int s2_mins = getMins(event2[0]);
    
    int e2_hours = getHours(event2[1]);
    int e2_mins = getMins(event2[1]);
    
    // std::cout << s1_hours << ":" << s1_mins << " " << e1_hours << ":" << e1_mins << std::endl;
    // std::cout << s2_hours << ":" << s2_mins << " " << e2_hours << ":" << e2_mins << std::endl;
    
    if(s1_hours <= s2_hours)
    {
      if((e1_hours > s2_hours) || (e1_hours == s2_hours && e1_mins >= s2_mins))
      {
        return true;
      }
    }
    else
    {
      if((e2_hours > s1_hours) || (e2_hours == s1_hours && e2_mins >= s1_mins))
      {
        return true;
      }
    }
    
    return false;
  }
};

/*
  Q: 2447. Number of Subarrays With GCD Equal to K - incomplete
*/
class Solution2_t
{
public:
  int subarrayGCD(vector<int>& nums, int k) 
  {
    int ans = 0;
    
    // int start = 0;
    // int end = 0;
    int count = 0;
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      if(nums[i]%k == 0)
      {
        // end = i;
        count++;
        continue;
      }
      
      if(count > 0)
      {
        ans += (count * (count+1))/2;
      }
      
      count = 0;
//       if(start < end)
//       {
//         int count = (end-start);
//         ans += (count * (count+1))/2;
//       }
      
//       start = i;
    }
    
    if(count > 0)
    {
      ans += (count * (count+1))/2;
    }
    
    // if(end == l-1)
    // {
    //   int count = (end-start);
    //   ans += (count * (count+1))/2;
    // }
    
    return ans;
  }
};

/*
  Q: 2448. Minimum Cost to Make Array Equal
*/
class Solution3_t 
{
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        
    }
};

/*
  Q: 2449. Minimum Number of Operations to Make Arrays Similar - 
*/
class Solution4_t
{
public:
  long long makeSimilar(vector<int>& nums, vector<int>& target) 
  {
      
  }
};