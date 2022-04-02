/****************************************************
Date: Feb 15th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3641/
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
  Q: The K Weakest Rows in a Matrix

  Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), 
  return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

  A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, 
  or they have the same number of soldiers but i is less than j. 
  Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

  Example 1:
    Input: 
      mat = 
        [[1,1,0,0,0],
        [1,1,1,1,0],
        [1,0,0,0,0],
        [1,1,0,0,0],
        [1,1,1,1,1]], 
      k = 3
    Output: [2,0,3]
    Explanation: 
      The number of soldiers for each row is: 
        row 0 -> 2 
        row 1 -> 4 
        row 2 -> 1 
        row 3 -> 2 
        row 4 -> 5 
    Rows ordered from the weakest to the strongest are [2,0,3,1,4]
  
  Example 2:
    Input: 
      mat = 
        [[1,0,0,0],
        [1,1,1,1],
        [1,0,0,0],
        [1,0,0,0]], 
      k = 2
    Output: [0,2]
    Explanation: 
      The number of soldiers for each row is: 
        row 0 -> 1 
        row 1 -> 4 
        row 2 -> 1 
        row 3 -> 1 
    Rows ordered from the weakest to the strongest are [0,2,3,1]

  Constraints:
    m == mat.length
    n == mat[i].length
    2 <= n, m <= 100
    1 <= k <= m
    matrix[i][j] is either 0 or 1.

  Hide Hint #1  
    Sort the matrix row indexes by the number of soldiers and then row indexes.
*/
class Solution 
{
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
  {
    int r = mat.size();
    int c = mat[0].size();
    
    unordered_map<int, vector<int>> strengthWithRowMap;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < r; ++i)
    {
      int strength = 0;
      for(int j = 0; j < c; ++j)
      {
        if(mat[i][j] == 0)
        {
          break;
        }
        
        strength++;
      }
      
      strengthWithRowMap[strength].push_back(i);
      if(strengthWithRowMap[strength].size() == 1)
      {
        pq.push(strength);
      }
    }
    
    vector<int> ans;
    while(k > 0)
    {
      vector<int>& rows = strengthWithRowMap[pq.top()];
      pq.pop();
      
      for(int n : rows)
      {
        ans.push_back(n);
        k--;
        if(k <= 0)
        {
          break;
        }
      }
    }
    
    return ans;
  }
};