/****************************************************
Date: June 13th, 2021
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-244
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
  Q: 1897. Redistribute Characters to Make All Strings Equal
*/
class Solution1_t
{
public:
  bool makeEqual(vector<string>& words) 
  {
    unordered_map<char, int> freq;
    for(const string& w : words)
    {
      for(char ch : w)
      {
        freq[ch]++;
      }
    }
    
    int l = words.size();
    for(auto f : freq)
    {
      if(f.second % l != 0)
      {
        return false;
      }
    }
    
    return true;
  }
};

/*
  Q: 1898. Maximum Number of Removable Characters - wrong answer
*/
class Solution2_t
{
public:
    int maximumRemovals(string s, string p, vector<int>& removable) 
    {
      int i = 0;
      unordered_map<char, pair<vector<int>, int>> s_pos_freq;
      for(char ch : s)
      {
        s_pos_freq[ch].first.push_back(i);
        s_pos_freq[ch].second++;
        i++;
      }
      
      unordered_map<char, int> p_freq;
      for(char ch : p)
      {
        p_freq[ch]++;
      }
      
      unordered_set<int> cannot_remove;
      for(auto it : p_freq)
      {
        int mini = min(it.second, s_pos_freq[it.first].second);
        
        vector<int>& pos = s_pos_freq[it.first].first;
        for(int i = 0; i < mini; ++i)
        {
          cannot_remove.insert(pos[i]);
        }
      }
      
      int ans = 0;
      for(int r : removable)
      {
        if(cannot_remove.find(r) != cannot_remove.end())
        {
          break;
        }
        
        ans++;
      }
      
      return ans;
    }
};

/*
  Q: 1899. Merge Triplets to Form Target Triplet - solved after looking at solution!
*/
class Solution3_t
{
public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) 
  {
    vector<int> t_ = {0,0,0};
    
    for(vector<int>& t : triplets)
    {
      if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2])
      {
        t_ = {max(t[0], t_[0]), max(t[1], t_[1]), max(t[2], t_[2])};
      }
    }
    
    return t_ == target;
  }
};

/*
  Q: 1900. The Earliest and Latest Rounds Where Players Compete
*/
class Solution4_t
{
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) 
    {
      
    }
};