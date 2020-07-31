/****************************************************
Date: July 30th

link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3406/
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
  Q: Word Break II - Logic is fine. Need to optimize it. Still not completed.
  
  Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
  add spaces in s to construct a sentence where each word is a valid dictionary word.
  Return all such possible sentences.

  Note:
    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.
  
  Example 1:
    Input:
      s = "catsanddog"
      wordDict = ["cat", "cats", "and", "sand", "dog"]
    Output:
      [
        "cats and dog",
        "cat sand dog"
      ]

  Example 2:
    Input:
      s = "pineapplepenapple"
      wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    Output:
      [
        "pine apple pen apple",
        "pineapple pen apple",
        "pine applepen apple"
      ]
  Explanation: Note that you are allowed to reuse a dictionary word.
  
  Example 3:
    Input:
      s = "catsandog"
      wordDict = ["cats", "dog", "sand", "and", "cat"]
    Output:
      []
*/
class Solution 
{
private:
  /*string getWord(string& s, int p_start, int len, unordered_map<int, vector<string>>& words)
  {
    if((p_start + len) > s.size() || (words[len] == words.end()))
    {
      return "";
    }
    
    string substr_ = s.substr(p_start, len);
    
    vector<strings>
    
  }
  
  int getSentnece(string& s, unordered_map<int, vector<string>>& words, string& sentence)
  {
    int p = 0;
    int l = s.szie();
    for(int i = 1; i <= l; ++i)
    {
      string w = getWord(s, p, i, words);
      if(w.empty())
      {
        continue;
      }
      
      
    }
    
    return (p != l) ? l-p : 0;
  }*/
  
  bool getSentences(string& s, string& part, int pos, unordered_map<int, vector<string>>& words, vector<string>& sents)
  {
    int l = s.size();
    if(pos >= l)
    {
      false;
    }
    
    for(int i = p + 1; i < l; ++i)
    {
      string substr_ = s.substr(p, i);
      if(words[i-p] != words.end())
      {
        for(string& str : words[i-p])
        {
          if(str == substr)
          {
            sents.push_back(part + substr_ + (i == l-1) ? "" : " ");
            return true;
          }
        }
      }
    }
    
    return false;
  }
  
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) 
  {
    unordered_map<int, vector<string>> length_words;
    for(string& w : wordDict)
    {
      length_words[w.size()].push_back(w);
    }
    
    vector<string> ans;
    while(true)
    {
      for(string& s : )
    }
    
    return ans;
  }
};