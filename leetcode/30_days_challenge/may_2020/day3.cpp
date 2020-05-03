/****************************************************
Date: May 3rd

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/
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
  Q: Ransom Note

  Given an arbitrary ransom note string and another string containing letters from all the magazines,
  write a function that will return true if the ransom note can be constructed from the magazines ;
  otherwise, it will return false.

  Each letter in the magazine string can only be used once in your ransom note.

  Note:
    You may assume that both strings contain only lowercase letters.

    canConstruct("a", "b") -> false
    canConstruct("aa", "ab") -> false
    canConstruct("aa", "aab") -> true
*/

class Solution 
{
public:
  bool canConstruct(string ransomNote, string magazine) 
  {
    if(magazine.empty() && !ransomNote.empty())
    {
      return false;
    }
    
    unordered_map<int, int> r;
    unordered_map<int, int> m;
    
    for(char ch : ransomNote)
    {
      r[ch]++;
    }
    
    for(char ch: magazine)
    {
      m[ch]++;
    }
    
    for(auto it = r.begin(); it != r.end(); it++)
    {
      if((m.count(it->first) == 0) || (m[it->first] < it->second))
      {
        return false;
      }
    }
    
    return true;
  }
};