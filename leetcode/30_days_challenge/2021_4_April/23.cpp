/****************************************************
Date: April 23rd

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3717/
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
  Q: Count Binary Substrings

  Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, 
  and all the 0's and all the 1's in these substrings are grouped consecutively.

  Substrings that occur multiple times are counted the number of times they occur.

  Example 1:
    Input: "00110011"
    Output: 6
    Explanation: 
      There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
      Notice that some of these substrings repeat and are counted the number of times they occur.
      Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

  Example 2:
    Input: "10101"
    Output: 4
    Explanation:
      There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

  Note:
    s.length will be between 1 and 50,000.
    s will only consist of "0" or "1" characters.

  Hide Hint #1  
    How many valid binary substrings exist in "000111", and how many in "11100"? What about "00011100"?
*/
class Solution 
{
public:
  int countBinarySubstrings(string s) 
  {
    int cur = 1, pre = 0, res = 0;
    for (int i = 1; i < s.size(); i++) 
    {
      if (s[i] == s[i - 1]) 
      {
        cur++;
      }
      else 
      {
        res += min(cur, pre);
        pre = cur;
        cur = 1;
      }
    }
    
    return res + min(cur, pre);
    /*vector<int> freq(2, 0);
    
    int ans = 0;
    int l = s.size();
    
    int si = 0;
    int sj = 0;

    int i = si;
    for( ; i < l-1;)
    {
      freq[s[i] - '0']++;
      if(s[i] == s[i+1])
      {
        i++;
        continue;
      }
      
      ans += min(freq[0], freq[1]);
      while(sj < si)
      {
        freq[s[sj] - '0']--;
        sj++;
      }
      
      sj = i+1;
      int j = sj;
      for(; j < l-1;)
      {
        freq[s[j] - '0']++;
        if(s[j] == s[j+1])
        {
          j++;
          continue;
        }
        else
        {
          break;
        }
      }
      
      ans += min(freq[0], freq[1]);
      while(si < sj)
      {
        freq[s[si] - '0']--;
        si++;
      }
      
      si = j+1;
      i = si;
    }
    
    //if((l > 1) && (s[l-2] != s[l-1]))
    if((l > 1) && (ans > 0))
    {
      ans++;
    }
    
    return ans;*/
  }
};