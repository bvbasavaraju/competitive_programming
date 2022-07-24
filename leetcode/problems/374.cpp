#include<bits/stdc++.h>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution 
{
public:
  int guessNumber(int n) 
  {
    int l = 0;
    int h = n;
    
    int ans = 0;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      int check = guess(m);
      if(check == 0)
      {
        ans = m;
        break;
      }
      
      if(check < 0)
      {
        h = m-1;
      }
      else
      {
        l = m+1;
      }
    }
    
    return ans;
  }
};