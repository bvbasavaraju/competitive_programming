/****************************************************
Date: Feb 20th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3641/
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
  Q: Roman to Integer

  Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

  Symbol       Value
  I             1
  V             5
  X             10
  L             50
  C             100
  D             500
  M             1000
  For example, 2 is written as II in Roman numeral, just two one's added together. 
  12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

  Roman numerals are usually written largest to smallest from left to right. 
  However, the numeral for four is not IIII. Instead, the number four is written as IV. 
  Because the one is before the five we subtract it making four. 
  The same principle applies to the number nine, which is written as IX. 
  
  There are six instances where subtraction is used:
    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900

  Given a roman numeral, convert it to an integer.

  Example 1:
    Input: s = "III"
    Output: 3

  Example 2:
    Input: s = "IV"
    Output: 4

  Example 3:
    Input: s = "IX"
    Output: 9

  Example 4:
    Input: s = "LVIII"
    Output: 58
    Explanation: 
      L = 50, V= 5, III = 3.

  Example 5:
    Input: s = "MCMXCIV"
    Output: 1994
    Explanation: 
      M = 1000, CM = 900, XC = 90 and IV = 4.

  Constraints:
    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].

  Hide Hint #1  
    Problem is simpler to solve by working the string from back to front and using a map.
*/
class Solution 
{
private:
  int getVal(char sym, char next_ch)
  {
    switch(sym)
    {
      case 'I' : 
        return next_ch == 'V' || next_ch == 'X' ? -1 : 1;
        
      case 'V' : 
        return 5;
        
      case 'X' : 
        return next_ch == 'L' || next_ch == 'C' ? -10 : 10;

      case 'L' : 
        return 50;
        
      case 'C' : 
        return next_ch == 'D' || next_ch == 'M' ? -100 : 100;
        
      case 'D' : 
        return 500;
        
      case 'M' : 
        return 1000;
    }
    
    return 0;
  }
  
public:
  int romanToInt(string s) 
  {
    int l = s.size();
    
    int ans = getVal(s[l-1], 0);
    for(int i = l-2; i >=0; --i)
    {
      int val = getVal(s[i], s[i+1]);
      
      ans += val;
    }
    
    return ans;
  }
};