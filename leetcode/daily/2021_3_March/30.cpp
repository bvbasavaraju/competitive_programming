/****************************************************
Date: March 30th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/592/week-5-march-29th-march-31st/3689/
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
  Q: Russian Doll Envelopes

  You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
  One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
  Return the maximum number of envelopes can you Russian doll (i.e., put one inside the other).

  Note: You cannot rotate an envelope.

  Example 1:
    Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
    Output: 3
    Explanation:
      The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

  Example 2:
    Input: envelopes = [[1,1],[1,1],[1,1]]
    Output: 1

  Constraints:
    1 <= envelopes.length <= 5000
    envelopes[i].length == 2
    1 <= wi, hi <= 104
*/

class Solution 
{
public:
  int maxEnvelopes(vector<vector<int>>& e) 
  {
    sort(e.begin(), e.end());
    
    int l = e.size();
    
    vector<int> rolls(l, 0);
    rolls[0] = 1;
    
    int ans = 1;
    for(int i = 1; i < l; ++i)
    {
      rolls[i] = 1;
      for(int j = i-1; j >= 0; --j)
      {
        if(e[i][0] > e[j][0] && e[i][1] > e[j][1])
        {
          rolls[i] = max(rolls[i], rolls[j]+1);
        }
      }
      
      ans = max(ans, rolls[i]);
    }
    
    return ans;
  }
};