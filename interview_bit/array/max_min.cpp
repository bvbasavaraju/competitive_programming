#include<bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A) 
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int a : A)
    {
        mini = min(mini, a);
        maxi = max(maxi, a);
    }

    return maxi + mini;
}
