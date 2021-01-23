/*
    Q: 20. Valid Parentheses
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
    bool isValid(string s)
    {
        int sl = s.size();
        stack<int> bs;

        for (int i = 0; i < sl; i++)
        {
            switch (s[i])
            {
            case '(':
            case '{':
            case '[':
                bs.push(s[i]);
                break;

            case ')':
                if (bs.empty() || bs.top() != '(')
                {
                    return false;
                }
                bs.pop();
                break;

            case '}':
                if (bs.empty() || bs.top() != '{')
                {
                    return false;
                }
                bs.pop();
                break;

            case ']':
                if (bs.empty() || bs.top() != '[')
                {
                    return false;
                }
                bs.pop();
                break;

            default:
                return false;
                break;
            }
        }

        return bs.empty();
    }
};