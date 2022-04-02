/****************************************************
Date: May 11th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/
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
  Q: Flood Fill
  An image is represented by a 2-D array of integers, 
  each integer representing the pixel value of the image (from 0 to 65535).

  Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill,
  and a pixel value newColor, "flood fill" the image.

  To perform a "flood fill", consider the starting pixel, 
  plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
  plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), 
  and so on. Replace the color of all of the aforementioned pixels with the newColor.

  At the end, return the modified image.

  Example 1:
    Input: 
    image = [[1,1,1],[1,1,0],[1,0,1]]
    sr = 1, sc = 1, newColor = 2
    Output: [[2,2,2],[2,2,0],[2,0,1]]
    Explanation: 
    From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
    by a path of the same color as the starting pixel are colored with the new color.
    Note the bottom corner is not colored 2, because it is not 4-directionally connected
    to the starting pixel.

  Note:
    The length of image and image[0] will be in the range [1, 50].
    The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
    The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
  
  Hide Hint #1  
    Write a recursive function that paints the pixel if it's the correct color, then recurses on neighboring pixels.
*/

class Solution 
{
private:
  int rows;
  int columns;
  int old_color;
  int new_color;
  
  void fillNewColor(vector<vector<int>>& image, int r, int c)
  {
    if(r < 0 || c < 0 || r >= rows || c >= columns || image[r][c] != old_color)
    {
      return;
    }
    
    image[r][c] = new_color;
    
    fillNewColor(image, r - 1, c);
    fillNewColor(image, r + 1, c);
    fillNewColor(image, r, c - 1);
    fillNewColor(image, r, c + 1);
  }
  
public:
  Solution() 
    : rows(0),
      columns(0),
      old_color(0),
      new_color(0)
  {}
  
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
  {
    rows = image.size();
    columns = image[0].size();
    old_color = image[sr][sc];
    new_color = newColor;
    
    if(old_color != new_color)
    {
      fillNewColor(image, sr, sc);
    }
    
    return image;
  }
};