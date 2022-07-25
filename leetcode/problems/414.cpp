#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int thirdMax(vector<int>& nums) 
  {
    set<int> nums_;
    for(int n : nums)
    {
      nums_.emplace(n);
    }
    
    auto it = nums_.end();
    it--;
    
    if(nums_.size() >= 3)
    {
      it--;
      it--;
    }

    return *it;
  }
};