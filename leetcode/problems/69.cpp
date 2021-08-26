/*
  Q: 69. Sqrt(x)
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution 
{
private:
  int getSqrt(int x)
  {
    long l = 0;
    long h = x;
    
    int ans = 1;
    while(l <= h)
    {
      long long mid = l + (h-l)/2;

      long long p = mid * mid;
      if(p == x)
      {
        return mid;
      }
      else if(p > x)
      {
        h = mid-1;
      }
      else
      {
        l = mid+1;
        ans = mid;
      }
    }

    return ans;
  }
public:
  int mySqrt(int x) 
  {
    return getSqrt(x);
  }
};