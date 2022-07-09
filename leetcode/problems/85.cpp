class Solution 
{
private:
  int getMaxAreaOfHistogram(const vector<int>& a)
  {
    int l = a.size();

    //calculate nearest small to right
    int i = 0;
    vector<int> nearestSmallToRightPos(l);
    stack< pair<int, int> > posHeightPair;
    for(i = 0; i < l; ++i)
    {
      if(posHeightPair.empty() || (a[i] >= posHeightPair.top().second))
      {
          posHeightPair.push({i, a[i]});
      }
      else
      {
        while(!posHeightPair.empty() && (a[i] < posHeightPair.top().second))
        {
          pair<int, int> p = posHeightPair.top();
          posHeightPair.pop();

          nearestSmallToRightPos[p.first] = i;
        }

        posHeightPair.push({i, a[i]});
      }
    }

    while(!posHeightPair.empty())
    {
      pair<int, int> p = posHeightPair.top();
      posHeightPair.pop();

      nearestSmallToRightPos[p.first] = i;
    }

    //calculate nearest small to left;
    vector<int> nearestSmallToLeftPos(l);
    for(i = l-1; i >= 0; --i)
    {
      if(posHeightPair.empty() || (a[i] >= posHeightPair.top().second))
      {
          posHeightPair.push({i, a[i]});
      }
      else
      {
        while(!posHeightPair.empty() && (a[i] < posHeightPair.top().second))
        {
          pair<int, int> p = posHeightPair.top();
          posHeightPair.pop();

          nearestSmallToLeftPos[p.first] = i;
        }

        posHeightPair.push({i, a[i]});
      }
    }

    while(!posHeightPair.empty())
    {
      pair<int, int> p = posHeightPair.top();
      posHeightPair.pop();

      nearestSmallToLeftPos[p.first] = i;
    }

    int maxArea = 0;
    for(i = 0; i < l; ++i)
    {
      int areaAtCurrentPos = (nearestSmallToRightPos[i] - nearestSmallToLeftPos[i] - 1) * a[i];
      maxArea = max(maxArea, areaAtCurrentPos);
    }

    return maxArea;
  } 
public:
  int maximalRectangle(vector<vector<char>>& matrix) 
  {
    if(matrix.size() <= 0)
    {
      return 0;
    }

    int maxArea = INT_MIN;
    vector<int> prevVal;
    for(vector<char> row_ : matrix)
    {
      vector<int> row;
      for(char ch : row_)
      {
        row.push_back(ch-'0');
      }
      if(!prevVal.empty())
      {
        for(int i = 0; i < row.size(); ++i)
        {
          if(row[i] != 0)
          {
            row[i] += prevVal[i];
          }
        }
      }

      prevVal = row;
      maxArea = max(maxArea, getMaxAreaOfHistogram(row));
    }

    return maxArea;
  }
};