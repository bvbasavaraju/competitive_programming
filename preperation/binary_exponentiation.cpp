/*
  Theory behind this algorithm is:

  a ^ (b+c) == (a^b) * (a^c)

  Example:
    if x^9 has to be calculated,
    9 can be written as 8 + 1 or 7 + 2 or 6 + 3 etc..
    binary representation of 9 is => 0b1001.

    x^9 == x^(0b1001) == x^(8+1) == x^8 * x^1

    Time complexity here is logarithmic.
    O(logn)

  Reference: https://cp-algorithms.com/algebra/binary-exp.html
*/

#include <iostream>

using namespace std;

typedef unsigned long long ull;

class Solution_t
{
public:
  ull calculatePower(ull a, ull power)
  {
    ull ans = 1;
    while(power > 0)
    {
      if(power & 0x01)
      {
        ans = ans * a;
      }

      a = a * a;
      power >>= 1;
    }

    return ans;
  }

  ull calculatePower(ull a, ull power, ull MOD)
  {
    a = a % MOD;

    ull ans = 1;
    while(power > 0)
    {
      if(power & 0x01)
      {
        ans = ans * a % MOD;
      }

      a = a * a % MOD;
      power >>= 1;
    }

    return ans;
  }
};

int main()
{
  Solution_t s;
  std::cout << s.calculatePower(3, 13) << std::endl;
  return 0;
}