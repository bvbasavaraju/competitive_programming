/****************************************************
Date: April 6th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3287/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
  Q:  Group Anagrams

  Given an array of strings, group anagrams together.

  Example:
  Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
  Output:
  [
    ["ate","eat","tea"],
    ["nat","tan"],
    ["bat"]
  ]

  Note:
  All inputs will be in lowercase.
  The order of your output does not matter.
*/

class Solution 
{
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) 
  {
    unordered_map<string, vector<string>> anagrams;
    for(auto& s : strs)
    {
      string dup = s;
      
      sort(dup.begin(), dup.end());
      anagrams[dup].push_back(s);
    }
    
    vector<vector<string>> result;
    for(auto& p : anagrams)
    {
      result.push_back(p.second);
    }
    
    return result;
  }
};