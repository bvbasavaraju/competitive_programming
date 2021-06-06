/*
  Q: B. Binary search: values

  Time limit	  1 second
  Memory        limit	256Mb
  Input	        standard input or input.txt
  Output	      standard output or output.txt
  
  In this problem you are given an array with sequential values of a[mid] obtained by the 
  implementation of the binary search from the lesson. Print the result of binary search — the index of 
  the leftmost value 1. Note that the array indices are zero-based.

  Input format
  The ﬁrst line of input contains two integers n, m(1 ≤ n ≤ 10^5, 1 ≤ m ≤ 20) — the size of the 
  array and the number of steps of binary search on this array.
  
  The next line contains m integers mid (0 ≤ mid ≤ 1) — values of a[mid] for sequential steps 
  of binary search. You may assume that there exists an array which generates such a sequence of 
  a[mid].

  Output format
  Print one integer — the position of the leftmost value 1 in the array. If the array consists only of 
  zeroes, print the value of n.

  Sample 1
  Input         Output
  10 4            4
  1 0 0 0

  Sample 2
  Input         Output
  10 3            0
  1 1 1

  Sample 3
  Input         Output
  10 4            10
  0 0 0 0
*/
#include <iostream>
#include <vector>

using namespace std;

int getLeftmostOne(vector<int>& nums, const vector<int>& mids)
{
  int l = 0;
  int h = nums.size() - 1;
  
  int i = 0;
  int ans = 0;
  while(l <= h)
    {
      int m = l + (h-l)/2;
      nums[m] = mids[i++];
      
      if(nums[m] == 1)
      {
        ans = m;
        h = m-1;
      }
      else
      {
        l = m+1;
      }
    }

  return ans;
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  vector<int> nums(n, 0);
  vector<int> mids(m);

  bool hasOnlyZeros = true;
  for(int i = 0; i < m; ++i)
    {
      std::cin >> mids[i];
      if(mids[i] > 0)
        {
          hasOnlyZeros = false;
        }
    }

  if(hasOnlyZeros)
    {
      std::cout << n << std::endl;
    }
  else
    {
      std::cout << getLeftmostOne(nums, mids) << std::endl;
    }
  
  return 0;
}