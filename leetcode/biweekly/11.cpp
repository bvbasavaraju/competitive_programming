/****************************************************
Date: October 19, 2019
Successful submissions : 1
Time expiration : 1
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-11
****************************************************/

/*
    5088. Missing Number In Arithmetic Progression

    In some array arr, the values were in arithmetic progression: 
    the values arr[i+1] - arr[i] are all equal for every 0 <= i < arr.length - 1.

    Then, a value from arr was removed that was not the first or last value in the array.

    Return the removed value.

    Ex:
    Input: arr = [5,7,11,13]
    Output: 9
    Explanation: The previous array was [5,7,9,11,13].

    Input: arr = [15,13,12]
    Output: 14
    Explanation: The previous array was [15,14,13,12].

    Constraints:
    3 <= arr.length <= 1000
    0 <= arr[i] <= 10^5
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution1_t
{
private:
    struct ApDiffWithPositions_t
    {
        int pos1;
        int pos2;
        int diff;

        ApDiffWithPositions_t(int pos1_, int pos2_)
        {
            pos1 = pos1_;
            pos2 = pos2_;
            diff = pos2 - pos1;
        }
    };

public:
    int missingNumber(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
        {
            return 0;
        }

        ApDiffWithPositions_t data(arr[0], arr[1]);
        int appDiff = data.diff;
        for (int i = 2; i < n; i++)
        {
            ApDiffWithPositions_t temp(arr[i - 1], arr[i]);

            if (temp.diff > 0)
            {
                if (temp.diff < data.diff)
                {
                    return data.pos1 + temp.diff;
                }
                else
                {
                    appDiff = (temp.diff < appDiff) ? temp.diff : appDiff;

                    //this is part of the sequence which has the missing number in between
                    data.pos1 = temp.pos1;
                    data.pos2 = temp.pos2;
                    data.diff = temp.diff;
                }
            }
            else
            {
                if (temp.diff > data.diff)
                {
                    return data.pos1 + temp.diff;
                }
                else
                {
                    appDiff = (temp.diff > appDiff) ? temp.diff : appDiff;

                    //this is part of the sequence which has the missing number in between
                    data.pos1 = temp.pos1;
                    data.pos2 = temp.pos2;
                    data.diff = temp.diff;
                }
            }
        }

        return data.pos1 + appDiff;
    }
};

/*
    Q: 5089. Meeting Scheduler
    Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, 
    return the earliest time slot that works for both of them and is of duration duration.

    If there is no common time slot that satisfies the requirements, return an empty array.

    The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.  

    It is guaranteed that no two availability slots of the same person intersect with each other. 
    That is, for any two time slots [start1, end1] and [start2, end2] of the same person, 
    either start1 > end2 or start2 > end1.

    Ex:
    Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
    Output: [60,68]

    Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
    Output: []

    Constraints:
    1 <= slots1.length, slots2.length <= 10^4
    slots1[i].length, slots2[i].length == 2
    slots1[i][0] < slots1[i][1]
    slots2[i][0] < slots2[i][1]
    0 <= slots1[i][j], slots2[i][j] <= 10^9
    1 <= duration <= 10^6 
*/

#include <algorithm>

class Solution2_t
{
private:
    int RemoveImpossibleSlots(vector<vector<int>> &data, int duration)
    {
        int length = data.size();
        for (vector<vector<int>>::iterator it = data.begin(); it != data.end();)
        {
            if (it->size() != 2)
            {
                return -1;
            }

            int diff = (*it)[0] - (*it)[1];
            if (diff < 0)
            {
                diff = diff * -1;
            }

            if (diff < duration)
            {
                data.erase(it);
            }
            else
            {
                it++;
            }
        }

        return 0;
    }

    bool IsSchedulableSlot(vector<int> slot1, vector<int> slot2, int duration, vector<int> &result)
    {
        int start = max(slot1[0], slot2[0]);
        int end = min(slot1[1], slot2[1]);

        if ((start > end) || ((start + duration) > end))
        {
            return false;
        }

        result.push_back(start);
        result.push_back(start + duration);
        return true;
    }

public:
    static bool minInVector(vector<int> i, vector<int> j)
    {
        return (i[0] < j[0]);
    }
    vector<int> minAvailableDuration(vector<vector<int>> &slots1, vector<vector<int>> &slots2, int duration)
    {
        vector<int> retVal;

        //Get rid of the impossible slots. slots whose dration is shorter than required.
        if (RemoveImpossibleSlots(slots1, duration) < 0)
        {
            retVal;
        }
        if (RemoveImpossibleSlots(slots2, duration) < 0)
        {
            retVal;
        }

        //Sort the slots in ascending order
        //sort(slots1.begin, slots1.end(), Solution::minInVector);
        //sort(slots1.begin, slots1.end());
        int slot1Length = slots1.size();
        int slot2Length = slots2.size();
        for (int i = 0; i < slot1Length; i++)
        {
            vector<int> slot1Data = slots1[i];
            for (int j = 0; j < slot2Length; j++)
            {
                vector<int> slot2Data = slots2[j];
                vector<int> schedulableSlot;
                if (IsSchedulableSlot(slot1Data, slot2Data, duration, schedulableSlot))
                {
                    if (retVal.empty() || (retVal[0] > schedulableSlot[0]))
                    {
                        retVal = schedulableSlot;
                    }
                }
            }
        }

        return retVal;
    }
};

/*
    Q: Toss Strange Coins

    You have some coins.  The i-th coin has a probability prob[i] of facing heads when tossed.

    Return the probability that the number of coins facing heads equals target if you toss every coin exactly once.

    EX:
    Input: prob = [0.4], target = 1
    Output: 0.40000

    Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
    Output: 0.03125

    Constraints:
    1 <= prob.length <= 1000
    0 <= prob[i] <= 1
    0 <= target <= prob.length
    Answers will be accepted as correct if they are within 10^-5 of the correct answer.
*/

class Solution3_t
{
public:
    double probabilityOfHeads(vector<double> &prob, int target)
    {
    }
};

/*
    Q: Divide Chocolate

    You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

    You want to share the chocolate with your K friends so you start cutting the chocolate bar into K+1 pieces using K cuts,
    each piece consists of some consecutive chunks.

    Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

    Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

    Ex:
    Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
    Output: 6
    Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]

    Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
    Output: 1
    Explanation: There is only one way to cut the bar into 9 pieces.

    Input: sweetness = [1,2,2,1,2,2,1,2,2], K = 2
    Output: 5
    Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]

    Constraints:
    0 <= K < sweetness.length <= 10^4
    1 <= sweetness[i] <= 10^5
*/

class Solution4_t
{
public:
    int maximizeSweetness(vector<int> &sweetness, int K)
    {
    }
};

int main()
{
    // {
    //     Solution1_t s;
    //     vector<int> input = {80387, 68178, 55969, 31551};
    //     s.missingNumber(input);
    //     return 0;
    // }

    {
        Solution2_t s;
        vector<vector<int>> slots1 = {{10, 50}, {60, 120}, {140, 210}};
        vector<vector<int>> slots2 = {{0, 15}, {60, 70}};
        int duration = 8;

        vector<int> schedulableSlot = s.minAvailableDuration(slots1, slots2, duration);
    }
}
