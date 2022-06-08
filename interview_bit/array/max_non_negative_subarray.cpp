#include<bits/stdc++.h>
using namespace std;

void updateAnswer(long long sum, vector<int>& curr, long long& maxSum, vector<int>& ans)
{
    if(sum > maxSum)
    {
        maxSum = sum;
        ans = curr;
    }
    if(sum == maxSum)
    {
        if(curr.size() > ans.size() || (curr.size() == ans.size() && curr[0] < ans[0]))
        {
            ans = curr;
        }
    }
}

vector<int> Solution::maxset(vector<int> &A) 
{
    long long sum = 0;
    long long maxSum = 0;
    vector<int> ans;

    vector<int> curr;
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] < 0)
        {
            if(sum > 0 || curr.size() > 0)
            {
                updateAnswer(sum, curr, maxSum, ans);
            }
            
            sum = 0;
            curr = {};
            continue;
        }

        sum += A[i];
        curr.push_back(A[i]);
    }

    if(sum > 0 || curr.size() > 0)
    {
        updateAnswer(sum, curr, maxSum, ans);
    }

    return ans;
}
