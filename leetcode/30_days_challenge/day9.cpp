/****************************************************
Date: April 9th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3291/
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
  Q:  Backspace String Compare

  Given two strings S and T, return if they are equal when both are typed into empty text editors. 
  # means a backspace character.

  Example 1:
  Input: S = "ab#c", T = "ad#c"
  Output: true
  Explanation: Both S and T become "ac".

  Example 2:
  Input: S = "ab##", T = "c#d#"
  Output: true
  Explanation: Both S and T become "".

  Example 3:
  Input: S = "a##c", T = "#a#c"
  Output: true
  Explanation: Both S and T become "c".

  Example 4:
  Input: S = "a#c", T = "b"
  Output: false
  Explanation: S becomes "c" while T becomes "b".

  Note:
  1 <= S.length <= 200
  1 <= T.length <= 200
  S and T only contain lowercase letters and '#' characters.


  Follow up:
  Can you solve it in O(N) time and O(1) space? - need to test implementation
*/
class Solution 
{
private:
  vector<int> s_print;
  vector<int> t_print;
  
  void printString(string& str, vector<int>& v)
  {
    int l = str.size();
    for(int i = 0; i < l; ++i)
    {
      if(str[i] != '#')
      {
        v.push_back(str[i]);
      }
      else if(v.size() > 0)
      {
        v.pop_back();
      }
    }
  }
  
public:
  bool backspaceCompare(string S, string T) 
  {
    //O(N+M) space and O(N+M) time
    printString(S, s_print);
    printString(T, t_print);
    
    return (t_print == s_print);
  }
};