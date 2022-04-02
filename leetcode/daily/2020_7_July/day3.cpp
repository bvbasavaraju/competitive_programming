/****************************************************
Date: July 3rd

link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
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
  Q: Prison Cells After N Days

  There are 8 prison cells in a row, and each cell is either occupied or vacant.
  
  Each day, whether the cell is occupied or vacant changes according to the following rules:
    + If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
    + Otherwise, it becomes vacant.
  
  (Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

  We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, 
  else cells[i] == 0.
  Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

  Example 1:
    Input: cells = [0,1,0,1,1,0,0,1], N = 7
    Output: [0,0,1,1,0,0,0,0]
    Explanation: 
      The following table summarizes the state of the prison on each day:
      Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
      Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
      Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
      Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
      Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
      Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
      Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
      Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

  Example 2:
    Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
    Output: [0,0,1,1,1,1,1,0]
    
  Note:
    cells.length == 8
    cells[i] is in {0, 1}
    1 <= N <= 10^9
*/

class Solution 
{
public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) 
  {
    int prev,curr,next;
    
    N=N%14;
    if(N==0)
    {
      N=14;
    }
    
    prev=cells[0];curr=cells[1];next=cells[2];
    
    for(int i=0;i<N;i++)
    {	 
      for(int j=1;j<7;j++)
      {
        next=cells[j+1];curr=cells[j];
        if(j==1&&i>0) 
        {
          prev=0;
        }
        if(prev == next)
        {
          cells[j]=1;
        }
        else
        { 
          cells[j]=0;
        }
        prev=curr;
      }
      cells[0]=0;
      cells[7]=0;                       
    }
    return cells;
  }
};