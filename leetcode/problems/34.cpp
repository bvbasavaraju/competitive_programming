#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<int> searchRange(vector<int>& nums, int target) 
  {
    int len = nums.size();
    std::vector<int>::iterator lower = lower_bound(nums.begin(), nums.end(), target);
    
    if(lower != nums.end() && (*lower == target))
    {
      int l = (lower - nums.begin());
      if(nums[len-1] == target)
      {
        return {l, len-1};
      }
      
      std::vector<int>::iterator upper = upper_bound(nums.begin(), nums.end(), target);
      int u = (upper - nums.begin());
      return {l, u-1};
    }
    
    return {-1, -1};
  }
};

/* little slower solution!
class Solution 
{
private:
  int getPosition(vector<int>& nums, int target)
  {
    int l = 0;
    int h = nums.size()-1;
    
    int ans = -1;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      if(nums[m] >= target)
      {
        ans = m;
        h = m-1;
      }
      else
      {
        l = m+1;
      }
    }
    
    return ans;
  }
    
public:
  vector<int> searchRange(vector<int>& nums, int target) 
  {
    int l = getPosition(nums, target);
    int h = -1;
    if((l >= 0) && (nums[l] == target))
    {
      if(nums[nums.size()-1] == nums[l])
      {
        h = nums.size()-1;
      }
      else
      {
        h = getPosition(nums, target+1) - 1;
      }
    }
    
    if(h < 0)
    {
      return {-1, -1};
    }
    
    return {l, h};
  }
};
*/