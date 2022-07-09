#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  void getAllPermutations(string s, int p, unordered_set<string>& ans)
  {
    if(p == s.size())
    {
      ans.insert(s);
      return;
    }
    
    for(int i = p; i < s.size(); ++i)
    {
      swap(s[i], s[p]);
      getAllPermutations(s, p+1, ans);
      swap(s[i], s[p]);
    }
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) 
  {
    string nums_ = "";
    for(int n : nums)
    {
      nums_ += n + 10 + 'a';
    }
    
    unordered_set<string> allPermutations;
    getAllPermutations(nums_, 0, allPermutations);
    
    vector<vector<int>> ans;
    for(auto it = allPermutations.begin(); it != allPermutations.end(); ++it)
    {
      vector<int> num;
      for(char ch : *it)
      {
        num.push_back(ch - 'a' - 10);
      }
      
      ans.push_back(num);
    }
    
    return ans;
  }
};