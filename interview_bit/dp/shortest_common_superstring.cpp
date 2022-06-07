#include<bits/stdc++.h>
using namespace std;

string getLeastCommonSuperString(const string& s1, const string& s2)
{
    int l1 = s1.size();
    int l2 = s2.size();

    vector< vector<int> > length(l1+1, vector<int>(l2+1, 0));
    length[0][0] = 1;

    for(int i = 1; i <= l1; ++i)
    {
        for(int j = 1; j <= l2; ++j)
        {
            if(s1[i-1] == s2[j-1])
            {
                length[i][j] = 1 + length[i-1][i-j];
            }
            else
            {
                length[i][j] = max(length[i-1][j], length[i][j-1]);
            }
        }
    }

    //fetch the superstring;
    int i = l1;
    int j = l2;
    string ans = "";
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            ans = s1[i-1] + ans;
            i--;
            j--;
        }
        else
        {
            if(length[i-1][j] < length[i][j-1])
            {
                ans = s2[j-1] + ans;
                j--;
            }
            else if(length[i-1][j] > length[i][j-1])
            {
                ans = s1[i-1] + ans;
                i--;
            }
            else
            {
                ans = s1[i-1] + ans;
                i--;
            }
        }
    }

    while(i > 0)
    {
        ans = s1[i-1] + ans;
        i--;
    }
    while(j > 0)
    {
        ans = s2[j-1] + ans;
        j--;
    }

    return ans;
}

int Solution::solve(vector<string> &A) 
{
    string ans = "";
    for(string s : A)
    {
        ans = getLeastCommonSuperString(ans, s);
    }

    return ans.size();
}
