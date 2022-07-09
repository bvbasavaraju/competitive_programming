#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int removeDuplicates(vector<int>& nums) 
  {
    int l = nums.size();
    
    int ans = 0;
    int count = 1;
    for(int i = 0; i < l-ans; ++i)
    {
      count = 1;
      int j = i+1;
      while(j < l-ans && nums[j] == nums[j-1])
      {
        count++;
        j++;
      }
      
      if(count > 2)
      {
        int delta = count - 2;
        for(j = i+2; j+delta < l; ++j)
        {
          nums[j] = nums[j+delta];
        }

        ans += delta;
      }

      if(count >= 2)
      {
        i++;
      }
    }
    
    return l - ans;
  }
};