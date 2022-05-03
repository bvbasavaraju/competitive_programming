#include<bits/stdc++.h>
using namespace std;

class Solution_t
{
public:
  void sort(vector<int>& nums)
  {
    int l = nums.size();

    int c = 0;
    int n = 0;
    bool duplicate_found = false;
    for(int i = 1; i < l; ++i)
    {
      if(!duplicate_found && nums[i-1] != nums[i])
      {
        continue;
      }

      if(!duplicate_found)
      {
        c = i;
      }

      n = i+1;
      duplicate_found = true;
      while(nums[n] == nums[c])
      {
        n++;
      }

      if(n >= l)
      {
        break;
      }

      swap(nums[n], nums[c]);
      c++;
      i = n;
    }

    std::cout << "Length with no duplicate is: " << c;
  }
};

int main()
{
  vector<int> nums = {1, 2, 2, 3, 4, 4, 4, 5, 5};

  Solution_t s;
  s.sort(nums);

  return 0;
}