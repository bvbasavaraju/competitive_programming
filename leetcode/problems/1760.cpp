#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  int getCount(vector<int>& nums, int balls)
  {
    int ops = 0;    
    for(int n : nums)
    {
      if(n % balls == 0)
      {
        ops--;
      }
      
      ops += n / balls;
    }
    
    return ops;
  }
public:
  int minimumSize(vector<int>& nums, int maxOperations) 
  {
    int maxi = INT_MIN;
    for(int ball : nums)
    {
      maxi = max(maxi, ball);
    }
    
    int l = 0;
    int h = maxi;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      if(getCount(nums, m) <= maxOperations)
      {
        h = m-1;
      }
      else
      {
        l = m+1;
      }
    }
    
    return l;
  }
};