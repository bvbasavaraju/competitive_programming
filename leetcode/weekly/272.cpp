/****************************************************
Date: Dec 19, 2021
Successful submissions : 3
Time expiration : 0
Not Solved : 0
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-272
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: 2108. Find First Palindromic String in the Array
*/
class Solution1_t
{
private:
  bool isPalindrome(const string& word)
  {
    int l = word.size();
    for(int i = 0, j = l-1; i < l && j >= 0 && i <= j; ++i, --j)
    {
      if(word[i] != word[j])
      {
        return false;
      }
    }
    
    return true;
  }
public:
  string firstPalindrome(vector<string>& words) 
  {
    for(const string& w : words)
    {
      if(isPalindrome(w))
      {
        return w;
      }
    }
    
    return "";
  }
};

/*
  Q: 2109. Adding Spaces to a String
*/
class Solution2_t
{
public:
  string addSpaces(string s, vector<int>& spaces) 
  {
    string ans = "";
    
    int pos = 0;
    int l = spaces.size();
    for(int i = 0; i < l; ++i)
    {
      ans += s.substr(pos, spaces[i] - pos) + " ";
      pos = spaces[i];
    }
    
    if(pos != s.size())
    {
      ans += s.substr(pos);
    }
    
    return ans;
  }
};

/*
  Q: 2110. Number of Smooth Descent Periods of a Stock
*/
class Solution3_t
{
public:
  long long getDescentPeriods(vector<int>& prices) 
  {
    long long ans = prices.size();
    
    long long count = 1;
    int l = prices.size();
    int oldStockValue = prices[0];
    for(int i = 1; i < l; ++i)
    {
      if(oldStockValue - prices[i] == 1)
      {
        count++;
      }
      else
      {
        if(count > 1)
        {
          ans += (count * (count -1) / 2);
        }
        count = 1;
      }
      
      oldStockValue = prices[i];
    }
    
    if(count > 1)
    {
      ans += (count * (count -1) / 2);
    }
    
    return ans;
  }
};

/*
  Q: 2111. Minimum Operations to Make the Array K-Increasing - wrong answer!
*/
class Solution4_t
{
public:
  int kIncreasing(vector<int>& arr, int k) 
  {
    int l = arr.size();
    
    int ans = 0;
    for(int i = 0; i < l-k; ++i)
    {
      if(arr[i] > arr[i+k])
      {
        ans++;
        arr[i+k] = arr[i];
      }
    }
    
    return ans;
  }
};