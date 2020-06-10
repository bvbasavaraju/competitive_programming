
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

    int ans = 0;
    int oneSecCount = 0;
    int tenSecCount = 0;
    int sixtySecCount = 0;
    queue<pair<int, int>> tenSecQueue;
    queue<pair<int, int>> sixtySecQueue;
    for (int i = 0; i < l; ++i)
    {
        if (i == 0)
        {
            oneSecCount++;
            tenSecCount++;
            sixtySecCount++;
        }
        else
        {
            bool needToUpdateCount = requestTime[i] != requestTime[i - 1] ? true : false;

            if (needToUpdateCount)
            {
                pair<int, int> p = std::make_pair(requestTime[i - 1], oneSecCount);
                tenSecQueue.push(p);
                sixtySecQueue.push(p);

                if (requestTime[i] > 60)
                {
                    int sixtySecStart = max(1, requestTime[i] - 59);

                    pair<int, int> temp = sixtySecQueue.front();
                    while (temp.first < sixtySecStart)
                    {
                        sixtySecCount -= temp.second;
                        sixtySecQueue.pop();
                        if (sixtySecQueue.empty())
                        {
                            break;
                        }
                        temp = sixtySecQueue.front();
                    }
                }
                if (requestTime[i] > 10)
                {
                    int tenSecStart = max(1, requestTime[i] - 9);

                    pair<int, int> temp = tenSecQueue.front();
                    while (temp.first < tenSecStart)
                    {
                        tenSecCount -= temp.second;
                        tenSecQueue.pop();
                        if (tenSecQueue.empty())
                        {
                            break;
                        }
                        temp = tenSecQueue.front();
                    }
                }

                oneSecCount = 0;
            }

            oneSecCount++;
            tenSecCount++;
            sixtySecCount++;

            if ((sixtySecCount > 60) || (tenSecCount > 20) || (oneSecCount > 3))
            {
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    // vector<int> val = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 11, 11, 11}; // - Correct ans == 6
    // printf("\n\nExcess = %d", droppedRequests(val));

    vector<int> val = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 11, 11, 11, 11}; //Correct ans = 7
    printf("\n\nExcess = %d", droppedRequests(val));

    //vector<int> val = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 14, 16, 16, 16, 16, 16, 16, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20};
    //printf("\n\nExcess = %d", droppedRequests(val)); //Correct ans == 67

    // vector<int> val = {100, 100, 101, 102, 102, 103, 103, 105, 105, 106, 106, 106, 107, 107, 109, 109, 109, 109, 110, 110, 110, 111, 111, 112, 114, 115, 115, 116, 116, 116, 117, 118, 118, 120, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, 127, 128, 128, 129, 131, 133, 134, 135, 135, 135, 136, 137, 137, 137, 138, 138, 140, 140, 140, 141, 141, 143, 144, 145, 146, 149, 149, 149, 149, 149, 151, 151, 152, 152, 154, 154, 155, 156, 156, 157, 158, 158, 159, 159, 160, 160, 160, 162, 162, 162, 164, 166, 167, 167, 169, 169, 172, 172, 172, 172, 174, 175, 175, 175, 176, 177, 177, 177, 179, 179, 180, 180, 180, 180, 181, 181};
    // printf("\n\nExcess = %d", droppedRequests(val)); //Correct ans == 67

    return 0;
}