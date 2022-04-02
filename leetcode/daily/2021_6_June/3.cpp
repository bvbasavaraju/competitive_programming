/****************************************************
Date: June 3rd

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3764/
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

/*
  Q: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

  Given a rectangular cake with height h and width w, and two arrays of integers 
  horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from 
  the top of the rectangular cake to the ith horizontal cut and similarly, 
  verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

  Return the maximum area of a piece of cake after you cut at each horizontal and 
  vertical position provided in the arrays horizontalCuts and verticalCuts. 
  Since the answer can be a huge number, return this modulo 10^9 + 7.

  Example 1:
    Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
    Output: 4 
    Explanation: 
      The figure above represents the given rectangular cake. 
      Red lines are the horizontal and vertical cuts. After you cut the cake, 
      the green piece of cake has the maximum area.

  Example 2:
    Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
    Output: 6
    Explanation:
      The figure above represents the given rectangular cake. 
      Red lines are the horizontal and vertical cuts. After you cut the cake, 
      the green and yellow pieces of cake have the maximum area.

  Example 3:
    Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
    Output: 9

  Constraints:
    2 <= h, w <= 10^9
    1 <= horizontalCuts.length < min(h, 10^5)
    1 <= verticalCuts.length < min(w, 10^5)
    1 <= horizontalCuts[i] < h
    1 <= verticalCuts[i] < w
    It is guaranteed that all elements in horizontalCuts are distinct.
    It is guaranteed that all elements in verticalCuts are distinct.

  Hide Hint #1  
    Sort the arrays, then compute the maximum difference between two consecutive 
    elements for horizontal cuts and vertical cuts.

  Hide Hint #2  
    The answer is the product of these maximum values in horizontal cuts and vertical cuts.
*/

class Solution 
{
public:
  int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) 
  {
    const int MOD = 1000000007;
    
    sort(hc.begin(), hc.end());
    sort(vc.begin(), vc.end());
    
    int hmax = max(hc[0], h-hc.back());
    int vmax = max(vc[0], w-vc.back());
    
    for(int i = 0; i < hc.size()-1; ++i)
    {
      hmax = max(hmax, hc[i+1]-hc[i]);
    }
    for(int i = 0; i < vc.size()-1; ++i)
    {
      vmax = max(vmax, vc[i+1]-vc[i]);
    }
    
    return (long long)((long long)hmax * (long long)vmax) % MOD;
    
    //below code is Memory limit exceeded error
//     hc.push_back(h);
//     vc.push_back(w);
    
//     sort(hc.begin(), hc.end());
//     sort(vc.begin(), vc.end());
    
//     int lh = hc.size();
//     int lc = vc.size();
    
//     int ans = 0;
//     vector<vector<int>> a(lh, vector<int>(lc, 0));
//     vector<vector<int>> p(lh, vector<int>(lc, 0));
//     for(int i = 0; i < lh; ++i)
//     {
//       int row_sum = 0;
//       for(int j = 0; j < lc; ++j)
//       {
//         p[i][j] = ((hc[i] % MOD) * (vc[j] % MOD)) % MOD;
        
//         if(i == 0 && j == 0)
//         {
//           a[i][j] = p[i][j];
//         }
//         else if(j == 0)
//         {
          
//           a[i][j] = (((p[i][j] - p[i-1][j]) % MOD ) + MOD) % MOD;
//         }
//         else if(i == 0)
//         {
//           a[i][j] = (((p[i][j] - p[i][j-1]) % MOD ) + MOD) % MOD;
//         }
//         else
//         {
//           a[i][j] = ((((((p[i][j] - p[i-1][j]) % MOD ) + MOD ) % MOD - row_sum) % MOD) + MOD ) % MOD;
//         }
        
//         row_sum = (row_sum + a[i][j]) % MOD;
//         ans = max(ans, a[i][j]);
//       }
//     }
    
    // return ans;
  }
};