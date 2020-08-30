/****************************************************
Date: August 28th

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
    Q: Implement Rand10() Using Rand7()

    Given the API rand7 which generates a uniform random integer in the range 1 to 7, 
    write a function rand10 which generates a uniform random integer in the range 1 to 10. 
    You can only call the API rand7 and you shouldn't call any other API. Please don't use the system's Math.random().
    
    Notice that Each test case has one argument n, the number of times that your implemented 
    function rand10 will be called while testing. 

    Follow up:
        What is the expected value for the number of calls to rand7() function?
        Could you minimize the number of calls to rand7()?
 
    Example 1:
        Input: n = 1
        Output: [2]

    Example 2:
        Input: n = 2
        Output: [2,8]

    Example 3:
        Input: n = 3
        Output: [3,8,10]

    Constraints:
        1 <= n <= 105
*/

// The rand7() API is already defined for you.
// @return a random integer in the range 1 to 7

int rand7()
{
    return rand() % 7 + 1;
}

class Solution
{
public:
    int rand10()
    {
        int ans = 40;
        while (ans >= 40)
        {
            ans = (rand7() - 1) * 7 + (rand7() - 1);
        }

        return ans % 10 + 1;
    }
};