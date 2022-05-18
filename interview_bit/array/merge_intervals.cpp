#include<bits/stdc++.h>

using namespace std;

struct Interval 
{
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    vector<Interval> ans;

    ans.push_back(newInterval);
    for(Interval interval : intervals)
    {
        Interval back = ans.back();
        ans.pop_back();

        if(back.start > interval.end)
        {
            ans.push_back(interval);
            ans.push_back(back);
        }
        else if(back.end < interval.start)
        {
            ans.push_back(back);
            ans.push_back(interval);
        }
        else
        {
            int mini = min(back.start, interval.start);
            int maxi = max(back.end, interval.end);
            ans.push_back(Interval(mini, maxi));
        }
    }

    return ans;
}
