#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
 
  int getCount(vector<int>& nums, int limit)
  {
    int count = 1;
    
    int sum = 0;
    for(int n : nums)
    {
      sum += n;
      
      if(sum > limit)
      {
        count++;
        sum = n;
      }
    }
    
    return count;
  }
  
public:
  int splitArray(vector<int>& nums, int m) 
  {
    int sum = 0;
    int maxi = 0;
    for(int n : nums)
    {
      sum += n;
      maxi = max(maxi, n);
    }
    
    int l = maxi;
    int h = sum;
    int ans = 0;
    while(l <= h)
    {
      int mid = l + (h-l)/2;
      
      int count = getCount(nums, mid);      
      if(count > m)
      {
        l = mid+1;
      }
      else
      {
        ans = mid;
        h = mid-1;
      }
    }
    
    return ans;
  }
};