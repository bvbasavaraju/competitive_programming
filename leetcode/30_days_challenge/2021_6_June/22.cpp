/****************************************************
Date: June 22st

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3781/
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
  Q: Number of Matching Subsequences

  Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
  A subsequence of a string is a new string generated from the original string with some characters (can be none)
  deleted without changing the relative order of the remaining characters.
  For example, "ace" is a subsequence of "abcde".

  Example 1:
    Input: s = "abcde", words = ["a","bb","acd","ace"]
    Output: 3
      Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

  Example 2:
    Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
    Output: 2

  Constraints:
    1 <= s.length <= 5 * 104
    1 <= words.length <= 5000
    1 <= words[i].length <= 50
    s and words[i] consist of only lowercase English letters.
*/
class Solution 
{
private:
  bool isSubSequence(const string& a, const string& b)
  {
    int size1 = a.size();
    int size2 = b.size();
    int i=0,j=0;
    for(i=0,j=0; i<size1 && j < size2 ;i++)
    {
      if(a[i]==b[j])
      {
        j++;
      }
    }
    
    return j == size2;
  }
  
public:
  int numMatchingSubseq(string s, vector<string>& words) 
  {
    int ans = 0;
    unordered_map<string, int> subs;
    for(auto& w : words)
    {
      if(subs.find(w) != subs.end())
      {
        ans+= subs[w];
      }
      else
      {
        subs[w] = isSubSequence(s, w);
        ans += subs[w];
      }
    }
    
    return ans;
  }
};