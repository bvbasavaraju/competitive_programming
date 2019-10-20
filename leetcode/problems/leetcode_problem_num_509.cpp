/*
    Q: https://leetcode.com/problems/fibonacci-number/

    The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
    such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

    F(0) = 0,   F(1) = 1
    F(N) = F(N - 1) + F(N - 2), for N > 1.

    Given N, calculate F(N).

    Ex:
    Input: 2
    Output: 1
    Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

    Input: 3
    Output: 2
    Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

    Input: 4
    Output: 3
    Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

    Note:
    0 ≤ N ≤ 30.
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution_t
{
public:
    int fib(int N)
    {
        if (N <= 0)
        {
            return 0;
        }
        if (N < 2)
        {
            return 1;
        }

        vector<int> series(N, 0);
        series[0] = 1;
        series[1] = 1;
        for (int i = 2; i < N; i++)
        {
            series[i] = series[i - 1] + series[i - 2];
        }

        return series[N - 1];
    }
};