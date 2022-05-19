#include<bits/stdc++.h>

using namespace std;

struct Interval 
{
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> Solution::merge(vector<Interval> &A) 
{
    int l = A.size();
    vector<Interval> ans;
    if(A.size() <= 0)
    {
        return ans;
    }    
    
    sort(A.begin(), A.end(), [](const Interval& i1, const Interval& i2) -> bool { return ((i1.start < i2.start) || (i1.start == i2.start && i1.end <= i2.end)); } );

    ans.push_back(A[0]);
    for(int i = 1; i < l; ++i)
    {
        Interval int1 = ans.back();
        Interval int2 = A[i];

        ans.pop_back();

        if(int1.end < int2.start)
        {
            ans.push_back(int1);
            ans.push_back(int2);
        }
        else if(int2.end < int1.start)
        {
            ans.push_back(int2);
            ans.push_back(int1);
        }
        else
        {
            int mini = min(int1.start, int2.start);
            int maxi = max(int1.end, int2.end);

            ans.push_back(Interval(mini, maxi));
        }
    }

    return ans;
}