
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

bool IsThereAPossiblePathTowardsEnd(vector<vector<int>> &m, int r, int c, vector<vector<int>> &p)
{
    if ((r == m.size() - 1) && (c == m[0].size() - 1))
    {
        if (m[r][c] != -1)
        {
            p[r][c] = 1;
            return true;
        }
        else
        {
            return false;
        }
    }

    if ((r <= m.size() - 1) && (c <= m[0].size() - 1) && (m[r][c] != -1))
    {
        p[r][c] = 1;

        if (IsThereAPossiblePathTowardsEnd(m, r, c + 1, p))
        {
            return true;
        }

        if (IsThereAPossiblePathTowardsEnd(m, r + 1, c, p))
        {
            return true;
        }

        //p[r][c] = 0;
    }

    return false;
}

bool IsThereAPossiblePathTowardsStart(vector<vector<int>> &m, int r, int c, vector<vector<int>> &p)
{
    if ((r == 0) && (c == 0))
    {
        if (m[0][0] != -1)
        {
            p[r][c] = 1;
            return true;
        }
        else
        {
            return false;
        }
    }

    if (r >= 0 && c >= 0 && m[r][c] != -1)
    {
        p[r][c] = 1;

        if (IsThereAPossiblePathTowardsStart(m, r, c - 1, p))
        {
            return true;
        }

        if (IsThereAPossiblePathTowardsStart(m, r - 1, c, p))
        {
            return true;
        }

        //p[r][c] = 0;
    }

    return false;
}

int collectMax(vector<vector<int>> mat)
{
    int r = mat.size();
    int c = mat[0].size();
    int result = 0;

    { //Find path to end
        vector<vector<int>> path(r, vector<int>(c, 0));
        if (!IsThereAPossiblePathTowardsEnd(mat, 0, 0, path) || path[r - 1][c - 1] == 0)
        {
            return 0;
        }

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; j++)
            {
                if (path[i][j] == 1)
                {
                    result += mat[i][j];
                    mat[i][j] = 0;
                }
            }
        }
    }

    { //Finding path to start
        vector<vector<int>> path(r, vector<int>(c, 0));
        if (!IsThereAPossiblePathTowardsStart(mat, r - 1, c - 1, path))
        {
            return 0;
        }

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (path[i][j] == 1)
                {
                    result += mat[i][j];
                    mat[i][j] = 0;
                }
            }
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> m = {{0, 1, 1}, {1, 0, -1}, {1, 1, -1}};
    printf("Count = %d", collectMax(m));

    return 0;
}