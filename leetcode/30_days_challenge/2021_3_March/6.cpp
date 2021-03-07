/****************************************************
Date: March 6th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3657/
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
  Q: Short Encoding of Words

  A valid encoding of an array of words is any reference string s and array of indices indices such that:

  words.length == indices.length
  The reference string s ends with the '#' character.
  For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
  Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.

  Example 1:
    Input: words = ["time", "me", "bell"]
    Output: 10
    Explanation: 
      A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
        words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
        words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
        words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"

  Example 2:
    Input: words = ["t"]
    Output: 2
    Explanation: 
      A valid encoding would be s = "t#" and indices = [0].

  Constraints:
    1 <= words.length <= 2000
    1 <= words[i].length <= 7
    words[i] consists of only lowercase letters.
*/

class Solution 
{
public:
  int minimumLengthEncoding(vector<string>& words) 
  {
    sort(words.begin(), words.end(), [](const string& s1, const string& s2) -> bool
         {
           return s1.size() > s2.size();
         }
        );
    
    string data = words[0] + "#";
    
    for(string& s : words)
    {
      if(data.find(s+"#") != std::string::npos)
      {
        continue;
      }
      
      data += s + "#";
    }
    
    return data.size();
  }
};

// class Solution 
// {
// public:
//   int minimumLengthEncoding(vector<string>& words) 
//   {
//     sort(words.begin(), words.end(), [](const string& s1, const string& s2) -> bool
//          {
//            return s1.size() > s2.size();
//          }
//         );
    
//     string data = words[0] + "#";
    
//     int l = words.size();
    
//     for(int i = 1; i < l; ++i)
//     {
//       string& s = words[i];
//       if(data.find(s+"#") != std::string::npos)
//       {
//         continue;
//       }
      
//       data += s + "#";
//     }
    
//     return data.size();
//   }
// };