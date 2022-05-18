#include<bits/stdc++.h>

using namespace std;

void Solution::rotate(vector<vector<int> > &A) 
{
    int r = A.size();
    if(r <= 1)
    {
        return;
    }

    int c = A[0].size();
    int loopCount = r/2;

    for(int i = 0; i < loopCount; ++i)
    {
        for(int j = i; j < ((c - 1) - i); ++j)
        {
            pair<int, int> p = {i, j};

            int num = A[p.first][p.second];
            for(int k = 0; k < 4; ++k)
            {
                pair<int, int> np = {p.second, (c-1)-p.first};
                
                int temp = A[np.first][np.second];
                A[np.first][np.second] = num;
                num = temp;
                p = np;
            }
        }
    }
}
