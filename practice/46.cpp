#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:  
  void getAllCombinations(vector<int> nums, int p, vector<vector<int>>& ans)
  {
    if(p == nums.size())
    {
      ans.push_back(nums);
      return;
    }
    
    for(int i = p; i < nums.size(); ++i)
    {
      swap(nums[i], nums[p]);
      getAllCombinations(nums, p+1, ans);
      swap(nums[i], nums[p]);
    }
  }
  
public:
  vector<vector<int>> permute(vector<int>& nums) 
  {
    vector< vector<int> > ans;
    getAllCombinations(nums, 0, ans);
    
    return ans;
  }
};