#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  int gcd(int a, int b)
  {
    return b == 0 ? a : gcd(b, a%b);
  }
public:
  int mirrorReflection(int p, int q) 
  {
    int lcm = (p*q) / gcd(p, q);
    
    int a = lcm / p;
    int b = lcm / q;
    
    return a%2 == 1 && b%2 == 0 ? 2 : (a%2 == 1 && b%2 == 1 ? 1 : 0);
  }
};