/****************************************************
Date: June 19th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3365/
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
  Q: Longest Duplicate Substring

  Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times (The occurrences may overlap).

  Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

  Example 1:
    Input: "banana"
    Output: "ana"

  Example 2:
    Input: "abcd"
    Output: ""

  Note:
    2 <= S.length <= 10^5
    S consists of lowercase English letters.

  Hide Hint #1  
    Binary search for the length of the answer. (If there's an answer of length 10, then there are answers of length 9, 8, 7, ...)
  Hide Hint #2  
    To check whether an answer of length K exists, we can use Rabin-Karp 's algorithm.
*/
class Solution 
{
public:
  string longestDupSubstring(string S) 
  {
    std::string_view str;
    unordered_set<string_view> strs;
    
    int lo = 1;
    int hi = S.size() - 1;
    
    while(lo <= hi)
    {
      int m = lo + (hi - lo)/2;
      
      bool found_dup = false;
      for(int i = 0; i < S.size() - m + 1; ++i)
      {
        auto[it, inserted] = strs.emplace(S.data() + i, m);
        if(!inserted)
        {
          found_dup = true;
          str = *it;
          break;
        }
      }
      
      if(found_dup)
      {
        lo = m + 1;
      }
      else
      {
        hi = m - 1;
      }
    }
    
    return {str.begin(), str.end()};
  }
};