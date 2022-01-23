/****************************************************
Date: Jan 23rd, 2022
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-277
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
  Q: 2148. Count Elements With Strictly Smaller and Greater Elements
*/
class Solution1_t
{
public:
  int countElements(vector<int>& nums) 
  {
    sort(nums.begin(), nums.end());
    
    vector<int> nums_;
    int l = nums.size();
    unordered_map<int, int> freq;
    for(int i = 0; i < l; ++i)
    {
      freq[nums[i]]++;
      
      if(freq[nums[i]] == 1)
      {
        nums_.push_back(nums[i]);
      }
    }
    
    l = nums_.size();
    if(l <= 2)
    {
      return 0;
    }
    
    int ans = l-2;
    for(int i = 1; i < l-1; ++i)
    {
      int count = freq[nums_[i]];
      if(count > 1)
      {
        ans += (count - 1); 
      }
    }
    
    return ans;
  }
};

/*
  Q: 2149. Rearrange Array Elements by Sign
*/
class Solution2_t
{
public:
  vector<int> rearrangeArray(vector<int>& nums) 
  {
    queue<int> pos;
    queue<int> neg;
    
    for(int n : nums)
    {
      if(n < 0)
      {
        neg.push(n);
      }
      else
      {
        pos.push(n);
      }
    }
    
    vector<int> ans;
    while(!pos.empty() && !neg.empty())
    {
      ans.push_back(pos.front());
      ans.push_back(neg.front());
      
      pos.pop();
      neg.pop();
    }
    
    return ans;
  }
};

/*
  Q: 2150. Find All Lonely Numbers in the Array
*/
class Solution3_t
{
public:
  vector<int> findLonely(vector<int>& nums) 
  {
    unordered_map<int, int> freq;
    for(int n : nums)
    {
      freq[n]++;
    }
    
    vector<int> ans;
    for(int n : nums)
    {
      if((freq[n] == 1) && (freq.count(n+1) == 0) && (freq.count(n-1) == 0))
      {
        ans.push_back(n);
      }
    }
    
    return ans;
  }
};

/*
  Q: 2151. Maximum Good People Based on Statements - not complete yet!
*/
class Solution4_t
{
private:
  int getGoodCount(vector<int>& people, vector<int>& statement)
  {
    
  }
public:
  int maximumGood(vector<vector<int>>& statements) 
  {
    int r = statements.size();
    int c = statements[0].size();
    
    int ans = 0;
    for(int i = r-1; i >=0; --i)
    {
      vector<int> people(r, -1);
      
      for(int j = 0; j < c; ++j)
      {
        if(i == j)
        {
          continue;
        }
        
        people[j] = statements[i][j];  
      }
      
      for(int k = 0; k , r; ++k)
      {
        if(k == i)
        {
          //count good people!
        }
        else
        {
          ans = max(ans, getGoodCount(people, statements[k]));
        }
      }
    }
    
    return ans;
  }
};