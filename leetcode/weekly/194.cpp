/****************************************************
Date: June 21th, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-194
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
  Q: 1486. XOR Operation in an Array
*/
class Solution1_t
{
public:
  int xorOperation(int n, int start) 
  {
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
      ans = ans ^ (start + 2 * i);
    }
    
    return ans;
  }
};

/*
  Q: 1487. Making File Names Unique
*/
class Solution2_t
{
public:
  vector<string> getFolderNames(vector<string>& names) 
  {
    vector<string> ans;
    unordered_map<string, int> names_count;
    
    int l = names.size();
    for(int i = 0; i < l; ++i)
    {
      int k = 0;
      string s = "";
      bool has_count = false;
      if(names[i].find_first_of('(') != string::npos)
      {
        has_count = true;
        s = names[i].substr(0, names[i].find_first_of('('));
      }
      
      
      string n = names[i];
      auto [it, inserted] = names_count.emplace(n, 1);
      if(!inserted)
      {
        string temp = n + "(" + to_string(names_count[n]) + ")";
        ans.push_back(temp);
        names_count[n]++;
        names_count[temp] = 1;
      }
      else
      {
        ans.push_back(n);
        if(has_count)
        {
          k = names[i].substr(names[i].find_last_of('(')+1, 1)[0] - '0';
          if(names_count.find(s) != names_count.end() && names_count[s] == k)
          {
            names_count[s]++;
          }
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1488. Avoid Flood in The City
*/
class Solution3_t
{
public:
  vector<int> avoidFlood(vector<int>& rains) 
  {
    
  }
};

/*
  Q: 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
*/
class Solution4_t
{
public:
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
  {
  }
};