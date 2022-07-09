#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) 
  {
    int l = intervals.size();
    
    sort(intervals.begin(), intervals.end());
    
    vector< vector<int> > ans;
    ans.push_back(intervals[0]);
    for(int i = 1; i < l; ++i)
    {
      vector<int> a = ans.back();
      vector<int> b = intervals[i];
      ans.pop_back();
      
      if(a[0] > b[1]) // a comes after b
      {
        ans.push_back(b);
        ans.push_back(a);
      }
      else if(a[1] < b[0])  // a comes before b
      {
        ans.push_back(a);
        ans.push_back(b);
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