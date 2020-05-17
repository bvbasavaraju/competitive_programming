/****************************************************
Date: May 17th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/
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
  Q: Find All Anagrams in a String
  Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
  Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

  The order of output does not matter.

  Example 1:
    Input:
      s: "cbaebabacd" p: "abc"
    Output:
      [0, 6]
    Explanation:
      The substring with start index = 0 is "cba", which is an anagram of "abc".
      The substring with start index = 6 is "bac", which is an anagram of "abc".

  Example 2:
    Input:
      s: "abab" p: "ab"
    Output:
      [0, 1, 2]
    Explanation:
      The substring with start index = 0 is "ab", which is an anagram of "ab".
      The substring with start index = 1 is "ba", which is an anagram of "ab".
      The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution 
{
public:
  vector<int> findAnagrams(string s, string p) 
  {
    int sl = s.size();
    int pl = p.size();
    
    vector<int> ans;
    if(sl < pl)
    {
      return ans;
    }
    
    vector<int> s_ch_count(26, 0); //there are 26 characters
    vector<int> p_ch_count(26, 0); //there are 26 characters
    
    //for the same length of p find the count of the each characters in s
    for(int i = 0; i < pl; ++i)
    {
      p_ch_count[p[i] - 'a']++;
      s_ch_count[s[i] - 'a']++;
    }
    
    for(int i = 0; i <= sl-pl; ++i)
    {
      if(s_ch_count == p_ch_count)
      {
        ans.push_back(i);
      }
      
      //Now slide the window of size pl!
      //So reduce the character count at i by 1
      //and increase the character count at i + pl by 1.
      //So, now windows has been glided!
      s_ch_count[s[i] - 'a']--;
      if(i + pl < sl)
      {
        s_ch_count[s[i + pl] - 'a']++;
      }
    }
    
    return ans;
  }
};