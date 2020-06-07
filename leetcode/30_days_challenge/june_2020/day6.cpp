/****************************************************
Date: June 6th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3352/
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

class Solution 
{
private:
  void updateResult(vector<int> p, vector<vector<int>>& ans)
  {
    int p_pos = p[1];
    if(ans.size() <= p_pos)
    {
      ans.push_back(p);
    }
    else
    {
      vector<int> cp = ans[p_pos];
      if(p[0] <= cp[0])
      {
        ans.insert(ans.begin() + p_pos, p);
      }
      else
      {
        ans.push_back(p);
      }
    }
  }
  
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
  {
    sort(people.begin(), people.end(), [](const vector<int>& p1, const vector<int>& p2)->bool 
                                          { 
                                            bool swap = (p1[0] > p2[0]);
                                            if(p1[0] == p2[0])
                                            {
                                              if(p1[1] < p2[1])
                                              {
                                                swap = true;
                                              }
                                            }
                                            return swap;
                                          }
                                        );  
    
    vector<vector<int>> ans;
    for(auto p : people)
    {
      updateResult(p, ans);
    }

    return ans;
  }
};