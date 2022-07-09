#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
  {
    int l = intervals.size();
    vector<vector<int>> ans;
    
    ans.push_back(newInterval);
    for(int i = 0; i < l; ++i)
    {
      vector<int> a = intervals[i];
      vector<int> b = ans.back();
      
      ans.pop_back();
      
      if(a[1] < b[0])
      {
        ans.push_back(a);
        ans.push_back(b);
      }
      else if(b[1] < a[0])
      {
        ans.push_back(b);
        ans.push_back(a);
      }
      else
      {
        int mini = min(a[0], b[0]);
        int maxi = max(a[1], b[1]);
        ans.push_back({mini, maxi});
      }
    }
    
    return ans;
  }
};