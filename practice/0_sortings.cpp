#include <iostream>
#include <vector>

using namespace std;
class Sorting_t
{
public:
    typedef enum
    {
        SORTING_TYPE_SELECTION = 0, //Time Complexity : O(n2)
        SORTING_TYPE_INSERTION = 1, //Time Complexity : O(n2)
        SORTING_TYPE_MERGE = 2,     //Time Complexity : nLog(n); But needs additional space for sorting
    } Type_t;

private:
    int SelectionSort(vector<int> &data)
    {
        int count = data.size();
        if (count <= 0)
        {
            return -1;
        }

        for (int i = 0; i < (count - 1); i++)
        {
            int minPos = i;
            for (int j = (i + 1); j < count; j++)
            {
                if (data[j] < data[minPos])
                {
                    minPos = j;
                }
            }

            swap(data[i], data[minPos]);
        }
    }

    int InsersionSort(vector<int> &data)
    {
        int loopCount = data.size();
        if (loopCount <= 0)
        {
            return -1;
        }

        for (int i = 0; i < (loopCount - 1); i++)
        {
            for (int j = (i + 1); j > 0; j--)
            {
                if (data[j] < data[j - 1])
                {
                    swap(data[j], data[j - 1]);
                }
                else
                {
                    break;
                }
            }
        }
        return 0;
    }

    void Merge(vector<int> &data, vector<int> &dataCopy, int lowerIndex, int median, int higherIndex)
    {
        // printf("\nBefore sort: ");
        for (int i = lowerIndex; i <= higherIndex; i++)
        {
            // printf("%d,", data[i]);
            dataCopy[i] = data[i];
        }

        int i = lowerIndex;
        int j = median + 1;
        for (int k = lowerIndex; k <= higherIndex; k++)
        {
            if (i > median)
            {
                data[k] = dataCopy[j++];
            }
            else if (j > higherIndex)
            {
                data[k] = dataCopy[i++];
            }
            else if (dataCopy[i] < dataCopy[j])
            {
                data[k] = dataCopy[i++];
            }
            else
            {
                data[k] = dataCopy[j++];
            }
        }

        // printf("\nAfter sort: ");
        // for (int i = lowerIndex; i <= higherIndex; i++)
        // {
        //     printf("%d,", data[i]);
        // }
    }

    void MergeSort(vector<int> &data, vector<int> &dataCopy, int lowerIndex, int higherIndex)
    {
        if (lowerIndex < higherIndex)
        {
            int median = lowerIndex + (higherIndex - lowerIndex) / 2;

            MergeSort(data, dataCopy, lowerIndex, median);
            MergeSort(data, dataCopy, (median + 1), higherIndex);

            Merge(data, dataCopy, lowerIndex, median, higherIndex);
        }
    }

    //TODO
    void QuickSort(vector<int> &data)
    {
    }

public:
    int Sort(vector<int> &input, Sorting_t::Type_t type)
    {
        switch (type)
        {
        case Sorting_t::SORTING_TYPE_SELECTION:
            return SelectionSort(input);
            break;

        case Sorting_t::SORTING_TYPE_INSERTION:
            return InsersionSort(input);
            break;

        case Sorting_t::SORTING_TYPE_MERGE:
        {
            vector<int> inputCopy;
            for (int i : input)
            {
                inputCopy.push_back(i);
            }
            MergeSort(input, inputCopy, 0, (input.size() - 1));
        }

        default:
            return -1;
            break;
        }
    }
};

int main()
{
    vector<int> data = {2, 3, 1, 4, 8, 10, 7, 6, 9, 5};
    printf("\nBefore sort: ");
    for (int i : data)
    {
        printf("%d, ", i);
    }

    Sorting_t sorting;
    sorting.Sort(data, Sorting_t::SORTING_TYPE_SELECTION);
    //sorting.Sort(data, Sorting_t::SORTING_TYPE_INSERTION);
    //sorting.Sort(data, Sorting_t::SORTING_TYPE_MERGE);

    printf("\nAfter sort: ");
    for (int i : data)
    {
        printf("%d, ", i);
    }

    return 0;
}