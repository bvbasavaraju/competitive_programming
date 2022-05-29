/****************************************************
Date: May 29th, 2022
Successful submissions : 1
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/weekly-contest-295
****************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
  Q: 2287. Rearrange Characters to Make Target String
*/
class Solution1_t
{
public:
  int rearrangeCharacters(string s, string target) 
  {
    unordered_map<int, int> freqS;
    for(char ch : s)
    {
      freqS[ch-'0']++;
    }
    
    unordered_map<int, int> freqT;
    for(char ch : target)
    {
      freqT[ch-'0']++;
    }
      
    int ans = INT_MAX;
    for(auto it = freqT.begin(); it != freqT.end(); ++it)
    {
      int ch = it->first;
      if(freqS.find(ch) == freqS.end())
      {
        return 0;
      }
      
      int count = freqS[ch] / it->second;
      ans = min(ans, count);
    }
    
    return ans;
  }
};

/*
  Q: 2288. Apply Discount to Prices. 99.99 % correct answer!!
*/
class Solution2_t
{
private:
  string getDiscountedPrice(double price, double discount) 
  {
    double discountAmount = (price) * (discount / 100.0);
    
    price -= discountAmount;
    
    string ans = std::to_string(price);
    int p = ans.find('.');
    if(p != std::string::npos)
    {
      if(ans.size() - p > 2)
      {
        ans = ans.substr(0, p+2+1);
      }
      else if(ans.size() - p < 2)
      {
        int l = ans.size();
        while(p < l)
        {
          ans += "0";
        }
      }
    }
    else
    {
      ans += ".00";
    }
    
    return ans;
  }
  
public:
  string discountPrices(string sentence, int discount) 
  {
    string ans = "";
    int l = sentence.size();
    for(int i = 0; i < l; )
    {
      ans += sentence[i];
      
      if(sentence[i] == '$' && (i == 0 || sentence[i-1] == ' ') && ((i+1) < l))
      {
        i++;
        int start = i;
        long long price = 0;
        bool foundNum = false;
        while(sentence[i]-'0' >= 0 && sentence[i]-'0' <= 9)
        {
          foundNum = true;
          price = (price * 10) + (sentence[i] - '0');
          i++;
        }
        
        if(!foundNum || (i < l && sentence[i] != ' ')) //|| price > INT_MAX)
        {
          while(start < i)
          {
            ans += sentence[start];
            start++;
          }
        }
        else
        {
          ans += getDiscountedPrice(price, discount);
        }
      }
      else
      {
        ++i;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2289. Steps to Make Array Non-decreasing - wrong answer
*/
class Solution3_t
{
public:
  int totalSteps(vector<int>& nums) 
  {
    int ans = 0;
    int l = nums.size();
    
    for(int i = 1; i < l;)
    {
      int count = 0;
      int prev = nums[i-1];
      if(prev > nums[i])
      {
        while((i < l) && prev > nums[i])
        {
          count++;
          i++;
        }
      }
      else
      {
        i++;
      }
      
      ans = count > 0 ? ans + 1 : ans;
    }
    
    return ans;
  }
};

/*
  Q: 2290. Minimum Obstacle Removal to Reach Corner
*/
class Solution4_t
{
public:
  int minimumObstacles(vector<vector<int>>& grid) 
  {
      
  }
};