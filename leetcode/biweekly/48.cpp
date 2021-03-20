/****************************************************
Date: March 20th, 2021
Successful submissions : 2
Time expiration : 1 (solved after understanding)
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-48
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>
#include <string_view>

using namespace std;

/*
  Q: 1796. Second Largest Digit in a String
*/
class Solution1_t
{
public:
  int secondHighest(string s) 
  {
    vector<bool> digits(10, false);
    priority_queue<int> pq;
    
    for(char ch : s)
    {
      if(ch >= '0' && ch <= '9')
      {
        if(digits[ch-'0'] == false)
        {
          pq.emplace(ch - '0');
          digits[ch-'0'] = true;
        }
      }
    }
    
    if(!pq.empty())
    {
      pq.pop();
    }
    
    return pq.empty() ? -1 : pq.top();
  }
};

/*
  Q: 1797. Design Authentication Manager
*/
class AuthenticationManager 
{
private:
  int lifeTime;
  unordered_map<string, int> tokens;
public:
  AuthenticationManager(int timeToLive) : lifeTime(timeToLive)
  {}

  void generate(string tokenId, int currentTime) 
  {
    tokens[tokenId] = currentTime + lifeTime;
  }

  void renew(string tokenId, int currentTime) 
  {
    auto it = tokens.find(tokenId);
    if(it != tokens.end())
    {
      if(it->second > currentTime)
      {
        tokens[tokenId] = currentTime + lifeTime;
      }
      else
      {
        tokens.erase(it);
      }
    }
  }

  int countUnexpiredTokens(int currentTime) 
  {
    int ans = 0;
    for(auto it = tokens.begin(); it != tokens.end();)
    {
      if(it->second > currentTime)
      {
        ans++;
        it++;
      }
      else
      {
        it = tokens.erase(it);
      }
    }
    
    return ans;
  }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

/*
  Q: 1798. Maximum Number of Consecutive Values You Can Make - got TLE, solved after looking at solution
*/
class Solution3_t
{
public:
  int getMaximumConsecutive(vector<int>& coins) 
  {
    sort(coins.begin(), coins.end());
    
    int ans = 1;
    
    int l =  coins.size();
    for(int i = 0; i < l && coins[i] <= ans; ++i)
    {
      ans += coins[i];
    }
    
    return ans;
    
    //Getting TLE
//     int rows = coins.size();
    
//     int cols = 0;
//     for(int c : coins)
//     {
//       cols += c;
//     }
//     cols++;
//     vector< vector<int> > data(rows, vector<int>(cols, 0));
    
//     int ans = INT_MIN;
//     for(int i = 0; i < rows; ++i)
//     {
//       for(int j = 0; j < cols; ++j)
//       {
//         if(j == 0)
//         {
//           data[i][j] = 1;
          
//           ans = max(ans, data[i][j]);
//           continue;
//         }
        
//         if(j < coins[i])
//         {
//           data[i][j] = i == 0 ? 0 : data[i-1][j];
//           continue;
//         }
//         else if(j == coins[i])
//         {
//           data[i][j] = data[i][j-1] + 1;
//         }
//         else
//         {
//           if((i > 0) && (data[i-1][j-coins[i]] > 0))
//           {
//             data[i][j] = data[i][j-1] + 1;
//           }
//         }
        
//         ans = max(ans, data[i][j]);
//       }
//     }
    
//     for(int i = 0; i < rows; ++i)
//     {
//       for(int j = 0; j < cols; ++j)
//       {
//         std::cout << data[i][j] << "  ";
//       }
      
//       std::cout << endl;
//     }
//     std::cout << endl;
    
    return ans;
  }
};

/*
  Q: 1799. Maximize Score After N Operations
*/
class Solution4_t
{
public:
  int maxScore(vector<int>& nums) 
  {
  }
};