#include <bits/stdc++.h>

using namespace std;

void printClosestPossible(vector<vector<int>>& printers)
{
  for(int i = 0; i < 3; ++i)
  {
    int ans = 0;
    for(int j = 0; j < 4; ++j)
    {
      ans += printers
    }
  }
}

int main()
{
  int T;
  for(int i = 0; i < T; ++i)
  {
    std::cout << "Case #" << (i+1) << ": ";

    vector< vector<int> > printers(3, vector<int>(4, 0));
    for(int i = 0; i < 3; ++i)
    {
      for(int j = 0; j < 4; ++j)
      {
        std::cin >> printers[i][j];
      }
    }

    printClosestPossible(printers);
  }
  return 0;
}