#include<bits/stdc++.h>
using namespace std;

//TODO: Memory Limit exceeded!! - so fix this!!

void getAllPermutation(vector<int> cuts, int p, vector<vector<int>>& permutations)
{
    if(p == cuts.size())
    {
        permutations.push_back(cuts);
        return;
    }

    for(int i = p; i < cuts.size(); ++i)
    {
        swap(cuts[i], cuts[p]);
        getAllPermutation(cuts, p+1, permutations);
        swap(cuts[i], cuts[p]);
    }
}

void getSubRod(int weakPoint, stack<pair<int, int>>& subRods, pair<int, int>& subRod)
{
    if(subRods.top().first < weakPoint && weakPoint < subRods.top().second)
    {
        subRod = subRods.top();
        subRods.pop();
        return;
    }

    pair<int, int> subRod_ = subRods.top();
    subRods.pop();

    getSubRod(weakPoint, subRods, subRod);
    subRods.push(subRod_);
}

long long getCost(int length, vector<int> weakPoints)
{
    long long ans = 0;
    stack<pair<int, int>> subRods;
    subRods.push({0, length});
    for(int wp : weakPoints)
    {
        pair<int, int> subRod;
        getSubRod(wp, subRods, subRod);

        ans += (subRod.second - subRod.first);
        subRods.push({subRod.first, wp});
        subRods.push({wp, subRod.second});
    }

    return ans;
}

vector<int> Solution::rodCut(int A, vector<int> &B) 
{
    vector<vector<int>> weakPointsArray;
    getAllPermutation(B, 0, weakPointsArray);

    long long minCost = INT_MAX;
    vector<int> possibleSolution;
    for(vector<int> weakPoints : weakPointsArray)
    {
        long long cost = getCost(A, weakPoints);
        if(cost < minCost)
        {
            minCost = cost;
            possibleSolution = weakPoints;
        }
        else if(cost == minCost)
        {
            if(weakPoints < possibleSolution)
            {
                possibleSolution = weakPoints;
            }
        }
    }

    return possibleSolution;
}
