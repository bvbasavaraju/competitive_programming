/*
  Q: Search a Word in a 2D Grid of characters

  First input is:   Grid Size,
  Second input is:  all the letters in that grid
  Third input is:   Word to be found

  Movements allowed Are:
  Right to Left,
  Left to Right,
  Bottom to Top,
  Top to Bottom,
  Diagonal

  Ex:
  Inputs:
    4,
    R K P B T O A J A T S P P M S E
    ROSE

  Output:
  (0,0)
  (1,1)
  (2,2)
  (3,3)

  Explanation:
  When given letters are arranged in the 2D matrix, it will be like below:
  R K P B
  T O A J
  A T S P
  P M S E

  So, R can be found in (0,0), O in (1,1), S in (2,2) and E in (3,3).
  With diagonal movement, the word can be found.
*/

#include<iostream>
#include <vector>
#include <string>

using namespace std;

static const uint8_t LEFT_TO_RIGHT = 0;
static const uint8_t RIGHT_TO_LEFT = 1;
static const uint8_t BOTTOM_TO_TOP = 2;
static const uint8_t TOP_TO_BOTTOM = 3;
static const uint8_t DIAGONAL_FROM_TOP_LEFT = 4;
static const uint8_t DIAGONAL_FROM_TOP_RIGHT = 5;
static const uint8_t DIAGONAL_FROM_BOTTOM_LEFT = 6;
static const uint8_t DIAGONAL_FROM_BOTTOM_RIGHT = 7;

bool did_found_letter(vector<vector<char>>& m, int n, int r, int c, const string& str, int pos, int dir, vector<vector<int>>& found_pos)
{
    //If position already reached string size meaning all characters has been identified. So, return true.
    if(pos == str.size())
    {
        return true;
    }
    
    //Check for the false conditions
    if(pos > str.size() || r < 0 || r >= n || c < 0 || c >= n || str[pos] != m[r][c])
    {
        return false;
    }
    
    //If false conditions are passed, that means matching character has been found
    found_pos.push_back({r, c});
    
    //As character matched, ret_val is true
    bool ret_val = true;
    switch(dir)
    {
        case LEFT_TO_RIGHT:
            ret_val = did_found_letter(m, n, r, c+1, str, pos+1, dir, found_pos);
            break;
        
        case RIGHT_TO_LEFT :
            ret_val = did_found_letter(m, n, r, c-1, str, pos+1, dir, found_pos);
            break;
            
        case BOTTOM_TO_TOP:
            ret_val = did_found_letter(m, n, r-1, c, str, pos+1, dir, found_pos);
            break;
            
        case TOP_TO_BOTTOM:
            ret_val = did_found_letter(m, n, r+1, c, str, pos+1, dir, found_pos);
            break;
            
        case DIAGONAL_FROM_TOP_LEFT:
            ret_val = did_found_letter(m, n, r+1, c+1, str, pos+1, dir, found_pos);
            break;
        
        case DIAGONAL_FROM_TOP_RIGHT:
            ret_val = did_found_letter(m, n, r+1, c-1, str, pos+1, dir, found_pos);
            break;
            
        case DIAGONAL_FROM_BOTTOM_LEFT:
            ret_val = did_found_letter(m, n, r-1, c+1, str, pos+1, dir, found_pos);
            break;
        
        case DIAGONAL_FROM_BOTTOM_RIGHT:
            ret_val = did_found_letter(m, n, r-1, c-1, str, pos+1, dir, found_pos);
            break;
            
        default:
            ret_val = false;
            break;
    }
    
    //If any character did not found, clear the found positions
    if(!ret_val)
    {
        found_pos.clear();
    }
    
    return ret_val;
}

void  solution_function()
{
//make modifications in the code below for accepting input from console /
  int n;
  cin>>n;
  
  //read the matrix
  vector<vector<char>> matrix(n, vector<char>(n));
  for(int i = 0; i < n; ++i)
  {
      for(int j = 0; j < n; ++j)
      {
          cin >> matrix[i][j];
      }
  }
  
  //Read the word to be found
  string str;
  cin >> str;
  
  bool found = false;
  vector<vector<int>> found_pos; // positions in which chacters from str has been found
  for(int i = 0; i < n && !found; ++i)
  {
      for(int j = 0; j < n && !found; ++j)
      {
          //Check from all possible directions, if found, just break from the loop!
          for(int d = 0; d < 8; d++)
          {
              if(did_found_letter(matrix, n, i, j, str, 0, d, found_pos))
              {
                  found = true;
                  break;
              }
          }
      }
  }
  
  if(found)
  {
      for(auto pos : found_pos)
      {
          cout << "(" << pos[0] << "," << pos[1] << ")" << endl; 
      }
  }
  else
  {
      cout << -1 << endl;
  }
}

int main()
{
  solution_function();
  return 0;
}