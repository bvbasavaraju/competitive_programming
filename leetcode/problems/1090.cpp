#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) 
  {
    vector<pair<int, int>> valueLabel;
    int l = values.size();
    for(int i = 0; i < l; ++i)
    {
      valueLabel.push_back({values[i], labels[i]});
    }
    
    sort(valueLabel.begin(), valueLabel.end(), [](const pair<int, int> p1, const pair<int, int> p2) -> bool 
         {
           return (p1.first < p2.first);
         });
    
    int ans = 0;
    unordered_map<int, int> labelUseCount;   
    for(int i = l-1; (i >= 0) && (numWanted > 0); --i)
    {
      int num = valueLabel[i].first;
      int label = valueLabel[i].second;
      if(labelUseCount.find(label) != labelUseCount.end() && labelUseCount[label] >= useLimit)
      {
        continue;
      }
      
      labelUseCount[label]++;
      ans += num;
      numWanted--;
    }
    
    return ans;
  }
};