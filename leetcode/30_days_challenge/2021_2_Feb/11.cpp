/****************************************************
Date: Feb 11th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3636/
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
  Q: Valid Anagram

  Given two strings s and t , write a function to determine if t is an anagram of s.

  Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

  Example 2:
    Input: s = "rat", t = "car"
    Output: false

  Note:
    You may assume the string contains only lowercase alphabets.

  Follow up:
    What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution 
{
public:
  bool isAnagram(string s, string t) 
  {
    int l = s.size();
    
    if(l != t.size())
    {
      return false;
    }
    
    unordered_map<int, int> s_freq;
    unordered_map<int, int> t_freq;
    for(int i = 0; i < l; ++i)
    {
      s_freq[s[i]]++;
      t_freq[t[i]]++;
    }
    
    return s_freq == t_freq;
  }
};