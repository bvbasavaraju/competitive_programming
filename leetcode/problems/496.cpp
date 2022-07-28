#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
  {
    unordered_map<int, int> nums;
  
    stack<int> st;
    int l = nums2.size();
    for(int i = 0; i < l; ++i)
    {
      while(!st.empty() && nums2[i] > st.top())
      {
        nums[st.top()] = nums2[i];
        st.pop();
      }
      
      st.push(nums2[i]);
    }
    
    while(!st.empty())
    {
      nums[st.top()] = -1;
      st.pop();
    }
    
    vector<int> ans;
    for(int n : nums1)
    {
      ans.push_back(nums[n]);
    }
    
    return ans;
  }
};