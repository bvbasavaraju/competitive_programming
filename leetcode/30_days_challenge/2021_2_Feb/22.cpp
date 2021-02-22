/****************************************************
Date: Feb 22nd

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3649/
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
  Q: Longest Word in Dictionary through Deleting

  Given a string and a string dictionary, find the longest string in the dictionary 
  that can be formed by deleting some characters of the given string. 
  If there are more than one possible results, 
  return the longest word with the smallest lexicographical order. 
  If there is no possible result, return the empty string.

  Example 1:
    Input:
      s = "abpcplea", d = ["ale","apple","monkey","plea"]
    Output: 
      "apple"

  Example 2:
    Input:
      s = "abpcplea", d = ["a","b","c"]
    Output: 
      "a"

  Note:
    All the strings in the input will only contain lower-case letters.
    The size of the dictionary won't exceed 1,000.
    The length of all the strings in the input won't exceed 1,000.
*/

class Solution 
{
private:
  bool isMatch(const string& s, const string& word)
  {
    int wi = 0;
    for(int i = 0; i < s.size(); ++i)
    {
      if(wi < word.size() && word[wi] == s[i])
      {
        wi++;
      }
    }
    
    return wi == word.size();
  }
  
public:
  string findLongestWord(string s, vector<string>& d) 
  {
    string ans = "";
    for(string& word : d)
    {
      if(isMatch(s, word))
      {
        if(ans.size() < word.size())
        {
          ans = word;
        }
        else if(ans.size() == word.size())
        {
          ans = min(ans, word);
        }
      }
    }
    
    return ans;
  }
};
