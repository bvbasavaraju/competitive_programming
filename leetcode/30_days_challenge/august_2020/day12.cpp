/****************************************************
Date: July 12th

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3417/
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
#include <set>

using namespace std;

/*
  Q: Pascal's Triangle II

  Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
  Note that the row index starts from 0.

  In Pascal's triangle, each number is the sum of the two numbers directly above it.
  Example:
    Input: 3
    Output: [1,3,3,1]
    Follow up:

  Could you optimize your algorithm to use only O(k) extra space?

                      1
                      1,1
                      1,2,1
                      1,3,3,1
                      1,4,6,4,1
                      1,5,10,10,5,1
                      1,6,15,20,15,6,1
                      1,7,21,35,35,21,7,1
*/

class Solution
{
public:
  vector<int> getRow(int r)
  {
    vector<int> prev;
    vector<int> ans(r + 1, 1);
    for (int i = 1; i <= r; ++i)
    {
      for (int j = 1; j < i; ++j)
      {
        ans[j] = prev[j - 1] + prev[j];
      }

      prev = ans;
    }

    return ans;
  }
};
