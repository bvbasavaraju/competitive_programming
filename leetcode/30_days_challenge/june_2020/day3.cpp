/****************************************************
Date: June 3rd

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/
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
  Q: Two City Scheduling

  There are 2N people a company is planning to interview.
  The cost of flying the i-th person to city A is costs[i][0],
  and the cost of flying the i-th person to city B is costs[i][1].

  Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

  Example 1:
    Input: [[10,20],[30,200],[400,50],[30,20]]
    Output: 110
    Explanation: 
      The first person goes to city A for a cost of 10.
      The second person goes to city A for a cost of 30.
      The third person goes to city B for a cost of 50.
      The fourth person goes to city B for a cost of 20.

    The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

  Note:
    + 1 <= costs.length <= 100
    + It is guaranteed that costs.length is even.
    + 1 <= costs[i][0], costs[i][1] <= 1000
*/

class Solution 
{
public:
  int twoCitySchedCost(vector<vector<int>>& costs) 
  {
    sort(costs.begin(), costs.end(), [](const vector<int>& c1, const vector<int>& c2) -> bool 
         { return ((c1[0] - c1[1])  < (c2[0] - c2[1])); });
    
    int ans = 0;
    int l = costs.size()/2;
    for(int i = 0; i < l; ++i)
    {
      ans += (costs[i][0] + costs[i+l][1]);
    }
    
    return ans;
  }
};