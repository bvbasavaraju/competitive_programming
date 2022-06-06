#include<bits/stdc++.h>
using namespace std;

bool isPossible(string s1, string s2, string op, int p, const string& c)
{
    if(p > 0 && op.back() != c[p-1])
    {
        return false;
    }

    if(op == c)
    {
        return true;
    }

    if(s1.empty())
    {
        if(op + s2 == c)
        {
            return true;
        }

        return false;
    }

    if(s2.empty())
    {
        if(op + s1 == c)
        {
            return true;
        }

        return false;
    }

    string op1 = op + s1[0];
    string op2 = op + s2[0];
    return isPossible(s1.substr(1), s2, op1, p+1, c) || isPossible(s1, s2.substr(1), op2, p+1, c);
}

int Solution::isInterleave(string A, string B, string C) 
{
    string str;
    return isPossible(A, B, str, 0, C);
}
