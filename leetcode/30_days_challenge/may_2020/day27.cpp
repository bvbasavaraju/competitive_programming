/****************************************************
Date: May 27th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3343/
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
  Q: Counting Bits
  Given a non negative integer number num.
  For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representationand return them as an array.

  Example 1:
    Input: 2
    Output: [0,1,1]

  Example 2:
    Input: 5
    Output: [0,1,1,2,1,2]
  
  Follow up:
    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

  Hide Hint #1  
    You should make use of what you have produced already.
  Hide Hint #2  
    Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
  Hide Hint #3  
    Or does the odd/even status of the number help you in calculating the number of 1s?
*/

class Solution 
{
public:
  vector<int> countBits(int num) 
  {
    int l_current = 0;
    vector<int> ans(num + 1, 0);
    
    int power_of_2 = 1; //2^0 == 1
    
    for(int i = 1; i <= num;)
    {
      int j = 0;
      
      //Till j reaches power of 2, add 1 to value at jth index,
      while((j < power_of_2) && (i <= num))
      {
        ans[i++] = ans[j++] + 1;
      }
      
      //Next power of 2
      power_of_2 = power_of_2 << 1;
    }
    
    return ans;
  }
};