#include<bits/stdc++.h>
using namespace std;

class NumArray 
{
private:
//   vector<int> sumArray;
  
//   int construct(int segIndex, int left, int right, vector<int>& nums)
//   {
//     if(left == right)
//     {
//       sumArray[segIndex] = nums[left];
//       return nums[left];
//     }
        
//     int mid = left + (right - left)/2;
//     int leftSum = construct(2*segIndex+1, left, mid, nums);
//     int rightSum = construct(2*segIndex+2, mid+1, right, nums);
    
//     sumArray[segIndex] += (leftSum + rightSum);
    
//     return sumArray[segIndex];
//   }
  
//   int getSum(int segIndex, int segL, int segR, int rL, int rR)
//   {
//     if(segR < rL || segL > rR)
//     {
//       return 0;
//     }
    
//     if(segL >= rL && segR <= rR)
//     {
//       return sumArray[segIndex];
//     }
    
//     int segM = segL + (segR - segL)/2;
    
//     int leftSum = getSum(2*segIndex+1, segL, segM, rL, rR);
//     int rightSum = getSum(2*segIndex+2, segM+1, segR, rL, rR);
    
//     return leftSum + rightSum;
//   }
  
  vector<int> prefixSum;
public:
  NumArray(vector<int>& nums) 
  {
//     int h = ceil(log2(nums.size()));
//     int l = ((1 << h) * 2) - 1;
    
//     sumArray.resize(l);
    
//     construct(0, 0, nums.size()-1, nums);
    prefixSum.push_back(0);
    for(int i = 0; i < nums.size(); ++i)
    {
      prefixSum.push_back(prefixSum.back() + nums[i]);
    }
  }

  int sumRange(int left, int right) 
  {
    // return getSum(0, 0, sumArray.size()-1, left, right);
    return prefixSum[right+1] - prefixSum[left];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */