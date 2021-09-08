/****************************************************
Date: September 8th

link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3968/
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
  Q: Shifting Letters

  You are given a string s of lowercase English letters and an integer array shifts of the same length.
  Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

  For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
  Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

  Return the final string after all such shifts to s are applied.

  Example 1:
    Input: s = "abc", shifts = [3,5,9]
    Output: "rpl"
    Explanation: 
      We start with "abc".
      After shifting the first 1 letters of s by 3, we have "dbc".
      After shifting the first 2 letters of s by 5, we have "igc".
      After shifting the first 3 letters of s by 9, we have "rpl", the answer.

  Example 2:
    Input: s = "aaa", shifts = [1,2,3]
    Output: "gfd"

  Constraints:
    1 <= s.length <= 105
    s consists of lowercase English letters.
    shifts.length == s.length
    0 <= shifts[i] <= 109
*/

class Solution 
{
public:
  string shiftingLetters(string s, vector<int>& shifts) 
  {
    int l = s.size();
    
    //Slower. takes 275+ ms
//     vector<int> pShifts(l, 0);
//     pShifts[l-1] = shifts[l-1] % 26;
//     for(int i = l-2; i >= 0; --i)
//     {
//       pShifts[i] = (pShifts[i + 1] + (shifts[i] % 26) ) % 26;
//     }
    
//     for(int i = 0; i < l; ++i)
//     {
//       s[i] = (s[i] - 'a' + static_cast<int>(pShifts[i])) % 26 + 'a';
//     }
    
    
//     s[l-1] = (s[l-1] -'a' + (shifts[l-1] % 26)) % 26 + 'a';
//     for(int i = l-2; i >= 0; --i)
//     {
//       shifts[i] = (shifts[i+1] % 26 + shifts[i] % 26) % 26;
      
//       s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
//     }
    
    //Much faster!!
    int sum = 0;
    for(int i = l-1; i >= 0; --i)
    {
      sum = (sum + shifts[i]) % 26;
      s[i] = (s[i] - 'a' + sum) % 26 + 'a';
    }
      
    
    return s;
  }
};