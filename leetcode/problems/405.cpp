#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  string toHex(int num) 
  {
    vector<string> hexi(16);
    for(int i = 0; i < 10; ++i)
    {
      hexi[i] = std::to_string(i);
    }
    
    char ch = 'a';
    for(int i = 10; i < 16; ++i)
    {
      hexi[i] = string(1, ch);
      ch++;
    }
    
    string ans = "";
    uint32_t newNum = num < 0 ? (UINT_MAX + (num + 1)) : static_cast<uint32_t>(num);
    while(newNum >= 16)
    {
      int r = newNum % 16;
      ans = hexi[r] + ans;
      
      newNum /= 16;
    }
    
    ans = hexi[static_cast<int>(newNum)] + ans;
    return ans;
  }
};