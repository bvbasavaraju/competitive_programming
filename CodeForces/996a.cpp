#include <bits/stdc++.h>
using namespace std;

class Solution_t
{
  // struct HashPair_t
  // {
  //   template<class U, class V>
  //   size_t operator()(const pair<U, V>& p) const
  //   {
  //     int h1 = hash<U>{}(p.first);
  //     int h2 = hash<V>{}(p.second);

  //     if(h1 != h2)
  //     {
  //       return h1 ^ h2;
  //     }

  //     return h1;
  //   }
  // };

  // unordered_map<pair<int, int>, int, HashPair_t> mem;
  // int getCount(int amount, vector<int>& bills, int p)
  // {
  //   if(p < 0)
  //   {
  //     return INT_MAX;
  //   }

  //   if(amount == 0)
  //   {
  //     return 0;
  //   }

  //   if(mem.count({amount, p}) != 0)
  //   {
  //     return mem[{amount, p}];
  //   }

  //   int ans = INT_MAX;
  //   if(bills[p] <= amount)
  //   {
  //     int s1 = 1 + getCount(amount - bills[p], bills, p);
  //     int s2 = getCount(amount, bills, p-1);

  //     ans = min(s1, s2);
  //     //return min( 1 + getCount(amount - bills[p], bills, p), getCount(amount, bills, p-1));
  //   }
  //   else
  //   {
  //     ans = getCount(amount, bills, p-1);
  //   }

  //   mem[{amount, p}] = ans;
  //   return ans;
  // }

public:
  int getMinimumBills(int amount, vector<int>& bills)
  {
    if(amount == 0)
    {
      return 0;
    }

    int ans = 0;
    int l = bills.size();
    for(int i = l-1; i>= 0; --i)
    {
      ans += (amount/bills[i]);
      amount = amount % bills[i];
    }

    return ans;

    // DP - top down approach!!
    // // int r = bills.size();
    // // int c = amount;
    // // int dp[r+1][c+1]; 
    // //// vector< vector<int> > dp(r+1, vector<int>(c+1, INT_MAX));
    // // for(int i = 0; i <= r; ++i)
    // // {
    // //   for(int j = 0; j <= c; ++j)
    // //   {
    // //     if(i == 0)
    // //     {
    // //       dp[i][j] = INT_MAX;
    // //       continue;
    // //     }

    // //     if(j == 0)
    // //     {
    // //       dp[i][j] = 0;
    // //       continue;
    // //     }

    // //     if(bills[i-1] <= j)
    // //     {
    // //       int amt = j - bills[i-1];
    // //       dp[i][j] = min(1+dp[i][amt], dp[i-1][j]);
    // //     }
    // //     else
    // //     {
    // //       dp[i][j] = dp[i-1][j];
    // //     }
    // //   }
    // // }
    // //int ans = dp[r][c];

    // dp - recursive!
    // int ans = getCount(amount, bills, bills.size()-1);
    // return ans;
  }

};

int main()
{
  int amount = 0;
  std::cin >> amount;

  vector<int> bills = {1, 5, 10, 20, 100};
  Solution_t s;
  std::cout << s.getMinimumBills(amount, bills);

  return 0;
}