/****************************************************
Date: June 4th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3764/
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
  Q: Open the Lock

  You have a lock in front of you with 4 circular wheels. 
  Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
  The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. 
  Each move consists of turning one wheel one slot.

  The lock initially starts at '0000', a string representing the state of the 4 wheels.

  You are given a list of deadends dead ends, meaning if the lock displays any of these codes, 
  the wheels of the lock will stop turning and you will be unable to open it.

  Given a target representing the value of the wheels that will unlock the lock, 
  return the minimum total number of turns required to open the lock, or -1 if it is impossible.

  Example 1:
    Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
    Output: 6
    Explanation:
      A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
      Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
      because the wheels of the lock become stuck after the display becomes the dead end "0102".

  Example 2:
    Input: deadends = ["8888"], target = "0009"
    Output: 1
    Explanation:
      We can turn the last wheel in reverse to move from "0000" -> "0009".

  Example 3:
    Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
    Output: -1
    Explanation:
      We can't reach the target without getting stuck.

  Example 4:
    Input: deadends = ["0000"], target = "8888"
    Output: -1

  Constraints:
    1 <= deadends.length <= 500
    deadends[i].length == 4
    target.length == 4
    target will not be in the list deadends.
    target and deadends[i] consist of digits only.

  Hide Hint #1  
    We can think of this problem as a shortest path problem on a graph: 
    there are `10000` nodes (strings `'0000'` to `'9999'`), 
    and there is an edge between two nodes if they differ in one digit, 
    that digit differs by 1 (wrapping around, so `'0'` and `'9'` differ by 1), 
    and if *both* nodes are not in `deadends`.
*/

class Solution 
{
private:
  void getCombs(const string& str, vector<string>& combs)
  {
    for(int i = 0; i < 4; ++i)
    {
      string temp = str;
      temp[i] = (str[i] - '0' + 1) % 10 + '0';
      combs.push_back(temp);
      temp[i] = (str[i] - '0' - 1 + 10) % 10 + '0';
      combs.push_back(temp);
    }
  }
public:
  int openLock(vector<string>& deadends, string target) 
  {
    unordered_set<string> dead;
    for(auto d : deadends)
    {
      dead.insert(d);
    }
    
    if((dead.find(target) != dead.end()) || (dead.find("0000") != dead.end()))
    {
      return -1;
    }
    if(target == "0000")
    {
      return 0;
    }
    
    int ans = 0;
    unordered_set<string> visited;
    queue<string> possible;
    
    visited.insert("0000");
    possible.push("0000");
    
    while(!possible.empty())
    {
      int count = possible.size();
      for(int i = 0; i < count; ++i)
      {
        string temp = possible.front();
        possible.pop();

        vector<string> combs;
        getCombs(temp, combs);
        for(string& comb : combs)
        {
          if(target == comb)
          {
            return ++ans;
          }
          else if(visited.find(comb) != visited.end())
          {
            continue;
          }
          else if(dead.find(comb) == dead.end())
          {
            possible.push(comb);
            visited.insert(comb);
          }
        }
      }
      
      ans++;
    }
    
    return -1;
  }
};