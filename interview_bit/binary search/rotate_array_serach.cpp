#include <bits/stdc++.h>
using namespace std;

int Solution::search(const vector<int> &A, int B) 
{
    int l = 0; 
    int h = A.size()-1;

    while(l <= h)
    {
        int m = l + (h-l)/2;

        if(A[m] == B)
        {
            return m;
        }

        //consider the sorted side for comparision!
        if(A[l] <= A[m])
        {
            //Left side is sorted
            //Check if it is in the range of sorted portion. imported thing is  "<="
            if(A[l] <= B && B < A[m])
            {
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        else
        {
            //right side is sorted
            // Check if it is in the range of sorted portion. imported thing is ">="
            if(A[m] < B && B <= A[h])
            {
                l = m+1;
            }
            else
            {
                h = m-1;
            }
        }
    }

    return -1;
}
