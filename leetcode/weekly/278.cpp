/****************************************************
Date: Jan 30th, 2022
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-278
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
  Q: 2154. Keep Multiplying Found Values by Two
*/
class Solution_1
{
public:
  int findFinalValue(vector<int>& nums, int original) 
  {
    unordered_map<int, int> freq;
    for(int n: nums)
    {
      freq[n]++;
    }
    
    bool found = freq.count(original) != 0;
    while(found)
    {
      original *= 2;
      found = freq.count(original) != 0;
    }
    
    return original;
  }
};

/*
  Q: 2155. All Divisions With the Highest Score of a Binary Array
*/
class Solution2_t
{
// private:
//   struct MyCompare_t
//   {
//     bool operator()(const vector<int>& ip1, const vector<int>& ip2)
//     {
//       return ip1[1] < ip2[1];
//     }
//   };
  
public:
  vector<int> maxScoreIndices(vector<int>& nums) 
  {
    int zero_count = 0;
    int one_count = 0;
    for(int n : nums)
    {
      if(n == 1)
      {
        one_count++;
      }
    }
    
    int i = 0;
    vector<int> ans = {i};
    int sum = {zero_count+one_count};
    for(int n : nums)
    {
      i++;
      if(nums[i-1] == 0)
      {
        zero_count++;
      }
      else
      {
        one_count--;
      }
      
      int count = zero_count+one_count;
      if(sum < count)
      {
        ans = {i};
        sum = count;
      }
      else if(sum == count)
      {
        ans.push_back(i);
      }
    }
    
    return ans;
    //comment code time limit exceeded!!
//     int i = 0;
//     priority_queue<vector<int>, vector<vector<int>>, MyCompare_t> pq;
    
//     pq.push({i, zero_count+one_count});
//     for(int n : nums)
//     {
//       i++;
//       if(nums[i-1] == 0)
//       {
//         zero_count++;
//       }
//       else
//       {
//         one_count--;
//       }
      
//       pq.push({i, zero_count+one_count});
//     }
    
//     vector<int> ans;
//     while(!pq.empty())
//     {
//       vector<int> p = pq.top();
//       pq.pop();
      
//       ans.push_back(p[0]);
//       if(p[1] > pq.top()[1])
//       {
//         break;
//       }
//     }
    
//     return ans;
  }
};

/*
  Q: 2156. Find Substring With Given Hash Value - yet to complete!
*/
class Solution3_t
{
public:
  string subStrHash(string s, int power, int modulo, int k, int hashValue) 
  {
    vector<long long> p = {1};
    
    for(int i = 0; i < k; ++i)
    {
      long long p_ = (p.back() * power) % modulo;
      p.push_back(p_);
    }
    
    int idx = 0;
    int l = s.size();
    
    bool init_done = false;
    int hash_calc = 0;
    for(int i = 0; i < l; ++i)
    {
      if(init_done)
      {
        hash_calc -= (s[i] - 'a' + 1) 
      }
      if(!init_done)
      {
        long long prod = 1;
        for( ;i < k; ++i)
        {
          hash_calc += (static_cast<long long>(s[i] - 'a' + 1) * (prod * static_cast<long long>(power) % modulo)) % modulo;
          prod *= static_cast<long long>(power);
        }
      }
    }
  }
};

/*
  Q: 2157. Groups of Strings
*/
class Solution4_t 
{
public:
  vector<int> groupStrings(vector<string>& words) 
  {
      
  }
};