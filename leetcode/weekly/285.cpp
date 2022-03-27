/****************************************************
Date: Mar 20th, 2022
Successful submissions : 1
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/weekly-contest-285
****************************************************/

#include<bits/stdc++.h>

using namespace std;

/*
  Q: 2210. Count Hills and Valleys in an Array
*/
class Solution1_t
{
public:
  int countHillValley(vector<int>& nums) 
  {
    int ans = 0;
    int l = nums.size();
    
    bool hill = false;
    bool valley = false;
    for(int i  = 1; i < l-1; ++i)
    {
      if(nums[i] > nums[i-1])
      {
        if(nums[i] > nums[i+1])
        {
          ans += 1; 
          hill = false;
        }
        else if(nums[i] == nums[i+1])
        {
          hill = true;
        }
      }      
      if(nums[i] < nums[i-1])
      {
        if(nums[i] < nums[i+1])
        {
          ans += 1;
          valley = false;
        }
        else if(nums[i] == nums[i+1])
        {
          valley = true;
        }
      }
      
      if(nums[i] == nums[i-1])
      {
        if(hill && (nums[i] > nums[i+1]))
        {
          ans += 1; 
          hill = false;
        }
        else if(valley && (nums[i] < nums[i+1]))
        {
          ans += 1;
          valley = false;
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 2211. Count Collisions on a Road - wrong answer!
*/
class Solution2_t
{
public:
  int countCollisions(string d) 
  {
    int l = d.size();
    
    int ans = 0;
    vector<int> c(l, 0);
    std::cout << 0 << " ";
    for(int i = 1; i < l; ++i)
    {
      // if(d[i] == 'S')
      // {
      //   continue;
      // }
      if(d[i] != d[i-1])
      {
        if(d[i-1] == 'R')
        {
          c[i] += d[i] == 'L' ? 2 : (d[i] == 'R' ? 0 : 1);
        }
        if(d[i-1] == 'S')
        {
          c[i] += d[i] == 'L' ? 1 : 0;
        }
      }
      else
      {
        c[i] = c[i-1] > 0 && d[i-1] != 'S' ? 1 : 0;
      }
      
      //std::cout << c[i] << " ";
    }
    
    for(int i : c)
    {
      ans += i;
    }

    return ans;
  }
};

/*
  Q: 2212. Maximum Points in an Archery Competition - not working!
*/
class Solution3_t
{
public:
  vector<int> maximumBobPoints(int n, vector<int>& a) 
  {
    int l = a.size();
    vector<vector<int>> dp(n+1, vector<int>(l+1, 0));
    
    for(int i = 0; i <= n; ++i)
    {
      for(int j = 0; j <= l; ++j)
      {
        if(i == 0 || j == 0)
        {
          dp[i][j] = 0;
          continue;
        }
        
        if(a[j-1] <= i)
        {
          dp[i][j] = max(i-1 + dp[i-1][j-a[j-1]], dp[i-1][j]);
        }
        else
        {
          dp[i][j] = dp[i-1][j];
        }
      }
    }
    
    int mx = dp[n][l];
    
    vector<int> ans;
    for(int i = n-1; i >= 0 && mx > 0; ++i)
    {
      if(mx == dp[i][n])
      {
        continue;
      }
      
      ans.push_back(a[i]+1);
      mx -= i;
      n -= a[i];
    }
    
    return ans;
  }
};

/*
  Q: 2213. Longest Substring of One Repeating Character - failing at few test cases!! - segment tree approach should be taken
*/

class Solution4_t
{
private:
  int getMax(vector<int>& freq)
  {
    int ans = 0;
    int l = freq.size();
    for(int i = 0; i < l; ++i)
    {
      ans = max(ans, freq[i]);
    }
    
    return ans;
  }
  
public:
  vector<int> longestRepeating(string s, string qc, vector<int>& qi) 
  {
    //int maxi = 0;
    int l = s.size();
    vector< vector<int> > freq(l+1, vector<int>(26, 0));
    for(int i = 0; i < l; ++i)
    {
      int j = s[i] - 'a';
      if(i == 0)
      {
        freq[i][j]++;
        freq[l][j] = freq[i][j];
        
        continue;
      }
      
      freq[i][j] = 1 + freq[i-1][j];
      freq[l][j] = max(freq[l][j], freq[i][j]);
      
      //maxi = max(maxi, freq[l][j]);
    }
    
    vector<int> ans;
    int ql = qc.size();
    for(int idx = 0; idx < ql; ++idx)
    {
      int p = qi[idx];
      int ch = qc[idx] - 'a';
      int rch = s[p] - 'a';
      
      if(freq[p][ch] == s[p])
      {
        ans.push_back(getMax(freq[l]));
        //ans.push_back(maxi);
        continue;
      }
      
      freq[p][rch] = 0; //Remove the existing character
      freq[p][ch] = 1 + ((p == 0) ? 0 : freq[p-1][ch]); //Add new character
      
      freq[l][ch] = max(freq[l][ch], freq[p][ch]);
      //freq[l][rch] = min(freq[l][rch], freq[p][rch]);
      //maxi = max(maxi, freq[l][ch]);
      
      for(int i = p+1; (i < l) && ((freq[i][ch] > 0) || (freq[i][rch] > 0)); ++i)
      {
        if(freq[i][ch] > 0)
        {
          //for adding new character!
          freq[i][ch] = 1 + freq[i-1][ch];
          freq[l][ch] = max(freq[l][ch], freq[i][ch]);
        }
        
        if(freq[i][rch] > 0)
        {
          //for removing the old character
          freq[i][rch] = 1 + freq[i-1][rch];
          freq[l][rch] = min(freq[l][rch], freq[i][rch]);
        }
        
        //maxi = max(maxi, freq[l][ch]);
      }
            
      ans.push_back(getMax(freq[l]));
      //ans.push_back(maxi);
    }
    
    return ans;
  }
};