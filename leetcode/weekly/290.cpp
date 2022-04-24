/****************************************************
Date: April 24th, 2022
Successful submissions : 1
Time expiration : 1
Memory exhausted : 0
Not Solved : 0
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/weekly-contest-290
****************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
  Q: 2248. Intersection of Multiple Arrays - correct answer
*/
class Solution1_t
{
public:
  vector<int> intersection(vector<vector<int>>& nums) 
  {
    int l = nums.size();
    map<int, int> freq;
    
    for(vector<int> nums_ : nums)
    {
      for(int n : nums_)
      {
        freq[n]++;
      }
    }
    
    vector<int> ans;
    for(auto it : freq)
    {
      if(it.second == l)
      {
        ans.push_back(it.first);
      }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
  }
};

/*
  Q: 2249. Count Lattice Points Inside a Circle - partial result
*/
class Solution2_t
{
private:
  bool isInside(const vector<int>& c, const vector<int>& p)
  {
    if((p[0] <= (c[0] + c[2])) && (p[0] >= (c[0] - c[2])) && (p[1] <= (c[1] + c[2])) && (p[1] >= (c[1] - c[2])))  
    {
      return true;
    }
    
    return false;
  }
  
public:
  int countLatticePoints(vector<vector<int>>& circles) 
  {
    unordered_set<pair<int, int>> ans;
    
    vector<pair<int, int>> points{{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
    for(vector<int>& c : circles)
    {
      int r = c[2];
      vector<int> o = {c[0], c[1]};
      
      ans.insert(make_pair(o[0], o[1]));
      for(int i = 1; i <= r; ++i)
      {
        for(pair<int, int> p : points)
        {
          vector<int> np = {o[0]+i+p.first, o[1]+i+p.second};
          if(isInside(c, np))
          {
            ans.insert(make_pair(np[0], np[1]));
          }
        }
      }
    }
    
    return ans.size();
  }
};

/*
  Q: 2250. Count Number of Rectangles Containing Each Point - partial result
*/
class Solution3_t
{
private:
  int getPos(const vector< vector<int> >& r, const vector<int>& p)
  {
    int l = 0;
    int h = r.size()-1;
    
    int ans = -1;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      const vector<int>& r_ = r[m];
      if(p[0] <= r_[0] && p[1] <= r_[1])
      {
        ans = m;
        l = m+1;
      }
      else
      {
        h = m-1;
      }
    }
    
    return ans;
  }
public:
  vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) 
  {
    sort(rectangles.begin(), rectangles.end(), [](const vector<int>& p1, const vector<int>& p2) -> bool
         {
           return ((p1[0] > p2[0]) || ((p1[0] == p2[0]) && (p1[1] > p2[1])));
         });
    
    
    vector<int> ans;
    for(vector<int> p : points)
    {
      int pos = getPos(rectangles, p);
      ans.push_back(pos >= 0 ? pos + 1 : 0);
    }
    
    return ans;
  }
};

/*
  Q: 2251. Number of Flowers in Full Bloom - TLE
*/
class Solution4_t
{
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) 
  {
    unordered_map<int, int> count;
    
    for(vector<int>& f_ : f)
    {
      for(int i = f_[0]; i <= f_[1]; ++i)
      {
        count[i]++;
      }
    }
    
    vector<int> ans;
    for(int t : p)
    {
      ans.push_back(count[t]);
    }
    
    return ans;
  }
};