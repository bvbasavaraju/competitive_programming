#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) 
  {
    int ans = 0;
    
    int l = timeSeries.size();
    pair<int, int> secs = {timeSeries[0], timeSeries[0] + duration -1};
    
    for(int i = 1; i < l; ++i)
    {
      if(timeSeries[i] == secs.first)
      {
        continue;
      }
      
      if(timeSeries[i] <= secs.second)
      {
        ans += (timeSeries[i] - secs.first - 1);
      }
      else
      {
        ans += (secs.second - secs.first);
      }
      
      ans++;
      secs = {timeSeries[i], timeSeries[i] + duration - 1};
    }
    
    ans += (secs.second - secs.first) + 1;
    
    return ans;
  }
};