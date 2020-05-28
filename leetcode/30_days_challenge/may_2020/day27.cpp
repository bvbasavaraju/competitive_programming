/****************************************************
Date: May 27th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3342/
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
  Q: Possible Bipartition

  Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
  Each person may dislike some other people, and they should not go into the same group. 
  Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
  Return true if and only if it is possible to split everyone into two groups in this way.

  Example 1:
    Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
    Output: true
    Explanation: group1 [1,4], group2 [2,3]

  Example 2:
    Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
    Output: false

  Example 3:
    Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
    Output: false

  Note:
    1 <= N <= 2000
    0 <= dislikes.length <= 10000
    1 <= dislikes[i][j] <= N
    dislikes[i][0] < dislikes[i][1]
    There does not exist i != j for which dislikes[i] == dislikes[j].
*/

class Solution 
{
private:
  bool assignGroup(unordered_map<int, vector<int>>& people_with_dislikes, vector<int>& groups, int person, int group)
  {
    //Assign person to given group;
    //All his dislikes should go to other group
    //Check if dislikes also in same group. if so, return false
    groups[person] = group;
    
    vector<int> dislikes = people_with_dislikes[person];
    for(auto p : dislikes)
    {
      if(groups[p] == group)
      {
        return false;
      }
     
      if(groups[p] == 0 && !assignGroup(people_with_dislikes, groups, p, -group))
      {
        return false;
      }
    }
    
    return true;
  }
  
public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
  {
    unordered_map<int, vector<int>> people_with_dislikes;
    for(auto n : dislikes)
    {
      people_with_dislikes[n[0]].push_back(n[1]);
      people_with_dislikes[n[1]].push_back(n[0]);
    }
    
    //0 - no group, 1 - group 1, -1 - group -1;
    vector<int> groups(N+1, 0);
    for(int i = 1; i <= N; ++i)
    {
      if(groups[i] == 0 && !assignGroup(people_with_dislikes, groups, i, 1))
      {
        return false;
      }
    }
    
    return true;
  }
};