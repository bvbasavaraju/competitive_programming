#include<bits/stdc++.h>
using namespace std;

int getMaxAreaOfHistorgram(const vector<int>& a)
{
    int l = a.size();
    
    //calculate nearest small to right
    int i = 0;
    vector<int> nearestSmallToRightPos(l);
    stack< pair<int, int> > posHeightPair;
    for(i = 0; i < l; ++i)
    {
        if(posHeightPair.empty() || (a[i] >= posHeightPair.top().second))
        {
            posHeightPair.push({i, a[i]});
        }
        else
        {
            while(!posHeightPair.empty() && (a[i] < posHeightPair.top().second))
            {
                pair<int, int> p = posHeightPair.top();
                posHeightPair.pop();

                nearestSmallToRightPos[p.first] = i;
            }

            posHeightPair.push({i, a[i]});
        }
    }

    while(!posHeightPair.empty())
    {
        pair<int, int> p = posHeightPair.top();
        posHeightPair.pop();

        nearestSmallToRightPos[p.first] = i;
    }

    //calculate nearest small to left;
    vector<int> nearestSmallToLeftPos(l);
    for(i = l-1; i >= 0; --i)
    {
        if(posHeightPair.empty() || (a[i] >= posHeightPair.top().second))
        {
            posHeightPair.push({i, a[i]});
        }
        else
        {
            while(!posHeightPair.empty() && (a[i] < posHeightPair.top().second))
            {
                pair<int, int> p = posHeightPair.top();
                posHeightPair.pop();

                nearestSmallToLeftPos[p.first] = i;
            }

            posHeightPair.push({i, a[i]});
        }
    }

    while(!posHeightPair.empty())
    {
        pair<int, int> p = posHeightPair.top();
        posHeightPair.pop();

        nearestSmallToLeftPos[p.first] = i;
    }

    int maxArea = 0;
    for(i = 0; i < l; ++i)
    {
        int areaAtCurrentPos = (nearestSmallToRightPos[i] - nearestSmallToLeftPos[i] - 1) * a[i];
        maxArea = max(maxArea, areaAtCurrentPos);
    }

    return maxArea;
}
int maximalRectangle(vector<vector<int> > &A) 
{
    if(A.size() <= 0)
    {
        return 0;
    }

    int maxArea = INT_MIN;
    vector<int> prevVal;
    for(vector<int> a : A)
    {
        if(!prevVal.empty())
        {
            for(int i = 0; i < a.size(); ++i)
            {
                if(a[i] != 0)
                {
                    a[i] += prevVal[i];
                }
            }
        }

        prevVal = a;
        maxArea = max(maxArea, getMaxAreaOfHistorgram(a));
    }

    return maxArea;
}


int main()
{
  vector<vector<int>> mat = {
    {1, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 1, 1},
    {1, 0, 0, 1},
  };
  maximalRectangle(mat);

  return 0;
}