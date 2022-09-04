/****************************************************
Date: Sept 4th, 2022
Successful submissions : 2
Successful submissions after timeout : 0
Time expiration : 0
Memory exhausted : 0
Not Solved : 0
Incomplete Solution : 1
Wrong Answer/ Partial result : 1
Solved looking at solutions : 0

link: https://leetcode.com/contest/weekly-contest-309
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2399. Check Distances Between Same Letters - solved
*/
class Solution1_t
{
public:
  bool checkDistances(string s, vector<int>& distance) 
  {
    vector<int> count(26, -1);
    
    int l = s.size();
    for(int i = 0; i < l; ++i)
    {
      int p = s[i] - 'a';
      if(count[p] >= 0)
      {
        count[p] = i - count[p] - 1;
      }
      else
      {
        count[p] = i;
      }
    }
    
    for(int i = 0; i < 26; ++i)
    {
      //std::cout << count[i] << " ";
      if((count[i] != -1) && (count[i] != distance[i]))
      {
        return false;
      }
    }
    
    return true;
  }
};

/*
  Q: 2400. Number of Ways to Reach a Position After Exactly k Steps
*/
class Solution2_t
{
private:
  static constexpr int MOD = 1e9 + 7;
  long long getCount(int val, int target, int count, unordered_map<string, int>& cache)
  {
    if(count <= 0)
    {
      if((count == 0) && (val == target))
      {
        return 1;
      }
      
      return 0;
    }
    
    string key = std::to_string(val) + "_" + std::to_string(count);
    if(cache.find(key) != cache.end())
    {
      return cache[key];
    }
    
    long long ans = (1 + getCount(val+1, target, count-1, cache) + getCount(val-1, target, count-1, cache)) % MOD;
    
    cache[key] = ans;
    return ans;
  }
public:
  int numberOfWays(int startPos, int endPos, int k) 
  {
    unordered_map<string, int> cache;
    
    int ans = getCount(startPos, endPos, k, cache);
    
    return static_cast<int> (ans);
  }
};

/*
  Q: 2401. Longest Nice Subarray - solved
*/
class Solution3_t
{
private:
  bool commonBitsSet(int num1, long long num2)
  {
    while(num1 > 0 && num2 > 0)
    {
      if((num1 & 0x01) && (num2 & 0x01))
      {
        return true;
      }
      
      num1 >>= 1;
      num2 >>= 1;
    }
    
    return false;
  }
public:
  int longestNiceSubarray(vector<int>& nums) 
  {
    int l = nums.size();
    if(l == 1)
    {
      return 1;
    }
    
    int j = 0;
    int ans = 1;
    long long sum = nums[0];
    for(int i = 1; i < l; ++i)
    {
      while(commonBitsSet(nums[i], sum))
      {
        sum -= nums[j];
        j++;
        if(i == j)
        {
          break;
        }
      }

      ans = max(ans, i-j+1);
      sum += nums[i];
    }
    
    return ans;
  }
};

/*
  Q: 2402. Meeting Rooms III - partial result. by that time I completed it, time was up already!!
*/
class Solution4_t
{
public:
  int mostBooked(int n, vector<vector<int>>& meetings) 
  {
    sort(meetings.begin(), meetings.end(), [](const vector<int>& t1, const vector<int>& t2) -> bool
         {
           if((t1[0] < t2[0]) || ((t1[0] == t2[0]) && (t1[1] < t2[1])))
           {
             return true;
           }
           
           return false;
         });
        
    int l = n;
    vector<int> count(n, 0);
    vector<int> endTime(n, 0);
    priority_queue<int, vector<int>, greater<int>> rooms;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> endTimeWithRoomNumber;
    
    while(n > 0)
    {
      rooms.push(n-1);
      n--;
    }

    for(vector<int> time : meetings)
    {
      if(rooms.empty())
      {
        pair<int, int> roomAndET = endTimeWithRoomNumber.top();
        endTimeWithRoomNumber.pop();
        
        rooms.push(roomAndET.second);
      }
      
      int room = rooms.top();
      rooms.pop();
      
      count[room]++;
      endTime[room] += time[1];
      endTimeWithRoomNumber.push({endTime[room], room});
    }
    
    int ans = 0;
    int maxi = -1;
    for(int i = 0; i < l; ++i)
    {
      if(count[i] > maxi)
      {
        ans = i;
        maxi = count[i];
      }
    }
    
    return ans;
  }
};