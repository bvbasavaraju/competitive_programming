#include <iostream>

using namespace std;

/*
  Q: Valid Anagram

  Given two strings s and t , write a function to determine if t is an anagram of s.

  Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

  Example 2:
    Input: s = "rat", t = "car"
    Output: false

  Note:
    You may assume the string contains only lowercase alphabets.

  Follow up:
    What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution 
{
public:
  bool isAnagram(string s, string t) 
  {
    vector<int> s_count(26, 0);
    vector<int> t_count(26, 0);
    
    int ls = s.size();
    int lt = t.size();
    for(int i = 0; i < ls; ++i)
    {
      s_count[s[i] - 'a']++;
    }
    
    for(int i = 0; i < lt; ++i)
    {
      t_count[t[i] - 'a']++;
    }
    
    return (s_count == t_count);
  }
};