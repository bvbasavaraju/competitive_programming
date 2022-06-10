#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  void getNearestSmall(const vector<int>& heights, bool right, vector<int>& nearestSmall)
  {
    int l = heights.size();
    
    int start = right ? 0 : l-1;
    int end = right ? l : -1;
    
    stack<pair<int, int>> posWithHeight;  // {val, pos}
    for(int i = start; right ? i < end : i > end; right ? ++i : --i)
    {
      if(posWithHeight.empty() || (heights[i] >= posWithHeight.top().first))
      {
        posWithHeight.push({heights[i], i});
      }
      else
      {
        while(!posWithHeight.empty() && heights[i] < posWithHeight.top().first)
        {
          pair<int, int> data = posWithHeight.top();
          posWithHeight.pop();
          
          nearestSmall[data.second] = i;
        }
        
        posWithHeight.push({heights[i], i});
      }
    }
    
    while(!posWithHeight.empty())
    {
      pair<int, int> data = posWithHeight.top();
      posWithHeight.pop();

      nearestSmall[data.second] = end;
    }
  }
  
public:
  int largestRectangleArea(vector<int>& heights) 
  {
    int l = heights.size();
    vector<int> nearestSmallToRight(l);
    vector<int> nearestSmallToLeft(l);
    
    getNearestSmall(heights, true, nearestSmallToRight);
    getNearestSmall(heights, false, nearestSmallToLeft);
    
    int ans = INT_MIN;
    for(int i = 0; i < l; ++i)
    {
      int area = (nearestSmallToRight[i] - nearestSmallToLeft[i] - 1) * heights[i];
      ans = max(ans, area);
    }
    
    return ans;
  }
};