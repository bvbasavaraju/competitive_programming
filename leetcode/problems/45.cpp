#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int jump(vector<int>& nums) 
  {
    int l = nums.size();
    
    vector<int> jumps(l, INT_MAX);
    jumps[0] = 0;
    
    int maxReachable = 0;
    for(int i = 0; i < l; ++i)
    {
      if(maxReachable < i)
      {
        return -1;
      }
      
      maxReachable = max(maxReachable, i + nums[i]);
      
      int jumpIndex = min(i+nums[i], l-1);
      jumps[jumpIndex] = min(jumps[jumpIndex], 1 + jumps[i]);
      
      // from i+1 -> jumpIndex-1 we need to update the jumps. based on the questions;
      for(int j = i+1; j < jumpIndex; ++j)
      {
        jumps[j] = min(jumps[j], 1 + jumps[i]);
      }
    }
    
    return jumps[l-1];
  }
};