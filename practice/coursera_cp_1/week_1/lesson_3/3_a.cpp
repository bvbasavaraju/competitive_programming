/*
  Q: 

  Wrong answer!
*/
#include <iostream>
#include <vector>

using namespace std;

int fun(long double x, int n, vector<int> coeffs)
{
  vector<long double> p(n);
  
  p[n-1] = x;
  for(int i = n-2; i >= 0; --i)
  {
    p[i] = x * p[i+1];
  }

  long double retVal = 0;
  for(int i = 0; i < n; ++i)
  {
    retVal += (p[i] * coeffs[i]);
  }

  return (retVal + coeffs[n]);
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> coeffs(n+1);
  
  for(int i = 0; i <= n; ++i)
  {
    std::cin >> coeffs[i];
  }

  long double l = -1e6 * 1.0;
  long double h = 1e6 * 1.0;

  while(l <= h)
  {
    long double m = (h-l)/2;
    if(fun(m, n, coeffs) < 0)
    {
      l = m;
    }
    else
    {
      h = m;
    }
  }

  std::cout << h << std::endl;

  return 0;
}