/*
  Q: Binary Search 1
  
  Find number of the iterations of the binary search on array of size 1000. 
  If there are several possible answers, sort the answers by increasing order and separate them by spaces.
*/
#include <iostream>

int main()
{
  int l = 0;
  int h = 999;

  int ans = 0;
  while(l <= h)
  {
    ans++;
    int m = l + (h-l)/2;
    l = m+1;
  }

  return 0;
}
