#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int minimumNumbers(int num, int k) 
  {
    vector<int> nums;
    while(k <= num)
    {
      nums.push_back(k);
      k += 10;
    }
    
    vector< vector<int> > dp(nums.size()+1, vector<int>(num+1, 0));
    
    for(int i = 0; i <= nums.size(); ++i)
    {
      for(int j = 0; j <= num; ++j)
      {
        if(i == 0 && j == 0)
        {
          continue;
        }
        
        if(i == 0 || j == 0)
        {
          dp[i][j] = 10000;
          continue;
        }
        
        if(nums[i-1] <= j)
        {
          dp[i][j] = min(1+dp[i-1][j-nums[i-1]], dp[i-1][j]);
        }
        else
        {
          dp[i][j] = dp[i-1][j];
        }
      }
    }
    
    return dp[nums.size()][num] == 10000 ? -1 : dp[nums.size()][num];
  }
};

int main()
{
  Solution s;
  s.minimumNumbers(0, 0);

  return 0;
}