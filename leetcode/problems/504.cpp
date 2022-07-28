#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  long long returnBase7(int num)
  {
    if(num == 0)
    {
      return 0;
    }
    
    long long n = returnBase7(num/7);
    
    n = (n * 10) + num%7;
    
    return n;
  }
public:
  string convertToBase7(int num) 
  {
    bool isNegative = (num < 0);
    num = isNegative ? num * -1 : num;
    
    long long ans = returnBase7(num);
    
    return isNegative ? "-"+std::to_string(ans) : std::to_string(ans);
//     if(num == 0)
//     {
//       return "0";
//     }
    
//     bool isNegative = (num < 0);
//     num = isNegative ? num * -1 : num;
    
//     string ans = "";
//     while(num > 0)
//     {
//       ans += std::to_string(num%7);
//       num /= 7;
//     }
    
//     reverse(ans.begin(), ans.end());
    
//     return isNegative ? "-"+ans : ans;
  }
};