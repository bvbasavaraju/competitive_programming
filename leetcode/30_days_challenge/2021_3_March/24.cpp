/****************************************************
Date: March 23th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3681/
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
  Q: Advantage Shuffle

  Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].
  Return any permutation of A that maximizes its advantage with respect to B.

  Example 1:
    Input: A = [2,7,11,15], B = [1,10,4,11]
    Output: [2,11,7,15]

  Example 2:
    Input: A = [12,24,8,32], B = [13,25,32,11]
    Output: [24,32,8,12]

  Note:
    1 <= A.length = B.length <= 10000
    0 <= A[i] <= 10^9
    0 <= B[i] <= 10^9
*/
class Solution 
{
public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) 
  {
    multiset set_(A.begin(), A.end());
    
    for(uint32_t i = 0; i < B.size(); ++i)
    {
      auto it = set_.upper_bound(B[i]);
      if(it == set_.end())
      {
        it = set_.begin();
      }
      
      A[i] = *it;
      set_.erase(it);
    }
    
    return A;
  }
};