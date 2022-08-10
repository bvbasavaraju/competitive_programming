#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<string> findRelativeRanks(vector<int>& score) 
  {
    int l = score.size();
    map<int, int, greater<int> > scoreWithPos;
    for(int i = 0; i < l; ++i)
    {
      scoreWithPos[score[i]] = i;
    }
    
    int rank = 1;
    vector<string> ans(l);
    for(auto it = scoreWithPos.begin(); it != scoreWithPos.end(); ++it)
    {
      ans[it->second] = std::to_string(rank);
      
      switch(rank)
      {
        case 1:
          ans[it->second] = "Gold Medal";
          break;
          
        case 2:
          ans[it->second] = "Silver Medal";
          break;
          
        case 3:
          ans[it->second] = "Bronze Medal";
          break;
      }
      
      rank++;
    }
    
    return ans;
  }
};