/*
  Q: 81. Search in Rotated Sorted Array II
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution 
{
public:
  bool search(vector<int>& nums, int target) 
  {
    int l = 0;
    int h = nums.size()-1;
    
    while(l <= h)
    {
      while(l < h && nums[l] == nums[l+1])
      {
        l++;
      }
      while(l < h && nums[h] == nums[h-1])
      {
        h--;
      }
      
      int m = l + (h-l)/2;
      
      if(nums[m] == target)
      {
        return true;
      }
      
      if(nums[l] < nums[m])
      {
        if(nums[l] <= target && nums[m] > target)
        {
          h = m-1;
        }
        else
        {
          l = m + 1;
        }
      }
      else
      {
        if(nums[m] < target && nums[h] > target)
        {
          l = m+1;
        }
        else
        {
          h = m-1;
        }
      }
    }
    
    return false;
  }
};

int main()
{
  vector<int> n = {1, 2, 3};

  Solution s;
  s.search(n, 1);

  return 0;
}