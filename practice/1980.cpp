#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:  
  string getBinaryString(int num, int expectedLength)
  {
    string ans = "";
    while(num > 0)
    {
      ans = std::to_string(num%2) + ans;
      num /= 2;
    }
    
    while(ans.size() != expectedLength)
    {
      ans = "0" + ans;
    }

    return ans;
  }

public:
  string findDifferentBinaryString(vector<string>& nums) 
  {
    unordered_set<string> numsSet;
    for(const string& n : nums)
    {
      numsSet.insert(n);
    }
    
    int expectedLength = nums[0].size();
    int maxi = 1 << expectedLength;
    
    string ans = "";
    for(int i = 0; i < maxi; ++i)
    {
      ans = getBinaryString(i, expectedLength);
      if(numsSet.find(ans) == numsSet.end())
      {
        break;
      }
    }
    
    return ans;
  }
};