#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  int getLongestCommonSubsequence(const string& s1, const string& s2)
  {
    int l1 = s1.size();
    int l2 = s2.size();
    
    vector<vector<int>> lcs(l1+1, vector<int>(l2+1, 0));
    
    for(int i = 0; i <= l1; ++i)
    {
      for(int j = 0; j <= l2; ++j)
      {        
        if((i == 0 && j == 0) || i == 0 || j == 0)
        {
          continue;
        }
        
        if(s1[i-1] == s2[j-1])
        {
          lcs[i][j] = 1 + lcs[i-1][j-1];
        }
        else
        {
          lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
      }
    }
    
    return lcs[l1][l2];
  }
  
//   int getLongestCommonSubsequence(const string& s1, const string& s2, int p1, int p2)
//   {
//     if(p1 < 0 || p2 < 0)
//     {
//       return 0;
//     }
    
//     //TODO : memoization
    
//     int ans = 0;
//     if(s1[p1] == s2[p2])
//     {
//       ans = 1 + getLongestCommonSubsequence(s1, s2, p1-1, p2-1);
//     }
//     else
//     {
//       ans = max(getLongestCommonSubsequence(s1, s2, p1-1, p2), getLongestCommonSubsequence(s1, s2, p1, p2-1));
//     }
    
//     return ans;
//   }
  
public:
  int minDistance(string word1, string word2) 
  {
    int lcs = getLongestCommonSubsequence(word1, word2);
    
    //int lcs = getLongestCommonSubsequence(word1, word2, word1.size()-1, word2.size()-1);
    
    return (word1.size() + word2.size() - 2*lcs);
  }
};