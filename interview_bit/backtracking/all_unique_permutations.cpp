#include <bits/stdc++.h>
using namespace std;

bool swappable(vector<int>& A, int start, int end)
{
    for(int i = start; i < end; ++i)
    {
        if(A[i] == A[end])
        {
            return false;
        }
    }

    return true;
}

void getAllCombinations(vector<int>& A, int index, vector<vector<int>>& ans)
{
    if(index >= A.size())
    {
        ans.push_back(A);
    }

    for(int i = index; i < A.size(); ++i)
    {
        bool isAllowed = swappable(A, index, i);
        if(isAllowed)
        {
            swap(A[index], A[i]);
            getAllCombinations(A, index+1, ans);
            swap(A[index], A[i]);
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) 
{
    vector<vector<int>> ans;
    getAllCombinations(A, 0, ans);

    return ans;
}
