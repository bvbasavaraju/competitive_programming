/****************************************************
Date: July 24th, 2022
Successful submissions : 1
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/weekly-contest-304
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2357. Make Array Zero by Subtracting Equal Amounts
*/
class Solution1_t
{
public:
  int minimumOperations(vector<int>& nums) 
  {
    //Fastest O(n) solution
    set<int> n;
    for(int n_ : nums)
    {
      if(n_ != 0)
      {
        n.insert(n_);
      }
    }
    
    return n.size();

    // O(nlogn + n^2)
    // sort(nums.begin(), nums.end());
    
    // int ans = 0;
    // int l = nums.size();
    // for(int i = 0; i < l; ++i)
    // {
    //   if(nums[i] <= 0)
    //   {
    //     continue;
    //   }
      
    //   ans++;
    //   int n = nums[i];
    //   for(int j = i; j < l; ++j)
    //   {
    //     nums[j] -= n;
    //   }
    // }
    
    // return ans;

    // O(n + n^2) 
    // set<int> n;
    // for(int n_ : nums)
    // {
    //   if(n_ != 0)
    //   {
    //     n.insert(n_);
    //   }
    // }
    
    // int ans = 0;
    // for(auto it = n.begin(); it != n.end(); ++it)
    // {
    //   bool operated = false;
    //   for(int& n_ : nums)
    //   {
    //     if(n_ == 0)
    //     {
    //       continue;
    //     }
        
    //     operated = true;
    //     n_ -= *it;
    //   }
      
    //   if(operated)
    //   {
    //     ans++;
    //   }
    // }
    
    // return ans;
  }
};

/*
  Q: 2358. Maximum Number of Groups Entering a Competition - solved after looking at the solution!
*/
class Solution2_t
{
private:
//   int getCount(vector<int>& nums, int limit)
//   {
//     int sum = 0;
//     int count = 1;
//     for(int n : nums)
//     {
//       sum += n;
      
//       if(sum > limit)
//       {
//         sum = n;
//         count++;
//       }
//     }
    
//     return count;
//   }
public:
  int maximumGroups(vector<int>& grades) 
  {
    int l = grades.size();
    int count = 0;
    int totalCount = 0;
    
    while(totalCount + count < l)
    {
      count++;
      totalCount += count;
    }
    
    return count;
// //     int maxi = 0;
// //     int sum = 0;
// //     for(int g : grades)
// //     {
// //       maxi = max(maxi, g);
// //       sum += g;
// //     }
    
// //     int l = maxi;
// //     int h = sum;
// //     int ans = 0;
// //     while(l <= h)
// //     {
// //       int m = l + (h-l)/2;
      
// //       int count = getCount(grades, m);
// //       if(count >= grades.size()/2)
// //       {
// //         l = m+1;
// //       }
// //       else
// //       {
// //         ans = count;
// //         h = m-1;
// //       }
// //     }
    
// //     return ans+1;
    
//     sort(grades.begin(), grades.end());
    
//     deque<int> dq;
//     for(int g : grades)
//     {
//       dq.push_back(g);
//     }
    
//     int ans = 1;
//     vector<pair<int, int>> sumCount;
    
//     sumCount.push_back({dq.back(), 1});
//     dq.pop_back();
    
//     while(dq.size() > sumCount.back().second)
//     {
//       std::cout << std::endl << dq.back() << ", ";
//       ans++;
//       int count = 1;
//       int sum = dq.back();
//       dq.pop_back();
      
//       bool addBack = false;
//       while(dq.size() > 0)
//       {
//         std::cout << dq.front() << ", ";
//         sum += dq.front();
//         count++;
          
//         dq.pop_front();
        
//         if(count > sumCount.back().second && sum > sumCount.back().first)
//         {
//           addBack = true;
//           break;
//         }
//       }
      
//       std::cout << sum << ":" << count;
//       //if(addBack)
//       {
//         sumCount.push_back({sum, count});
//       }
//     }
    
//     return ans;
    
// //     int prevSum = 0;
// //     vector<vector<int>> groups;
// //     while(dq.size() > groups.back().size())
// //     {
// //       ans++;
      
// //       int prevCount = groups.back().size();
      
// //       int sum = 0;
// //       int count = 0;
      
// //       sum += dq.back();
// //       count++;
// //       groups.push_back({dq.back()});
// //       dq.pop_back();
      
// //       while(count < prevCount || sum < prevSum)
// //       {
// //         count++;
// //         sum += dq.front();
// //         dq.pop_front();
// //       }
// //     }
    
//     // return ans;
  }
};

/*
  Q: 2359. Find Closest Node to Given Two Nodes - yet to solve
*/
class Solution3_t
{
public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) 
  {
    int l = edges.size();
    vector<int> dist1(l, INT_MIN);
    vector<int> dist2(l, INT_MIN);
    
    dist1[node1] = 0;
    dist2[node2] = 0;
    
    for(int i = 0; i < l; ++i)
    {
      for(int j = 0; j < l; ++j)
      {
        if(i == j)
        {
          continue;
        }
        
        if(edges[j] == -1)
        {
          continue;
        }
        
        if(dist1[i] + 1 < dist1[j])
        {
          dist1[j] = dist1[i] + 1;
        }
        
        if(dist2[i] + 1 < dist2[j])
        {
          dist2[j] = dist2[i] + 1;
        }
      }
    }
    
    int diff = INT_MAX;
    int ans = l+1;
    for(int i = 0; i < l; ++i)
    {
      if(abs(dist1[i] - dist2[i]) < diff)
      {
        diff = abs(dist1[i] - dist2[i]);
        ans = i;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2360. Longest Cycle in a Graph
*/
class Solution 
{
public:
  int longestCycle(vector<int>& edges) 
  {
      
  }
};