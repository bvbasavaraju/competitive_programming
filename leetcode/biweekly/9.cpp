/****************************************************
Date: September 21, 2019
Successful submissions : 2
Time expiration : 0 
Not Solved : 2
****************************************************/
/*
    Q: How Many Apples Can You Put into the Basket
        You have some apples, where arr[i] is the weight of the i-th apple.  
        You also have a basket that can carry up to 5000 units of weight.
        Return the maximum number of apples you can put in the basket.

    Ex:
        Input: arr = [100,200,150,1000]
        Output: 4
        Explanation: All 4 apples can be carried by the basket since their sum of weights is 1450.

        Input: arr = [900,950,800,1000,700,800]
        Output: 5
        Explanation: The sum of weights of the 6 apples exceeds 5000 so we choose any 5 of them.
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution1
{
private:
    class Basket_t
    {
    private:
        int capacity;
        int currentWeight;
        int count;

    public:
        Basket_t(int maxWeight_)
            : capacity(maxWeight_),
              currentWeight(0),
              count(0)
        {
        }
        ~Basket_t() {}

        int AddWeight(int weight)
        {
            if (weight < 0)
            {
                return -1;
            }

            if ((currentWeight + weight) <= capacity)
            {
                currentWeight += weight;
                count++;
            }

            return 0;
        }

        int Count(void)
        {
            return count;
        }
    };

    int InsersionSort(vector<int> &input)
    {
        int loopCount = input.size();
        if (loopCount <= 0)
        {
            return -1;
        }

        for (int i = 0; i < (loopCount - 1); i++)
        {
            for (int j = (i + 1); j > 0; j--)
            {
                if (input[j] < input[j - 1])
                {
                    swap(input[j], input[j - 1]);
                }
                else
                {
                    break;
                }
            }
        }
        return 0;
    }

public:
    int maxNumberOfApples(vector<int> &arr)
    {
        Basket_t basket(5000);
        int sortResult = InsersionSort(arr);
        if (sortResult < 0)
        {
            return 0;
        }

        for (int i : arr)
        {
            basket.AddWeight(i);
        }

        return basket.Count();
    }
};

// int main()
// {
//     Solution1 s1;
//     //vector<int> input = {900, 950, 800, -1000, 700, 800};
//     vector<int> input = {988, 641, 984, 635, 461, 527, 491, 610, 274, 104, 348, 468, 220, 837, 126, 111, 536, 368, 89, 201, 589, 481, 849, 708, 258, 853, 563, 868, 92, 76, 566, 398, 272, 697, 584, 851, 302, 766, 88, 428, 276, 797, 460, 244, 950, 134, 838, 161, 15, 330};

//     int possibleAppleCount = s1.maxNumberOfApples(input);
//     printf("Apple Count: %d", possibleAppleCount);

//     return 0;
// }

/*
    Q: Minimum Knight Moves
    In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].    
    A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, 
    then one square in an orthogonal direction.

    Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.

    Ex:
        Input: x = 2, y = 1
        Output: 1
        Explanation: [0, 0] → [2, 1]

        Input: x = 5, y = 5
        Output: 4
        Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]

    link:   https://leetcode.com/contest/biweekly-contest-9/problems/minimum-knight-moves/
*/

/*
    Q: Find Smallest Common Element in All Rows
    Given a matrix mat where every row is sorted in increasing order, return the smallest common element in all rows.
    If there is no common element, return -1.

    Ex:
        Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
        Output: 5
*/

class Solution2
{
private:
    bool IsPresent(int num, vector<int> numToSearch)
    {
        bool retVal = false;
        for (int i : numToSearch)
        {
            if (num == i)
            {
                retVal = true;
                break;
            }
        }

        return retVal;
    }

public:
    int smallestCommonElement(vector<vector<int>> &mat)
    {
        vector<int> firstEntry = mat[0];
        int numOfRows = mat.size();
        int retVal = -1;

        int foundCount = 0;

        for (int i : firstEntry)
        {
            foundCount = 1;
            for (int j = 1; j < numOfRows; j++)
            {
                if (IsPresent(i, mat[j]))
                {
                    foundCount++;
                }
            }
            if (foundCount == numOfRows)
            {
                retVal = i;
                break;
            }
        }

        return retVal;
    }
};

int main()
{
    vector<vector<int>> input = {{1, 2, 3, 4, 5}, {2, 4, 5, 8, 10}, {3, 5, 7, 9, 11}, {1, 3, 5, 7, 9}};
    Solution2 s2;

    int lowest = s2.smallestCommonElement(input);
    printf("Lowest is: %d", lowest);

    return 0;
}

/*
    Q: Minimum Time to Build Blocks
    You are given a list of blocks, where blocks[i] = t means that the i-th block needs t units of time to be built.
    A block can only be built by exactly one worker.

    A worker can either split into two workers (number of workers increases by one) or build a block then go home.
    Both decisions cost some time.

    The time cost of spliting one worker into two workers is given as an integer split. 
    Note that if two workers split at the same time, they split in parallel so the cost would be split.

    Output the minimum time needed to build all blocks.

    Initially, there is only one worker.

    Ex:
        Input: blocks = [1], split = 1
        Output: 1
        Explanation: We use 1 worker to build 1 block in 1 time unit.

        Input: blocks = [1,2], split = 5
        Output: 7
        Explanation: We split the worker into 2 workers in 5 time units then assign each of them to a block so the cost is 5 + max(1, 2) = 7.

        Input: blocks = [1,2,3], split = 1
        Output: 4
        Explanation: Split 1 worker into 2, then assign the first worker to the last block and split the second worker into 2.
        Then, use the two unassigned workers to build the first two blocks.
        The cost is 1 + max(3, 1 + max(1, 2)) = 4.

    link: https://leetcode.com/contest/biweekly-contest-9/problems/minimum-time-to-build-blocks/
*/