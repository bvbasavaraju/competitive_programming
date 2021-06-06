/*
    Q: Find Last Less

  Time limit	  1 second
  Memory        limit	256Mb
  Input	        standard input or input.txt
  Output	      standard output or output.txt

  In this problem your task will be to process multiple queries in the form “ﬁnd the index of the leftmost 
  integer in a non-increasing array which is less than or equal to a given integer”. Note that in this task 
  indices are 1-based.
  
  Input format
  The ﬁrst line of input contains two integers n, m(1 ≤ n,m ≤ 2 * 10^5) — the size of the array 
  and the number of queries, respectively.
  The next line contains the array — n integers, each not exceeding 10^9 by absolute value. You may 
  assume that the integers in the array are sorted in non-increasing order.
  
  Each of the next m lines describes one query and contains one integer not exceeding 10^9. Your task 
  is to ﬁnd the smallest integer in the array which is not less than the given one.

  Output format
  For each query print the 1-based index in the array of the leftmost integer which is not greater than
  the given one. If there is no such integer, print “NO SOLUTION” instead.

  Sample
  Input                           Output
  10 10
  16 15 13 5 3 -1 -4 -6 -15 -18
  -1                                6
  7                                 4
  -6                                8
  0                                 6
  5                                 4
  18                                1
  15                                2
  3                                 5
  -18                               10
  -19                               NO SOLUTION
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  std::cin >> n >> m;
  
  vector<int> nums(n);
  for(int i = 0; i < n; ++i)
    {
      std::cin >> nums[i];
    }

  for(int i = 0; i < m; ++i)
    {
      int num;
      std::cin >> num;
      
      int l = 0;
      int h = n-1;
      int ans = 1e9+7;
      while(l <= h)
        {
          int m = l + (h-l)/2;
          if(nums[m] <= num)
            {
              ans = m;
              h = m-1;
            }
          else
            {
              l = m+1;
            }
        }
    
      if(ans == 1e9+7)
        {
          std::cout << "NO SOLUTION" << std::endl;
        }
      else
        {
          std::cout << ans+1 << std::endl;
        }
    }

  return 0;
}