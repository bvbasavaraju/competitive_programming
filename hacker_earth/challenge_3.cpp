
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

// bool IsThereAPossiblePathTowardsEnd(vector<vector<int>> &m, int r, int c, vector<vector<int>> &p)
// {
//     if ((r == m.size() - 1) && (c == m[0].size() - 1))
//     {
//         if (m[r][c] != -1)
//         {
//             p[r][c] = 1;
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }

//     if ((r <= m.size() - 1) && (c <= m[0].size() - 1) && (m[r][c] != -1))
//     {
//         p[r][c] = 1;

//         if (IsThereAPossiblePathTowardsEnd(m, r, c + 1, p))
//         {
//             return true;
//         }

//         if (IsThereAPossiblePathTowardsEnd(m, r + 1, c, p))
//         {
//             return true;
//         }

//         //p[r][c] = 0;
//     }

//     return false;
// }

// bool IsThereAPossiblePathTowardsStart(vector<vector<int>> &m, int r, int c, vector<vector<int>> &p)
// {
//     if ((r == 0) && (c == 0))
//     {
//         if (m[0][0] != -1)
//         {
//             p[r][c] = 1;
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }

//     if (r >= 0 && c >= 0 && m[r][c] != -1)
//     {
//         p[r][c] = 1;

//         if (IsThereAPossiblePathTowardsStart(m, r, c - 1, p))
//         {
//             return true;
//         }

//         if (IsThereAPossiblePathTowardsStart(m, r - 1, c, p))
//         {
//             return true;
//         }

//         //p[r][c] = 0;
//     }

//     return false;
// }

// int collectMax(vector<vector<int>> mat)
// {
//     int r = mat.size();
//     int c = mat[0].size();
//     int result = 0;

//     { //Find path to end
//         vector<vector<int>> path(r, vector<int>(c, 0));
//         if (!IsThereAPossiblePathTowardsEnd(mat, 0, 0, path) || path[r - 1][c - 1] == 0)
//         {
//             return 0;
//         }

//         for (int i = 0; i < r; ++i)
//         {
//             for (int j = 0; j < c; j++)
//             {
//                 if (path[i][j] == 1)
//                 {
//                     result += mat[i][j];
//                     mat[i][j] = 0;
//                 }
//             }
//         }
//     }

//     { //Finding path to start
//         vector<vector<int>> path(r, vector<int>(c, 0));
//         if (!IsThereAPossiblePathTowardsStart(mat, r - 1, c - 1, path))
//         {
//             return 0;
//         }

//         for (int i = 0; i < r; ++i)
//         {
//             for (int j = 0; j < c; ++j)
//             {
//                 if (path[i][j] == 1)
//                 {
//                     result += mat[i][j];
//                     mat[i][j] = 0;
//                 }
//             }
//         }
//     }

// return result;
// }

/*void collectRiderTowardsStart(vector<vector<int>> &mat, int i, int j, int &ans, bool &reached)
{
    if (i < 0 || j < 0 || mat[i][j] < 0 || reached)
    {
        return;
    }

    ans += mat[i][j];
    mat[i][j] = 0;

    if (i == 0 && j == 0)
    {
        reached = true;
    }

    if (!reached)
    {
        collectRiderTowardsStart(mat, i, j - 1, ans, reached);
        collectRiderTowardsStart(mat, i - 1, j, ans, reached);
    }
}

void collectRiderTowardsEnd(vector<vector<int>> &mat, int i, int j, int r, int c, int &ans, bool &reached)
{
    if (i >= r || j >= c || mat[i][j] < 0 || reached)
    {
        return;
    }

    ans += mat[i][j];
    mat[i][j] = 0;

    if (((r - 1) == i) && ((c - 1) == j))
    {
        reached = true;
    }

    if (!reached)
    {
        collectRiderTowardsEnd(mat, i, j + 1, r, c, ans, reached);
        collectRiderTowardsEnd(mat, i + 1, j, r, c, ans, reached);
    }
}

int collectMax(vector<vector<int>> mat)
{
    int ans = 0;

    int r = mat.size();
    if (r <= 0)
    {
        return 0;
    }
    int c = mat[0].size();

    bool reachedEnd = false;
    collectRiderTowardsEnd(mat, 0, 0, r, c, ans, reachedEnd);
    if (!reachedEnd)
    {
        ans = 0;
    }
    else
    {
        bool reachedStart = false;
        collectRiderTowardsStart(mat, r - 1, c - 1, ans, reachedStart);
        if (!reachedStart)
        {
            return 0;
        }
    }

    return ans;
}*/

bool collectRiderTowardsStart(vector<vector<int>> &mat, int i, int j, int &ans)
{
    if (i < 0 || j < 0 || mat[i][j] < 0)
    {
        return false;
    }

    int value_added = mat[i][j];
    ans += mat[i][j];
    mat[i][j] = 0;

    if (i == 0 && j == 0)
    {
        return true;
    }

    if (!collectRiderTowardsStart(mat, i, j - 1, ans))
    {
        mat[i][j] = value_added;
        ans -= value_added;
        return false;
    }
    if (!collectRiderTowardsStart(mat, i - 1, j, ans))
    {
        mat[i][j] = value_added;
        ans -= value_added;
        return false;
    }

    return true;
}

bool collectRiderTowardsEnd(vector<vector<int>> &mat, int i, int j, int r, int c, int &ans)
{
    if (i >= r || j >= c || mat[i][j] < 0)
    {
        return false;
    }

    int value_added = mat[i][j];
    ans += mat[i][j];
    mat[i][j] = 0;

    if (((r - 1) == i) && ((c - 1) == j))
    {
        return true;
    }

    if (!collectRiderTowardsEnd(mat, i, j + 1, r, c, ans))
    {
        mat[i][j] = value_added;
        ans -= value_added;
        return false;
    }
    if (!collectRiderTowardsEnd(mat, i + 1, j, r, c, ans))
    {
        mat[i][j] = value_added;
        ans -= value_added;
        return false;
    }

    return true;
}

int collectMax(vector<vector<int>> mat)
{
    int ans = 0;

    int r = mat.size();
    if (r <= 0)
    {
        return 0;
    }
    int c = mat[0].size();

    // if (!collectRiderTowardsEnd(mat, 0, 0, r, c, ans))
    // {
    //     ans = 0;
    // }
    // else
    // {
    //     if (!collectRiderTowardsStart(mat, r - 1, c - 1, ans))
    //     {
    //         ans = 0;
    //     }
    // }
    int lastValue = mat[r - 1][c - 1];
    if (lastValue < 0)
    {
        return 0;
    }

    ans = 0;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (mat[i][j] < 0)
            {
                continue;
            }

            if (i == 0 && j == 0)
            {
                //nothing to do
            }
            else if (i == 0)
            {
                mat[i][j] += mat[i][j - 1];
                mat[i][j - 1] = 0;
            }
            else if (j == 0)
            {
                mat[i][j] += mat[i - 1][j];
                mat[i - 1][j] = 0;
            }
            else
            {
                if (mat[i][j - 1] >= mat[i - 1][j])
                {
                    mat[i][j] += mat[i][j - 1];
                    mat[i][j - 1] = 0;
                }
                else
                {
                    mat[i][j] += mat[i - 1][j];
                    mat[i - 1][j] = 0;
                }
            }
        }
    }

    ans += mat[r - 1][c - 1];
    mat[r - 1][c - 1] = 0;
    for (int i = r - 1; i >= 0; --i)
    {
        for (int j = c - 1; j >= 0; --j)
        {
            if (mat[i][j] < 0)
            {
                continue;
            }
            if (i == r - 1 && j == c - 1)
            {
                //nothing to do
            }
            else if (i == r - 1)
            {
                mat[i][j] += mat[i][j + 1];
                mat[i][j + 1] = 0;
            }
            else if (j == c - 1)
            {
                mat[i][j] += mat[i + 1][j];
                mat[i + 1][j] = 0;
            }
            else
            {
                if (mat[i][j + 1] >= mat[i + 1][j])
                {
                    mat[i][j] += mat[i][j + 1];
                    mat[i][j + 1] = 0;
                }
                else
                {
                    mat[i][j] += mat[i + 1][j];
                    mat[i + 1][j] = 0;
                }
            }
        }
    }
    ans += mat[0][0] + 1;

    return ans;
}

int main()
{
    vector<vector<int>> m = {{0, 1, 1}, {1, 0, -1}, {1, 1, -1}};
    printf("Count = %d", collectMax(m));

    return 0;
}