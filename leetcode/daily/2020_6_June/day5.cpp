/****************************************************
Date: June 5th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3351/
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
  Q: Random Pick with Weight

  Given an array w of positive integers, where w[i] describes the weight of index i,
  write a function pickIndex which randomly picks an index in proportion to its weight.

  Note:
    1 <= w.length <= 10000
    1 <= w[i] <= 10^5
    pickIndex will be called at most 10000 times.

  Example 1:
    Input: 
    ["Solution","pickIndex"]
    [[[1]],[]]
    Output: [null,0]

  Example 2:
    Input: 
    ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
    [[[1,3]],[],[],[],[],[]]
    Output: [null,0,1,1,1,0]

  Explanation of Input Syntax:
    The input is two lists: the subroutines called and their arguments. 
    Solution's constructor has one argument, the array w. pickIndex has no arguments. 
    Arguments are always wrapped with a list, even if there aren't any.
*/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

class Solution 
{
private:
  int total_weight;
  vector<int> weights;
public:
  Solution(vector<int>& w) 
  {
    total_weight = 0;
    for(auto n : w)
    {
      total_weight += n;
      weights.push_back(total_weight);
    }
  }
    
  int pickIndex() 
  {
    int l = weights.size();
    int random_weight = rand() % total_weight;
    for(int i = 0; i < l; ++i)
    {
      if(weights[i] > random_weight)
      {
        return i;
      }
    }
    
    return l;
  }
};