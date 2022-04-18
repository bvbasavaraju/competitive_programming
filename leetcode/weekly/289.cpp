/****************************************************
Date: April 10th, 2022
Successful submissions : 2
Time expiration : 0
Memory exhausted : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-289
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2243. Calculate Digit Sum of a String
*/
class Solution1_t
{
public:
  string digitSum(string s, int k) 
  {
    while(s.size() > k)
    {
      string grouped = "";
      
      int sum = 0;
      int count = 0;
      int l = s.size();
      for(int i = 0; i < l; ++i)
      {
        sum += (s[i] - '0');
        count++;
        
        if(count >= k)
        {
          count = 0;
          grouped += std::to_string(sum);
          sum = 0;
        }
      }
      
      if(count > 0)
      {
        grouped += std::to_string(sum);
      }
      
      s = grouped;
    }
    
    return s;
  }
};

/*
  Q: 2244. Minimum Rounds to Complete All Tasks
*/
class Solution2_t
{
private:
  int getCount(int num)
  {
    int retVal = 0;
    
    if(num % 3 == 0)
    {
      retVal = num/3;
      num %= 3;
    }
    else if(num % 3 == 2)
    {
      retVal = (num/3) + 1; // 1 for dividing by 2!!
      
      num %= 3;
      num %= 2;
    }
    else if(num % 3 == 1)
    {     
      if((num - 4) > 0)
      {
        retVal = ((num-4)/3);
        
        num = 4;
        retVal += num/2;
        num %= 2;
      }
      else
      {
        retVal = num/2;
        num %= 2;
      }
    }
    
    if(num > 0)
    {
      return -1;
    }
    
    return retVal;
  }
public:
  int minimumRounds(vector<int>& tasks) 
  {
    unordered_map<int, int> freq;
    
    for(int t : tasks)
    {
      freq[t]++;
    }
    
    int ans = 0;
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
      int count = getCount(it->second);
      if(count < 0)
      {
        return -1;
      }
      
      ans += count;
    }
    
    return ans;
  }
};

/*
  Q: 2245. Maximum Trailing Zeros in a Cornered Path
*/
class Solution3_t
{
public:
  int maxTrailingZeros(vector<vector<int>>& grid) 
  {
      
  }
};

/*
  Q: 2246. Longest Path With Different Adjacent Characters
*/
class Solution4_t
{
public:
  int longestPath(vector<int>& parent, string s) 
  {
      
  }
};