/****************************************************
Date: May 15th, 2021
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

Note: 2 other solved after looking at the solution

link: https://leetcode.com/contest/biweekly-contest-52
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
  Q: 1859. Sorting the Sentence
*/
class Solution1_t 
{
public:
  string sortSentence(string s) 
  {
    int p = 0;
    vector<string> words(9, "");
    while(p < s.size())
    {
      int l = s.find_first_of(' ', p);
      if(l == std::string::npos)
      {
        break;
      }
      
      string str = s.substr(p, l-1-p);
      p = l+1;
      
      words[s[l-1] - '0' - 1] = str;
    }

    string str = s.substr(p, s.size()-1-p);
    words[s[s.size()-1] - '0' - 1] = str;

    string ans = "";
    
    for(const string& str : words)
    {
      if(str.empty())
      {
        break;
      }

      if(!ans.empty())
      {
        ans += " ";
      }
      ans += str;
    }
    
    return ans;
  }
};

/*
  Q: 1860. Incremental Memory Leak
*/
class Solution2_t
{
public:
  vector<int> memLeak(int m1, int m2) 
  {
    int i = 1;
    while(true)
    {
      if(m1 >= m2)
      {
        if(m1 >= i)
        {
          m1 -= i;
        }
        else
        {
          return {i, m1, m2};
        }
      }
      else
      {
        if(m2 >= i)
        {
          m2 -= i;
        }
        else
        {
          return {i, m1, m2};
        }
      }
      
      ++i;
    }
  }
};

/*
  Q: 1861. Rotating the Box
*/
class Solution3_t
{
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
  {
    int r = box.size();
    int c = box[0].size();
    
    for(int i = 0; i < r; ++i)
    {
      int best = c-1;
      for(int j = c-1;j >= 0; j--)
      {
        if(box[i][j]=='#')
        {
          box[i][best] = '#';
          
          if(best != j)
          {
            box[i][j] = '.';
          }
          
          best = best-1;
        }
        else if(box[i][j] == '*')
        {
          best = j-1;
        }
      }
    }
    
    vector< vector<char> > ans(c, vector<char>(r));
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        ans[j][r-i-1] = box[i][j];
      }
    }
    
    return ans;
  }
};

/*
  Q: 1862. Sum of Floored Pairs
*/
class Solution4_t
{
public:
    int sumOfFlooredPairs(vector<int>& nums) 
    {
        
    }
};