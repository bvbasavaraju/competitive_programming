/*
    Q: 4. Median of Two Sorted Arrays
*/

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <string>
#include <map>

using namespace std;

class Solution 
{
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
  {
    int l = nums1.size() + nums2.size();
    
    if(l == 1)
    {
      return nums1.size() == 0 ? nums2[0] * 1.0 : nums1[0] * 1.0;
    }
    
    vector<int> nums = nums1;
    for(int n : nums2)
    {
      nums.push_back(n);
    }
    
    sort(nums.begin(), nums.end());
    
    double ans = 0.0; 
    if(l%2 == 0)
    {
      ans = ((nums[l/2 - 1] + nums[l/2])/2.0) * 1.0;
    }
    else
    {
      ans = nums[l/2] * 1.0;
    }
    
    return ans;
  }
};