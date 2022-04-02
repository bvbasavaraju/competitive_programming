/****************************************************
Date: March 21th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3673/
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
  Q: Reordered Power of 2

  Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

  Return true if and only if we can do this in a way such that the resulting number is a power of 2.

  Example 1:
    Input: 1
    Output: true

  Example 2:
    Input: 10
    Output: false

  Example 3:
    Input: 16
    Output: true

  Example 4:
    Input: 24
    Output: false

  Example 5:
    Input: 46
    Output: true

  Note:
    1 <= N <= 10^9
*/

class Solution 
{  
// private:
//   void getInVector(int num, vector<int>& ans)
//   {
//     while(num > 0)
//     {
//       ans.push_back(num%10);
//       num /= 10;
//     }
    
//     sort(ans.begin(), ans.end());
//   }
    
public:
  bool reorderedPowerOf2(int N) 
  {
    //Slower!!
//     vector<int> nVec;
//     getInVector(N, nVec);
    
//     for(int i = 0; i < 32; ++i)
//     {
//       vector<int> pv;
//       getInVector(1 << i, pv);
      
//       if(pv == nVec)
//       {
//         return true;
//       }
//     }
    
//     return false;

    //Faster!!
    string num = std::to_string(N);
    
    sort(num.begin(), num.end());
    
    for(int i = 0; i < 32; ++i)
    {
      int p2 = 1 << i;
      
      string p2str = std::to_string(p2);
      sort(p2str.begin(), p2str.end());
      
      if(p2str == num)
      {
        return true;
      }
    }
    
    return false;
  }
};