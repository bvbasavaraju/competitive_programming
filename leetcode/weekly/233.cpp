
/****************************************************
Date: Mar 21th, 2021
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-233
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
  Q: 1800. Maximum Ascending Subarray Sum
*/
class Solution1_t
{
public:
  int maxAscendingSum(vector<int>& nums) 
  {
    int sum = nums[0];
    int ans = sum;
    
    int l = nums.size();
    for(int i = 1; i < l; ++i)
    {
      sum = (nums[i] > nums[i-1]) ? max(sum + nums[i], nums[i]) : nums[i];
      ans = max(ans, sum);
    }
    
    return ans;
  }
};

/*
  Q: 1801. Number of Orders in the Backlog
*/
class Solution2_t
{
public:
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) 
  {
    priority_queue<int> buyPrices;
    priority_queue<int, vector<int>, greater<int>> sellerPrices;
    
    unordered_map<int, int> buy;
    unordered_map<int, int> sell;
    
    for(vector<int>& order : orders)
    {
      int p = order[0];
      int count = order[1];
      
      if(order[2] == 0)
      {
        if(sell.empty())
        {
          buy[p] = count;
        }
        else
        {
          while(!sellerPrices.empty())
          {
            int price = sellerPrices.top();
            if(price <= p)
            {
              auto it = sell.find(price);
              if( it != sell.end())
              {
                if(it->second <= count)
                {
                  sellerPrices.pop();
                  count -= it->second;

                  sell.erase(it);
                }
                else
                {
                  sell[price] -= count;
                  count = 0;
                  break;
                }
              }
              else
              {
                sellerPrices.pop();
              }
            }
            else
            {
              break;
            }
          }
          
          if(count > 0)
          {
            buy[p] = count;
          }
        }
        
        buyPrices.push(p);
      }
      else
      {
        if(buy.empty())
        {
          sell[p] = count;
        }
        else
        {
          while(!buyPrices.empty())
          {
            int price = buyPrices.top();
            if(price >= p)
            {
              auto it = buy.find(price);
              if(it != buy.end())
              {
                if(it->second <= count)
                {
                  buyPrices.pop();
                  count -= it->second;

                  buy.erase(it);
                }
                else
                {
                  buy[price] -= count;
                  count = 0;
                  break;
                }
              }
              else
              {
                buyPrices.pop();
              }
            }
            else
            {
              break;
            }
          }
          if(count > 0)
          {
            sell[p] = count;
          }
        }
        
        sellerPrices.push(p);
      }
    }
    
    long long ans = 0;
    static const int MOD = 1e9 + 7;
    
    for(auto it = buy.begin(); it != buy.end(); ++it)
    {
      ans = (ans + it->second) % MOD;
    }
    
    for(auto it = sell.begin(); it != sell.end(); ++it)
    {
      ans = (ans + it->second) % MOD;
    }
    
    return ans;
  }
};

/*
  Q: 1802. Maximum Value at a Given Index in a Bounded Array
*/
class Solution3_t
{
public:
  int maxValue(int n, int index, int maxSum) 
  {
    if(maxSum == n)
    {
      return 1;
    }
  }
};

/*
  Q: 1803. Count Pairs With XOR in a Range
*/

class Solution4_t 
{
public:
  int countPairs(vector<int>& nums, int low, int high) 
  {
      
  }
};