#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  bool isPalindrome(const string& s, int start, int end)
  {
    while(start < end)
    {
      if(s[start] != s[end])
      {
        return false;
      }
      
      start++;
      end--;
    }
    
    return true;
  }
  
  int getMinCuts(const string& s, int start, int end, vector<vector<int>>& dp)
  {
    if((start >= end) || isPalindrome(s, start, end))
    {
      return 0;
    }
    
    if(dp[start][end] != INT_MIN)
    {
      return dp[start][end];
    }
    
    int ans = INT_MAX;
    for(int i = start; i < end; ++i)
    {
      // if we do both left and right cuts, it will end up in time limit exceeded!
      //int leftCuts = getMinCuts(s, start, i, dp);
      //int rightCuts = getMinCuts(s, i+1, end, dp);
      
      //ans = min(ans, 1 + leftCuts + rightCuts);
      //dp[start][end] = ans;
      
      //only if left cut is palindrome, check for right cut otherwise skip!! this will speed up
      if(isPalindrome(s, start, i))
      {
        int rightCuts = getMinCuts(s, i+1, end, dp);
        
        ans = min(ans, 1+rightCuts);  
      }
      
      dp[start][end] = ans;
    }
    
    return dp[start][end];
  }
public:
  int minCut(string s) 
  {
    int l = s.size();
    vector<vector<int>> dp(l, vector<int>(l, INT_MIN));
    
    return getMinCuts(s, 0, l-1, dp);
  }
};