/****************************************************
Date: May 17th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3744/
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
  Q: Longest String Chain

  Given a list of words, each word consists of English lowercase letters.

  Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter 
  anywhere in word1 to make it equal to word2. For example, "abc" is a predecessor of "abac".

  A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 
  is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

  Return the longest possible length of a word chain with words chosen from the given list of words.

  Example 1:
    Input: words = ["a","b","ba","bca","bda","bdca"]
    Output: 4
    Explanation:
      One of the longest word chain is "a","ba","bda","bdca".

  Example 2:
    Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
    Output: 5

  Constraints:
    1 <= words.length <= 1000
    1 <= words[i].length <= 16
    words[i] only consists of English lowercase letters.

  Hide Hint #1  
    Instead of adding a character, try deleting a character to form a chain in reverse.
  
  Hide Hint #2  
    For each word in order of length, for each word2 which is word with one character removed, 
    length[word2] = max(length[word2], length[word] + 1).
*/

class Solution 
{  
public:
  int longestStrChain(vector<string>& words) 
  {
    sort(words.begin(), words.end(), [](const string& s1, const string& s2) -> bool
         {
           return s1.size() < s2.size();
         });
    
    unordered_map<string, int> dp;
    
    int ans = 0;
    for(string w: words)
    {
      int l = w.size();
      for(int i = 0; i < l; ++i)
      {
        string prev = w.substr(0, i) + w.substr(i+1);
        dp[w] = max(dp[w], (dp.find(prev) == dp.end()) ? 1 : dp[prev] + 1);
      }
      
      ans = max(ans, dp[w]);
    }
    
    return ans;
  }
};