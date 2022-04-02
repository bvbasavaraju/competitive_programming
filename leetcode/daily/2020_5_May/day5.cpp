/****************************************************
Date: May 5th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/
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

using namespace std;

/*
  Q: First Unique Character in a String

  Given a string, find the first non-repeating character in it and return it's index.
  If it doesn't exist, return -1.

  Examples:
    s = "leetcode"
    return 0.

    s = "loveleetcode",
    return 2.

  Note: You may assume the string contain only lowercase letters.
*/

class Solution 
{
public:
  int firstUniqChar(string s) 
  {
    //Better space complexity than before
    int i = 0;
    unordered_map<int, pair<int, int>> freq;
    for(auto ch : s)
    {
      if(freq.count(ch) <= 0)
      {
        freq[ch] = std::make_pair(1, i);
      }
      else
      {
        freq[ch].first++;
      }
      i++;
    }
    
    int ans = INT_MAX;
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
      if(it->second.first == 1)
      {
        ans = min(ans, it->second.second);
      }
    }
    
    return ans == INT_MAX ? -1 : ans;

    /*
    int i = 0;
    unordered_map<int, int> freq;
    unordered_map<int, int> pos_map;
    for(auto ch : s)
    {
      freq[ch]++;
      if(pos_map.count(ch) <= 0)
      {
        pos_map[ch] = i;
      }
      i++;
    }
    
    int ans = INT_MAX;
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
      if(it->second == 1)
      {
        ans = min(ans, pos_map[it->first]);
      }
    }
    
    return ans == INT_MAX ? -1 : ans;*/
  }
};