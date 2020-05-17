/****************************************************
Date: May 17th, 2020
Successful submissions : 2
Time expiration : 1
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-189
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
  Q: 1450. Number of Students Doing Homework at a Given Time
*/
class Solution1_t
{
public:
  int busyStudent(vector<int>& st, vector<int>& et, int qt) 
  {
    int ans = 0;
    int l = st.size();
    for(int i = 0; i < l; ++i)
    {
      if(st[i] <= qt && et[i] >= qt)
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1451. Rearrange Words in a Sentence
*/
class Solution2_t
{
public:
  string arrangeWords(string text) 
  {
    map< int, vector<string> > len_strings_map;
    
    int l = text.size();
    for(int i = 0; i < l;)
    {
      size_t pos = text.find_first_of(' ', i);
      
      if(pos == std::string::npos)
      {
        pos = l;
      }
      
      int sub_str_l = pos - i;
      len_strings_map[sub_str_l].push_back(text.substr(i, sub_str_l));
      
      i = (pos + 1);
    }
    
    string ans = "";
    for(auto it = len_strings_map.begin(); it != len_strings_map.end(); ++it)
    {
      for(string s : it->second)
      {
        if(ans.empty())
        {
          if(s[0] >= 'a' && s[0] <= 'z')
          {
            s[0] = s[0] - 32;
          }
        }
        else
        {
          if(s[0] >= 'A' && s[0] <= 'Z')
          {
            s[0] = s[0] + 32;
          }
        }
        
        ans += s;
        ans += " ";
      }
    }
    
    ans.pop_back();
    
    return ans;
  }
};

/*
  Q: 1452. People Whose List of Favorite Companies Is Not a Subset of Another List
*/
class Solution3_t
{
public:
  vector<int> peopleIndexes(vector<vector<string>>& favComps) 
  {
    unordered_map<int, unordered_set<string>> sets_of_comps;
    
    int pos = 0;
    for(vector<string>& vs : favComps)
    {
      unordered_set<string> comps;
      for(string& comp : vs)
      {
        comps.insert(comp);
      }
      
      sets_of_comps[pos++] = comps;
    }
    
    vector<int> ans;
    for(auto it = sets_of_comps.begin(); it != sets_of_comps.end(); ++it)
    {
      bool found = false;
      unordered_set<string> comps = it->second;
      
      // auto it_backup = it;
      // it++;
      for(auto it2 = sets_of_comps.begin(); it2 != sets_of_comps.end(); ++it2)
      {
        if(it2->first == it->first || it2->second.size() < comps.size())
        {
          continue;
        }
        
        int found_count = 0;
        for(string comp : comps)
        {
          if(it2->second.find(comp) != it2->second.end())
          {
            found_count++;
          }
        }
        
        if(found_count == comps.size())
        {
          found = true;
          break;
        }
      }
      
      // it = it_backup;
      if(!found)
      {
        ans.push_back(it->first);
      }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
  }
};

/*
  Q: 1453. Maximum Number of Darts Inside of a Circular Dartboard
*/
class Solution4_t
{
public:
  int numPoints(vector<vector<int>>& points, int r) 
  {
      
  }
};

int main()
{
  // {
  //   Solution s;
  //   vector<vector<string>> data = {{"leetcode","google","facebook"},{"leetcode","amazon"},{"facebook","google"}};
  //   vector<int> r = s.peopleIndexes(data);
  // }
  {
    Solution3_t s;
    vector<vector<string>> data = {{"nxaqhyoprhlhvhyojanr","ovqdyfqmlpxapbjwtssm","qmsbphxzmnvflrwyvxlc","udfuxjdxkxwqnqvgjjsp","yawoixzhsdkaaauramvg","zycidpyopumzgdpamnty"},{"nxaqhyoprhlhvhyojanr","ovqdyfqmlpxapbjwtssm","udfuxjdxkxwqnqvgjjsp","yawoixzhsdkaaauramvg","zycidpyopumzgdpamnty"},{"ovqdyfqmlpxapbjwtssm","qmsbphxzmnvflrwyvxlc","udfuxjdxkxwqnqvgjjsp","yawoixzhsdkaaauramvg","zycidpyopumzgdpamnty"}};
    vector<int> r = s.peopleIndexes(data);
  }
}