/****************************************************
Date: July 26th

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3434/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>
#include <set>

using namespace std;

/*
    Q: Fizz Buzz

    Write a program that outputs the string representation of numbers from 1 to n.

    But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”.
    For numbers which are multiples of both three and five output “FizzBuzz”.

    Example:
        n = 15,

        Return:
        [
            "1",
            "2",
            "Fizz",
            "4",
            "Buzz",
            "Fizz",
            "7",
            "8",
            "Fizz",
            "Buzz",
            "11",
            "Fizz",
            "13",
            "14",
            "FizzBuzz"
        ]
*/

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;

        for (int i = 1; i <= n; ++i)
        {
            if ((i % 3 == 0) && (i % 5 == 0))
            {
                ans.push_back("FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                ans.push_back("Fizz");
            }
            else if (i % 5 == 0)
            {
                ans.push_back("Buzz");
            }
            else
            {
                ans.push_back(std::to_string(i));
            }
        }

        return ans;
    }
};