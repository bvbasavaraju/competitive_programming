#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int minOperations(vector<int>& nums, int x) 
  {
    int l = nums.size();
    
    int sum = 0;
    for(int n : nums)
    {
      sum += n;
    }
    
    int subArraySumRequired = sum - x;
    
    int p = 0;
    int currentSum = 0;
    int maxi = -1;
    for(int i = 0; i < l; ++i)
    {
      currentSum += nums[i];
      
      while((p < l) && (currentSum > subArraySumRequired))
      {
        currentSum -= nums[p];
        p++;
      }
      
      if(sum - currentSum == x)
      {
        maxi = max(maxi, i - p + 1);
      }
    }
    
    return (maxi == -1) ? -1 : l - maxi;
  }
};