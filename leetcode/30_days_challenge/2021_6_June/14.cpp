/****************************************************
Date: June 14th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3772/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;
/*
  Q: Maximum Units on a Truck

  You are assigned to put some amount of boxes onto one truck. 
  You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
    + numberOfBoxesi is the number of boxes of type i.
    + numberOfUnitsPerBoxi is the number of units in each box of the type i.

  You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. 
  You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

  Return the maximum total number of units that can be put on the truck.

  Example 1:
    Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
    Output: 8
    Explanation: There are:
      - 1 box of the first type that contains 3 units.
      - 2 boxes of the second type that contain 2 units each.
      - 3 boxes of the third type that contain 1 unit each.
      You can take all the boxes of the first and second types, and one box of the third type.
      The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

  Example 2:
    Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
    Output: 91

  Constraints:
    1 <= boxTypes.length <= 1000
    1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
    1 <= truckSize <= 106

  Hide Hint #1  
    If we have space for at least one box, it's always optimal to put the box with the most units.

  Hide Hint #2  
    Sort the box types with the number of units per box non-increasingly.

  Hide Hint #3  
    Iterate on the box types and take from each type as many as you can.
*/
class Solution 
{
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
  {
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& t1, const vector<int>& t2) -> bool
         {
           if(t1[1] > t2[1])
           {
             return true;
           }
           else if(t1[1] == t2[1])
           {
             if(t1[0] <= t2[0])
             {
               return true;
             }
           }
           
           return false;
         }
        );
    
    int ans = 0;
    for(vector<int>& boxType : boxTypes)
    {
      int units = boxType[1];
      int boxCount = boxType[0];

      if(truckSize >= boxCount)
      {
        ans += (boxCount * units);
        truckSize -= boxCount;
      }
      else
      {
        ans += (truckSize * units);
        truckSize = 0;
      }

      if(truckSize == 0)
      {
        break;
      }
    }
    
    return ans;
  }
};