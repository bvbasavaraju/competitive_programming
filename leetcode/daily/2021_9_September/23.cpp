/****************************************************
Date: September 22th

https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3985/
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
  Q : Break a Palindrome

  Given a palindromic string of lowercase English letters palindrome, 
  replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome 
  and that it is the lexicographically smallest one possible.

  Return the resulting string. If there is no way to replace a character to make it not a palindrome, 
  return an empty string.

  A string a is lexicographically smaller than a string b (of the same length) if in the first position 
  where a and b differ, a has a character strictly smaller than the corresponding character in b. 
  For example, "abcc" is lexicographically smaller than "abcd" because the first position 
  they differ is at the fourth character, and 'c' is smaller than 'd'.

  Example 1:
    Input: palindrome = "abccba"
    Output: "aaccba"
    Explanation: 
      There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
      Of all the ways, "aaccba" is the lexicographically smallest.

  Example 2:
    Input: palindrome = "a"
    Output: ""
    Explanation: 
      There is no way to replace a single character to make "a" not a palindrome, so return an empty string.

  Example 3:
    Input: palindrome = "aa"
    Output: "ab"

  Example 4:
    Input: palindrome = "aba"
    Output: "abb"

  Constraints:
    1 <= palindrome.length <= 1000
    palindrome consists of only lowercase English letters.

  Hide Hint #1  
    How to detect if there is impossible to perform the replacement? Only when the length = 1.

  Hide Hint #2  
    Change the first non 'a' character to 'a'.

  Hide Hint #3  
    What if the string has only 'a'?

  Hide Hint #4  
    Change the last character to 'b'.
*/

class Solution 
{
public:
  string breakPalindrome(string s) 
  {
    int l = s.size();
    bool modified = false;
    for(int i = 0; i < l/2; ++i)
    {
      if(s[i] != 'a')
      {
        s[i] = 'a';
        modified = true;
        break;
      }
    }
    
    if(!modified && (l > 1))
    {
      s[l -1] = 'b';
      modified = true;
    }
    
    return modified ? s : "";
  }
};