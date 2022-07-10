#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  int getMaxSubArraySum(vector<int>& nums, int start, int end, int ans)
  {
    int sum = 0;
    for(int i = start; i <= end; ++i)
    {
      sum = max(sum, sum + nums[i]);
      ans = max(ans, sum);
    }
    
    return ans;
  }
public:
  int maxResult(vector<int>& nums, int k) 
  {
    int l = nums.size();
    
    vector<int> sum(l, 0);
    int maxSumCalcIndex = 0;
    
    sum[0] = nums[0];
    for(int i = 0; i < l; ++i)
    {
      int maxIndex = min(max(i+1, min(l-1, i+k)), l-1);
      if(maxIndex < maxSumCalcIndex)
      {
        continue;
      }
      
      int subArraySum = getMaxSubArraySum(nums, i+1, maxIndex, sum[i]);
      
      for(int p = maxSumCalcIndex+1; p <= maxIndex; ++p)
      {
        sum[p] = subArraySum;
      }
      
      maxSumCalcIndex = maxIndex;
    }
    
    return sum[l-1];
  }
};

int main()
{
  vector<int> n = {1,-1,-2,4,-7,3};
  Solution s;
  s.maxResult(n, 2);

  return 0;
}