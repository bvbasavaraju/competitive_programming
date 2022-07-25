#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  string licenseKeyFormatting(string s, int k) 
  {
    vector<int> caps(26);
    for(char i = 'A'; i <= 'Z'; ++i)
    {
      caps[i-'A'] = i;
    }
    
    string ans = "";
    
    int count = 0;
    int i = s.size() - 1;
    while(i >= 0)
    {
      if(s[i] == '-')
      {
        i--;
        continue;
      }
      
      if(count == k)
      {
        count = 0;
        //ans = "-" + ans;
        ans += "-";
      }
      
      char ch = (s[i]-'a' < 0 ? s[i] : caps[s[i] - 'a']);
      //ans = string(1, ch) + ans;
      ans += ch;
      
      i--;
      count++;
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
  }
};