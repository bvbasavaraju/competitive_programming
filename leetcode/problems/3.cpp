#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int lengthOfLongestSubstring(string s) 
  {
    int ans = 0;
    int l = s.size();
    for(int i = 0; i < l; ++i)
    {
      vector<int> freq(128, 0);
      
      int len = 1;
      freq[s[i]]++;
      for(int j = i+1; j < l; ++j)
      {
        if(freq[s[j]] != 0)
        {
          break;
        }
        
        len++;
        freq[s[j]]++;
      }
      
      ans = max(ans, len);
    }
    
    return ans;
  }
};