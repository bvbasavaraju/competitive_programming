#include <iostream>
#include <vector>

using namespace std;

/*
  Q: 300. Longest Increasing Subsequence
*/

class Solution 
{
public:
  int lengthOfLIS(vector<int>& nums) 
  {
    int l = nums.size();
    if(l <= 0)
    {
      return 0;
    }
    
    vector<int> sorted_nums;
    
    for(int n : nums)
    {
      auto it = lower_bound(sorted_nums.begin(), sorted_nums.end(), n);
      if(it == sorted_nums.end())
      {
        sorted_nums.push_back(n);
      }
      else
      {
        *it = n;
      }
    }
    
    return sorted_nums.size();
  }
};