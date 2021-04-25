/****************************************************
Date: April 25th, 2021
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-238
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
  Q: 1837. Sum of Digits in Base K
*/
class Solution 
{
public:
  int sumBase(int n, int k) 
  {
    int ans = 0;
    while(n > 0)
    {
      ans += (n%k);
      n /= k;
    }
    
    return ans;
  }
};

/*
  Q: 1838. Frequency of the Most Frequent Element - wrong answer
*/
class Solution 
{
private:
  bool isFound(vector<int>& nums, int& h, int val)
  {
    int l = 0;
    
    if(val < 0)
    {
      return false;
    }
    
    while(l <= h)
    {
      int m = l + (h-l)/2;
      if(nums[m] == val)
      {
        return true;
      }
      
      if(nums[m] < val)
      {
        l = m+1;
      }
      else
      {
        h = m-1;
      }
    }
    
    return false;
  }
  
public:
  int maxFrequency(vector<int>& nums, int k) 
  {
    sort(nums.begin(), nums.end());
    
    int ans = 0;
    int l = nums.size();
    
    for(int i = l-1; i > 0; --i)
    {
      int val = nums[i];
      int remainingK = k;
      
      int j = i-1;
      int count = 1;
      int n = val - nums[j];
      while((j >= 0) && (n > remainingK) && isFound(nums, j, n))
      {
        count++;
        remainingK -= n;
        
        j--;
        n = val - (val - nums[j]);
      }
      
      ans = max(ans, count);
    }
    
    return ans;
  }
};

/*
  Q: 1839. Longest Substring Of All Vowels in Order
*/
class Solution 
{
private:
  bool allPresent(vector<int>& letters)
  {
    if((letters['a'-'a'] <= 0) 
      || (letters['e'-'a'] <= 0)
      || (letters['i'-'a'] <= 0)
      || (letters['o'-'a'] <= 0)
      || (letters['u'-'a'] <= 0))
    {
      return false;
    }
    
    return true;
  }
public:
  int longestBeautifulSubstring(string word) 
  {
    int l = word.size();
    
    int ans = 0;
    
    for(int i = 0; i < l-1;)
    {
      int j = i+1;
      vector<int> letters(26, 0);
      
      letters[word[i]-'a']++;
      for(;j < l; ++j)
      {
        if(word[j] < word[j-1])
        {
          if(allPresent(letters))
          {
            ans = max(ans, j-i);
          }
          
          i = j;
          break;
        }
        
        letters[word[j]-'a']++;
      }
      
      if(j >= l)
      {
        if(allPresent(letters))
        {
          ans = max(ans, j-i);
        }
        break;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1840. Maximum Building Height
*/
class Solution 
{
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) 
    {
        
    }
};