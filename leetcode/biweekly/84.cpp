/****************************************************
Date: Aug 6th, 2022
Successful submissions : 2
Time expiration : 1
Memory limit exceeded : 0
Not Solved : 0
Wrong Answer/ Partial result / partial solution not submitted : 1

link: https://leetcode.com/contest/biweekly-contest-84
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2363. Merge Similar Items
*/
class Solution1_t
{
private:
  void updateMap(vector<vector<int>>& items, map<int, int>& ans)
  {
    for(vector<int> it : items)
    {
      ans[it[0]] += it[1];
    }
  }
public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
  {
    map<int, int> valueWeight;
    
    updateMap(items1, valueWeight);
    updateMap(items2, valueWeight);
    
    vector<vector<int>> ans;
    for(auto it = valueWeight.begin(); it != valueWeight.end(); it++)
    {
      ans.push_back({it->first, it->second});
    }
    
    return ans;
  }
};

/*
  Q: 2364. Count Number of Bad Pairs - TLE
*/
class Solution2_t
{
public:
  long long countBadPairs(vector<int>& nums) 
  {
    int l = nums.size();
    
    long long ans = 0ll;
    for(int i = 0; i < l-1; ++i)
    {
      for(int j = i+1; j < l; ++j)
      {
        if(j-i == nums[j] - nums[i])
        {
          continue;
        }
        
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2365. Task Scheduler II
*/
class Solution3_t
{
public:
  long long taskSchedulerII(vector<int>& tasks, int space) 
  {
    unordered_map<int, long long> taskStartDays;
    
    long long ans = 0;
    int l = tasks.size();
    for(int i = 0; i < l; ++i)
    {
      ans++;
      if(taskStartDays.find(tasks[i]) != taskStartDays.end())
      {
          //Resulting in TLE. later simplified!
        //while((ans - taskStartDays[tasks[i]]) <= space)
        // {
        //   ans++;
        // }
        if((ans - taskStartDays[tasks[i]]) <= space)
        {
          ans = taskStartDays[tasks[i]] + space + 1LL;
        }
      }
         
      taskStartDays[tasks[i]] = ans;
    }
    
    return ans;
  }
};
/*
  Q: 2366. Minimum Replacements to Sort the Array - initially wrong answer. After looking at solutions, I had to tweek the solution!
*/
class Solution4_t
{
public:
  long long minimumReplacement(vector<int>& nums) 
  {
    int l = nums.size();
    
    long long ans = 0LL;
    
    int num = nums[l-1];
    for(int i = l-2; i >= 0; --i)
    {
      if(nums[i] <= num)
      {
        num = nums[i];
        continue;
      }
      
      long long count = (nums[i] + num - 1)/num;
      
      ans += count-1;
      if(nums[i] % num != 0)
      {
        num = nums[i] / count;
      }
    }
    
    return ans;
  }
};