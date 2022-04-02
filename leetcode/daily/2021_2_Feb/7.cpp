/****************************************************
Date: Feb 7th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3628/
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
  Q: Shortest Distance to a Character

  Given a string s and a character c that occurs in s, return an array of integers answer where 
  answer.length == s.length and answer[i] is the shortest distance from s[i] to the character c in s.

  Example 1:
    Input: s = "loveleetcode", c = "e"
    Output: [3,2,1,0,1,0,0,1,2,2,1,0]

  Example 2:
    Input: s = "aaab", c = "b"
    Output: [3,2,1,0]

  Constraints:
    1 <= s.length <= 104
    s[i] and c are lowercase English letters.
    c occurs at least once in s.
*/
class Solution 
{
public:
  vector<int> shortestToChar(string s, char c) 
  {
    vector<int> ans;
    deque<char> letters;
    
    int prev_dist = INT_MAX;
    for(char ch : s)
    {
      if(ch == c)
      {
        while(!letters.empty())
        {
          ans.push_back(min(prev_dist, static_cast<int>(letters.size())));
          letters.pop_front();
          if(prev_dist != INT_MAX)
          {
            prev_dist++;
          }
        }
        
        ans.push_back(0);
        prev_dist = 1;
      }
      else
      {
        letters.push_front(ch);
      }
    }
    
    prev_dist = 1;
    while(!letters.empty())
    {
      ans.push_back(prev_dist);
      letters.pop_front();
      
      prev_dist++;
    }
    
    return ans;
  }
};