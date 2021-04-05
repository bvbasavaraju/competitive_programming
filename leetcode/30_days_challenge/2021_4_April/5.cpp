/****************************************************
Date: April 5th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/
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
  Q: Global and Local Inversions

  We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.
  The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].
  The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].
  Return true if and only if the number of global inversions is equal to the number of local inversions.

  Example 1:
    Input: A = [1,0,2]
    Output: true
    Explanation:
      There is 1 global inversion, and 1 local inversion.

  Example 2:
    Input: A = [1,2,0]
    Output: false
    Explanation:
      There are 2 global inversions, and 1 local inversion.

  Note:
    A will be a permutation of [0, 1, ..., A.length - 1].
    A will have length in range [1, 5000].
    The time limit for this problem has been reduced.

  Hide Hint #1  
    Where can the 0 be placed in an ideal permutation? What about the 1?
*/
class Solution 
{
public:
  bool isIdealPermutation(vector<int>& A) 
  {
    int l = A.size();
    
    for(int i = 0; i < l; ++i)
    {
      if(abs(A[i]-i) > 1)
      {
        return false;
      }
    }
    
    return true;
    
    //TLE
//     int cl = 0;
//     for(int i = 0; i < l-1; ++i)
//     {
//       if(A[i] > A[i+1])
//       {
//         cl++;
//       }
//     }
    
//     int cg = 0;
//     for(int i = 0; i < l-1; ++i)
//     {
//       for(int j = i+1; j < l; ++j)
//       {
//         if(A[i] > A[j])
//         {
//           cg++;
//         }
//       }
//     }
    
//     return cg == cl;
  }
};