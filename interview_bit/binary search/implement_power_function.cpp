#include<bits/stdc++.h>
using namespace std;

long long getPower(long long x, long long n, long long d)
{
    if(x == 0)
    {
        return 0;
    }

    if(n == 0)
    {
        return 1; 
    }

    long long power = getPower(x, n/2, d);
    long long ans = (power * power) % d;

    if(n%2 == 0)
    {
        return ans;
    }
    
    return (ans * x) % d;
}

int Solution::pow(int x, int n, int d)
{
    long long ans = getPower(x, n, d);

    if(ans < 0)
    {
        return ans + d;
    }

    return ans;

    // resulted in error in edge conditions!!
    // if(n == 0)
    // {
    //     return x == 0 ? 0 : 1;
    // }

    // if(n == 1)
    // {
    //     return x < 0 ? d+x : x%d;
    // }

    // long long num = x < 0 ? d+x : x%d;
    // int powerCount = 1 << 1;
    // while(powerCount <= n)
    // {
    //     num = ((num % d) * (num % d)) % d;

    //     powerCount <<= 1;
    // }

    // powerCount >>= 1;
    // if(n-powerCount >= 1)
    // {
    //     long long num_ = x < 0 ? d+x : x%d;
    //     if(n-powerCount > 1)
    //     {
    //         num_ = (num_ * num_) % d;
    //     }

    //     num = ((num%d) * (num_%d))%d;
    // }

    // return num;
}
