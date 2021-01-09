/****************************************************
Date: May 22th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/
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
  Q: Sort Characters By Frequency
  Given a string, sort it in decreasing order based on the frequency of characters.

  Example 1:
    Input:
    "tree"
    Output:
    "eert"
    Explanation:
    'e' appears twice while 'r' and 't' both appear once.
    So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

  Example 2:
    Input:
    "cccaaa"

    Output:
    "cccaaa"

    Explanation:
    Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
    Note that "cacaca" is incorrect, as the same characters must be together.

  Example 3:
    Input:
    "Aabb"

    Output:
    "bbAa"

    Explanation:
    "bbaA" is also a valid answer, but "Aabb" is incorrect.
    Note that 'A' and 'a' are treated as two different characters.
*/

class Solution 
{
public:
  string frequencySort(string s) 
  {
    unordered_map<int, int> freq;
    
    for(int ch : s)
    {
      freq[ch]++;
    }
    
    vector<pair<int, int>> data(freq.begin(), freq.end());
    sort(data.begin(), data.end(), [](const pair<int, int>& d1, const pair<int, int>& d2) -> bool { return d1.second > d2.second;});
    
    string ans = "";
    for(auto it = data.begin(); it != data.end(); ++it)
    {
      for(int i = 0; i < it->second; ++i)
      {
        ans += it->first;
      }
    }
    
    return ans;
  }
};