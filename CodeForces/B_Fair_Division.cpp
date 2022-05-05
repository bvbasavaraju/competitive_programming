#include<bits/stdc++.h>
using namespace std;

class Solution_t
{
public:
  bool CanDistributeEqually(vector<int> weights)
  {
    int totalWeight = 0;
    for(int w : weights)
    {
      totalWeight += w;
    }

    if(totalWeight % 2 != 0)
    {
      return false;
    }

    totalWeight /= 2;
    int l = weights.size();
    vector< vector<bool> > dp(l+1, vector<bool>(totalWeight+1, false) );

    for(int i = 0; i <= l; ++i)
    {
      for(int j = 0; j <= totalWeight; ++j)
      {
        if(j == 0)
        {
          dp[i][j] = true;
          continue;
        }

        if(i == 0)
        {
          continue;
        }

        if(weights[i-1] <= j)
        {
          dp[i][j] = dp[i-1][j-weights[i-1]] || dp[i-1][j];
        }
        else
        {
          dp[i][j] = dp[i-1][j];
        }
      }
    }

    return (dp[l][totalWeight]);
  }
};


int main()
{
  int testCases = 0;
  std::cin >> testCases;

  for(int i = 0; i < testCases; ++i)
  {
    int received = 0;
    std::cin >> received;

    vector<int> weights;
    for(int j = 0; j < received; ++j)
    {
      int w;
      std::cin >> w;
      weights.push_back(w);
    }
    
    Solution_t s;
    if(s.CanDistributeEqually(weights))
    {
      std::cout << "YES" << std::endl;
    }
    else
    {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}