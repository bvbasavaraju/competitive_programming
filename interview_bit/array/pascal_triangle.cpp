#include<bits/stdc++.h>

using namespace std;

//Generate!
vector<vector<int> > Solution::solve(int A) 
{
    vector<vector<int>> ans;
    if(A <= 0)
    {
        return ans;
    }

    ans.push_back({1});
    if(A == 1)
    {
        return ans;
    }

    ans.push_back({1,1});
    for(int i = 2; i < A; ++i)
    {
        int currentRowSize = ans.back().size() + 1;
        vector<int> row(currentRowSize);
        for(int j = 1; j < currentRowSize - 1; ++j)
        {
            row[j] = ans[i-1][j] + ans[i-1][j-1];
        }
        row[0] = 1;
        row[currentRowSize-1] = 1;

        ans.push_back(row);
    }

    return ans;
}

