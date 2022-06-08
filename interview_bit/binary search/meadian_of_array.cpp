#include<bits/stdc++.h>
using namespace std;

//TODO: this is resulting in TLE!! - need to be optimized!!

void adjustPQ(priority_queue<int, vector<int>, greater<int>>& minPQ, priority_queue<int>& maxPQ)
{
    int diff = abs(static_cast<int>(minPQ.size() - maxPQ.size()));
    if(diff <= 1)
    {
        return;
    }

    if(minPQ.size() > maxPQ.size())
    {
        maxPQ.push(minPQ.top());
        minPQ.pop();
    }
    else
    {
        minPQ.push(maxPQ.top());
        maxPQ.pop();
    }
}
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) 
{
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;

    int i = 0;
    int j = 0;
    while(i < A.size() && j < B.size())
    {
        if(A[i] <= B[j])
        {
            minPQ.push(A[i]);
            i++;
        }
        else
        {
            minPQ.push(B[j]);
            j++;
        }
        adjustPQ(minPQ, maxPQ);
    }

    while(i < A.size())
    {
        minPQ.push(A[i++]);
        adjustPQ(minPQ, maxPQ);
    }

    while(j < B.size())
    {
        minPQ.push(B[j++]);
        adjustPQ(minPQ, maxPQ);
    }

    double ans = 0;
    if(minPQ.size() > maxPQ.size())
    {
        ans = minPQ.top() * 1.0;
    }
    else if(maxPQ.size() > minPQ.size())
    {
        ans = maxPQ.top() * 1.0;
    }
    else
    {
        ans = (minPQ.top() + maxPQ.top()) / 2.0;
    }

    return ans;
}
