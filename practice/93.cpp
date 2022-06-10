#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  bool isValid(string ip)
  {
    int count = 0;
    int octate = 0;
    string octateS = "";
    for(char ch : ip)
    {
      if(ch == '.')
      {
        count++;
      }
      
      octateS += ch;
      octate = octate * 10 + (ch - '0');
      
      if(octate > 255 || ((octateS.size() > 1) && octateS[0] == 0))
      {
        return false;
      }
    }
    
    // if(octate > 255 || ((octateS.size() > 1) && octateS[0] == 0))
    // {
    //   return false;
    // }
    count++;
    
    return count == 4;
  }
  void getAllCombinations(string s, string ip, int p, int pointerCount, vector<string>& ans)
  {
    if(p >= s.size())
    {
      if(pointerCount == 3 && isValid(ip))
      {
        ans.push_back(ip);
      }
      return;
    }

    if(pointerCount == 3 && isValid(ip))
    {
      ans.push_back(ip);
      return;
    }

    for(int i = p; i < s.size(); ++i)
    {
      ip += s[i];
      if(pointerCount < 3)
      {
        ip += ".";
        getAllCombinations(s, ip, i+1, pointerCount+1, ans);
      }
      else
      {
        getAllCombinations(s, ip, i+1, pointerCount, ans);
      }
      ip.pop_back();
      //getAllCombinations(s, ip, i+1, pointerCount, ans);
    }
  }
public:
  vector<string> restoreIpAddresses(string s) 
  {
    string ip;
    vector<string> ans;
    getAllCombinations(s, ip, 0, 0, ans);
    
    return ans;
  }
};

int main()
{
  Solution s;
  s.restoreIpAddresses("25525511135");

  return 0;
}