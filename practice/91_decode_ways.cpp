#include <bits/stdc++.h>

using namespace std;

class Solution 
{
private:
  
//   void getStrings(string s, string ds, unordered_map<string, string>& kv, vector<string>& strs)
//   {
//     if(s.empty())
//     {
//       if(!ds.empty())
//       {
//         strs.push_back(ds);
//       }
      
//       return;
//     }
    
//     //int l = s.size();
//     string s1 = s.substr(0, 1);
//     if(kv.count(s1) != 0)
//     {
//       getStrings(s.substr(1), ds+kv[s1], kv, strs);
//     }

//     if(s.size() > 1)
//     {
//       string s2 = s.substr(0, 2);
//       if(kv.count(s2) > 0)
//       {
//         getStrings(s.substr(2), ds+kv[s2], kv, strs); 
//       }
//     }
//   }
  
  void getCount(string s, int pos, int& ans)
  {
    if(pos >= s.size())
    {
      ans += 1;
      return;
    }
    
    int n = s[pos] - '0';
    
    if(n > 0)
    {
      bool callForNextSingleDigit = true;
      if(pos < s.size()-1)
      {
        int next = (s[pos+1] - '0');
        callForNextSingleDigit = (next != 0);
        n = (n * 10) + next;  
        if(n < 27)
        {
          getCount(s, pos+2, ans);
        }
      }  
      
      if(callForNextSingleDigit)
      {
        getCount(s, pos+1, ans); 
      }
    }
  }
  
public:
  int numDecodings(string s) 
  {
    int ans = 0;
    getCount(s, 0, ans);
    
    return ans;
//     int l = s.size();
    
//     unordered_map<string, string> keyValues;
//     for(int i = 0; i < 26; ++i)
//     {
//       keyValues[std::to_string(i+1)] = string(1, 'A'+i);
//     }
    
//     string ds = "";
//     vector<string> strs;
//     getStrings(s, ds, keyValues, strs);
    
//     return strs.size();
  }
};