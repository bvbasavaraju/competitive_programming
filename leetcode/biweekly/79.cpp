/****************************************************
Date: May 28th, 2022
Successful submissions : 3
Time expiration : 1
Memory limit exceeded : 0
Not Solved : 0
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-79
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2283. Check if Number Has Equal Digit Count and Digit Value
*/
class Solution1_t
{
public:
  bool digitCount(string num) 
  {
    unordered_map<int, int> freq;
    for(char ch : num)
    {
      freq[ch-'0']++;
    }
   
    int l = num.size();
    for(int i = 0; i < l; ++i)
    {
      if((num[i]-'0') != freq[i])
      {
        return false;
      }
    }
    
    return true;
  }
};

/*
  Q: 2284. Sender With Largest Word Count
*/
class Solution2_t
{
private:
  int getWordCount(const string& str)
  {
    int ans = 1;
    for(char ch : str)
    {
      if(ch == ' ')
      {
        ans++;
      }
    }
    
    return ans;
  }
public:
  string largestWordCount(vector<string>& messages, vector<string>& senders) 
  {
    int l = messages.size();
    unordered_map<string, int> wordCount;
    for(int i = 0; i < l; ++i)
    {
      wordCount[senders[i]] += getWordCount(messages[i]);
    }
    
    std::pair<string, int> ans = {"", 0};
    for(auto it = wordCount.begin(); it != wordCount.end(); ++it)
    {
      if((it->second > ans.second) || ((it->second == ans.second) && (it->first > ans.first)))
      {
        ans = {it->first, it->second};
      }
    }
    
    return ans.first;
  }
};

/*
  Q: 2285. Maximum Total Importance of Roads
*/
class Solution3_t
{
public:
  long long maximumImportance(int n, vector<vector<int>>& roads) 
  {
    unordered_map<int, int> freq;
    for(const vector<int>& road : roads)
    {
      freq[road[0]]++;
      freq[road[1]]++;
    }
    
    vector< priority_queue<int> > nodesWithConnectionCount(n);
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
      nodesWithConnectionCount[it->second].push(it->first);
    }
    
    int count = n;
    vector<long long> nodeWithVal(n, 0);
    for(int i = n-1; i >= 0; --i)
    {
      while(!nodesWithConnectionCount[i].empty())
      {
        int node = nodesWithConnectionCount[i].top();
        nodesWithConnectionCount[i].pop();
        nodeWithVal[node] = count;
        count--;
      }
    }
    
    long long ans = 0;
    for(const vector<int>& road : roads)
    {
      ans += nodeWithVal[road[0]] + nodeWithVal[road[1]];
    }
    
    return ans;
  }
};

/*
  Q: 2286. Booking Concert Tickets in Groups - time limit exceeds!!
*/
class BookMyShow_t
{
private:
    int lowestPossibleRow;
    int maxSeatsInEachRow;
    vector<int> seatCountRemaining;
  
public:
    BookMyShow_t(int n, int m) 
    {
      lowestPossibleRow = 0;
      maxSeatsInEachRow = m;
      for(int i = 0; i < n; ++i)
      {
        seatCountRemaining.push_back(m);
      }
    }
    
    vector<int> gather(int k, int maxRow) 
    {
      if((maxSeatsInEachRow < k))
      {
        return {};
      }
      
      int selectedRow = INT_MAX;
      for(int i = lowestPossibleRow; i <= maxRow; ++i)
      {
        if(seatCountRemaining[i] >= k)
        {
          selectedRow = i;
          break;
        }
      }
      
      if(selectedRow != INT_MAX)
      {
        int lowetSeat = maxSeatsInEachRow - seatCountRemaining[selectedRow];
        seatCountRemaining[selectedRow] -= k;
        return {selectedRow, lowetSeat};
      }
      
      return {};
    }
    
    bool scatter(int k, int maxRow) 
    {      
      int vacantSeatsTillMaxRow = 0;
      for(int i = lowestPossibleRow; (i <= maxRow) && (vacantSeatsTillMaxRow < k); ++i)
      {
        vacantSeatsTillMaxRow += seatCountRemaining[i];
      }
      
      if(vacantSeatsTillMaxRow < k)
      {
        return false;
      }
      
      //totalSeats -= k;
      for(int i = lowestPossibleRow; i <= maxRow; ++i)
      {
        if(k <= 0)
        {
          break;
        }
        
        int seatsVacant = seatCountRemaining[i];
        if(seatsVacant >= k)
        {
          int lowestSeat = maxSeatsInEachRow - seatCountRemaining[i];
          seatCountRemaining[i] -= k;
          if(seatCountRemaining[i] <= 0)
          {
            lowestPossibleRow = i+1;
          }
          return true;
        }
        else
        {
          int seatsVacant = seatCountRemaining[i];
          seatCountRemaining[i] = 0;
          lowestPossibleRow = i+1;
          k -= seatsVacant;
        }
      }
      
      return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */