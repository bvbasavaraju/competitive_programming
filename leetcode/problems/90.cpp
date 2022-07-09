#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) 
  {
    char conversion = 'a';
    
    unordered_map<char, int> charToNumMapping;
    unordered_map<int, char> numToCharMapping;
    for(int n : nums)
    {
      if(numToCharMapping.find(n) != numToCharMapping.end())
      {
        continue;
      }
      
      numToCharMapping[n] = conversion;
      charToNumMapping[conversion] = n;
      conversion++;
    }
    
    string numS = "";
    for(int n : nums)
    {
      numS += numToCharMapping[n];
    }
    
    int l = numS.size();
    
    int total = 1 << l;
    unordered_set<string> uniques;
    for(int b = 0; b < total; ++b)
    {
      string s = "";
      
      int i = 1;
      int pos = 0;
      while(i < total)
      {
        if(i & b)
        {
          s = numS[pos] + s;
        }
        pos++;
        i <<= 1;
      }
      sort(s.begin(), s.end());
      
      uniques.insert(s);
    }
    
    vector<vector<int>> ans;
    for(auto it = uniques.begin(); it != uniques.end(); ++it)
    {
      vector<int> set;
      for(auto ch : *it)
      {
        set.push_back(charToNumMapping[ch]);
      }
      
      ans.push_back(set);
    }
    
    return ans;
  }
};