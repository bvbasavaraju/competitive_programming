
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

int droppedRequests(vector<int> requestTime)
{
    int l = requestTime.size();
    if (l <= 0)
    {
        return 0;
    }

    struct Requests_t
    {
        uint32_t count;
        uint32_t totalCount;
        uint32_t excessCount;
        uint32_t totalOneSecWindowExcessCount;
        uint32_t totalTenSecWindowExcessCount;
        uint32_t totalSixtySecWindowExcessCount;
    };

    //map<int, Requests_t> reqsAtTimeT;
    unordered_map<int, Requests_t> reqsAtTimeT;
    reqsAtTimeT[requestTime[0]].count++;
    reqsAtTimeT[requestTime[0]].totalCount++;
    reqsAtTimeT[requestTime[0]].excessCount = 0;
    reqsAtTimeT[requestTime[0]].totalOneSecWindowExcessCount = 0;
    reqsAtTimeT[requestTime[0]].totalTenSecWindowExcessCount = 0;
    reqsAtTimeT[requestTime[0]].totalSixtySecWindowExcessCount = 0;

    for (int i = 1; i < l; ++i)
    {
        int currTimeT = requestTime[i];
        int prevTimeT = requestTime[i - 1];

        if ((currTimeT - prevTimeT) > 1)
        {
            for (int j = prevTimeT + 1; j < currTimeT; ++j)
            {
                reqsAtTimeT[j].count = 0;
                reqsAtTimeT[j].totalCount = reqsAtTimeT[j - 1].totalCount;
                reqsAtTimeT[j].excessCount = 0;
                reqsAtTimeT[j].totalOneSecWindowExcessCount = reqsAtTimeT[j - 1].totalOneSecWindowExcessCount;
                reqsAtTimeT[j].totalTenSecWindowExcessCount = reqsAtTimeT[j - 1].totalTenSecWindowExcessCount;
                reqsAtTimeT[j].totalSixtySecWindowExcessCount = reqsAtTimeT[j - 1].totalSixtySecWindowExcessCount;
            }
        }

        reqsAtTimeT[currTimeT].count++;
        reqsAtTimeT[currTimeT].totalCount++;
        if (reqsAtTimeT[currTimeT].count > 3)
        {
            reqsAtTimeT[currTimeT].excessCount++;
            reqsAtTimeT[currTimeT].totalOneSecWindowExcessCount++;
        }

        if (currTimeT != prevTimeT)
        {
            reqsAtTimeT[currTimeT].totalCount += reqsAtTimeT[currTimeT - 1].totalCount;
            reqsAtTimeT[currTimeT].totalOneSecWindowExcessCount += reqsAtTimeT[currTimeT - 1].totalOneSecWindowExcessCount;
            reqsAtTimeT[currTimeT].totalTenSecWindowExcessCount = reqsAtTimeT[currTimeT - 1].totalTenSecWindowExcessCount;
            reqsAtTimeT[currTimeT].totalSixtySecWindowExcessCount = reqsAtTimeT[currTimeT - 1].totalSixtySecWindowExcessCount;
        }

        if (reqsAtTimeT[currTimeT].excessCount == 0)
        {
            int tenSecDiff = reqsAtTimeT[currTimeT].totalCount - 20;
            if (tenSecDiff > 0)
            {
                if (currTimeT > 10)
                {
                    int timeDiff = (tenSecDiff - reqsAtTimeT[currTimeT - 10].totalCount);
                    if (timeDiff > 0)
                    {
                        reqsAtTimeT[currTimeT].totalTenSecWindowExcessCount++;
                    }
                }
                else
                {
                    reqsAtTimeT[currTimeT].totalTenSecWindowExcessCount++;
                }
            }
            else if (tenSecDiff == 0)
            {
                int sixtySecDiff = reqsAtTimeT[currTimeT].totalCount - 60;
                if (sixtySecDiff > 0)
                {
                    if (currTimeT > 60)
                    {
                        int timeDiff = sixtySecDiff - reqsAtTimeT[currTimeT - 60].totalCount;
                        if (timeDiff > 0)
                        {
                            reqsAtTimeT[currTimeT].totalSixtySecWindowExcessCount++;
                        }
                    }
                    else
                    {
                        reqsAtTimeT[currTimeT].totalSixtySecWindowExcessCount++;
                    }
                }
            }
        }

        printf("\n%d ==> ", currTimeT);
        printf(" count = %d,", reqsAtTimeT[currTimeT].count);
        printf(" totalCount = %d,", reqsAtTimeT[currTimeT].totalCount);
        printf(" excessCount = %d,", reqsAtTimeT[currTimeT].excessCount);
        printf(" 1sec = %d,", reqsAtTimeT[currTimeT].totalOneSecWindowExcessCount);
        printf(" 10sec = %d,", reqsAtTimeT[currTimeT].totalTenSecWindowExcessCount);
        printf(" 60sec = %d,", reqsAtTimeT[currTimeT].totalSixtySecWindowExcessCount);
    }

    int t = requestTime[l - 1];
    return reqsAtTimeT[t].totalOneSecWindowExcessCount + reqsAtTimeT[t].totalTenSecWindowExcessCount + reqsAtTimeT[t].totalSixtySecWindowExcessCount;
}

int main()
{
    // vector<int> val = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 11, 11, 11}; // - Correct ans == 6
    // printf("\n\nExcess = %d", droppedRequests(val));

    // vector<int> val = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 11, 11, 11, 11}; //Correct ans = 7
    // printf("\n\nExcess = %d", droppedRequests(val));

    //vector<int> val = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 14, 16, 16, 16, 16, 16, 16, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20};
    //printf("\n\nExcess = %d", droppedRequests(val)); //Correct ans == 67

    vector<int> val = {100, 100, 101, 102, 102, 103, 103, 105, 105, 106, 106, 106, 107, 107, 109, 109, 109, 109, 110, 110, 110, 111, 111, 112, 114, 115, 115, 116, 116, 116, 117, 118, 118, 120, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, 127, 128, 128, 129, 131, 133, 134, 135, 135, 135, 136, 137, 137, 137, 138, 138, 140, 140, 140, 141, 141, 143, 144, 145, 146, 149, 149, 149, 149, 149, 151, 151, 152, 152, 154, 154, 155, 156, 156, 157, 158, 158, 159, 159, 160, 160, 160, 162, 162, 162, 164, 166, 167, 167, 169, 169, 172, 172, 172, 172, 174, 175, 175, 175, 176, 177, 177, 177, 179, 179, 180, 180, 180, 180, 181, 181};
    printf("\n\nExcess = %d", droppedRequests(val)); //Correct ans == 67

    return 0;
}