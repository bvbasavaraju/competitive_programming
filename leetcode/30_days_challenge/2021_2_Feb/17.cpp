/****************************************************
Date: Feb 16th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3641/
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
  Q: Container With Most Water

  Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
  n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
  Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

  Notice that you may not slant the container.

  Example 1:
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: 
      The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
      In this case, the max area of water (blue section) the container can contain is 49.

  Example 2:
    Input: height = [1,1]
    Output: 1

  Example 3:
    Input: height = [4,3,2,1,4]
    Output: 16

  Example 4:
    Input: height = [1,2,1]
    Output: 2

  Constraints:
    n == height.length
    2 <= n <= 3 * 104
    0 <= height[i] <= 3 * 104

  Hide Hint #1  
    The aim is to maximize the area formed between the vertical lines. 
    The area of any container is calculated using the shorter line as length and the distance between the lines as the width of the rectangle.
    
    Area = length of shorter vertical line * distance between lines

    We can definitely get the maximum width container as the outermost lines have the maximum distance between them. 
    However, this container might not be the maximum in size as one of the vertical lines of this container could be really short.

  Hide Hint #2  
    Start with the maximum width container and go to a shorter width container if there is a vertical line 
    longer than the current containers shorter line. This way we are compromising on the width but we are looking forward to a longer length container.
*/

class Solution 
{
public:
  int maxArea(vector<int>& height) 
  {
    int l = height.size();
    
    int p1 = 0;
    int p2 = l-1;
    int ans = 0;
    while(p1 != p2)
    {
      int area = min(height[p1], height[p2]) * abs(p1 - p2);
      ans = max(ans, area);
      
      if(height[p1] <= height[p2])
      {
        p1++;
      }
      else
      {
        p2--;
      }
    }
    
    return ans;
  }
};