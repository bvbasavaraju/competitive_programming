#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int numTrees(int n) 
  {
    vector<int> treeCount(n+1);
    
    treeCount[0] = 1;
    treeCount[1] = 1;
    
    for(int i = 2; i <= n; ++i)
    {
      int leftCount = 0;
      int rightCount = i-1;
      
      while(leftCount <= i-1)
      {
        treeCount[i] += treeCount[leftCount] * treeCount[rightCount];
        
        leftCount++;
        rightCount--;
      }
    }
    
    return treeCount[n];
  }
};