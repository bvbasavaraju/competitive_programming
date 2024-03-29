/****************************************************
Date: May 30rd, 2021
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-243
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
  Q: 1880. Check if Word Equals Summation of Two Words
*/
class Solution1_t
{
private:
  int getSum(const string& word)
  {
    int sum = 0;
    for(char ch : word)
    {
      sum = (sum * 10) + (ch - 'a');
    }
    
    return sum;
  }
public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) 
  {
    return (getSum(firstWord) + getSum(secondWord) == getSum(targetWord));
  }
};

/*
  Q: 1881. Maximum Value after Insertion
*/
class Solution2_t
{
public:
  string maxValue(string n, int x) 
  {
    bool isNegative = (n[0] == '-');
    
    string ans = "";
    int l = n.size();
    for(int i = 0; i < l; ++i)
    {
      if(isNegative)
      {
        if(x < (n[i]-'0'))
        {
          ans = n.substr(0,i) + std::to_string(x) + n.substr(i);
          break;
        }
      }
      else
      {
        if(x > (n[i] - '0'))
        {
          ans = n.substr(0,i) + std::to_string(x) + n.substr(i);
          break;
        }
      }
    }
    
    if(ans.size() == 0)
    {
      ans = n + std::to_string(x);
    }
    
    return ans;
  }
};

/*
  Q: 1882. Process Tasks Using Servers - wrong answer. Need to complete.
*/
class Solution3_t
{
  struct compWeight
  {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
    {
      return (p1.first > p2.first) || ((p1.first == p2.first) && p1.second > p2.second);
    }
  };
  
  struct compTime
  {
    bool operator()(const pair<int, pair<int, int> >& p1, const pair<int, pair<int, int> >& p2)
    {
      if(p1.second.second > p2.second.second)
      {
        return true;
      }
      else if(p1.second.second == p2.second.second)
      {
        if(p1.first > p2.first)
        {
          return true;
        }
        else if(p1.first == p2.first)
        {
          return p1.second.first > p2.second.first;
        }
      }

      return false;
    }
  };
  
public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) 
  {
    priority_queue< pair<int, int>, vector< pair<int, int> >, compWeight > ser;
    priority_queue< pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, compTime > busy;
    
    int tl = tasks.size();
    vector<int> ans(tl);
    
    int i = 0;
    for(int n : servers)
    {
      ser.push(std::make_pair(n, i++));
    }
    
    int mt = 0;
    for(i = 0; i < tl; ++i)
    {
      if(!ser.empty())
      {
        ans[i] = ser.top().second;
        busy.push(make_pair(ser.top().first, make_pair(ser.top().second, mt + tasks[i])));
        ser.pop();
      }

      mt++;
      if(!busy.empty())
      {
        if(busy.top().second.second <= mt)
        {
          ser.push(make_pair(busy.top().first, busy.top().second.first));
          busy.pop();
        }
        
        while(ser.empty())
        {
          mt++;
          
          if(busy.top().second.second >= mt)
          {
            ser.push(make_pair(busy.top().first, busy.top().second.first));
            break;
          }
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1883. Minimum Skips to Arrive at Meeting On Time
*/
class Solution4_t 
{
public:
  int minSkips(vector<int>& dist, int speed, int hoursBefore) 
  {
      
  }
};

int main()
{
  Solution3_t s3;
  vector<int> v1 = {3,3,2};
  vector<int> v2 = {1,2,3,2,1,2};

  s3.assignTasks(v1, v2);

  return 0;
}