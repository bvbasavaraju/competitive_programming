#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int arrayPairSum(vector<int>& nums) 
  {
    sort(nums.begin(), nums.end());
    
    int ans = 0;
    int l = nums.size();
    for(int i = 0; i < l; i += 2)
    {
      ans += min(nums[i], nums[i+1]);
    }
    
    return ans;
  }
};