/****************************************************
Date: June 28th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3372/
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
#include <string_view>

using namespace std;

/*
  Q: 
  Given a list of airline tickets represented by pairs of departure and arrival airports [from, to],
  reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. 
  Thus, the itinerary must begin with JFK.

  Note:
    + If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order 
      when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than 
      ["JFK", "LGB"].
    + All airports are represented by three capital letters (IATA code).
    + You may assume all tickets form at least one valid itinerary.
    + One must use all the tickets once and only once.

  Example 1:
    Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

  Example 2:
    Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
    Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
                But it is larger in lexical order.
*/

class Solution 
{
private:
  unordered_map<string, priority_queue<string, vector<string>, greater<string> > > data;
  
  void getItinerary(string& stop, vector<string>& ans)
  {
    while(!data[stop].empty())  
    {
      string next = data[stop].top();
      
      data[stop].pop();
      getItinerary(next, ans);
    }
    
    ans.push_back(stop);
  }
  
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) 
  {
    for(vector<string>& t : tickets)
    {
      data[t[0]].push(t[1]);
    }
    
    vector<string> ans;
    
    string l = "JFK";
    getItinerary(l, ans);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  {
    Solution s;
    vector<vector<string>> v = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    s.findItinerary(v);
  }

  return 0;
}