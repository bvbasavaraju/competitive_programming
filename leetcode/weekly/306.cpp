/****************************************************
Date: August 14th, 2022
Successful submissions : 2
Successful submissions after timeout : 1
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-306
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2373. Largest Local Values in a Matrix
*/
class Solution1_t
{
private:
  int getMax(vector<vector<int>>& grid, int rs, int cs, int re, int ce)
  {
    int maxi = 0;
    for(int i = rs; i <= re; ++i)
    {
      for(int j = cs; j <= ce; ++j)
      {
        maxi = max(maxi, grid[i][j]);
      }
    }
    
    return maxi;
  }
public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
  {
    int r = grid.size();
    int c = grid[0].size();
    
    vector<vector<int>> ans(r-2, vector<int>(c-2, 0));
    for(int i = 1 ; i < r-1; ++i)
    {
      for(int j = 1; j < c-1; ++j)
      {
        ans[i-1][j-1] = getMax(grid, i-1, j-1, i+1, j+1);
      }
    }
    
    return ans;
  }
};

/*
  Q: 2374. Node With Highest Edge Score
*/
class Solution2_t
{
public:
  int edgeScore(vector<int>& edges) 
  {
    int l = edges.size();
    
    vector<long long> score(l, 0);
    for(int i = 0; i < l; ++i)
    {
      score[edges[i]] += i;
    }
    
    std::pair<long long, int> ans = {INT_MIN, -1};  // score && index
    for(int i = 0; i < l; ++i)
    {
      if((score[i] > ans.first) || ((score[i] == ans.first) && (i < ans.second)))
      {
        ans = {score[i], i};
      }
    }
    
    return ans.second;
  }
};

/*
  Q: 2375. Construct Smallest Number From DI String - before I could complete it was timed out. But, solved without looking at solution!!
*/
class Solution3_t
{
private:  
  bool isValid(const string& pattern, int pos, const string& possible)
  {
    bool ans = false; 
    if(pos == 0)
    {
      if(pattern[pos] == 'I')
      {
        ans = (possible[pos] - '0') < 9;
      }
      else
      {
        ans =  (possible[pos] - '0') > 1;
      }
    }
    else
    {
      if(pattern[pos-1] == 'I')
      {
        ans =  (possible[pos] - '0') > (possible[pos-1] - '0');
      }
      else
      {
        ans =  (possible[pos] - '0') < (possible[pos-1] - '0');
      }
    }
    
    return ans;
  }
  
  void getAllPossible(const string& pattern, int pos, vector<bool>& used, string possible, vector<string>& ans)
  {
    if(pos >= pattern.size())
    {
      if(possible.size() != pattern.size())
      {
        return;
      }

      for(int i = 1; i <= 9; ++i)
      {
        if(used[i])
        {
          continue;
        }
        
        used[i] = true;
        possible += (i + '0');
        if(isValid(pattern, pos, possible))
        {
          ans.push_back(possible);
        }
        possible.pop_back();
        used[i] = false;
      }

      return;
    }
    
    for(int i = 1; i <= 9; ++i)
    {
      if(used[i])
      {
        continue;
      }
      
      used[i] = true;
      possible += (i + '0');
      if(isValid(pattern, pos, possible))
      {
        getAllPossible(pattern, pos+1, used, possible, ans);
      }
      possible.pop_back();
      used[i] = false;
    }
  }
  
  void getMinPossible(const string& pattern, int pos, vector<bool>& used, string possible, string& ans)
  {
    if(pos >= pattern.size())
    {
      if(possible.size() != pattern.size())
      {
        return;
      }

      for(int i = 1; i <= 9; ++i)
      {
        if(used[i])
        {
          continue;
        }
        
        used[i] = true;
        possible += (i + '0');
        if(isValid(pattern, pos, possible))
        {
          ans = min(ans, possible);
        }
        possible.pop_back();
        used[i] = false;
      }

      return;
    }
    
    for(int i = 1; i <= 9; ++i)
    {
      if(used[i])
      {
        continue;
      }
      
      used[i] = true;
      possible += (i + '0');
      if(isValid(pattern, pos, possible))
      {
        getMinPossible(pattern, pos+1, used, possible, ans);
      }
      possible.pop_back();
      used[i] = false;
    }
  }
  
public:
  string smallestNumber(string pattern) 
  {
    vector<bool> used(10, false);
    
    //Fastest
    string ans = "99999999999999999999999";
    getMinPossible(pattern, 0, used, "", ans);
    
    // Little solwer ans I have to go through each entry of the all combinations!!
//     vector<string> allCombs;
//     getAllPossible(pattern, 0, used, "", allCombs);
    
//     string ans = "9999999999999999";
//     for(string s : allCombs)
//     {
//       ans = min(ans, s);
//     }
    
    return ans;
  }
};

/*
  Q: 2376. Count Special Integers
*/
class Solution4_t
{
public:
  int countSpecialNumbers(int n) 
  {
      
  }
};