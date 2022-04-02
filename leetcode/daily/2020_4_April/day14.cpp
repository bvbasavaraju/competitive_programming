/****************************************************
Date: April 14th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3299/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
  Q:  Perform String Shifts

  You are given a string s containing lowercase English letters, and a matrix shift, 
  where shift[i] = [direction, amount]:

  direction can be 0 (for left shift) or 1 (for right shift). 
  amount is the amount by which string s is to be shifted.
  A left shift by 1 means remove the first character of s and append it to the end.
  Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
  Return the final string after all operations.

  

  Example 1:
  Input: s = "abc", shift = [[0,1],[1,2]]
  Output: "cab"
  Explanation: 
  [0,1] means shift to left by 1. "abc" -> "bca"
  [1,2] means shift to right by 2. "bca" -> "cab"

  Example 2:
  Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
  Output: "efgabcd"
  Explanation:  
  [1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
  [1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
  [0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
  [1,3] means shift to right by 3. "abcdefg" -> "efgabcd"

  Constraints:
  1 <= s.length <= 100
  s only contains lower case English letters.
  1 <= shift.length <= 100
  shift[i].length == 2
  0 <= shift[i][0] <= 1
  0 <= shift[i][1] <= 100

  Show Hint #1
    Intuitively performing all shift operations is acceptable due to the constraints.
  Show Hint #2  
    You may notice that left shift cancels the right shift, so count the total left shift times 
    (may be negative if the final result is right shift), and perform it once.
*/

class Solution 
{
public:
  string stringShift(string s, vector<vector<int>>& shift) 
  {
    int p = 0;  //starting position!
    int l_str = s.size();
    int l_sh = shift.size();
    
    for(int i = 0; i < l_sh; ++i)
    {
      if(shift[i][0] == 0)
      {
        //Shift POSITION(p) right by amount! 
        //because string is left shifted, starting position for printing that stirng is right shifted.
        p += shift[i][1];
      }
      else
      {
        //Shift POSITION(p) left by amount
        //because string is right shifted, starting position for printing that stirng is left shifted.
        p -= shift[i][1];
      }
      
      //Consider string is in circular buffer. Hence positionn has to be adjusted.
      //if position is negetive or greater than length, then update it to point to the correct position
      if(p < 0)
      {
        p = l_str + p;
      }
      else if(p >= l_str)
      {
        p %= l_str;
      }
    }
    
    string ans;
    for(int i = 0; i < l_str; ++i)
    {
      ans += s[(i+p) % l_str];
    }
    
    return ans;
  }
};