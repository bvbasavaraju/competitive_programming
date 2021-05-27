/****************************************************
Date: May 27th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3752/
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
  Q: Maximum Product of Word Lengths

  Given a string array words, return the maximum value of length(word[i]) * length(word[j]) 
  where the two words do not share common letters. If no such two words exist, return 0.

  Example 1:
    Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
    Output: 16
    Explanation:
      The two words can be "abcw", "xtfn".

  Example 2:
    Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
    Output: 4
    Explanation:
      The two words can be "ab", "cd".

  Example 3:
    Input: words = ["a","aa","aaa","aaaa"]
    Output: 0
    Explanation:
      No such pair of words.

  Constraints:
    2 <= words.length <= 1000
    1 <= words[i].length <= 1000
    words[i] consists only of lowercase English letters.
*/

class Solution 
{
private:
  bool isUnique(vector<int>& f1, vector<int>& f2)
  {
    for(int i = 0; i < 26; ++i)
    {
      if(f1[i] > 0 && f2[i] > 0)
      {
        return false;
      }
    }

    return true;
  }
  
  void calcFreq(const string& s, vector<int>& freq)
  {
    if(freq.size() == 26)
    {
      return;
    }
    
    freq.resize(26, 0);
    for(char ch : s)
    {
      freq[ch-'a']++;
    }
  }
  
public:
  int maxProduct(vector<string>& words) 
  {
    int ans = 0;
    int l = words.size();
    vector< vector<int> > freq(l, vector<int>(0, 0));
    
    for(int i = 0; i < l-1; ++i)
    {
      calcFreq(words[i], freq[i]);
      for(int j = i+1; j < l; ++j)
      {
        calcFreq(words[j], freq[j]);
        
        if(isUnique(freq[i], freq[j]))
        {
          int p = words[i].size() * words[j].size();
          ans = max(ans, p);
        }
      }
    }
    
    return ans;
  }
};