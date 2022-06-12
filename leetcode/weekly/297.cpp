/****************************************************
Date: June 12th, 2022
Successful submissions : 1
Time expiration : 1
Memory exhausted : 0
Not Solved : 0
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/weekly-contest-296
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2303. Calculate Amount Paid in Taxes - only correct solution
*/
class Solution1_t
{
public:
  double calculateTax(vector<vector<int>>& brackets, int income) 
  {
    double ans = 0;
    int l = brackets.size();
    
    int i = 0;
    int amountTaxed = 0;
    int percent = 0;
    int recedue = 0;
    for(; i < l; ++i)
    {
      if(income >= brackets[i][0])
      {
        int amountToBeTaxed = i == 0 ? brackets[i][0] : brackets[i][0] - brackets[i-1][0];
        
        ans += ((amountToBeTaxed * 1.0) * (brackets[i][1] / 100.0));
        amountTaxed += amountToBeTaxed;
      }
      else
      {
        percent = brackets[i][1];
        recedue = i > 0 ? income - brackets[i-1][0] : income;
        break;
      }
    }
    
    if(recedue != 0)
    {
      ans += (recedue * 1.0) * (percent / 100.0);
    }
    
    ans = (ans * 100000) / 100000;
    return ans;
  }
};

/*
  Q: 2304. Minimum Path Cost in a Grid - somehow both approaches resulting in wrong answers!!
*/
class Solution2_t
{
public:
  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) 
  {
//     int r = grid.size();
//     int c = grid[0].size();
//     unordered_map<int, vector<pair<int, int>>> adjLists;
//     for(int i = 0; i < r-1; ++i)
//     {
//       for(int j = 0; j < c; ++j)
//       {
//         int source = grid[i][j];
//         for(int k = 0; k < c; ++k)
//         {
//           int adjNode = grid[i+1][k];
//           int dist = moveCost[source][k];
//           adjLists[source].push_back({adjNode, dist});
//         }
//       }
//     }
    
//     int ans = INT_MAX;
//     int totalNodes = r*c;
//     for(int i = 0; i < c; ++i)
//     {
//       int startNode = grid[0][i];
//       vector<int> distance(totalNodes, INT_MAX);
//       vector<int> processed(totalNodes, false);  
      
//       distance[startNode] = 0;
//       priority_queue<pair<int, int>> pq;
//       pq.push({startNode, 0});
//       while(!pq.empty())
//       {
//         int source = pq.top().first;
//         int sourceDist = pq.top().second;
//         pq.pop();
        
//         if(processed[source] == true)
//         {
//           continue;
//         }
        
//         processed[source] = adjLists[source].size() > 0 ? true : false;
//         for(pair<int, int> adjNodeData : adjLists[source])
//         {
//           int adjNode = adjNodeData.first;
//           int adjNodeDist = adjNodeData.second;
          
//           int newDist = ((distance[source] == 0 ? source : 0) + adjNode + adjNodeDist + distance[source]);
//           if(!processed[adjNode] && (distance[adjNode] > newDist))
//           {
//             distance[adjNode] = newDist;
//             pq.push({adjNode, distance[adjNode]});
//           }
//         }

//       }
      
//       for(int j = 0; j < c; ++j)
//       {
//         ans = min(ans, distance[grid[r-1][j]]);
//       }
//     }
    
//     return ans;
    
    //TODO: both approaches resulting in wrong answer!
    
    unordered_map<int, vector<int>> valueCostToNextRow;
    
    int r = grid.size();
    int c = grid[0].size();
    for(int i = 0; i < r-1; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        valueCostToNextRow[grid[i][j]] = moveCost[grid[i][j]];
      }
    }
    
    vector<vector<int>> cost(r, vector<int>(c, 0));
    for(int i = 1; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        int currentNode = grid[i][j];
        int mini = INT_MAX;
        for(int k = 0; k < c; ++k)
        {
          int prevNode = grid[i-1][k];
          int prevNodeCost = cost[i-1][k];
          int prevToCurrNodeDist = valueCostToNextRow[grid[i-1][k]][j];
          mini = min(mini, currentNode + prevNode + prevNodeCost + prevToCurrNodeDist);
        }
        cost[i][j] = mini;
      }
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < c; ++i)
    {
      ans = min(ans, cost[r-1][i]);
    }
    
    return ans;
  }
};

/*
  Q: 2305. Fair Distribution of Cookies - Approach was correct. But, needed to iterate for all permutation of cookies!! SOlved after looking at the problem
*/
class Solution3_t
{
private:
  int getCount(vector<int>& cookies, long long avg)
  {
    int count = 1;
    int sum = 0;
    for(int c : cookies)
    {
      sum += c;
      if(sum > avg)
      {
        count++;
        sum = c;
      }
    }
    
    return count;
  }
public:
  int distributeCookies(vector<int>& cookies, int k) 
  {
    sort(cookies.begin(), cookies.end());
    
    int maxi = 0;
    long long sum = 0;
    for(int c : cookies)
    {
      sum += (c * 1LL);
      maxi = max(maxi, c);
    }

    int ans = INT_MAX;
    do
    {
      long long l = maxi;
      long long h = sum;
      while(l <= h)
      {
        int m = l + (h-l)/2;

        if(getCount(cookies, m) > k)
        {
          l = m+1;
        }
        else
        {
          ans = min(ans, m);
          h = m-1;
        }
      }
    }while(next_permutation(cookies.begin(), cookies.end()));
    
    return ans;
  }
};

/*
  Q: 2306. Naming a Company - Time limit exceeded!
*/
class Solution4_t
{
public:
  long long distinctNames(vector<string>& ideas) 
  {
    unordered_set<string> ids;
    for(string s : ideas)
    {
      ids.insert(s);
    }
    
    int ans = 0;
    int l = ideas.size();
    for(int i = 0; i < l; ++i)
    {
      for(int j = i+1; j < l; ++j)
      {
        string first = ideas[i];
        string second = ideas[j];
        
        swap(first[0], second[0]);
        
        if(ids.find(first) == ids.end() && ids.find(second) == ids.end())
        {
          ans += 2;
        }
      }
    }
    
    return ans;
  }
};