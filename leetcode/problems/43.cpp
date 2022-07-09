#include<bits/stdc++.h>
using namespace std;

class Solution 
{
  string getProduct(string num, int digit)
  {
    int carry = 0;
    string ans = "";
    int l = num.size();
    for(int i = l-1; i >= 0; --i)
    {
      int prodAndCarry = (digit * (num[i]-'0')) + carry;
      
      carry = prodAndCarry/10;
      ans = std::to_string(prodAndCarry % 10) + ans;
    }
    
    if(carry > 0)
    {
      ans = std::to_string(carry) + ans;
    }
    
    return ans;
  }
  
public:
  string multiply(string num1, string num2) 
  {
    if(num1 == "0" || num2 == "0")
    {
      return "0";
    }
    
    vector<string> digitProds;
    
    string zeros = "";
    int count = num2.size();
    int maxLength = INT_MIN;
    for(int i = count-1; i >= 0; --i)
    {
      char digit = num2[i];
      
      string prod = getProduct(num1, digit-'0');
      
      digitProds.push_back(prod + zeros);
      
      zeros += "0";
      
      maxLength = max(maxLength, static_cast<int>(digitProds.back().size()));
    }
    
    string ans = "";
    int carry = 0;
    for(int i = 0; i < maxLength; ++i)
    {
      int sum = carry;
      for(string& prod : digitProds)
      {
        if(prod.empty())
        {
          continue;
        }
        
        sum += (prod.back() - '0');
        prod.pop_back();
      }
      
      carry = sum/10;
      ans = std::to_string(sum % 10) + ans;
    }
    
    if(carry > 0)
    {
      ans = std::to_string(carry) + ans;
    }
    
    return ans;
  }
};