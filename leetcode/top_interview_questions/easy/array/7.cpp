#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
  Q: Plus One

  Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
  The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
  You may assume the integer does not contain any leading zero, except the number 0 itself.

  Example 1:
    Input: digits = [1,2,3]
    Output: [1,2,4]
    Explanation: 
      The array represents the integer 123.

  Example 2:
    Input: digits = [4,3,2,1]
    Output: [4,3,2,2]
    Explanation: 
      The array represents the integer 4321.

  Example 3:
    Input: digits = [0]
    Output: [1]

  Constraints:
    1 <= digits.length <= 100
    0 <= digits[i] <= 9
*/

class Solution 
{
public:
  vector<int> plusOne(vector<int>& digits) 
  {
    int carry = 1;
    int l = digits.size();
    for(int i = l-1; (i >= 0) && (carry > 0); --i)
    {
      digits[i] += carry;
      
      carry = digits[i]/10;
      digits[i] = digits[i] % 10;
    }
    
    if(carry)
    {
      vector<int> ans(l+1, 0);
      ans[0] = 1;
      return ans;
    }
    
    return digits;
  }
};