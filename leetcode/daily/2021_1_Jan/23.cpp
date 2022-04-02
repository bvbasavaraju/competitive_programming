/****************************************************
Date: Jan 23th

link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3613/
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
  Q: Sort the Matrix Diagonally

  A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and 
  going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], 
  where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

  Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

  Example 1:
    Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
    Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

  Constraints:
    m == mat.length
    n == mat[i].length
    1 <= m, n <= 100
    1 <= mat[i][j] <= 100

  Hide Hint #1  
    Use a data structure to store all values of each diagonal.
  Hide Hint #2  
    How to index the data structure with the id of the diagonal?
  Hide Hint #3  
    All cells in the same diagonal (i,j) have the same difference so we can get the diagonal of a cell using the difference i-j.
*/
class Solution 
{
private:
  void getDiagonalAndSort(const vector<vector<int>>& mat, int r, int c, int rows, int cols, vector<int>& diag)
  {
    if(r >= rows || c >= cols)
    {
      sort(diag.begin(), diag.end());
      return;
    }
    
    diag.push_back(mat[r][c]);
    getDiagonalAndSort(mat, r+1, c+1, rows, cols, diag);
  }
  
  void fillDiagonal(const vector<int>& diag, int p, int r, int c, int rows, int cols, vector<vector<int>>& ans)
  {
    if(r >= rows || c >= cols || p >= diag.size())
    {
      return;
    }
    
    ans[r][c] = diag[p];
    fillDiagonal(diag, p+1, r+1, c+1, rows, cols, ans);
  }
  
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
  {
    int rows = mat.size();
    int cols = mat[0].size();
    
    vector<vector<int>> ans(rows, vector<int>(cols, 0));
    for(int i = cols-1; i >= 0; --i)
    {
      vector<int> diag;
      getDiagonalAndSort(mat, 0, i, rows, cols, diag);
      fillDiagonal(diag, 0, 0, i, rows, cols, ans);
    }
    
    for(int i = 1; i < rows; ++i)
    {
      vector<int> diag;
      getDiagonalAndSort(mat, i, 0, rows, cols, diag);
      fillDiagonal(diag, 0, i, 0, rows, cols, ans);
    }
    
    return ans;
  }
};