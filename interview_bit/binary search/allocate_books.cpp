#include <bits/stdc++.h>
using namespace std;

bool isFeasible(const vector<int>& pages, int headCount, int maxAllowedPerStudent)
{
    int count = 1;
    int pageCount = 0;
    for(int i = 0; i < pages.size(); ++i)
    {
        if(pageCount + pages[i] > maxAllowedPerStudent)
        {
            count++;
            pageCount = pages[i];
        }
        else
        {
            pageCount += pages[i];
        }
    }

    return count <= headCount;
}
int Solution::books(vector<int> &A, int B) 
{
    int l = A.size();
    if(B > l)
    {
        return -1;
    }

    int maxPageNumber = 0;
    int totalPageNumbers = 0;
    for(int a : A)
    {
        totalPageNumbers += a;
        maxPageNumber = max(maxPageNumber, a);
    }

    int ans = 0;
    int low = maxPageNumber;
    int high = totalPageNumbers;
    while(low <= high)
    {
        int m = low + (high-low)/2;
        if(isFeasible(A, B, m))
        {
            ans = m;
            high = m-1;
        }
        else
        {
            low = m+1;
        }
    }

    return ans;
}
