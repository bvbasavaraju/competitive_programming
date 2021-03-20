/****************************************************
Date: March 19th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3673/
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
  Q: Keys and Rooms

  There are N rooms and you start in room 0.  
  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 

  Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an 
  integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.

  Initially, all the rooms start locked (except for room 0). 
  You can walk back and forth between rooms freely.
  Return true if and only if you can enter every room.

  Example 1:
    Input: [[1],[2],[3],[]]
    Output: true
    Explanation:  
      We start in room 0, and pick up key 1.
      We then go to room 1, and pick up key 2.
      We then go to room 2, and pick up key 3.
      We then go to room 3.  Since we were able to go to every room, we return true.

  Example 2:
    Input: [[1,3],[3,0,1],[2],[0]]
    Output: false
    Explanation: 
      We can't enter the room with number 2.

  Note:
    1 <= rooms.length <= 1000
    0 <= rooms[i].length <= 1000
    The number of keys in all rooms combined is at most 3000.
*/
class Solution 
{
private:
  void visitRooms(vector<vector<int>>& rooms, int num, vector<bool>& visited)
  {
    if(num >= rooms.size())
    {
      return;
    }
    
    visited[num] = true;
    for(int i = 0; i < rooms[num].size(); ++i)
    {
      if(!visited[rooms[num][i]])
      {
        visitRooms(rooms, rooms[num][i], visited);
      }
    }
  }
  
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) 
  {
    int l = rooms.size();
    
    vector<bool> visited(l, false);
    visitRooms(rooms, 0, visited);
    
    for(bool v : visited)
    {
      if(v == false)
      {
        return false;
      }
    }
    
    return true;
//     int reqKey = 1;
    
//     int l = rooms.size();
//     for(int i = 0; i < l-1; ++i)
//     {
//       vector<int>& keysCollection = rooms[i];
//       unordered_set<int> keys;
//       for(int k : keysCollection)
//       {
//         keys.insert(k);
//       }
      
//       if(keys.find(reqKey) == keys.end())
//       {
//         return false;
//       }
      
//       reqKey++;
//     }
    
//     return true;
  }
};