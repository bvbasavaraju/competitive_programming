#include <iostream>
#include <vector>

using namespace std;

/*
  Q: Hamming Distance

  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
  Given two integers x and y, calculate the Hamming distance.

  Note:
    0 ≤ x, y < 231.

  Example:
    Input: x = 1, y = 4
    Output: 2
    Explanation:
      1   (0 0 0 1)
      4   (0 1 0 0)
            ↑   ↑

  The above arrows point to positions where the corresponding bits are different.
*/

class Solution 
{
public:
  int hammingDistance(int x, int y) 
  {
    //better soluton
    int r = x ^ y;
    
    int ans = 0;
    while(r > 0)
    {
      if(r & 0x01)
      {
        ans++;
      }
      
      r >>= 1;
    }
    
    return ans;
    
    //Another approach
//     int ans = 0;
//     while((x > 0) && (y > 0))
//     {
//       if((x & 0x01) != (y & 0x01))
//       {
//         ans++;
//       }
      
//       x = x >> 1;
//       y = y >> 1;
//     }
    
//     while(x > 0)
//     {
//       if(x & 0x01)
//       {
//         ans++;
//       }
      
//       x = x >> 1;
//     }
    
//     while(y > 0)
//     {
//       if(y & 0x01)
//       {
//         ans++;
//       }
      
//       y = y >> 1;
//     }
    
//     return ans;
  }
};