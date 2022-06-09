#include<bits/stdc++.h>
using namespace std;

//TODO: resulting in wrong answer!!
class Solution 
{
private:
  bool isTargetPresentInSource(const string& target, const vector<int>& tFreq, const vector<int>& sFreq)
  {    
    for(char ch : target)
    {
      if(tFreq[ch] != sFreq[ch])
      {
        return false;
      }
    }
    
    return true;
  }
  
public:
  string minWindow(string s, string t) 
  {
    vector<int> tFreq(128, 0);
    for(char ch : t)
    {
      tFreq[ch]++;
    }
    
    vector<int> sFreq(128, 0);
    for(int i = 0; i < t.size() && i < s.size(); ++i)
    {
      sFreq[s[i]]++;
    }
    
    int i = t.size();
    int len = INT_MAX;
    pair<int, int> ans = {};
    vector<int> sFreqTemp = sFreq;
    while(i < s.size())
    {
      for(int j = i; j < s.size(); ++j)
      {
        int start = j-i;
        int end = j;
        if(isTargetPresentInSource(t, tFreq, sFreq))
        {
          if((end - start + 1) < len)
          {
            len = end-start + 1;
            ans = {start, end};
          }
        }

        sFreq[s[start]]--;
        sFreq[s[end]]++;
      }
      
      sFreq = sFreqTemp;
      sFreq[s[i]]++;
      i++;
    }
    
    return len == INT_MAX ? "" : s.substr(ans.first, ans.second-ans.first+1);
  }
};

int main()
{
  Solution s;
  s.minWindow("ADOBECODEBANC", "ABC");

  return 0;
}