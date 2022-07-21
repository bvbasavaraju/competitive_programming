#include<bits/stdc++.h>
using namespace std;

class Solution_t
{
public:
  double getMaxMetricVal(vector<int> nums, int m)
  {
      sort(nums.begin(), nums.end());
      
      double ans = 0.0;
      while(m > 1)
      {
          ans += nums.back();
          
          nums.pop_back();
          
          m--;
      }
      
      int l = nums.size();
      if(l % 2 == 0)
      {
        ans += ((nums[l/2] + nums[(l/2) - 1])/2.0);
      }
      else
      {
          ans += nums[l/2];
      }
      
      
      return ans;
  }
};

int main()
{
    int T;
    std::cin >> T;
    
    Solution_t s;
    int count = 1;
    while(count <= T)
    {
        int N;
        int M;
        
        std::cin >> N;
        std::cin >> M;
        
        int i = 0;
        vector<int> nums(N);
        while(N > 0)
        {
            std::cin >> vector[i];
            N--;
            i++;
        }
        
        std::cout << "Case #" << count << ": " << s.getMaxMetricVal(nums, M) << std::endl;
        
        count++;
    }
    
    return 0;
}