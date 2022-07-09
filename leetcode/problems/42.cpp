#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int trap(vector<int>& height) 
  {
    int l = height.size();
    vector<int> maxToRight(l, 0);
    vector<int> maxToLeft(l, 0);
    
    int currentMaxToRight = height[l-1];
    for(int i = l-1; i >= 0; --i)
    {
      currentMaxToRight = max(currentMaxToRight, height[i]);
      maxToRight[i] = currentMaxToRight;
    }
    
    int currentMaxToLeft = height[0];
    for(int i = 0; i < l; ++i)
    {
      currentMaxToLeft = max(currentMaxToLeft, height[i]);
      maxToLeft[i] = currentMaxToLeft;
    }
    
    int ans = 0;
    for(int i = 0; i < l; ++i)
    {
      ans += (min(maxToRight[i], maxToLeft[i]) - height[i]);
    }
    
    return ans;
  }
};