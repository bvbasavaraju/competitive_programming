#include<bits/stdc++.h>
using namespace std;

class Solution 
{  
private:
  void AddRemaining(const string& num, int p, int& carry, string& ans)
  {
    while(p >= 0)
    {
      int sum = (num[p] - '0') + carry;
      
      carry = sum / 10;
      sum %= 10;
      
      ans = std::to_string(sum) + ans;
      
      p--;
    }
  }
  
public:
  string addStrings(string num1, string num2) 
  {
    int l1 = num1.size()-1;
    int l2 = num2.size()-1;
    
    int carry = 0;
    string ans = "";
    while(l1 >= 0 && l2 >= 0)
    {
      int sum = (num1[l1] - '0') + (num2[l2] - '0') + carry;
      
      carry = sum / 10;
      sum %= 10;
      
      ans = std::to_string(sum) + ans;
      
      l1--;
      l2--;
    }
    
    if(l1 >= 0)
    {
      AddRemaining(num1, l1, carry, ans);
    }
    
    if(l2 >= 0)
    {
      AddRemaining(num2, l2, carry, ans);
    }
    
    if(carry > 0)
    {
      ans = std::to_string(carry) + ans;
    }
    
    return ans;
  }
};