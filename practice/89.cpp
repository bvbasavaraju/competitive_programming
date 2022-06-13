#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  vector<int> generateDigits(int n)
  {
    if(n == 1)
    {
      return {0, 1};
    }
    
    vector<int> prevDigits = generateDigits(n-1);
    
    //first half ==> 0 and previous values for each entry
    vector<int> ans;
    for(int digits : prevDigits)
    {
      ans.push_back(digits);
    }
    
    //second half added with 2^(n-1); i.e. for MSB ==> 1 and previous values in reverse order for each entry
    int msb = 1 << (n-1);
    reverse(prevDigits.begin(), prevDigits.end());
    for(int digits : prevDigits)
    {
      ans.push_back(msb + digits);
    }
    
    return ans;
  }
public:
  vector<int> grayCode(int n) 
  {
    return generateDigits(n);
  }
};