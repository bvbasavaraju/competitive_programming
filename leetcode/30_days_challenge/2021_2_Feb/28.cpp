/****************************************************
Date: Feb 28th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3649/
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
  Q: Maximum Frequency Stack

  Implement FreqStack, a class which simulates the operation of a stack-like data structure.

  FreqStack has two functions:
    push(int x), which pushes an integer x onto the stack.
    pop(), which removes and returns the most frequent element in the stack.
      If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.

  Example 1:
    Input: 
      ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
      [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
    Output: 
      [null,null,null,null,null,null,null,5,7,5,4]
    Explanation:
      After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

      pop() -> returns 5, as 5 is the most frequent.
        The stack becomes [5,7,5,7,4].

      pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
        The stack becomes [5,7,5,4].

      pop() -> returns 5.
        The stack becomes [5,7,4].

      pop() -> returns 4.
        The stack becomes [5,7].

  Note:
    Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
    It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
    The total number of FreqStack.push calls will not exceed 10000 in a single test case.
    The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
    The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
*/

class FreqStack 
{
private:
  
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> collections;
  int count;
public:
  FreqStack() 
    : count(0)
  {
  }

  void push(int x) 
  {
    freq[x]++;
    collections[freq[x]].push(x);
    count = max(count, freq[x]);
  }

  int pop() 
  {
    int ans = collections[count].top();
    collections[count].pop();
    freq[ans]--;
    
    if(collections[count].empty())
    {
      count--;
    }
    
    return ans;
  }
};

// class FreqStack 
// {
// private:
  
//   unordered_map<int, int> freq;
//   unordered_map<int, int> freqCount;
//   stack<pair<int, int>> data;
//   int count;
// public:
//   FreqStack() 
//     : count(0)
//   {
//   }

//   void push(int x) 
//   {
//     freq[x]++;
//     data.push({x, freq[x]});
    
//     count = max(count, freq[x]);
//     freqCount[freq[x]]++;
//   }

//   int pop() 
//   {
//     stack<pair<int, int>> temp;
    
//     int ans;
//     while(!data.empty())
//     {
//       pair<int, int> d = data.top();
//       data.pop();
      
//       if(d.second == count)
//       {
//         ans = d.first;
//         freq[ans]--;
//         freqCount[count]--;
//         if(freqCount[count] <= 0)
//         {
//           count--;
//         }
//         break;
//       }
//       else
//       {
//         temp.push(d);
//       }
//     }
    
//     while(!temp.empty())
//     {
//       data.push(temp.top());
//       temp.pop();
//     }
    
//     return ans;
//   }
// };

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */