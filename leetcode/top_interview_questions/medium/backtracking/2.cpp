#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>

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