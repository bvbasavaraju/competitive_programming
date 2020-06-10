/****************************************************
Date: June 7th, 2020
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-192
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
  Q: 1470. Shuffle the Array
*/
class Solution1_t
{
public:
  vector<int> shuffle(vector<int>& nums, int n) 
  {
    int l = nums.size();
    
    vector<int> ans(l);
    for(int i = 0, j = 0; i < l && j < n; ++i, ++j)
    {
      ans[i] = nums[j];
      ans[i+1] = nums[j+n];
      
      i++;
    }
    
    return ans;
  }
};

/*
  Q: 1471. The k Strongest Values in an Array
*/
class Solution2_t
{
public:
  vector<int> getStrongest(vector<int>& arr, int k) 
  {
    sort(arr.begin(), arr.end());
    
    int m = arr[(arr.size() - 1) / 2];
    
    int l = arr.size();
    vector<int> ans(k);
    for(int i = 0, j = l-1, p = 0; i <= j /*l && j >= 0*/ && p < k; ++p)
    {
      if(abs(arr[j] - m) == abs(arr[i] - m))
      {
        if(arr[j] >= arr[i])
        {
          ans[p] = arr[j];
          j--;
        }
        else
        {
          ans[p] = arr[i];
          i++;
        }
      }
      else if(abs(arr[j] - m) > abs(arr[i] - m))
      {
        ans[p] = arr[j];
        j--;
      }
      else
      {
        ans[p] = arr[i];
        i++;
      }
    }
    
    return ans;
    /* even below logic works but time will expire.
    sort(arr.begin(), arr.end(), [m](int n1, int n2) -> bool 
         { 
           bool swap = false;
           
           if((abs(n1 - m) > abs(n2 - m)) || ((abs(n1 - m) == abs(n2 - m)) && (n1 > n2)))
           {
             swap = true;
           }
           
           return swap;
         } );
    
    vector<int> ans(k);
    for(int i = 0; i < k; ++i)
    {
      ans[i] = arr[i];
    }
    
    return ans;*/
    /*vector<int> ans = arr;
    while(ans.size() > k)
    {
      ans.pop_back();
    }
    
    return ans;*/
  }
};

/*
  Q: 1472. Design Browser History
*/
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
class BrowserHistory_t
{
private:
  int curr_pos;
  vector<string> urls;
public:
  BrowserHistory_t(string homepage)
  {
    urls.push_back(homepage);
    curr_pos = 0;
  }

  void visit(string url) 
  {
    int l = urls.size();
    while(l - 1 > curr_pos)
    {
      urls.pop_back();
      l--;
    }
    
    urls.push_back(url);
    curr_pos = urls.size() - 1;
  }

  string back(int steps) 
  {
    int l = urls.size();
    if(curr_pos == l - 1)
    {
      int diff = (l - steps);
      curr_pos = diff > 0 ? diff - 1 : 0;
    }
    else
    {
      int diff = curr_pos - steps;
      curr_pos = diff > 0 ? diff : 0;
    }
    
    return urls[curr_pos];
  }

  string forward(int steps) 
  {
    int l = urls.size();
    if(curr_pos < l - 1)
    {
      curr_pos = ((curr_pos + steps) < l) ? (curr_pos + steps)  : l - 1;
    }
    
    return urls[curr_pos];
  }
};

/*
  Q: 1473. Paint House III
*/
class Solution4_t
{
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        
    }
};