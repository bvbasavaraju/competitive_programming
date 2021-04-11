/****************************************************
Date: April 11th, 2021
Successful submissions : 0
Time expiration : 0
Not Solved : 0
Wrong Answer/ Partial result : 0

Note: Solved it after the contest as I could not make it!!. Able to solve only 1!!

link: https://leetcode.com/contest/weekly-contest-235
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
  Q: 1822. Sign of the Product of an Array
*/
class Solution1_t
{
public:
  int arraySign(vector<int>& nums) 
  {
    long long ans = 1;
    for(int& n : nums)
    {
      if(n == 0)
      {
        return 0;
      }
      
      ans = (ans * n) > 0 ? 1 : -1;
    }
    
    return ans;
  }
};

/*
  Q: 1823. Find the Winner of the Circular Game - not working!! problem is always taking from the beginning!!
*/
class Solution2_t
{
public:
  int findTheWinner(int n, int k) 
  {
    if(k == 1)
    {
      return n;
    }
    
    vector<int> nums;
    int i = 1;
    while(i <= n)
    {
      nums.push_back(i);
      i++;
    }
    
    while(nums.size() > 1)
    { 
      if(nums.size() >= k)
      {
        nums.erase(nums.begin() + k - 1);
      }
      else
      {
        k = k % nums.size();
      }
      
      if(k == 1)
      {
        return nums.back();
      }
    }
    
    return nums[0];
  }
};

/*
  Q: 1824. Minimum Sideway Jumps
*/

class Solution3_t
{
public:
  int minSideJumps(vector<int>& obstacles) 
  {
      
  }
};

/*
  Q: 1825. Finding MK Average
*/
class MKAverage {
public:
    MKAverage(int m, int k) {
        
    }
    
    void addElement(int num) {
        
    }
    
    int calculateMKAverage() {
        
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
