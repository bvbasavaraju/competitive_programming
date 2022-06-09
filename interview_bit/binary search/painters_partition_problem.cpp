#include<bits/stdc++.h>
using namespace std;

int getNumberOfEmployees(vector<int>& block, int cost)
{
    int headCount = 1;
    long long sum = 0;
    int l = block.size();
    for(int i = 0; i < l; ++i)
    {
        sum += block[i];
        if(sum > cost)
        {
            headCount++;
            sum = block[i];
        }
    }

    return headCount;
}

int Solution::paint(int A, int B, vector<int> &C) 
{
    const int MOD = 1e7 + 3;

    int low = INT_MIN;
    int high = 0;

    for(int i = 0; i < C.size(); ++i)
    {
        low = max(low, C[i]);
        high += C[i];
    }

    if(C.size() <= A)
    {
        return (1LL * low * B) % MOD;
    }

    long long ans = low;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(getNumberOfEmployees(C, mid) > A)
        {
            low = mid+1;    //needed more emplyees, hence update the avg block size
        }
        else
        {
            ans = mid;
            high = mid-1;
        }
    }

    return (ans*B) % MOD;
}
