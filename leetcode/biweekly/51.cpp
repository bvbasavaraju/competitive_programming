/****************************************************
Date: May 1st, 2021
Successful submissions : 3
Time expiration : 0
Not Solved : 0
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-51
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
  Q: 1844. Replace All Digits with Characters
*/
class Solution1_t
{
public:
  string replaceDigits(string s) 
  {
    int l = s.size();
    for(int i = 1; i < l; i+=2)
    {
      char ch = s[i-1] + (s[i]-'0');
      if(ch > 'z')
      {
        s[i] = 'a' + (ch - 'z' - 1);
      }
      else
      {
        s[i] = ch;
      }
    }
    
    return s;
  }
};

/*
  Q: 1845. Seat Reservation Manager
*/

class SeatManager 
{
private:
  priority_queue<int, vector<int>, greater<int> > pq;
public:
  SeatManager(int n) 
  {
    for(int i = 1; i <= n; ++i)
    {
      pq.push(i);
    }
  }

  int reserve() 
  {
    int ans = pq.top();
    
    pq.pop();
    return ans;
  }

  void unreserve(int seatNumber) 
  {
    pq.push(seatNumber);
  }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

/*
  Q: 1846. Maximum Element After Decreasing and Rearranging
*/
class Solution3_t
{
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
  {
    sort(arr.begin(), arr.end());
    
    int l = arr.size();
    if(arr[0] != 1)
    {
      arr[0] = 1;
    }
    
    for(int i = 1; i < l; ++i)
    {
      if(abs(arr[i] - arr[i-1]) > 1)
      {
        arr[i] = arr[i-1] + 1;
      }
    }
    
    return arr[l-1];
  }
};

/*
  Q: 1847. Closest Room - wrong answer
*/
class Solution4_t
{
public:
  vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) 
  {
    unordered_map<int, vector< pair<int, int> > > data;
    
    int i = 0;
    for(vector<int>& r : rooms)
    {
      data[r[1]].push_back({r[0], i});
      i++;
    }
    
    vector<int> ans;
    for(vector<int>& q : queries)
    {
      if(data.count(q[1]) > 0)
      {
        vector< pair<int, int> >& data_ = data[q[1]];
        
        int mini = INT_MAX;
        int index = -1;
        for(auto& p : data_)
        {
          if(abs(p.first - q[0]) <= mini)
          {
            index = p.second;
            mini = p.first - q[0];
          }
        }
        
        ans.push_back(index);
      }
      else
      {
        ans.push_back(-1);
      }
    }
    
    return ans;
  }
};