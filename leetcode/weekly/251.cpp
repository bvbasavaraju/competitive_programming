/****************************************************
Date: July 25th, 2021
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-251
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: 1945. Sum of Digits of String After Convert
*/
class Solution1_t
{
public:
  int getLucky(string s, int k) 
  {    
    int l = s.size();
    string sAsNums = "";
    for(int i = 0; i < l; ++i)
    {
      sAsNums += "" + std::to_string(s[i] - 'a' + 1);
    }
    
    int ans = 0;
    while(k > 0)
    {
      for(char ch : sAsNums)
      {
        ans += (ch - '0');
      }
      
      k--;
      sAsNums = std::to_string(ans);
      if(k > 0)
      {
        ans = 0;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1946. Largest Number After Mutating Substring
*/
class Solution2_t
{
public:
  string maximumNumber(string num, vector<int>& change) 
  {
    int l = num.size();
    string maxPos = num;
    for(char& ch : maxPos)
    {
      int i = ch - '0';
      ch = max(i, change[i]) + '0';
    }
    
    string ans = num;
    bool changed = false;
    for(int i = 0; i < l; ++i)
    {
      if(maxPos[i] == num[i])
      {
        if((change[num[i]-'0'] != num[i]-'0') && (changed))
        {
          break;
        }
        else
        {
          continue;
        }
      }
      
      changed = true;
      ans[i] = maxPos[i];
    }
    
    return ans;
  }
};

/*
  Q: 1947. Maximum Compatibility Score Sum - yet to complete
*/
class Solution3_t
{
private:
  struct ScoreInVal_t
  {
    
  };
  
  void GetVal(const vector<vector<int>>& bits_array, vector<int>& val_array)
  {
    for(vector<int>& bits : bits_array)
    {
      int val = 0;
      for(int b : bits)
      {
        val <<= 1;
        val |= b;
      }
      val_array.push_back(val);
    }
  }
    
public:
  int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) 
  {
    int q_count = mentors[0].size();
    int mask = 0;
    for(int i = 0; i < q_count; ++i)
    {
      mask <<= 1;
      mask |= 1;
    }
    
    vector<int> s_val;
    GetVal(students, s_val);
    
    vector<int> m_val;
    GetVal(students, m_val);    
  }
};

/*
  Q: 1948. Delete Duplicate Folders in System
*/
class Solution4_t
{
public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) 
  {
      
  }
};