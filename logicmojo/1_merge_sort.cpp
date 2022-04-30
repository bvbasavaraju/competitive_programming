#include <bits/stdc++.h>

using namespace std;

class MergeSort_t
{
private:
  void Merge(vector<int>& nums, int low, int mid, int high)
  {
    int i = low;
    int j = mid+1;

    int k = 0;
    vector<int> temp(high - low + 1);
    while(i <= mid && j <= high)
    {
      if(nums[i] < nums[j])
      {
        temp[k++] = nums[i++];
      }
      else
      {
        temp[k++] = nums[j++];
      }
    }

    while(i <= mid)
    {
      temp[k++] = nums[i++];
    }
    while(j <= high)
    {
      temp[k++] = nums[j++];
    }

    k = 0;
    for(int i = low; i <= high; ++i)
    {
      nums[i] = temp[k++];
    }
  }

  void Sort(vector<int>& nums, int low, int high)
  {
    if(low == high)
    {
      return;
    }

    int mid = low + (high - low)/2;
    Sort(nums, low, mid);
    Sort(nums, mid+1, high);

    Merge(nums, low, mid, high);
  }

public:
  void Solve(vector<int>& nums)
  {
    int l = nums.size() - 1;
    Sort(nums, 0, l);
  }
};

int main()
{
  vector<int> nums = {8,4,3,12,25,6,13,10};

  std::cout << "Before Sort: ";
  for(int n : nums)
  {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  MergeSort_t obj;
  obj.Solve(nums);

  std::cout << "After Sort: ";
  for(int n : nums)
  {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  return 0;
}