/*
  Q: 997. Find the Town Judge
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;

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