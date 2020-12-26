/****************************************************
Date: Dec 26th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-42
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
  Q: 1700. Number of Students Unable to Eat Lunch
*/
class Solution1
{
public:
  int countStudents(vector<int>& stds, vector<int>& sands) 
  {
    queue<int> std_q;
    for(auto f : stds)
    {
      std_q.push(f);
    }
    
    int count = 0;
    int sand_length = sands.size();
    for(int i = 0; i < sand_length; ++i)
    {
      bool food_taken = false;
      count = std_q.size();
      while(count > 0)
      {
        int sc = std_q.front();
        
        std_q.pop();
        if(sc == sands[i])
        {
          food_taken = true;
          break;
        }
        else
        {
          std_q.push(sc);
          count--;
        }
      }
      
      if(!food_taken)
      {
        break;
      }
    }
    
    return std_q.size();
  }
};

/*
  Q: 1701. Average Waiting Time
*/
class Solution2
{
public:
  double averageWaitingTime(vector<vector<int>>& customers) 
  {
    long long wait_time = 0;
    long long start_time = customers[0][0];
    for(vector<int> cust : customers)
    {
      start_time = max(start_time, static_cast<long long>(cust[0]));
      
      long long total_time = start_time + cust[1];
      
      wait_time += total_time - cust[0];
      
      start_time = total_time;
    }
    
    double l = customers.size();
    double wt = (wait_time * 1.0) / l;
    
    return ((wt * 1e5) / 1e5);
  }
};

/*
  Q: 1702. Maximum Binary String After Change - wrong answer
*/
class Solution3
{
public:
  string maximumBinaryString(string binary) 
  {
    int one_count = 0;
    for(int ch : binary)
    {
      if(ch == '1')
      {
        one_count++;
      }
    }
    int l = binary.size();
    int zero_count = l - one_count;
    
    sort(binary.begin(), binary.end());
    
    int i = 1;
    bool swapped = false;
    for(; i < l; ++i)
    {
      if(binary[i] == '0')
      {
        swapped = true;
        binary[i-1] = '1';
      }
      else
      {
        break;
      }
    }
    
    if(swapped && (i < l) && (one_count > zero_count))
    {
      binary[i-1] = '1';
      binary[i] = '0';
    }
    
    return binary;
  }
};

/*
  Q: 1703. Minimum Adjacent Swaps for K Consecutive Ones
*/

class Solution4
{
public:
  int minMoves(vector<int>& nums, int k) 
  {
      
  }
};