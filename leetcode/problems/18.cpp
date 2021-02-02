#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

/*
  Q: 18. 4Sum
*/

class Solution 
{
private:
  int getTargetPos(const vector<int>& nums, int l, int h, long long target)
  {
    while(l <= h)
    {
      int m = l + (h-l)/2;
      if(nums[m] == target)
      {
        return m;
      }
      
      if(nums[m] > target)
      {
        h = m-1;
      }
      else
      {
        l = m+1;
      }
    }
    
    return -1;
  }
  
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) 
  {
    sort(nums.begin(), nums.end());
    
    vector<vector<int> > ans;
    unordered_set<string> unique;
    int l = nums.size();
    for(int i = 0; i < l-3; ++i)
    {
      for(int j = i+1; j < l-2; ++j)
      {
        for(int k = j+1; k < l-1; ++k)
        {
          int pos = getTargetPos(nums, k+1, l-1, target-nums[i]-nums[j]-nums[k]);
          if(pos > k)
          {
            string str = "" + std::to_string(nums[i]) + std::to_string(nums[j]) + std::to_string(nums[k]) + std::to_string(nums[pos]);
            if(unique.find(str) == unique.end())
            {
              unique.insert(str);
              ans.push_back({nums[i], nums[j], nums[k], nums[pos]});
            }
          }
        }
      }
    }
    
    return ans;
  }
};
