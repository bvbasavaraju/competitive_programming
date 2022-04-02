/****************************************************
Date: July 28th

link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/
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
  Q: Task Scheduler

  You are given a char array representing tasks CPU need to do. 
  It contains capital letters A to Z where each letter represents a different task. 
  Tasks could be done without the original order of the array. Each task is done in one unit of time. 
  For each unit of time, the CPU could complete either one task or just be idle.

  However, there is a non-negative integer n that represents the cooldown period between two same tasks 
  (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

  You need to return the least number of units of times that the CPU will take to finish all the given tasks.

  Example 1:
    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    Explanation: 
      A -> B -> idle -> A -> B -> idle -> A -> B
      There is at least 2 units of time between any two same tasks.
  
  Example 2:
    Input: tasks = ["A","A","A","B","B","B"], n = 0
    Output: 6
    Explanation: On this case any permutation of size 6 would work since n = 0.
      ["A","A","A","B","B","B"]
      ["A","B","A","B","A","B"]
      ["B","B","B","A","A","A"]
      ...
      And so on.

  Example 3:
    Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
    Output: 16
    Explanation: 
      One possible solution is
      A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

  Constraints:
    The number of tasks is in the range [1, 10000].
    The integer n is in the range [0, 100].
*/

class Solution 
{
public:
  int leastInterval(vector<char>& tasks, int n) 
  {
    unordered_map<int, int> freq;
    for(auto ch : tasks)
    {
      freq[ch]++;
    }
    
    priority_queue<pair<int, int>> pq;
    for(auto f : freq)
    {
      pq.push(make_pair(f.second, f.first));
    }
    
    int ans = 0;
    int cycles = n+1; // after this count, the same task can be repeated;
    while(!pq.empty())
    {
      int task_count = 0;
      priority_queue<pair<int, int>> temp;
      for(int i = 0; i < cycles; ++i)
      {
        if(!pq.empty())
        {
          pair<int, int> data = pq.top();
          pq.pop();

          task_count++;

          data.first--;
          if(data.first > 0)
          {
            temp.push(data);
          }
        }
      }
      
      while(!temp.empty())
      {
        pq.push(temp.top());
        temp.pop();
      }
      
      ans += !pq.empty() ? cycles : task_count;
    }
    
    return ans;
  }
};