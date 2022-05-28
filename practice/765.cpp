#include<bits/stdc++.h>

using namespace std;

/*
  ! need to fix it!!
*/

class Solution 
{
private:
  int getMinSwap(vector<int> row, int p)
  {
    if(p >= row.size())
    {
      return INT_MAX;
    }
    
    //TODO: Add Memoization
    
    if(abs(row[p-1] - row[p]) == 1)
    {
      int noSwap = getMinSwap(row, p+2);
      
      if(p+1 < row.size())
      {
        swap(row[p], row[p+1]);  
        return min(noSwap, 1+getMinSwap(row, p));  
      }      
      
      return noSwap;
    }
    else if(p+1 < row.size())
    {
      swap(row[p], row[p+1]);  
      return 1+getMinSwap(row, p);
    }
    
    return 0;
  }
  
public:
  int minSwapsCouples(vector<int>& row) 
  {
    return getMinSwap(row, 1);
  }
};

int main()
{
  vector<int> row = {0,2,1,3};
  Solution s;
  s.minSwapsCouples(row);

  return 0;
}