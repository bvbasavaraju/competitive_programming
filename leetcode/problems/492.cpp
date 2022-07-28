#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<int> constructRectangle(int area) 
  {
    vector<int> ans{area, 1};
    
    for(int x = 2; (x*x) <= area; ++x)
    {
      if((area % x) == 0)
      {
        int y = area/x;
        
        if(abs(y-x) < abs(ans[0] - ans[1]))
        {
          int mini = min(x, y);
          int maxi = max(x, y);
          
          ans = {maxi, mini};
        }
      }
    }
    
    return ans;
  }
};