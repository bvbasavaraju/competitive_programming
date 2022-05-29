#include <bits/stdc++.h>

using namespace std;
class Solution 
{
private:
  void getCombinations(vector<int>& nums, int p, int k, vector<int>& comb, vector<vector<int>>& ans)
  {
    if(p >= nums.size())
    {
      return;
    }
    
    if(comb.size() == k)
    {
      ans.push_back(comb);
      return;
    }
    
    for(int i = p; i < nums.size(); ++i)
    {
      comb.push_back(nums[i]);
      getCombinations(nums, i+1, k, comb, ans);
      comb.pop_back();  
    }
  }
public:
  vector<vector<int>> combine(int n, int k) 
  {
    vector<int> nums;
    for(int i = 1; i <= n; ++i)
    {
      nums.push_back(i);
    }
    
    vector<vector<int>> ans;
    //for(int i = 0; i < n; ++i)
    {
      vector<int> comb;
      getCombinations(nums, 0, k, comb, ans);
    }
        
    return ans;
  }
};

int main()
{
  Solution s;
  s.combine(4, 2);

  return 0;
}