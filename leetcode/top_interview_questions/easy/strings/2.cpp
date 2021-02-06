#include <iostream>

using namespace std;

/*
  Q: Reverse Integer

  Given a signed 32-bit integer x, return x with its digits reversed. 
  If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

  Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

  Example 1:
    Input: x = 123
    Output: 321

  Example 2:
    Input: x = -123
    Output: -321

  Example 3:
    Input: x = 120
    Output: 21

  Example 4:
    Input: x = 0
    Output: 0

  Constraints:
    -231 <= x <= 231 - 1
*/

class Solution 
{
public:
  int reverse(int x) 
  {   
    bool is_negative = (x < 0) ? true : false;
    string max_s_to_compare = is_negative ? std::to_string(INT_MIN) : std::to_string(INT_MAX);
    
    long long x_ = x;
    x_ = is_negative ? (x_ * -1) : x;
    string s = is_negative ? "-" : "";
    
    while(x_ > 0)
    {
      s += std::to_string(x_ % 10);
      x_ /= 10;
    }
    
    if((s.size() == max_s_to_compare.size()) && (s > max_s_to_compare))
    {
      return 0;
    }
    
    int ans = 0;
    for(int i = is_negative ? 1 : 0; i < s.size(); ++i)
    {
      ans = (ans * 10) + (s[i] - '0');
    }
    
    return is_negative ? (ans * -1) : ans;
  }
};