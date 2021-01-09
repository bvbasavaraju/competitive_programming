/****************************************************
Date: May 18th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/
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
  Q: Permutation in String
  Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
  In other words, one of the first string's permutations is the substring of the second string.

  Example 1:
    Input: s1 = "ab" s2 = "eidbaooo"
    Output: True
    Explanation: s2 contains one permutation of s1 ("ba").

  Example 2:
    Input:s1= "ab" s2 = "eidboaoo"
    Output: False

  Note:
    The input strings only contain lower case letters.
    The length of both given strings is in range [1, 10,000].
  
  Hide Hint #1  
    Obviously, brute force will result in TLE. Think of something else.
  Hide Hint #2  
    How will you check whether one string is a permutation of another string?
  Hide Hint #3  
    One way is to sort the string and then compare. But, Is there a better way?
  Hide Hint #4  
    If one string is a permutation of another string then they must one common metric. What is that?
  Hide Hint #5  
    Both strings must have same character frequencies, if one is permutation of another. Which data structure should be used to store frequencies?
  Hide Hint #6  
    What about hash table? An array of size 26?
*/
class Solution
{
public:
  bool checkInclusion(string s1, string s2) 
  {
    int ls1 = s1.size();
    int ls2 = s2.size();
    
    if(ls2 < ls1)
    {
      return false;
    }
    
    vector<int> letter_count_s1(26, 0);
    vector<int> letter_count_s2(26, 0);
    
    for(int i = 0; i < ls1; ++i)
    {
      letter_count_s1[s1[i] - 'a']++;
      letter_count_s2[s2[i] - 'a']++;
    }
    
    for(int i = 0; i <= ls2 - ls1; ++i)
    {
      if(letter_count_s1 == letter_count_s2)
      {
        return true;
      }
      
      letter_count_s2[s2[i] - 'a']--;
      if(i + ls1 < ls2)
      {
        letter_count_s2[s2[i+ls1] - 'a']++;
      }
    }
    
    return false;
  }
};