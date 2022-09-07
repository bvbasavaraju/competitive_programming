#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
  {
    unordered_map<string, vector<int>> stringPos;
    
    int l = list1.size();
    for(int i = 0; i < l; ++i)
    {
      stringPos[list1[i]].push_back(i);
    }
    
    l = list2.size();
    for(int i = 0; i < l; ++i)
    {
      stringPos[list2[i]].push_back(i);
    }
    
    map<int, vector<string>> commonStrings;
    for(auto it = stringPos.begin(); it != stringPos.end(); ++it)
    {
      if(it->second.size() == 2)
      {
        commonStrings[it->second[0] + it->second[1]].push_back(it->first);
      }
    }
    
    return commonStrings.begin()->second;
  }
};