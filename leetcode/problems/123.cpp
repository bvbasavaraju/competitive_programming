#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int maxProfit(vector<int>& prices) 
  {
    int len = prices.size();
    vector<int> leftProfits(len, 0);
    vector<int> rightProfits(len, 0);
    
    int leftMin = prices[0];
    int rightMax = prices[len-1];
    for(int l = 1, r = len-2; l < len && r >= 0; ++l, --r)
    {
      leftMin = min(leftMin, prices[l]);
      leftProfits[l] = max(leftProfits[l-1], prices[l]-leftMin);
      
      rightMax = max(rightMax, prices[r]);
      rightProfits[r] = max(rightProfits[r+1], rightMax-prices[r]);
    }
    
    int ans = 0;
    for(int i = 0; i < len; ++i)
    {
      ans = max(ans, leftProfits[i] + rightProfits[i]);
    }
    
    return ans;
  }
};