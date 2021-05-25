/****************************************************
Date: May 25th

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
  Q: Evaluate Reverse Polish Notation

  Evaluate the value of an arithmetic expression in Reverse Polish Notation.

  Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

  Note that division between two integers should truncate toward zero.

  It is guaranteed that the given RPN expression is always valid. 
  That means the expression would always evaluate to a result, and there will not be any division by zero operation.
*/

class Solution 
{
private:
  void update(const string& t, stack<int>& data)
  {
    switch(t[0])
    {
      case '+' :
        {
          int n2 = data.top(); data.pop();
          int n1 = data.top(); data.pop();
          data.push(n1+n2);       
        }
        break;
        
      case '-' :
        {
          int n2 = data.top(); data.pop();
          int n1 = data.top(); data.pop();
          data.push(n1-n2);       
        }
        break;
        
      case '*' :
        {
          int n2 = data.top(); data.pop();
          int n1 = data.top(); data.pop();
          data.push(n1*n2);       
        }
        break;
        
      case '/' :
        {
          int n2 = data.top(); data.pop();
          int n1 = data.top(); data.pop();
          data.push(n1/n2);       
        }
        break;
        
      default:
        data.push(std::stoi(t));
        break;
    }
  }
public:
  int evalRPN(vector<string>& tokens) 
  {
    stack<int> data;
    
    for(auto t : tokens)
    {
      if(t.size() == 1)
      {
        update(t, data);
      }
      else
      {
        data.push(std::stoi(t));
      }
    }
    
    return data.top();
  }
};

int main()
{
  Solution s;
  vector<string> str = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  s.evalRPN(str);

  return 0;
}