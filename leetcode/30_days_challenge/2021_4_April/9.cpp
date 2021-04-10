/****************************************************
Date: April 9th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3701/
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
  Q: Verifying an Alien Dictionary

  In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. 
  The order of the alphabet is some permutation of lowercase letters.

  Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only 
  if the given words are sorted lexicographicaly in this alien language.

  Example 1:
    Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
    Output: true
    Explanation: 
      As 'h' comes before 'l' in this language, then the sequence is sorted.

  Example 2:
    Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
    Output: false
    Explanation: 
      As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

  Example 3:
    Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
    Output: false
    Explanation: 
      The first three characters "app" match, and the second string is shorter (in size.) 
      According to lexicographical rules "apple" > "app", because 'l' > '∅', 
      where '∅' is defined as the blank character which is less than any other character (More info).

  Constraints:
    1 <= words.length <= 100
    1 <= words[i].length <= 20
    order.length == 26
    All characters in words[i] and order are English lowercase letters.
*/

class Solution 
{
public:
  bool isAlienSorted(vector<string>& words, string order) 
  {
    //Using vector makes it even faster!!
    string ourOrder = "abcdefghijklmnopqrstuvwxyz";
    
    vector<int> replacePos(26,0);
    for(int i = 0; i < 26; ++i)
    {
      replacePos[order[i]-'a'] = i;
    }

    for(string& w : words)
    {
      for(char& ch : w)
      {
        ch = ourOrder[replacePos[ch-'a']];
      }
    }
    
    return is_sorted(words.begin(), words.end());
    
//     unordered_map<int, int> order_;
    
//     int i = 0;
//     for(int ch : order)
//     {
//       order_[ch] = i;
//       i++;
//     }
    
//     string ourOrder = "abcdefghijklmnopqrstuvwxyz";

//     for(string& w : words)
//     {
//       for(char& ch : w)
//       {
//         ch = ourOrder[order_[ch]];
//       }
//     }
    
//     return is_sorted(words.begin(), words.end());
    
    //Below code is little slower and takes O(n) extra memory

//     vector<string> words_ = words;
//     for(string& w : words_)
//     {
//       for(char& ch : w)
//       {
//         ch = ourOrder[order_[ch]];
//       }
//     }
    
//     sort(words_.begin(), words_.end());
//     for(string& w : words_)
//     {
//       for(char& ch : w)
//       {
//         ch = order[ch-'a'];
//       }
//     }
    
//     return (words_ == words);
  }
};