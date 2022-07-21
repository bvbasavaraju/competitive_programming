/****************************************************
Date: July 17th, 2022
Successful submissions : 2
Time expiration : 1
Memory exhausted : 0
Not Solved : 0
Wrong Answer/ Partial result : 1

Note: 4th question was almost solved! instead of getting the gcd, it got the min.

link: https://leetcode.com/contest/weekly-contest-302
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2341. Maximum Number of Pairs in Array
*/
class Solution1_t
{
public:
  vector<int> numberOfPairs(vector<int>& nums) 
  {
    unordered_map<int, int> freq;
    for(int n : nums)
    {
      freq[n]++;
    }
    
    vector<int> ans(2, 0);
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
      //std::cout << it->first << " "<< it->second << std::endl;
      ans[0] += it->second / 2;
      ans[1] += it->second % 2;
    }
    
    return ans;
  }
};

/*
  Q: 2342. Max Sum of a Pair With Equal Sum of Digits
*/
class Solution2_t
{
private:
  int getSumOfDigits(int n)
  {
    int ans = 0;
    while(n > 0)
    {
      ans += n%10;
      n /= 10;
    }
    
    return ans;
  }
  
public:
  int maximumSum(vector<int>& nums) 
  {
    unordered_map<int, priority_queue<int>> sums;
    for(int n : nums)
    {
      int digitSum = getSumOfDigits(n);
      sums[digitSum].push(n);
    }
    
    int ans = 0;
    for(auto it = sums.begin(); it != sums.end(); ++it)
    {
      if(it->second.size() >= 2)
      {
        int sum = it->second.top();
        it->second.pop();
        sum += it->second.top();
        
        ans = max(ans, sum);
      }
    }
        
    return ans == 0 ? -1 : ans;
  }
};

/*
  Q: 2343. Query Kth Smallest Trimmed Number - time limit exceeding!!
*/
class Solution3_t
{
public:
  vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
  {
    int l = nums.size();
    int nl = nums[0].size();
    
//     unordered_map<int, multiset<pair<string, int>>> trimmedNums;
//     for(vector<int>& q : queries)
//     {
//       if(trimmedNums.find(q[1]) != trimmedNums.end())
//       {
//         continue;
//       }
      
//       for(int i = 0; i < l; ++i)
//       {
//         trimmedNums[q[1]].insert({nums[i].substr(nl-q[1]), i});
//       }
//     }
    
//     int ql = queries.size();
//     vector<int> ans(ql);
//     for(int i = 0; i < ql; ++i)
//     {
//       multiset<pair<string, int>> trimmed = trimmedNums[queries[i][1]];
//       ans[i] = (trimmed.begin() + queries[i][0] - 1).second;
//     }
    
    unordered_map<int, vector<pair<string, int>>> trimmedNums;
    for(vector<int>& q : queries)
    {
      if(trimmedNums.find(q[1]) != trimmedNums.end())
      {
        continue;
      }
      
      for(int i = 0; i < l; ++i)
      {
        trimmedNums[q[1]].push_back({nums[i].substr(nl-q[1]), i});
      }
      
      sort(trimmedNums[q[1]].begin(), trimmedNums[q[1]].end(), [](const pair<string, int> p1, const pair<string, int> p2) -> bool
           {
             if(p1.first < p2.first)
             {
               return true;
             }
             else if((p1.first == p2.first) && (p1.second < p2.second))
             {
               //std::cout << p1.first << " " << p1.second << p1.first << " " << p1.second << std::endl;
               return true;
             }
             
             //std::cout << p1.first << " " << p1.second << " -> "<< p2.first << " " << p2.second << std::endl;
             return false;
           }
          );
      // if(q[1] == 2)
      // {
      //   for(auto p : trimmedNums[q[1]])
      //   {
      //     std::cout << p.first << " " << p.second << std::endl;
      //   }
      // }
    }
    
    int ql = queries.size();
    vector<int> ans(ql);
    for(int i = 0; i < ql; ++i)
    {
      vector<pair<string, int>>& trimmed = trimmedNums[queries[i][1]];
      ans[i] = trimmed[queries[i][0] - 1].second;
    }
    
    return ans;
  }
};

/*
  Q: 2344. Minimum Deletions to Make Array Divisible
*/
class Solution4_t
{
  int getgcd(int m, int n)
  {
    return n == 0 ? m : getgcd(n, m%n);
  }
public:
  int minOperations(vector<int>& nums, vector<int>& numsDivide) 
  {
    sort(numsDivide.begin(), numsDivide.end());
    
    int l = numsDivide.size();
    int n = numsDivide[0];
   
    for(int i = 1; i < l; ++i)
    {
      n = getgcd(n, numsDivide[i]); //Instead of calculating the GCD! went with the min number!! 
    }
    
    int ans = 0;
    sort(nums.begin(), nums.end());
    
    bool divided = false;
    l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      if(n % nums[i] == 0)
      {
        divided = true;
        break;
      }
      else
      {
        ans++;
      }
    }
    
    return divided == false ? -1 : ans;
  }
};