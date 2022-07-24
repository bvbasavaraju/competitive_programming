#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<string> summaryRanges(vector<int>& nums) 
  {
    int l = nums.size();
    if(l <= 0)
    {
      return {};
    }
    
    int index = 0;
    vector<string> ans;
    ans.push_back(std::to_string(nums[0]));
    
    for(int i = 1; i < l; ++i)
    {
      if(nums[i]-1 != nums[i-1])
      {
        if(i-1 != index)
        {
          ans.back() += "->" + std::to_string(nums[i-1]);
        }
        
        ans.push_back(std::to_string(nums[i]));
        index = i;
      }
    }
    
    if(index != l-1)
    {
      ans.back() += "->" + std::to_string(nums[l-1]);
    }
    
    return ans;
  }
};