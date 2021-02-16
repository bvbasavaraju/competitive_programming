/****************************************************
Date: Feb 16th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3641/
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
  Q: Letter Case Permutation

  Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

  Return a list of all possible strings we could create. You can return the output in any order.

  Example 1:
    Input: S = "a1b2"
    Output: ["a1b2","a1B2","A1b2","A1B2"]

  Example 2:
    Input: S = "3z4"
    Output: ["3z4","3Z4"]

  Example 3:
    Input: S = "12345"
    Output: ["12345"]

  Example 4:
    Input: S = "0"
    Output: ["0"]

  Constraints:
    S will be a string with length between 1 and 12.
    S will consist only of letters or digits.
*/

class Solution 
{
private:
  void collectString(string s, int p, unordered_set<string>& db)
  {
    db.insert(s);
    
    if(p >= s.size())
    {
      return;
    }
    
    if((s[p] >= '0') && (s[p] <= '9'))
    {
      return collectString(s, p+1, db);
    }
    
    char& ch = s[p];
    if(ch >= 'a' && ch <= 'z')
    {
      string str = s;
      str[p] = (ch - 'a') + 'A';
      collectString(str, p+1, db);
    }
    else if(ch >= 'A' && ch <= 'Z')
    {
      string str = s;
      str[p] = (ch - 'A') + 'a';
      collectString(str, p+1, db);
    }
    
    collectString(s, p+1, db);
  }
  
public:
  vector<string> letterCasePermutation(string S) 
  {
    unordered_set<string> db;
    collectString(S, 0, db);
    
    vector<string> ans;
    for(auto s : db)
    {
      ans.push_back(s);
    }
    
    return ans;
  }
};