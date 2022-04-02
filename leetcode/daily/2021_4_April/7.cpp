/****************************************************
Date: April 7th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/
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
  Q: Determine if String Halves Are Alike

  You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
  Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
  Return true if a and b are alike. Otherwise, return false.

  Example 1:
    Input: s = "book"
    Output: true
    Explanation: 
      a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

  Example 2:
    Input: s = "textbook"
    Output: false
    Explanation: 
      a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
      Notice that the vowel o is counted twice.

  Example 3:
    Input: s = "MerryChristmas"
    Output: false

  Example 4:
    Input: s = "AbCdEfGh"
    Output: true

  Constraints:
    2 <= s.length <= 1000
    s.length is even.
    s consists of uppercase and lowercase letters.

  Hide Hint #1  
    Create a function that checks if a character is a vowel, either uppercase or lowercase.
*/

class Solution 
{
private:
  bool isVoWel(char& ch)
  {
    switch(ch)
    {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        return true;
    }
    
    return false;
  }
public:
  bool halvesAreAlike(string s) 
  {
    int aCount = 0;
    int bCount = 0;
    
    int l = s.size();
    for(int i = 0; i < l/2; ++i)
    {
      aCount = (isVoWel(s[i]) == true) ? aCount + 1 : aCount;
      bCount = (isVoWel(s[l-1-i]) == true) ? bCount + 1 : bCount;
    }
    
    return (aCount == bCount);
  }
};