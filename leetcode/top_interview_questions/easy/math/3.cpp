#include <iostream>
#include <vector>

using namespace std;

/*
  Power of Three

  Given an integer n, return true if it is a power of three. Otherwise, return false.
  An integer n is a power of three, if there exists an integer x such that n == 3x.

  Example 1:
    Input: n = 27
    Output: true

  Example 2:
    Input: n = 0
    Output: false

  Example 3:
    Input: n = 9
    Output: true

  Example 4:
    Input: n = 45
    Output: false

  Constraints:
    -231 <= n <= 231 - 1

  Follow up: 
    Could you do it without using any loop / recursion?
*/

class Solution 
{
public:
  bool isPowerOfThree(int n) 
  {
    if(n <= 0)
    {
      return false;
    }
    
    //After learning from the discussion. log can be used
    
    int p = log10(n) / log10(3);    
    return pow(3, p) == n;

    // My original solution is below:    
//     int power = 1;
//     long long val = 1;
    
//     while(val != n)
//     {
//       if(val > n)
//       {
//         return false;
//       }
      
//       val *= 3;
//     }
    
//     return true;
  }
};