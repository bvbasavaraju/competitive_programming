/****************************************************
Date: April 16th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3709/
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
  Q: Remove All Adjacent Duplicates in String II

  Given a string s, a k duplicate removal consists of choosing k adjacent and equal
  letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

  We repeatedly make k duplicate removals on s until we no longer can.
  Return the final string after all such duplicate removals have been made.
  It is guaranteed that the answer is unique.

  Example 1:
    Input: s = "abcd", k = 2
    Output: "abcd"
    Explanation:
      There's nothing to delete.

  Example 2:
    Input: s = "deeedbbcccbdaa", k = 3
    Output: "aa"
    Explanation: 
      First delete "eee" and "ccc", get "ddbbbdaa"
      Then delete "bbb", get "dddaa"
      Finally delete "ddd", get "aa"

  Example 3:
    Input: s = "pbbcggttciiippooaais", k = 2
    Output: "ps"

  Constraints:
    1 <= s.length <= 10^5
    2 <= k <= 10^4
    s only contains lower case English letters.

  Hide Hint #1  
    Use a stack to store the characters, when there are k same characters, delete them.
  Hide Hint #2  
    To make it more efficient, use a pair to store the value and the count of each character.
*/

class Solution 
{
public:
  string removeDuplicates(string s, int k) 
  {
    int l = s.size();
    vector< vector<int> > data; //~40% faster, with 20% additional memory!
    for(int i = 0; i < l; ++i)
    {
      int ch = s[i] - 'a';
      
      bool added = false;
      if(!data.empty() && data.back()[0] == ch)
      {
        data.back().push_back(ch);
        added = true;
      }
      
      if(!data.empty() && data.back().size() == k)
      {
        data.pop_back();
      }
      
      if(!added)
      {
        data.push_back({ch});
      }
    }
    
    string ans = "";
    for(vector<int>& d : data)
    {
      for(int& ch : d)
      {
        ans += (ch + 'a'); 
      }
    }
    
    return ans;
    
    //Slower as I am using the substr(), but memory usage is less.
//     vector<string> data;
    
//     for(int i = 0; i < l; ++i)
//     {
//       string str = s.substr(i, 1);
      
//       bool added = false;
//       if(!data.empty() && data.back()[0] == str[0])
//       {
//         data.back() += str;
//         added = true;
//       }
      
//       if(!data.empty() && data.back().size() == k)
//       {
//         data.pop_back();
//       }
      
//       if(!added)
//       {
//         data.push_back(str);
//       }
//     }
    
//     string ans = "";
//     for(string& d : data)
//     {
//       ans += d;
//     }
    
//     return ans;
  }
};