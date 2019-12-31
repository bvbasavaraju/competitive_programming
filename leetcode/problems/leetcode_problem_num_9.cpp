/*
    Q: 9. Palindrome Number
*/

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <math.h>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        long long t = x;
        long long xr = 0;
        while (t > 0)
        {
            xr = (xr * 10ll) + (t % 10ll);
            t /= 10ll;
        }

        return (xr == x);
    }
};