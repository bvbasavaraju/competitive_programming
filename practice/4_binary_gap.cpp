/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:
  int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
 */
#include <iostream>
#include <vector>

using namespace std;

int solution(int N)
{
  vector<int> binaryGap;

  //divide by 2 till first non 0 bit is found
  while (N > 0)
  {
    if (1 == (N & 0x01))
    {
      break;
    }
    N = N >> 1;
  }

  int binaryGap_ = 0;
  while (N > 0)
  {
    uint8_t lsb = N & 0x01;

    if (lsb == 1) //if lsb is 1 meaning end of binary gap otherwise increment binaryGap_ count
    {
      if (binaryGap_ > 0)
      {
        binaryGap.push_back(binaryGap_); // Add to the list of binary gaps
      }
      binaryGap_ = 0;
    }
    else
    {
      binaryGap_++;
    }

    N = N >> 1;
  }

  //Find the highest binary gap for a given number
  int retVal = 0;
  for (auto element = binaryGap.begin(); element != binaryGap.end(); ++element)
  {
    if (*element > retVal)
    {
      retVal = *element;
    }
  }

  return retVal;
}

int main()
{
  int num;
  cin >> num;

  int binaryGap = solution(num);
  cout << "Binary Gap for " << num << " is: " << binaryGap;

  return 0;
}