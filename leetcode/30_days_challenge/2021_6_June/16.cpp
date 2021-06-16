/****************************************************
Date: June 16th

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
  Q: Generate Parentheses

  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

  Example 1:
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]

  Example 2:
    Input: n = 1
    Output: ["()"]
  

  Constraints:
    1 <= n <= 8
*/

class Solution 
{
private:  
  void collect(string s, int left, int right, vector<string>& ans)
  {
    if((left == 0) && (right == 0))
    {
      ans.push_back(s);
      return;
    }
    
    if(left > 0)
    {
      collect(s+"(", left-1, right, ans);
    }
    if(right > left)
    {
      collect(s+")", left, right-1, ans);
    }
  }
  
public:
  vector<string> generateParenthesis(int n) 
  { 
    vector<string> ans;
    collect("", n, n, ans);
    
    return ans;
  }
};