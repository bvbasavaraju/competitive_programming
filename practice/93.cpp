#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  bool isValid(const string& ipByte)
  {
    int l = ipByte.size();
    if(l <= 0 || l > 3 || (l > 1 && ipByte[0] == '0'))
    {
      return false;
    }
    
    int val = 0;
    for(int ch : ipByte)
    {
      val = (val * 10) + (ch-'0');
    }
    
    return val < 256;
  }
  
public:
  vector<string> restoreIpAddresses(string s) 
  {
    int start  = 0;
    int end = s.size();
    
    if(end < 4)
    {
      return {};
    }

    unordered_set<string> ips;
    for(int i = start+1; abs(i-start) <= 3; ++i)
    {
      string ipByte1 = s.substr(start, i-start);
      if(!isValid(ipByte1))
      {
        break;
      }
      
      for(int j = i+1; abs(j-i) <= 3 && j < end; ++j)
      {
        string ipByte2 = s.substr(i, j-i);
        if(!isValid(ipByte2))
        {
          break;
        }
        
        for(int k = j+1; abs(k-j) <= 3 && k < end; ++k)
        {
          string ipByte3 = s.substr(j, k-j);
          if(!isValid(ipByte3))
          {
            break;
          }
          
          //for(int l = k+1; l <= end; ++l)
          for(int l = k+1; abs(end-l) <= 3; ++l)
          {
            string ipByte4 = s.substr(k);
            if(!isValid(ipByte4))
            {
              break;
            }
            
            ips.insert(ipByte1 + "." + ipByte2 + "." + ipByte3 + "." + ipByte4);
          }
        }
      }
    }
    
    vector<string> ans;
    for(auto it = ips.begin(); it != ips.end(); ++it)
    {
      ans.push_back(*it);
    }
    
    return ans;
  }
};