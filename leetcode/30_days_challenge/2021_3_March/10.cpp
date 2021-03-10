/****************************************************
Date: March 10th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3665/
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
  Q: Integer to Roman

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
  The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

  I can be placed before V (5) and X (10) to make 4 and 9. 
  X can be placed before L (50) and C (100) to make 40 and 90. 
  C can be placed before D (500) and M (1000) to make 400 and 900.
  Given an integer, convert it to a roman numeral.

  Example 1:
    Input: num = 3
    Output: "III"

  Example 2:
    Input: num = 4
    Output: "IV"

  Example 3:
    Input: num = 9
    Output: "IX"

  Example 4:
    Input: num = 58
    Output: "LVIII"
    Explanation: 
      L = 50, V = 5, III = 3.

  Example 5:
    Input: num = 1994
    Output: "MCMXCIV"
    Explanation: 
      M = 1000, CM = 900, XC = 90 and IV = 4.

  Constraints:
    1 <= num <= 3999
*/
class Solution 
{
private:
  enum Position_t
  {
    DIGIT_COUNT_ONE = 1,
    DIGIT_COUNT_TWO = 2,
    DIGIT_COUNT_THREE = 3,
  };
  
  void AddRomanString(const string& rS, int c, string& output)
  {
    if(c <= 0 || rS.size() <= 0)
    {
      return;
    }
    
    for(int i = 0; i < c; i++)
    {
      output += rS;
    }
  }
  
  void UpdateRomanSymbol(Position_t pos, int val, string& output)
  {
    string s = "";
    switch(val)
    {
      case 9:
        s = (pos == DIGIT_COUNT_ONE) ? "IX" : ( (pos == DIGIT_COUNT_TWO) ? "XC" : "CM" );
        break;
        
      case 8:
        s = (pos == DIGIT_COUNT_ONE) ? "VIII" : ( (pos == DIGIT_COUNT_TWO) ? "LXXX" : "DCCC" );
        break;
        
      case 7:
        s = (pos == DIGIT_COUNT_ONE) ? "VII" : ( (pos == DIGIT_COUNT_TWO) ? "LXX" : "DCC" );
        break;
        
      case 6:
        s = (pos == DIGIT_COUNT_ONE) ? "VI" : ( (pos == DIGIT_COUNT_TWO) ? "LX" : "DC" );
        break;
        
      case 5:
        s = (pos == DIGIT_COUNT_ONE) ? "V" : ( (pos == DIGIT_COUNT_TWO) ? "L" : "D" );
        break;
        
      case 4:
        s = (pos == DIGIT_COUNT_ONE) ? "IV" : ( (pos == DIGIT_COUNT_TWO) ? "XL" : "CD" );
        break;
        
      case 3:
        s = (pos == DIGIT_COUNT_ONE) ? "III" : ( (pos == DIGIT_COUNT_TWO) ? "XXX" : "CCC" );
        break;
        
      case 2:
        s = (pos == DIGIT_COUNT_ONE) ? "II" : ( (pos == DIGIT_COUNT_TWO) ? "XX" : "CC" );
        break;
        
      case 1:
        s = (pos == DIGIT_COUNT_ONE) ? "I" : ( (pos == DIGIT_COUNT_TWO) ? "X" : "C" );
        break;
    }
    
    output += s;
  }
  
public:
  string intToRoman(int num) 
  {
    string retVal = "";
    
    int mCount = num / 1000;
    AddRomanString("M", mCount, retVal);
    
    num = num % 1000;
    int h = num / 100;
    UpdateRomanSymbol(DIGIT_COUNT_THREE, h, retVal);
    
    num = num % 100;
    int t = num / 10;
    UpdateRomanSymbol(DIGIT_COUNT_TWO, t, retVal);
    
    num = num % 10;
    UpdateRomanSymbol(DIGIT_COUNT_ONE, num, retVal);
    
    return retVal;
  }
};