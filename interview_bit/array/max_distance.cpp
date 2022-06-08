#include<bits/stdc++.h>
using namespace std;

int Solution::maximumGap(const vector<int> &A) 
{
    int ans = 0;
    int l = A.size();
    //TLE for hard solution
    // for(int i = 0; i < l/2+1; ++i)
    // {
    //     for(int j = l-1; j >= l/2; --j)
    //     {
    //         if(A[i] <= A[j])
    //         {
    //             ans = max(ans, j-i);
    //             break;
    //         }
    //     }
    // }

  //O(2n) solution!!
    vector<int> farthestGreater(l);
    farthestGreater[l-1] = A[l-1];
    for(int i = l-2; i >= 0; --i)
    {
        farthestGreater[i] = max(A[i], farthestGreater[i+1]);
    }

    int pos = 0;
    for(int i = 0; i < l && pos < l; ++i)
    {
        while(pos < l && A[i] <= farthestGreater[pos])
        {
            ans = max(ans, pos-i);
            pos++;
        }
    }

    return ans;
}
