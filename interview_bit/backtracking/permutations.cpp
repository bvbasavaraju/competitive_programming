#include <bits/stdc++.h>
using namespace std;

void getAllPerms(vector<int>& A, int index, vector<vector<int>>& ans)
{
    if(index >= A.size())
    {
        ans.push_back(A);
        return;
    }

    for(int i = index; i < A.size(); ++i)
    {
        swap(A[index], A[i]);
        getAllPerms(A, index+1, ans);
        swap(A[index], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) 
{
    vector<vector<int>> ans;
    getAllPerms(A, 0, ans);

    return ans;
}
