#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int findClosestNumber(vector<int>& nums) 
  {
    int ans = INT_MAX;
    
    for(int n : nums)
    {
      if(abs(n) < abs(ans))
      {
        ans = n;
      }
      else if(abs(n) == abs(ans))
      {
        if(n > ans)
        {
          ans = n;
        }
      }
    }
    
    return ans;
  }
};