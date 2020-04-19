/****************************************************
Date: April 19th, 2020
Successful submissions : 1
Time expiration : 1
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-185
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: 1417. Reformat The String
*/
class Solution1_t
{
public:
  string reformat(string s) 
  {
    string l = "";
    string d = "";
    
    for(auto ch : s)
    {
      if(ch >= '0' && ch <= '9')
      {
        d += ch;
      }
      else
      {
        l += ch;
      }
    }
    
    int ls = l.size();
    int ds = d.size();
    if(ls == 1 && ds == 0)
    {
      return l;
    }
    else if(ds == 1 && ls == 0)
    {
      return d;
    }
    else if(ls == 0 || ds == 0 || (ls != ds && (ls < ds ? ls + 1 != ds : ds + 1 != ls)))
    {
      return "";
    }
    
    bool start_with_num = ls <= ds ? true : false;
    
    string ans = "";
    for(int i = 0; i < min(ls, ds); ++i)
    {
      if(start_with_num)
      {
        ans += d[i];
        ans += l[i];
      }
      else
      {
        ans += l[i];
        ans += d[i];
      }
    }
    
    if (ls != ds)
    {
      ans += start_with_num ? d.back() : l.back();
    }
    
    //printf("ans = %s", ans.c_str());
    
    return ans;
  }
};

/*
  Q: 1418. Display Table of Food Orders in a Restaurant - wrong ans for large input!
*/
class Solution2_t
{
public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) 
  {
    unordered_set<string> food_;
    map<int, unordered_map<string, int>> data;
    
    for(vector<string>& x : orders)
    {
      food_.insert(x[2]);
      unordered_map<string, int>& fc = data[stoi(x[1])];
      fc[x[2]]++;
      
      //printf("table : %s, food: %s, fc: %d\n", x[1].c_str(), x[2].c_str(), fc[x[2]]);
    }
    
    vector<string> food;
    for(string f : food_)
    {
      food.push_back(f);
    }
    
    sort(food.begin(), food.end(), [](const string& s1, const string& s2) -> bool {
      int ls1 = s1.size();
      int ls2 = s2.size();
      
      for(int i = 0; i < min(ls1, ls2); ++i)
      {
        if(s1[i] == s2[i])
        {
          continue;
        }
        if(s1[i] < s2[i])
        {
          return true;
        }
        else
        {
          return false;
        }
      }
      
      return false;
    });
    
    food.insert(food.begin(), "Table");
    
    int lf = food.size();
    vector<vector<string>> ans;
    ans.push_back(food);
    
    for(auto it = data.begin(); it != data.end(); it++)
    {
      vector<string> row;
      row.push_back(std::to_string(it->first));
      
      unordered_map<string, int>& food_from_table = it->second;
      
      for(int i = 1; i < lf; ++i)
      {
        int count = food_from_table.count(food[i]) > 0 ? food_from_table[food[i]] : 0;
        row.push_back(std::to_string(count));
      }
      
      ans.push_back(row);
    }
    
    return ans;
  }
};

/*
  Q: 1419. Minimum Number of Frogs Croaking - time limit exceeded!
*/
class Solution3_t
{
private:
  //Avoid using the vector<string>. Use the map instad!
  int getStringWithLastLetter(vector<string>& strs, char ch)
  {
    int pos = 0;
    for(string& s : strs)
    {
      if(s.back() == ch)
      {
        return pos;
      }
      pos++;
    }
    
    return -1;
  }
public:
  int minNumberOfFrogs(string cs) 
  {
    if(cs.size() % 5 != 0)
    {
      return -1;
    }
    
    int ans = -1;
    vector<string> strs;
    for(char ch : cs)
    {      
      int p = -1;
      switch(ch)
      {
        case 'c':
          {
            string s = "";
            s += ch;
            strs.push_back(s);
            continue;
          }
          break;
          
        case 'r':
          p = getStringWithLastLetter(strs, 'c');
          break;
          
        case 'o':
          p = getStringWithLastLetter(strs, 'r');
          break;
          
        case 'a':
          p = getStringWithLastLetter(strs, 'o');
          break;
          
        case 'k':
          p = getStringWithLastLetter(strs, 'a');
          break;
      }
      
      if(p < 0)
      {
        return -1;
      }
      
      strs[p].push_back(ch);
      if(ch == 'k')
      {
        ans = max(ans, static_cast<int>(strs.size()));
        strs.erase(strs.begin() + p); 
      }
    }
    
    return ans;
  }
};

/*
  Q: 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
*/
class Solution4_t
{
public:
    int numOfArrays(int n, int m, int k) 
    {
        
    }
};