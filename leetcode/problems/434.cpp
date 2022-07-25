#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int countSegments(string s) 
  {
    int ans = 0;
    bool charStart = false;
    for(char ch : s)
    {
      if((ch == ' '))
      {
        if(charStart)
        {
          ans++;
        }
        
        charStart = false;
        continue;
      }
      
      charStart = true;
    }
    
    return s.empty() ? 0 : (charStart ? ans+1 : ans);
  }
};