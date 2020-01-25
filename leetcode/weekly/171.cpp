/****************************************************
Date: Jan 12, 2020
Successful submissions : 0
Time expiration : 0
Not Solved : 4
Wrong Answer/ Partial result : 0

Note: I was on vacation. Been to hometown for Makara Sankranti festival.

link: https://leetcode.com/contest/biweekly-contest-171
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

/*
    Q: 1317. Convert Integer to the Sum of Two No-Zero Integers - solved and accepted
*/
class Solution1_t
{
private:
    bool DoesContainZero(int n)
    {
        while (n > 0)
        {
            if (n % 10 == 0)
            {
                return true;
            }

            n = n / 10;
        }

        return false;
    }

public:
    vector<int> getNoZeroIntegers(int n)
    {
        int x = 0;
        int y = 0;

        do
        {
            x++;
            y = n - x;

            if (!DoesContainZero(x) && !DoesContainZero(y))
            {
                break;
            }
        } while (x < n);

        return {x, y};
    }
};

/*
    Q: 1318. Minimum Flips to Make a OR b Equal to c - solved and accepted
*/
class Solution2_t
{
private:
    vector<int> vA;
    vector<int> vB;
    vector<int> vC;

    void ConvertToBinary(int n, vector<int> &result)
    {
        while (n > 0)
        {
            result.push_back(n % 2);
            n /= 2;
        }
    }

    void AddZeros(int n, vector<int> &result)
    {
        while (n > 0)
        {
            result.push_back(0);
            n--;
        }
    }

    void SetToEqualLength(void)
    {
        int al = vA.size();
        int bl = vB.size();
        int cl = vC.size();

        int m = (al > bl) ? ((al > cl) ? al : cl) : ((bl > cl) ? bl : cl);
        if (m != al)
        {
            AddZeros(m - al, vA);
        }

        if (m != bl)
        {
            AddZeros(m - bl, vB);
        }

        if (m != cl)
        {
            AddZeros(m - cl, vC);
        }
    }

public:
    int minFlips(int a, int b, int c)
    {
        ConvertToBinary(a, vA);
        ConvertToBinary(b, vB);
        ConvertToBinary(c, vC);

        SetToEqualLength();

        //Now try to get the flip count!
        int result = 0;
        int n = vC.size();
        for (int i = 0; i < n; i++)
        {
            if (vC[i] > 0)
            {
                if ((vA[i] == 0) && (vB[i] == 0))
                {
                    result++;
                }
            }
            else
            {
                if (vA[i] != 0)
                {
                    result++;
                }
                if (vB[i] != 0)
                {
                    result++;
                }
            }
        }

        return result;
    }
};

/*
    Q: 1319. Number of Operations to Make Network Connected - Not solved
*/
class Solution3_t
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
    }
};

/*
    Q: 1320. Minimum Distance to Type a Word Using Two Fingers - Not complete!!
*/
class Solution4_t
{
private:
    vector<vector<int>> d;
    int result;

    void GetSubStrings(int p1, int p2, const string &s, string &s1, string &s2)
    {
        s1 = "";
        s2 = "";
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if ((i < p1) || (i > p2))
            {
                s1 += s[i];
            }
            else
            {
                s2 += s[i];
            }
        }
    }

    int CalculateTheCost(const string &s)
    {
        int retVal = 0;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            retVal += d[s[i - 1] - 'A'][s[i] - 'A'];
        }

        return retVal;
    }

    void CalculateAndUpdateTheMin(const string &s1, const string &s2)
    {
        result = min(result, (CalculateTheCost(s1) + CalculateTheCost(s2)));
    }

public:
    Solution4_t()
        : d(26, vector<int>(26, 0)),
          result(1 << 30)
    {
        //Fill the positions as per the keyboard layout
        int r = 0;
        int c = 0;
        map<int, vector<int>> p;
        for (int i = 0; i < 26; i++)
        {
            if ((i >= 6) && (i % 6 == 0))
            {
                r++;
            }
            c = i % 6;

            p[i + 'A'] = {r, c};

            //printf("key = %c [%d, %d]\n", i + 'A', r, c);
        }

        //Fill the distances between the characters!
        for (int i = 0; i < 26; i++)
        {
            vector<int> ci = p[i + 'A'];
            for (int j = 0; j < 26; j++)
            {
                vector<int> cj = p[j + 'A'];

                d[i][j] = (ci[0] > cj[0] ? ci[0] - cj[0] : cj[0] - ci[0]) + (ci[1] > cj[1] ? ci[1] - cj[1] : cj[1] - ci[1]);
                //printf("%d, ", d[i][j]);
            }
            //printf("\n");
        }
    }

    int minimumDistance(string word)
    {
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                string s1;
                string s2;
                //TODO: Pass the positions for the second sub string calculated from i and j
                GetSubStrings(j, i, word, s1, s2);

                if ((s1.size() > 0) && (s2.size() > 0))
                {
                    CalculateAndUpdateTheMin(s1, s2);
                }
            }
        }

        return result;
    }
};

int main(void)
{
    {
        Solution4_t s4;
        printf("%d\n", s4.minimumDistance("CAKE"));
    }
    {
        Solution4_t s4;
        printf("%d\n", s4.minimumDistance("HAPPY"));
    }
    {
        Solution4_t s4;
        printf("%d\n", s4.minimumDistance("NEW"));
    }
    {
        Solution4_t s4;
        printf("%d\n", s4.minimumDistance("YEAR"));
    }
}