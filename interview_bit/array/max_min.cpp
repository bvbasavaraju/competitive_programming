pair<int, int> getMaxMin(vector<int>& A, int start, int end)
{
    if(start == end)
    {
        return {A[start], A[start]};
    }

    int mid = start + (end-start)/2;
    pair<int, int> p1 = getMaxMin(A, start, mid);
    pair<int, int> p2 = getMaxMin(A, mid+1, end);

    int mini = min(p1.first, p2.first);
    int maxi = max(p1.second, p2.second);

    return {mini, maxi};
}

int Solution::solve(vector<int> &A) 
{
    // int mini = INT_MAX;
    // int maxi = INT_MIN;

    // for(int a : A)
    // {
    //     mini = min(mini, a);
    //     maxi = max(maxi, a);
    // }

    // return maxi + mini;

    //much faster implementation!
    pair<int, int> minMaxPair = getMaxMin(A, 0, A.size()-1);

    return minMaxPair.second + minMaxPair.first;
}
