#include<bits/stdc++.h>

using namespace std;

//Find key when sorted nums are rotated at some position!!

class BinarySearch_t
{
public:
  int find(vector<int>& nums, int key)
  {
    int l = 0;
    int h = nums.size() - 1;

    while(l <= h)
    {
      int m = l + (h-l)/2;

      if(nums[m] == key)
      {
        return m;
      }

      if(nums[l] <= nums[m] && nums[m] >= nums[h])
      {
        if(nums[m] >= key && nums[l] <= key)
        {
          h = m-1;
        }
        else
        {
          l = m+1;
        }
      }
      else
      {
        if(nums[m] <= key && nums[h] >= key)
        {
          l = m+1;
        }
        else
        {
          h = m-1;
        }
      }
    }

    return -1;
  }
};

int main()
{
  //vector<int> nums = {3,4,5,6,7,8,9,10,1,2};
  vector<int> nums = {7,8,9,10,1,2,3,4,5,6};
  BinarySearch_t bs;
  //std::cout << bs.find(nums, 8);
  std::cout << bs.find(nums, 5);

  return 0;
}