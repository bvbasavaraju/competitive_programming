#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int maximumProduct(vector<int>& nums) 
    {
      int mini1 = INT_MAX;
      int mini2 = INT_MAX;
      
      int maxi1 = INT_MIN;
      int maxi2 = INT_MIN;
      int maxi3 = INT_MIN;
      
      for(int n : nums)
      {
        if(n <= mini1)
        {
          mini2 = mini1;
          mini1 = n;
        }
        else if(n <= mini2)
        {
          mini2 = n;
        }
        
        if(n >= maxi1)
        {
          maxi3 = maxi2;
          maxi2 = maxi1;
          maxi1 = n;
        }
        else if(n >= maxi2)
        {
          maxi3 = maxi2;
          maxi2 = n;
        }
        else if(n >= maxi3)
        {
          maxi3 = n;
        }
      }
      
      return max(mini1 * mini2 * maxi1, maxi1 * maxi2 * maxi3);

      //Below code is slower . it solved in n*logn time above code is linear! n
//       sort(nums.begin(), nums.end());
      
//       int l = nums.size();
      
//       int ans = nums[l-1] * nums[l-2] * nums[l-3];
      
//       if(nums[0] < 0 && nums[1] < 0)
//       {
//         ans = max(ans, nums[0] * nums[1] * nums[l-1]);
//       }
      
//       return ans;
    }
};