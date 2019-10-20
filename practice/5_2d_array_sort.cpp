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

int32_t SelectionSort2DArray(int32_t **&input, int32_t rows, int32_t columns)
{
    if ((!input) || (!*input) || ((rows <= 0) && (columns <= 0)) || (rows < 0) || (columns < 0))
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

int32_t Print2DArray(int32_t **&input, int32_t rows, int32_t columns)
{
    if ((!input) || (!*input) || ((rows <= 0) && (columns <= 0)) || (rows < 0) || (columns < 0))
    {
        return -1;
    }

    for (int32_t i = 0; i < rows; i++)
    {
        printf("[");
        for (int32_t j = 0; j < columns; j++)
        {
            printf(" %d", input[i][j]);
        }
        printf(" ]\n");
    }
}

int32_t Fill2DArray(int32_t **&input, int32_t &rows, int32_t &columns)
{
    printf("Enter num of Rows in array: ");
    scanf("%d", &rows);
    printf("Enter num of Rows in array: ");
    scanf("%d", &columns);

    input = new int *[rows];
    if (!input)
    {
        return -1;
    }

    printf("\nEnter the values for 2D array:\n");
    for (int32_t i = 0; i < rows; i++)
    {
        input[i] = new int[columns];
        for (int32_t j = 0; j < columns; j++)
        {
            scanf("%d", &input[i][j]);
        }
    }

    return 0;
}

int main()
{
    int32_t **array2D;

    int32_t rows;
    int32_t columns;
    int32_t result = Fill2DArray(array2D, rows, columns);
    if (result < 0)
    {
        exit(-1);
    }

    printf("\nGiven 2D array is:\n");
    result = Print2DArray(array2D, rows, columns);
    if (result < 0)
    {
        exit(-1);
    }

    result = SelectionSort2DArray(array2D, rows, columns);
    if (result < 0)
    {
        exit(-1);
    }

    printf("\nAfter sorting 2D array:\n");
    result = Print2DArray(array2D, rows, columns);
    if (result < 0)
    {
        exit(-1);
    }

    return 0;
}