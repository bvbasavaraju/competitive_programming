/****************************************************
Date: Jan 26th

link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3616/
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
  Q: Path With Minimum Effort

  You are a hiker preparing for an upcoming hike. You are given heights, 
  a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). 
  You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
  You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

  A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
  Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

  Example 1:
    Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
    Output: 2
    Explanation: 
      The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
      This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

  Example 2:
    Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
    Output: 1
    Explanation: 
      The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

  Example 3:
    Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
    Output: 0
    Explanation: 
      This route does not require any effort.

  Constraints:
    rows == heights.length
    columns == heights[i].length
    1 <= rows, columns <= 100
    1 <= heights[i][j] <= 106
 
  Hide Hint #1  
    Consider the grid as a graph, where adjacent cells have an edge with cost of the difference between the cells.
  Hide Hint #2  
    If you are given threshold k, check if it is possible to go from (0, 0) to (n-1, m-1) using only edges of ≤ k cost.
  Hide Hint #3  
    Binary search the k value.
*/
class Solution 
{  
private:
  struct TreeNode
  {
    int x;
    int y;
    int effort;
    
    TreeNode(int x_, int y_, int e_) : x(x_), y(y_), effort(e_) {};
  };
  
public:
  int minimumEffortPath(vector<vector<int>>& heights) 
  {
    int row = heights.size();
    int col = heights[0].size();
    
    vector<vector<long long>> effort(row, vector<long long>(col, INT_MAX));
    effort[0][0] = 0;
    
    TreeNode* node = new TreeNode(0,0,0);
    auto comp = [](const TreeNode* n1, const TreeNode* n2) { return (n1->effort >= n2->effort); };
    priority_queue<TreeNode*, vector<TreeNode*>, decltype(comp) > pq(comp);
    
    pq.push(node);
    vector<pair<int, int>> paths = {{-1,0}, {0, -1}, {0, 1}, {1, 0}};
    
    while(!pq.empty())
    {
      TreeNode* n = pq.top();
      pq.pop();
      
      
      if(n->x >= row && n->y >= col)
      {
        break;
      }
      for(int p = 0; p < 4; ++p)
      {
        int xn = n->x + paths[p].first;
        int yn = n->y + paths[p].second;
        
        if(xn < 0 || yn < 0 || xn >= row || yn >= col)
        {
          continue;
        }
        
        long long diff = abs(heights[n->x][n->y] - heights[xn][yn]);
        
        int new_effort = max(effort[n->x][n->y], diff);
        if(new_effort < effort[xn][yn])
        {
          effort[xn][yn] = new_effort;
          TreeNode* node_ = new TreeNode(xn,yn,new_effort);
          pq.push(node_);
        }
      }
    }
    
    return effort[row-1][col-1];
  }
};