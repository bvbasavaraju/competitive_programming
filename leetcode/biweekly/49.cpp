/****************************************************
Date: March 20th, 2021
Successful submissions : 2
Time expiration : 1 (solved after looking at the discussion)
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-49
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
#include <string_view>

using namespace std;

/*
  Q: 1812. Determine Color of a Chessboard Square
*/
class Solution1_t
{
public:
  bool squareIsWhite(string coordinates) 
  {
    vector< vector<bool> > cb(8, vector<bool>(8, false));
    
    bool color = false;
    for(int i = 0; i < 8; ++i)
    {
      for(int j = 0; j < 8; ++j)
      {
        cb[i][j] = color;
        color = !color;
      }
      color = !color;
    }
    
    return cb[coordinates[0]-'a'][coordinates[1]-'0'-1];
  }
};

/*
  Q: 1813. Sentence Similarity III
*/
class Solution 
{
private:
  void getWords(string& str, vector<string>& words)
  {
    size_t p = 0;
    while(p != std::string::npos)
    {
      size_t temp = str.find_first_of(' ', p);
      
      words.push_back(str.substr(p, temp-p));
      
      if(temp == std::string::npos)
      {
        break;
      }
      
      p = temp+1;
    }
  }
  
  bool similar(vector<string>& s1, vector<string>& s2)
  {
    int ans = 0;
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    
    while(it1 != s1.end() && it2 != s2.end())
    {
      if(*it1 != *it2)
      {
        ans++;
        string temp = "" + *it2;
        while(it1 != s1.end() && *it1 != temp)
        {
          it2 = s2.insert(it2, *it1);
          it1++;
          it2++;
        }
        
        if(ans >= 2)
        {
          return false;
        }
      }
      else
      {
        it1++;
        it2++;
      }
    }
    
    return (it2 == s2.end() && ans == 0 && it1 != s1.end()) || (it1 == s1.end() && it2 == s2.end());
  }
  
public:
  bool areSentencesSimilar(string sentence1, string sentence2) 
  {
    vector<string> s1;
    getWords(sentence1, s1);
    
    vector<string> s2;
    getWords(sentence2, s2);
    
    return (s1.size() >= s2.size()) ? similar(s1, s2) : similar(s2, s1);
  }
};

/*
  Q: 1814. Count Nice Pairs in an Array - solved after looking at the solution
*/
class Solution3_t
{  
public:
  int countNicePairs(vector<int>& nums) 
  {
    unordered_map<int, int> freq;
    
    int ans = 0;
    static const int MOD = 1e9 + 7;
    for(int n : nums)
    {
      int r = 0;
      int t = n;
      while(n > 0 )
      {
        r = (r * 10) + (n%10);
        n /= 10;
      }
      
      ans = (ans + (freq[t-r]++) % MOD) % MOD;
      freq[t-r] = freq[t-r] % MOD;
    }
    
    return ans;
  }
};

/*
  Q: 1815. Maximum Number of Groups Getting Fresh Donuts
*/
class Solution 
{
public:
  int maxHappyGroups(int batchSize, vector<int>& groups) 
  {

  }
};