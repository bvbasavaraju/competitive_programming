// Sort 2D Array :
// 1st trial - (start time : 11 : 45 AM IST, end time : 12 : 25PM) - need to improve!
//Ex : Input : [ [ 5, 12, 17, 21, 23 ],
//                      [ 1, 2, 4, 6, 8 ],
//                      [ 12, 14, 18, 19, 27 ],
//                      [ 3, 7, 9, 15, 25 ] ]

//      Output : [ [ 1, 2, 3, 4, 5 ],
//                        [ 6, 7, 8, 9, 12 ],
//                        [ 12, 14, 15, 17, 18 ],
//                        [ 19, 21, 23, 25, 27 ] ]

//2D arrays are basically 1D arrays internally. So, we can use any sorting
//algorithms like selection sort/bubble sort. For now I will use the selection sort.
//I will C++ as my programming language!

//Approach
// function is going to return -1 on failure!

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Simplified2DArrayDimension_t
{
private:
    int32_t rows;
    int32_t columns;

public:
    Simplified2DArrayDimension_t(int32_t rows_, int32_t columns_)
        : rows(rows_), columns(columns_)
    {
    }

    ~Simplified2DArrayDimension_t()
    {
    }

    void Get2DimensionEquivalent(int32_t indexIn1D, int32_t &row, int32_t &column)
    {
        row = (indexIn1D) / columns;
        column = (indexIn1D) % columns;
    }
};

int32_t SelectionSort2DArray(vector<vector<int32_t>> &input)
{
    int32_t rows = input.size();
    if (rows <= 0)
    {
        return -1;
    }
    int32_t columns = input.at(0).size(); //Assumptions. Each rows will have same number of columns!
    if (columns <= 0)
    {
        return -1;
    }

    Simplified2DArrayDimension_t simDim(rows, columns);
    int32_t totalEntries = rows * columns;

    //Since it is a loop. Time complexity is: O(n)
    for (int32_t i = 0; i < (totalEntries - 1); i++)
    {
        int32_t minPos = i;
        int32_t iRow = 0;
        int32_t iColumn = 0;
        simDim.Get2DimensionEquivalent(i, iRow, iColumn);

        //Initially it is assumed ith row and column is the minimum;
        int32_t minRowIndex = iRow;
        int32_t minColumnIndex = iColumn;

        //Since it is a loop. Time complexity is: O(n)
        for (int32_t j = (i + 1); j < totalEntries; j++)
        {
            int32_t jRow = 0;
            int32_t jColumn = 0;
            simDim.Get2DimensionEquivalent(j, jRow, jColumn);
            if (input[jRow][jColumn] < input[minRowIndex][minColumnIndex])
            {
                minRowIndex = jRow;
                minColumnIndex = jColumn;
            }
        }

        //Swap the values
        if ((minRowIndex != iRow) || (minColumnIndex != iColumn))
        {
            int32_t temp = input[minRowIndex][minColumnIndex];
            input[minRowIndex][minColumnIndex] = input[iRow][iColumn];
            input[iRow][iColumn] = temp;
        }
    }

    return 0;
}

int32_t Print2DArray(vector<vector<int32_t>> &input)
{
    for (auto i : input)
    {
        printf("[");
        for (auto j : i)
        {
            printf(" %d", j);
        }
        printf(" ]\n");
    }
}

int main()
{
    vector<vector<int32_t>> array2D = {{5, 12, 17, 21, 23}, {1, 2, 4, 6, 8}, {12, 14, 18, 19, 27}, {3, 7, 9, 15, 25}};

    printf("\nGiven 2D array is:\n");
    int32_t result = Print2DArray(array2D);
    if (result < 0)
    {
        exit(-1);
    }

    result = SelectionSort2DArray(array2D);
    if (result < 0)
    {
        exit(-1);
    }

    printf("\nAfter sorting 2D array:\n");
    result = Print2DArray(array2D);
    if (result < 0)
    {
        exit(-1);
    }

    return 0;
}