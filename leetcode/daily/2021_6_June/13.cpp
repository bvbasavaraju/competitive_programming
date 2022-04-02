/****************************************************
Date: June 13th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3772/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
  Q: 
*/

class Solution 
{
private:
  bool isPalindrome(const string& a, const string& b)
  {
    string w = "" + a + b;
    
    int l = w.size();
    for(int i = 0; i < l/2; ++i)
    {
      if(w[i] != w[l-1-i])
      {
        return false;
      }
    }
    
    return true;
  }
public:
  vector<vector<int>> palindromePairs(vector<string>& words) 
  {
    int l = words.size();
    
    vector< vector<int> > ans;
    for(int i = 0; i < l; ++i)
    {
      for(int j = 0; i < l; ++j)
      {
        if(i == j)
        {
          continue;
        }
        
        if(isPalindrome(words[i], words[j]))
        {
          ans.push_back({i, j});
        }
      }
    }
    
    return ans;
  }
};

int main()
{
  Solution s;

  vector<string> words = {"abcd","dcba","lls","s","sssll"};
  s.palindromePairs(words);
  return 0;
}