#include<bits/stdc++.h>

using namespace std;

class Solution 
{
public:
  vector<int> recoverArray(int n, vector<int>& sums) 
  {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    for(int& s : sums)
    {
      mini = min(mini, s);
      maxi = max(maxi, s);
    }

    int l = sums.size();
    int cols = mini < 0 ? maxi - mini : maxi;
    
    vector< vector<int> > dp(l+1, vector<int>(cols, 0));
    //uint32_t dp[l+1][cols+1] = {0};
    vector<int> essential_nums;
    for(int i = 0; i <= l; ++i)
    {
      int count = 0;
      for(int j = 0; j <= cols; ++j)
      {
        int sum = j + mini;
        if((sums[i-1] == sum) || (sum == 0))
        {
          dp[i][j] = 1;
        }
        else
        {
          if(sums[i-1] <= sum)
          {
            dp[i][j] = ((sum - abs(sums[i-1]) >= 0) && (i > 0)) ? dp[i-1][sum - abs(sums[i-1])] : 0;
          }
          else
          {
            dp[i][j] = (i == 0) ? 0 : dp[i-1][j];
          }
        }

        count += dp[i][j];
      }
      
      if(count == 2)
      {
        essential_nums.push_back(sums[i-1]);
      }
    }
    
    sort(essential_nums.begin(), essential_nums.end());
    if(essential_nums.size() == n)
    {
      return essential_nums;
    }
    
    if(essential_nums.size() < n)
    {
      for(int i = 0; i < n-essential_nums.size(); ++i)
      {
        essential_nums.push_back(0);
      }
      
      return essential_nums;
    }
    
    vector<int> ans;
    if(mini == maxi)
    {
      ans.push_back(mini);
    }
    for(int i = 0; i < essential_nums.size(); ++i)
    {
      if(essential_nums[i] == 0)
      {
        continue;
      }
      if(mini == maxi)
      {
        continue;
      }
      ans.push_back(essential_nums[i]);
    }
    
    return ans;
  }
};