/****************************************************
Date: Oct 11th, 2020
Successful submissions : 1
Time expiration : 1
Not Solved : 2
Wrong Answer/ Partial result : 0
link: https://leetcode.com/contest/weekly-contest-210
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
    Q: 1614. Maximum Nesting Depth of the Parentheses - correct
*/
class Solution
{
public:
    int maxDepth(string s)
    {
        int oc = 0;
        int ans = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                oc++;
            }
            else if (ch == ')')
            {
                oc--;
            }

            ans = max(ans, oc);
        }

        return ans;
    }
};

/*
    Q: 1615. Maximal Network Rank - solved looking at Discussion after time expired!!
*/
class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> connections(n, 0);

        set<pair<int, int>> adj;
        for (vector<int> &r : roads)
        {
            connections[r[0]]++;
            connections[r[1]]++;

            adj.insert({min(r[0], r[1]), max(r[0], r[1])});
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int c = (connections[i] + connections[j] - adj.count({i, j}));
                ans = max(ans, c);
            }
        }

        return ans;
    }
};

/*
    Q: 1616. Split Two Strings to Make Palindrome - initially, wrong answer and then time expired. After content over, looked at
    discussion and then solved it

    commented code is time limit exceeded
*/
class Solution
{
private:
    /*bool isPalindrome(const string& a)
  {
    int l = a.size();
    //printf("%s\n", a.c_str());
    for(int i = 0; i < l/2; ++i)
    {
      if(a[i] != a[l-i-1])
      {
        return false;
      }
    }
    
    return true;
  }*/

    bool check(string &a, string &b, int l, int r)
    {
        while (l >= 0 && a[l] == a[r])
        {
            --l;
            ++r;
        }

        {
            int left = l;
            int right = r;

            while ((left >= 0) && (a[left] == b[right]))
            {
                --left;
                ++right;
            }

            if (left < 0)
            {
                return true;
            }
        }

        {
            int left = l;
            int right = r;

            while ((left >= 0) && (b[left] == a[right]))
            {
                --left;
                ++right;
            }

            if (left < 0)
            {
                return true;
            }
        }

        return false;
    }

public:
    bool checkPalindromeFormation(string a, string b)
    {
        int l = a.size();
        /*if((l == 1) || isPalindrome(a) || isPalindrome(b))
    {
      return true;
    }*/

        int left = (l % 2 == 0) ? l / 2 - 1 : l / 2;
        int right = l / 2;

        return (check(a, b, left, right) || (check(b, a, left, right)));
        /*string rev_a = a;
    reverse(rev_a.begin(), rev_a.end());
    string rev_b = b;
    reverse(rev_b.begin(), rev_b.end());
    
    for(int i = 1; i < l; ++i)
    {
      string ap = a.substr(0, i);
      string bs = b.substr(i,l-i);
      string rev_bs = rev_b.substr(0, l-i);
      
      
      if((ap == rev_bs) || (isPalindrome(ap+bs)))
      {
        return true;
      }
      
      string bp = b.substr(0, i);
      string as = a.substr(i, l-i);
      string rev_as = rev_a.substr(0, l-i);
      if((bp == rev_as) || (isPalindrome(bp+as)))
      {
        return true;
      }
    }
    
    return false;*/
    }
};

/*
    Q: 1617. Count Subtrees With Max Distance Between Cities
*/
class Solution
{
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges)
    {
    }
};