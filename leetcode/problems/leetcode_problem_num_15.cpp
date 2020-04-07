/*
    Q: 12. Integer to Roman
    //Time Limit Exceeded - need to optimize the code!
    //TODO - optimize!!
*/

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <math.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution 
{
private:
  bool isTargetPresent(vector<int>& nums, int s, int e, int target)
  {
    while(s <= e)
    {
      int m = s + (e-s)/2;
      
      if(nums[m] == target)
      {
        return true;
      }
      else if(nums[m] > target)
      {
        e = m - 1;
      }
      else
      {
        s = m + 1;
      }
    }
    
    return false;
  }
  
public:
  vector<vector<int>> threeSum(vector<int>& n) 
  {
    sort(n.begin(), n.end());
    
    int count = 1;
    vector<int> nums;
    for(int a : n)
    {
      if(nums.size() > 0)
      {
        if(nums.back() == a)
        {
          count++;  
        }
        else
        {
          count = 1;
        }
        
        if(count <= 3)
        {
          nums.push_back(a);
        }
      }
      else
      {
        nums.push_back(a);
      }
    }
    
    vector<vector<int>> result;
    int l = nums.size();
    for(int i = 0; i < l - 2; ++i)
    {
      for(int j = i + 1; j < l - 1; ++j)
      {
        int t = 0 - (nums[i] + nums[j]);  
        if(isTargetPresent(nums, j + 1, l - 1, t))
        {
          vector<int> v = {nums[i], nums[j], t};
          if((result.size() == 0) || (result.size() > 0 && v != result.back()))
          {
            result.push_back(v);
          }          
        }
      }
    }
    
    //now remove duplicates if any!
    l = result.size();
    if(l > 0)
    {
      sort(result.begin(), result.end());

      l = result.size();
      vector<vector<int>> ans;
      ans.push_back(result[0]);
      int j = 1;
      for(int i = 1; i < l; i++)
      {
        if(result[i] != ans.back())
        {
          ans.push_back(result[i]);
        }
      }

      return ans;
    }
    
    return result;
  }
};

int main()
{
    Solution s;
    // vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<int> v = {0,0,0,0};

    s.threeSum(v);
}