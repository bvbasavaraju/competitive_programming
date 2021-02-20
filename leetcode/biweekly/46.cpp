
/****************************************************
Date: Feb 20th, 2021
Successful submissions : 2 (1 solved after understanding)
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-46
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
  Q:  1763. Longest Nice Substring - solved
*/
class Solution1_t
{
public:
  string longestNiceSubstring(string s) 
  {
    int l = s.size();
    if(l < 2)
    {
      return "";
    }
    
    unordered_map<int, vector<string>> subStrs; //based on length
    
    int bigLength = INT_MIN;
    for(int i = 0; i < l; ++i)
    {
      vector<bool> small(26, false);
      vector<bool> big(26, false);
      
      if(s[i] >= 'a' && s[i] <= 'z')
      {
        small[s[i]-'a'] = true;
      }
      else
      {
        big[s[i]-'A'] = true;
      }
      
      for(int j = i+1; j < l; ++j)
      {
        if(s[j] >= 'a' && s[j] <= 'z')
        {
          small[s[j]-'a'] = true;
        }
        else
        {
          big[s[j]-'A'] = true;
        }
        
        if(small == big)
        {
          int len = j-i+1;
          bigLength = max(bigLength, len);
          subStrs[len].push_back(s.substr(i, len));
        }
      }
    }
    
    return bigLength >= 2 ? subStrs[bigLength][0] : "";
  }
};

/*
  Q: 1764. Form Array by Concatenating Subarrays of Another Array - solved
*/
class Solution2_t
{
private:
  void createDeque(vector<int>& g, int sp, int l, deque<int>& data)
  {
    int count = 0;
    for(int i = sp; count < l && i < g.size(); ++i,count++)
    {
      data.push_back(g[i]);
    }
  }
  
public:
  bool canChoose(vector<vector<int>>& groups, vector<int>& nums) 
  {
    int pNum = 0;
    int count = 0;
    for(vector<int> g : groups)
    {
      //std::cout << "hi";
      int l = g.size();
      
      deque<int> gdq;
      createDeque(g, 0, l, gdq);
      
      deque<int> nums_;
      createDeque(nums, pNum, l, nums_);      
      if(nums_.size() != l)
      {
        break;
      }
      
      pNum += l;
      for( ; pNum < nums.size(); ++pNum)
      {
        if(nums_ == gdq)
        {
          count++;
          break;
        }
        else
        {
          nums_.pop_front();
          nums_.push_back(nums[pNum]);
        }
      }
      
      if(pNum == nums.size())
      {
        count = (nums_ == gdq) ? count + 1 : count;
        break;
      }
    }
    
    //std::cout << endl;
    return count == groups.size();
  }
};

/*
  Q: 1765. Map of Highest Peak - could not solve
*/
class Solution3_t
{
public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
  {
    int r = isWater.size();
    int c = isWater[0].size();
    
    int ans = 0;
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        
      }
    }

    //Thought of solving using BFS! but could not write complete logic!! - TODO
  }
};

/*
  Q: 1766. Tree of Coprimes - wrong answer!!
*/
class Solution4_t
{
private:
  int getGCD(int x, int y)
  {
    if(x == 0)
    {
      return y;
    }
    if(y == 0)
    {
      return x;
    }
    
    return x > y ? getGCD(x-y, y) : getGCD(x, y-x);
  }
  
public:
  vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) 
  {
    unordered_map<int, int> ancMap;
    for(vector<int>& e : edges)
    {
      ancMap[e[1]] = e[0];
    }
    
    int l = edges.size()+1;
    
    vector<int> ans(l, -1);
    for(int i = 1; i < l; ++i)
    {
      int child = i;
      while(ancMap.find(child) != ancMap.end())
      {
        int anc = ancMap[child];
        
        int gcd = getGCD(nums[i], nums[anc]);
        if(gcd == 1)
        {
          ans[i] = anc;
          break;
        }
        
        child = anc;
      }
    }
    
    return ans;
  }
};