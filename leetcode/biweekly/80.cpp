/****************************************************
Date: June 11th, 2022
Successful submissions : 2
Time expiration : 0
Memory limit exceeded : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-80
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2299. Strong Password Checker II
*/
class Solution1_t
{
public:
  bool strongPasswordCheckerII(string password) 
  {
    int l = password.size();
    if(l < 8)
    {
      return false;
    }
    
    string splChars = "!@#$%^&*()-+";
    
    char prevChar = 0;
    bool smallChar = false;
    bool capitalChar = false;
    bool digit = false;
    bool specialChar = false;
    
    for(int i = 0; i < l; ++i)
    {
      if((i > 0) && (prevChar == password[i]))
      {
        return false;
      }
      
      if(!smallChar && (password[i] >= 'a' && password[i] <= 'z'))
      {
        smallChar = true;
      }
      
      if(!capitalChar && (password[i] >= 'A' && password[i] <= 'Z'))
      {
        capitalChar = true;
      }
      
      if(!digit && (password[i] >= '0' && password[i] <= '9'))
      {
        digit = true;
      }
      
      if(!specialChar)
      {
        if(splChars.find(password[i]) != std::string::npos)
        {
          specialChar = true;
        }
      }
      
      prevChar = password[i];
    }
    
    //std::cout << smallChar << capitalChar << digit << specialChar << std::endl;
    return smallChar && capitalChar && digit && specialChar;
  }
};

/*
  Q: 2300. Successful Pairs of Spells and Potions
*/
class Solution2_t
{
private:
  int getIndex(vector<int>& potions, long long sp, long long success)
  {
    int l = 0;
    int h = potions.size() - 1;
    
    int ans = -1;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      long long po = potions[m];
      if(po * sp >= success)
      {
        ans = m;
        h = m-1;
      }
      else
      {
        l = m + 1;
      }
    }
    
    return ans;
  }
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
  {
    int sl = spells.size();
    int pl = potions.size();
    sort(potions.begin(), potions.end());
    
    vector<int> ans(sl, 0);
    for(int i = 0; i < sl; ++i)
    {
      int count = 0;
      int pos = getIndex(potions, spells[i], success);
      
      ans[i] = pos >= 0 ? pl - pos : 0;
    }
    
    return ans;
  }
};

/*
  Q: 2301. Match Substring After Replacement - solved after looking into solution!
*/
class Solution3_t
{  
public:
  bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
  {
    int sl = s.size();
    int subl = sub.size();
    unordered_map<char, unordered_set<char>> maps;
    for(vector<char> maps_ : mappings)
    {
      maps[maps_[0]].insert(maps_[1]);
    }
    
    for(int i = 0; i <= sl - subl; ++i)
    {
      bool matching = true;
      for(int j = 0; j < subl; ++j)
      {
        char ch1 = s[i+j];
        char ch2 = sub[j];
        
        if(ch1 == ch2)
        {
          continue;
        }
        
        if(maps[ch2].find(ch1) != maps[ch2].end())
        {
          continue;
        }
        else
        {
          matching = false;
          break;
        }
      }
      
      if(matching)
      {
        return true;
      }
    }
    
    return false;
  }
};

/*
  Q: 2302. Count Subarrays With Score Less Than K - solved after looking into solution!
*/
class Solution 
{
public:
  long long countSubarrays(vector<int>& nums, long long k) 
  {
    long long ans = 0;
    int l = nums.size();
    
    int pos = 0;
    long long sum = 0;
    for(int i = 0; i < l; ++i)
    {
      sum += nums[i];
      
      while(sum * (i-pos + 1) >= k)
      {
        sum -= nums[pos];
        pos++;
      }
      
      ans += (i-pos + 1);
    }
    
    return ans;
  }
};