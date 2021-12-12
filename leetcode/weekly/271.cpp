/****************************************************
Date: Dec 12, 2021
Successful submissions : 1
Time expiration : 1
Not Solved : 2 (1 solved later. after timeout!!)
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-271
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
  Q: 2103. Rings and Rods
*/
class Solution1_t
{
public:
  int countPoints(string rings) 
  {
    vector<unordered_set<char>> rods(10);
    
    int l = rings.size();
    for(int i = 0; i < l; i=i+2)
    {
      char color = rings[i];
      char pos = rings[i+1];
      
      rods[pos - '0'].insert(color);
    }
    
    int ans = 0;
    for(auto it : rods)
    {
      if((it.count('R') > 0) && (it.count('G') > 0) && (it.count('B') > 0))
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2104. Sum of Subarray Ranges - timeout!!
*/
class Solution2_t
{
private:
  void calcFirstMinMax(const vector<int>& nums, int ws, map<int, int>& sorted_nums_freq)
  {
    for(int i = 0; i < ws; ++i)
    {
      sorted_nums_freq[nums[i]]++;
    }
  }
    
  long long calcRange(const vector<int>& nums, int ws, map<int, int>& sorted_nums_freq)
  {
    auto it_f = sorted_nums_freq.begin();
    auto it_l = sorted_nums_freq.rbegin();
    
    long long ans = it_l->first - it_f->first;
    for(int i = 1; i <= (nums.size() - ws); ++i)
    {
      if(sorted_nums_freq.count(nums[i-1]) > 0)
      {
        sorted_nums_freq[nums[i-1]]--;
        if(sorted_nums_freq[nums[i-1]] == 0)
        {
          sorted_nums_freq.erase(nums[i-1]);
        }
      }
      
      sorted_nums_freq[nums[i+ws-1]]++;
            
      it_f = sorted_nums_freq.begin();
      it_l = sorted_nums_freq.rbegin();
      
      ans += it_l->first - it_f->first;;
    }
    
    return ans;
  }
public:
  long long subArrayRanges(vector<int>& nums) 
  {    
    int ws = 2;
    long long ans = 0;
    while(ws <= nums.size())
    {
      map<int, int> subArray;
      calcFirstMinMax(nums, ws, subArray);
      ans += calcRange(nums, ws, subArray);
      
      ws++;
    }
    
    return ans;
  }
};

/*
  Q: 2105. Watering Plants II - submitted after timeout!
*/
class Solution3_t
{
public:
  int minimumRefill(vector<int>& plants, int cA, int cB) 
  {
    int cAM = cA;
    int cBM = cB;
    int l = plants.size();
    
    int ap = 0;
    int bp = l-1;
    
    int ans = 0;
    while(ap < bp)
    {
      if(cA < plants[ap])
      {
        ans++;
        cA = cAM;
      }
      cA -= plants[ap];
      ap++;
      
      if(cB < plants[bp])
      {
        ans++;
        cB = cBM;
      }
      cB -= plants[bp];
      bp--;
      
    }
    
    if(l % 2 != 0)
    {
      if((cA == cB) || (cA > cB))
      {
        if(cA < plants[ap])
        {
          ans++;
          cA = cAM;
        }
      }
      else
      {
        if(cB < plants[bp])
        {
          ans++;
          cB = cBM;
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 2106. Maximum Fruits Harvested After at Most K Steps
*/
class Solution4_t
{
public:
  int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
  {
      
  }
};