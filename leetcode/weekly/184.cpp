/****************************************************
Date: April 12th, 2020
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-184
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
  Q: 1408. String Matching in an Array
*/
class Solution1_t
{
public:
  vector<string> stringMatching(vector<string>& words) 
  {
    sort(words.begin(), words.end(), [](const string& s1, const string& s2) -> bool { return (s1.size() > s2.size()); } );
    
    vector<string> result;
    int l = words.size();
    
    for(int j = l-1; j >= 0; --j)
    {
      string& to_find = words[j];
      for(int i = 0; i < j; ++i)
      {
        if(words[i].find(to_find) != string::npos)
        {
          result.push_back(to_find);
          break;
        }
      }
    }
    
    return result;
  }
};

/*
  Q: 1409. Queries on a Permutation With Key
*/
class Solution2_t
{
public:
  vector<int> processQueries(vector<int>& queries, int m) 
  {
    vector<int> p(m);
    for(int i = 0; i < m; ++i)
    {
      p[i] = i + 1;
    }
    
    int l = queries.size();
    vector<int> ans(l);
    for(int j = 0; j < l; ++j)
    {
      for(int i = 0; i < m; ++i)
      {
        if(p[i] == queries[j])
        {
          ans[j] = i;
          p.erase(p.begin() + i);
          p.insert(p.begin(), queries[j]);
          break;          
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1410. HTML Entity Parser
*/
class Solution3_t
{  
public:
  string entityParser(string t) 
  {
    string result = "";
    int l = t.size();
    for(int i = 0; i < l; ++i)
    {
      //printf("%d,", i);
      if(t[i] != '&')
      {
        result += t[i];
        continue;
      }
      
      i++;
      if(i >= l)
      {
        break;
      }
      
      string s = t.substr(i, 6);
      bool replaced = false;
      switch(t[i])
      {
        case 'q':
          if(s.find("uot;", 1) != string::npos)
          {
            result += "\"";
            i += 4;
            replaced = true;
          }
          break;
        
        case 'a':
          if(s.find("pos;", 1) != string::npos)
          {
            result += "\'";
            i += 4;
            replaced = true;
          }
          else if(s.find("mp;", 1) != string::npos)
          {
            result += "&";
            i += 3;
            replaced = true;
          }
          break;
          
        case 'g':
          if(s.find("t;", 1) != string::npos)
          {
            result += ">";
            i += 2;
            replaced = true;
          }
          break;
          
        case 'l':
          if(s.find("t;", 1) != string::npos)
          {
            result += "<";
            i += 2;
            replaced = true;
          }
          break;
          
        case 'f':
          if(s.find("rasl;", 1) != string::npos)
          {
            result += "/";
            i += 5;
            replaced = true;
          }
          break;
          
        default:
          break;
      }
      
      if(!replaced)
      {
        result += "&";
        result += t[i];
      }
    }
    
    return result;
  }
};

/*
  Q: 1411. Number of Ways to Paint N × 3 Grid
*/
class Solution4_t
{
public:
    int numOfWays(int n) 
    {
        
    }
};