/****************************************************
Date: May 10th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/
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
  Q: Find the Town Judge
  In a town, there are N people labelled from 1 to N.
  There is a rumor that one of these people is secretly the town judge.

  If the town judge exists, then:
    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.

  You are given trust, an array of pairs trust[i] = [a, b] 
  representing that the person labelled a trusts the person labelled b.

  If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

  Example 1:
    Input: N = 2, trust = [[1,2]]
    Output: 2

  Example 2:
    Input: N = 3, trust = [[1,3],[2,3]]
    Output: 3

  Example 3:
    Input: N = 3, trust = [[1,3],[2,3],[3,1]]
    Output: -1

  Example 4:
    Input: N = 3, trust = [[1,2],[2,3]]
    Output: -1

  Example 5:
    Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
    Output: 3

  Note:
    1 <= N <= 1000
    trust.length <= 10000
    trust[i] are all different
    trust[i][0] != trust[i][1]
    1 <= trust[i][0], trust[i][1] <= N
*/

class Solution 
{
public:
  int findJudge(int N, vector<vector<int>>& trust) 
  {
    //Fastest!!
    unordered_map<int, int> non_judges;
    unordered_map<int, int> trust_list;

    for(auto& p : trust)
    {
      non_judges[p[0]]++;
      trust_list[p[1]]++;
    }
    
    for(auto& p : trust_list)
    {
      if((non_judges.count(p.first) == 0) && (p.second == (N - 1)))
      {
        return p.first;
      }
    }

    /* //Faster
    unordered_set<int> non_judges;
    unordered_map<int, int> trust_list;
    
    int l = trust.size();
    for(int i = 0; i < l; ++i)
    {
      non_judges.insert(trust[i][0]);
      trust_list[trust[i][1]]++;
    }
    
    for(auto it : trust_list)
    {
      if((non_judges.count(it.first) == 0) && (it.second == (N - 1)))
      {
        return it.first;
      }
    }*/
    
    /* //Little slower
    unordered_set<int> non_judge;
    unordered_map<int, vector<int>> trust_list;
    
    int l = trust.size();
    for(int i = 0; i < l; ++i)
    {
      non_judge.insert(trust[i][0]);
      trust_list[trust[i][1]].push_back(trust[i][0]);
    }
    
    for(int i = 0; i < l; ++i)
    {
      if(non_judge.count(trust[i][1]) == 0)
      {
        if(trust_list[trust[i][1]].size() == (N - 1))
        {
          return trust[i][1]; 
        }
      }
    }*/

    return (N == 1) ? 1 : -1;
  }
};