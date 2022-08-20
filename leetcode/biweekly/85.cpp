/****************************************************
Date: August 20th, 2022
Successful submissions : 2
Successful submissions after timeout : 0
Time expiration : 1
Memory exhausted : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-85
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2379. Minimum Recolors to Get K Consecutive Black Blocks
*/
class Solution1_t
{
public:
  int minimumRecolors(string blocks, int k) 
  {
    int l = blocks.size();
    vector<int> clr(26, 0);
    
    int i = 0;
    while(i < k)
    {
      clr[blocks[i]-'A']++;
      i++;
    }
    
    int ans = clr['W'-'A'];
    for( ;i < l; ++i)
    {
      clr[blocks[i-k] - 'A']--;
      clr[blocks[i]-'A']++;
      
      ans = min(ans, clr['W'-'A']);
    }
    
    return ans;
  }
};

/*
  Q: 2380. Time Needed to Rearrange a Binary String
*/
class Solution2_t
{
public:
  int secondsToRemoveOccurrences(string s) 
  {
    int l = s.size();
    
    int ans = 0;
    
    bool modified = true;
    while(modified)
    {
      modified = false;
      
      for(int i = 1; i < l; i++)
      {
        if(s[i-1] == '0' && s[i] == '1')
        {
          s[i-1] = '1';
          s[i] = '0';
          i++;
          modified = true;
        }
      }
      
      if(modified)
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2381. Shifting Letters II
*/
class Solution 
{
public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) 
  {
    int l = s.size();
    vector<int> count(l, 0);
    
   
    //TLE
    // for(vector<int>& sh : shifts)
    // {
    //   if(sh[2] == 1)
    //   {
    //     for(int i = sh[0]; i <= sh[1]; ++i)
    //     {
    //       s[i] = (((s[i] - 'a') + 1) % 26) + 'a';
    //     }
    //   }
    //   else
    //   {
    //     for(int i = sh[0]; i <= sh[1]; ++i)
    //     {
    //       s[i] = (((s[i] - 'a') - 1 + 26) % 26) + 'a';
    //     }
    //   }
    // }
    
    return s;
  }
};

/*
  Q: 2382. Maximum Segment Sum After Removals
*/
class Solution4_t
{
public:
  vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) 
  {
      
  }
};