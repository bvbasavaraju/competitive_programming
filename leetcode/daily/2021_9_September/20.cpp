/****************************************************
Date: September 20th

https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3981/
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

class Solution 
{
private:
  char checkRows(vector< vector<char> >& game)
  {
    for(int i = 0; i < 3; ++i)
    {
      if(game[i][0] != '.' && (game[i][0] == game[i][1]) && (game[i][0] == game[i][2]))
      {
        return game[i][0];
      }
    }
    
    return '.';
  }
  
  char checkColumns(vector< vector<char> >& game)
  {
    for(int i = 0; i < 3; ++i)
    {
      if(game[0][i] != '.' && (game[0][i] == game[1][i]) && (game[0][i] == game[2][i]))
      {
        return game[0][i];
      }
    }
    
    return '.';
  }
  
  char checkDiag(vector< vector<char> >& game)
  {
    if(game[0][0] != '.' && (game[0][0] == game[1][1]) && (game[0][0] == game[2][2]))
    {
      return game[0][0];
    }
    
    if(game[0][2] != '.' && (game[0][2] == game[1][1]) && (game[0][2] == game[2][0]))
    {
      return game[0][2];
    }
    
    return '.';
  }
  
public:
  string tictactoe(vector<vector<int>>& moves) 
  {
    vector< vector<char> > game(3, vector<char>(3, '.'));
    
    int count = 0;
    for(vector<int>& m : moves)
    {
      char n = count % 2 == 0 ? 'A' : 'B';
      game[m[0]][m[1]] = n;
      count++;
    }
    
    char ans = checkRows(game);
    if(ans != '.')
    {
      return ans == 'A' ? "A" : "B";
    }
    
    ans = checkColumns(game);
    if(ans != '.')
    {
      return ans == 'A' ? "A" : "B";
    }
    
    ans = checkDiag(game);
    if(ans != '.')
    {
      return ans == 'A' ? "A" : "B";
    }
    
    return count == 9 ? "Draw" : "Pending";
  }
};