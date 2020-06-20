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

#include<bits/stdc++.h>
using namespace std;

int Solution (int x1, int x2, int y1, int y2, int xc, int yc, int R) 
{
   int ans = 0;
   long long R_square = R * R;

   for(long long i = y1; i <= y2; ++i)
   {
      long long b_square = (yc - i) * (yc - i);
      if(b_square > R_square)
      {
         continue;
      }

      for(long long j = x1; j <= x2; ++j)
      {
         long long a_square = (xc - j) * (xc - j);
         long long dist_square = a_square + b_square;

         if(dist_square <= R_square)
         {
            ans++;
         }        
      }
   }

   return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1;
    cin >> x1;
    int y1;
    cin >> y1;
    int x2;
    cin >> x2;
    int y2;
    cin >> y2;
    int xc;
    cin >> xc;
    int yc;
    cin >> yc;
    int R;
    cin >> R;

    int out_;
    out_ = Solution(x1, x2, y1, y2, xc, yc, R);
    cout << out_;
    //int ans = Solution(0, 1, 0, 1, -7, 0, 8);

    //printf("%d", ans);
    return 0;
}