#include<bits/stdc++.h>
using namespace std;

void printPunchCard(int R, int C)
{
  int r = R*2+1;
  int c = C*2+1;

  for(int i = 0; i < r; ++i)
  {
    for(int j = 0; j < c; ++j)
    {
      if((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0))
      {
        std::cout << '.';
        continue;
      }

      if(i % 2 == 0)
      { //PlusMinus
        if((j % 2) == 0)
        {
          std::cout << '+';
        }
        else
        {
          std::cout << '-';
        }
      }
      else
      { //barDot
        if((j % 2) == 0)
        {
          std::cout << '|';
        }
        else
        {
          std::cout << '.';
        }
      }
    }
    std::cout << std::endl;
  }

//   vector<vector<char>> card(r, vector<char>(c));
//   for(int i = 0; i < r; ++i)
//   {
//      for(int j = 0; j < c; ++j)
//      {
//       if((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0))
//       {
//          card[i][j] = '.';
//          continue;
//       }

//       if(i % 2 == 0)
//       { //PlusMinus
//          card[i][j] = ((j % 2) == 0) ? '+' : '-'; 
//       }
//       else
//       { //barDot
//          card[i][j] = ((j % 2) == 0) ? '|' : '.';
//       }
//      }
//   }

//   for(int i = 0; i < r; ++i)
//   {
//      for(int j = 0; j < c; ++j)
//      {
//       std::cout << card[i][j];
//      }
//      std::cout << std::endl;
//   }
} 

int main()
{
  int T = 0;
  std::cin >> T;
  for(int i = 0; i < T; ++i)
  {
    int R = 0;
    int C = 0;
    std::cin >> R;
    std::cin >> C;
    std::cout << "Case #" << i+1 << ":" << std::endl;
    printPunchCard(R, C);
  }

  return 0;
}