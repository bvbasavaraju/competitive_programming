#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  char findTheDifference(string s, string t) 
  {
    vector<int> freq(26, 0);
    
    for(int ch : s)
    {
      freq[ch-'a']++;
    }
    
    for(int ch : t)
    {
      freq[ch-'a']++;
    }
    
    int ans = 0;
    for(int i = 0; i < 26; ++i)
    {
      if(freq[i]%2 != 0)
      {
        ans = i;
        break;
      }
    }
    
    return 'a' + ans;
  }
};