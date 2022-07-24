/****************************************************
Date: July 24th, 2022
Successful submissions : 3
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-303
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2351. First Letter to Appear Twice
*/
class Solution1_t
{
public:
  char repeatedCharacter(string s) 
  {
    unordered_map<char, int> freq;
    
    char ans = 0;
    for(char ch : s)
    {
      freq[ch]++;
      if(freq[ch] == 2)
      {
        ans = ch;
        break;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2352. Equal Row and Column Pairs
*/
class Solution2_t
{
public:
  int equalPairs(vector<vector<int>>& grid) 
  {
    int r = grid.size();
    int c = grid[0].size();
    
    int ans = 0;
    for(int i = 0; i < r; ++i)
    {
      vector<int>& row = grid[i];
      
      for(int j = 0; j < c; ++j)
      {
        bool matches = true;
        //vector<int> col;
        
        for(int p = 0, q = 0; (p < r) && (q < c); ++p, ++q)
        {
          //col.push_back(grid[p][j]);
          if(grid[p][j] != row[q])
          {
            matches = false;
            break;
          }
        }
        
        if(matches)
        //if(col == row)
        {
          ans++;
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 2353. Design a Food Rating System
*/
class FoodRatings 
{
private:
  
  struct compare 
  {
    bool operator()(const pair<int, string>& p1, const pair<int, string>& p2) const 
    {
      return (p1.first > p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
    }
  };
  
  unordered_map<string, string> fc;
  unordered_map<string, set<pair<int, string>, compare> > crf;
  unordered_map<string, int> fr;
  

public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
  {
    int l = foods.size();
    for(int i = 0; i < l; ++i)
    {
      fc[foods[i]] = cuisines[i];
      
      pair<int, string> rf = {ratings[i], foods[i]};
      
      crf[cuisines[i]].insert(rf);
      
      fr[foods[i]] = ratings[i];
    }
  }
    
  void changeRating(string food, int newRating) 
  {
    string c = fc[food];
    
    pair<int, string> p = {fr[food], food};
    
    crf[c].erase(p);
    
    crf[c].insert({newRating, food});
    
    fr[food] = newRating;
  }

  string highestRated(string cuisine) 
  {
    return crf[cuisine].begin()->second;
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

/*
  Q: 2354. Number of Excellent Pairs - approach is correct but the logic needs a fix in i and j loop!!
*/

class Solution4_t
{
public:
  long long countExcellentPairs(vector<int>& nums, int k) 
  {
    vector<set<int>> bitCount(33);
    for(int n : nums)
    {
      int c = std::__builtin_popcount[n];
      
      bitCount[c].insert(n);
    }
    
    long long ans = 0;
    for(int i = 0; i < 33; ++i)
    {
      int v = (i&i) + (i|i);
      if(val >= k)
      {
        ans = ans + (bitCount[i].size() * bitCount[i].size());
      }
      
      for(int j = 0; j < i; ++j)
      {
        int val = (i&j) + (i|j);
        if(val >= k)
        {
          ans = ans + (bitCount[i].size() * bitCount[j].size());
        }
      }
    }
    
    return ans;
  }
};