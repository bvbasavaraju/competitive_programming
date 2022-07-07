#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  bool isInterleave(const string& s1, const string& s2, const string& s3, int p1, int p2, int p3, vector<vector<int>>& cache)
  {
    if(p1 >= s1.size())
    {
      return s2.substr(p2) == s3.substr(p3);
    }
    
    if(p2 >= s2.size())
    {
      return s1.substr(p1) == s3.substr(p3);
    }
    
    if(cache[p1][p2] != -1)
    {
      return cache[p1][p2] == 1 ? true : false;
    }
    
    bool ans = false;
    if(s1[p1] == s3[p3])
    {
      ans = isInterleave(s1, s2, s3, p1+1, p2, p3+1, cache);
    }
    
    if(!ans && (s2[p2] == s3[p3]))
    {
      ans = isInterleave(s1, s2, s3, p1, p2+1, p3+1, cache);
    }
    
    cache[p1][p2] = ans == true ? 1 : 0;
    
    return ans;
  }
public:
  bool isInterleave(string s1, string s2, string s3) 
  {
    if(s1.size() + s2.size() != s3.size())
    {
      return false;
    }
    
    vector<vector<int>> cache(s1.size(), vector<int>(s2.size(), -1));
    return isInterleave(s1, s2, s3, 0, 0, 0, cache);
    
//     vector< vector<bool> > dp(s1.size()+1, vector<bool>(s2.size()+1, false));
//     for(int i = 0; i <= s1.size(); ++i)
//     {
//       for(int j = 0; j <= s2.size(); ++j)
//       {
//         if(i == 0 && j == 0)
//         {
//           dp[i][j] = true;
//         }
//         else if(i == 0)
//         {
//           dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
//         }
//         else if(j == 0)
//         {
//           dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
//         }
//         else
//         {
//           dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]) || dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
//         }
//       }
//     }
    
//     return dp[s1.size()][s2.size()];
  }
};