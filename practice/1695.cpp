#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int maximumUniqueSubarray(vector<int>& nums) 
  {
    int ans = 0;
    int sum = 0;
    //unordered_map<int, int> freq;
    vector<int> freq(1e4+1, 0);
    
    int pos = 0;
    for(int n : nums)
    {
      sum += n;
      freq[n]++;
      while(freq[n] > 1 && freq[n] != 1)
      {
        sum -= nums[pos];
        freq[nums[pos++]]--;
        //pos++;
      }
      
      ans = max(ans, sum);
    }
    
    return ans;
  }
};