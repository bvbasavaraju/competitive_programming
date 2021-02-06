#include <iostream>

using namespace std;

/*
  Q: Valid Palindrome

  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

  Note: For the purpose of this problem, we define empty string as valid palindrome.

  Example 1:
    Input: "A man, a plan, a canal: Panama"
    Output: true

  Example 2:
    Input: "race a car"
    Output: false

  Constraints:
    s consists only of printable ASCII characters.
*/

class Solution 
{
public:
  bool isPalindrome(string s) 
  {
    vector<int> alpha_nums;
    for(auto ch : s)
    {
      if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
      {
        alpha_nums.push_back(ch);
      }
      else if(ch >= 'A' && ch <= 'Z')
      {
        alpha_nums.push_back(ch - 'A' + 'a');
      }
    }
    
    int l = alpha_nums.size();
    for(int i = 0; i < l/2; ++i)
    {
      if(alpha_nums[i] != alpha_nums[l - 1 - i])
      {
        return false;
      }
    }
    
    return true;
  }
};