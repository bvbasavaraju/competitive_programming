#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<string> findWords(vector<string>& words) 
  {
    static const string row1 = "qwertyuiop";
    static const string row2 = "asdfghjkl";
    static const string row3 = "zxcvbnm";
    
    vector<int> row(26, 0);
    for(char ch = 'a'; ch <= 'z'; ++ch)
    {
      row[ch-'a'] = (row1.find(ch) != string::npos) ? 1 : ((row2.find(ch) != string::npos) ? 2 : 3);
    }
    
    vector<string> ans;
    for(string s : words)
    {
      int num = 0;
      bool includeWord = true;
      for(char ch : s)
      {
        int r = (ch - 'a' >= 0) ? row[ch-'a'] : row[ch-'A'];
        if(num != r && num > 0)
        {
          includeWord = false;
          break;
        }
        
        num = r;
      }
      
      if(includeWord)
      {
        ans.push_back(s);
      }
    }
    
    return ans;
  }
};