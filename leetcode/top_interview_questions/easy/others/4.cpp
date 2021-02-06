#include <iostream>
#include <vector>

using namespace std;

/*
  Q: Pascal's Triangle

  Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

  In Pascal's triangle, each number is the sum of the two numbers directly above it.

  Example:
    Input: 5
    Output:
      [
          [1],
          [1,1],
        [1,2,1],
        [1,3,3,1],
      [1,4,6,4,1]
      ]
*/

class Solution 
{
public:
  vector<vector<int>> generate(int numRows) 
  {
    vector< vector<int> > ans;
    
    for(int i = 0; i < numRows; ++i)
    {
      if(i == 0)
      {
        ans.push_back({1});
      }
      else if(i == 1)
      {
        ans.push_back({1, 1});
      }
      else
      {        
        vector<int> curr(i+1, 0);
        curr[0] = 1;
        curr[i] = 1;
        
        for(int j = 1; j <= (i+1)/2; ++j)
        {
          curr[j] = ans[i-1][j-1] + ans[i-1][j];
          curr[i - j] = curr[j];
        }
        
        ans.push_back(curr);
      }
    }
    
    return ans;
  }
};