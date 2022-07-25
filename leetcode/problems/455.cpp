#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int findContentChildren(vector<int>& g, vector<int>& s) 
  {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int i = 0;
    int j = 0;
    
    int ans1 = 0;
    while(i < g.size() && j < s.size())
    {
      while(i < g.size() &&  g[i] > s[j])
      {
        i++;
      }
      
      while(i < g.size() && j < s.size() && g[i] <= s[j])
      {
        ans1++;
        i++;
        j++;
      }
    }
    
    i = g.size()-1;
    j = s.size()-1;
    int ans2 = 0;
    while(i >= 0 && j >= 0)
    {
      while(i >= 0 &&  g[i] > s[j])
      {
        i--;
      }
      
      while(i >= 0 && j >= 0 && g[i] <= s[j])
      {
        ans2++;
        i--;
        j--;
      }
    }
    
    return max(ans1, ans2);
  }
};