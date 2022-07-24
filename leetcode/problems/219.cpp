#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) 
  {
    unordered_map<int, int> freq;
    
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      if(i > k)
      {
        freq[nums[i-k-1]]--;
      }
      
      freq[nums[i]]++;
      if(freq[nums[i]] > 1)
      {
        return true;
      }
    }
    
    return false;
  }
};