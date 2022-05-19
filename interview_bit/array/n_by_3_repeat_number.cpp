#include <bits/stdc++.h>

using namespace std;

int Solution::repeatedNumber(const vector<int> &A) 
{
    int l = A.size();

    int count1 = 0;
    int count2 = 0;
    int num1 = INT_MAX;
    int num2 = INT_MAX;

    for(int i = 0; i < l; ++i)
    {
        if(num1 == A[i])
        {
            count1++;
        }
        else if(num2 == A[i])
        {
            count2++;
        }
        else if(count1 == 0)
        {
            num1 = A[i];
            count1++;
        }
        else if(count2 == 0)
        {
            num2 = A[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for(int i = 0; i < l; ++i)
    {
        if(A[i] == num1)
        {
            count1++;
        }
        else if(A[i] == num2)
        {
            count2++;
        }
    }

    if(count1 > l/3)
    {
        return num1;
    }

    if(count2 > l/3)
    {
        return num2;
    }

    return -1;
    // int l = A.size();

    // unordered_map<int, int> freq;
    // for(int i = 0; i < l; ++i)
    // {
    //     freq[A[i]]++;

    //     if(freq[A[i]] > l/3)
    //     {
    //         return A[i];
    //     }
    // }

    // return -1;
}
