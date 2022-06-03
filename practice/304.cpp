#include<bits/stdc++.h>

using namespace std;

class NumMatrix 
{
private:
  vector< vector<int> > matrixSum;
public:
  NumMatrix(vector<vector<int>>& matrix) 
  {
    int row = matrix.size();
    int col = matrix[0].size();
    
    matrixSum.resize(row, vector<int>(col, 0));
    
    for(int i = 0; i < row; ++i)
    {
      for(int j = 0; j < col; ++j)
      {
        if(i == 0 && j == 0)
        {
          matrixSum[i][j] = matrix[i][j];
          continue;
        }
        
        if(i == 0)
        {
          matrixSum[i][j] = matrix[i][j] + matrixSum[i][j-1];
          continue;
        }
        
        if(j == 0)
        {
          matrixSum[i][j] = matrix[i][j] + matrixSum[i-1][j];
          continue;
        }
        
        matrixSum[i][j] = matrix[i][j] + matrixSum[i-1][j] + matrixSum[i][j-1] - matrixSum[i-1][j-1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) 
  {
    int ans = matrixSum[row2][col2];
    
    if(row1 > 0 && col1 > 0)
    {
      ans = ans - matrixSum[row2][col1-1] - matrixSum[row1-1][col2] + matrixSum[row1-1][col1-1];  
    }
    else if(row1 > 0)
    {
      ans = ans - matrixSum[row1-1][col2];
    }
    else if(col1 > 0)
    {
      ans = ans - matrixSum[row2][col1-1];
    }
    
    return ans;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */