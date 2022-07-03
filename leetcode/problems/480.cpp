#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  multiset<int> minHeap;
  multiset<int, greater<int>> maxHeap;
  
  void addNum(int num)
  {
    if(minHeap.size() == maxHeap.size())
    {
      if(!maxHeap.empty() && *maxHeap.begin() > num)
      {
        minHeap.insert(*maxHeap.begin());
        maxHeap.erase(maxHeap.begin());
        
        maxHeap.insert(num);
      }
      else
      {
        minHeap.insert(num);
      }      
    }
    else
    {
      if(maxHeap.size() > minHeap.size())
      {
        if(*maxHeap.begin() > num)
        {
          minHeap.insert(*maxHeap.begin());
          maxHeap.erase(maxHeap.begin());
          
          maxHeap.insert(num);
        }
        else
        {
          minHeap.insert(num);
        }
      }
      else
      {
        if(*minHeap.begin() < num)
        {
          maxHeap.insert(*minHeap.begin());
          minHeap.erase(minHeap.begin());
          
          minHeap.insert(num);
        }
        else
        {
          maxHeap.insert(num);
        }
      }
    }
  }
  
  double getMedian(void)
  {
    double ans = 0;
    if(maxHeap.size() == minHeap.size())
    {
      long long num1 = *maxHeap.begin();
      long long num2 = *minHeap.begin();
      
      ans = (num1 + num2) / 2.0;
    }
    else
    {
      ans = maxHeap.size() > minHeap.size() ? *maxHeap.begin() : *minHeap.begin();
    }
    
    ans = (ans * 1e5) / 1e5;
    return ans;
  }
  
  void removeNum(int num)
  {
    auto it = maxHeap.find(num);
    if(it != maxHeap.end())
    {
      maxHeap.erase(it);
    }
    else
    {
      it = minHeap.find(num);
      minHeap.erase(it);  
    }
  }
  
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) 
  {
    int l = nums.size();
    
    vector<double> ans;
    for(int i = 0; i < l; ++i)
    {   
      addNum(nums[i]);
      
      if(maxHeap.size() + minHeap.size() < k)
      {
        continue;
      }
      
      ans.push_back(getMedian());
      
      removeNum(nums[i+1-k]);
    }
    
    return ans;
  } 
};