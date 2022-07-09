#include<bits/stdc++.h>
using namespace std;

class MedianFinder 
{
private:
  priority_queue<int> maxPQ;  // store small number in descending order
  priority_queue<int, vector<int>, greater<int>> minPQ;  // stores large numbers in ascending order
public:
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
      if(maxPQ.size() == minPQ.size())
      {
        if(!maxPQ.empty() && maxPQ.top() > num)
        {
          int top = maxPQ.top();
          maxPQ.pop();
          
          minPQ.push(top);
          maxPQ.push(num);
        }
        else
        {
          minPQ.push(num);
        }
      }
      else
      {
        if(maxPQ.size() > minPQ.size())
        {
          if(maxPQ.top() > num)
          {
            int top = maxPQ.top();
            maxPQ.pop();
            
            minPQ.push(top);
            maxPQ.push(num);
          }
          else
          {
            minPQ.push(num);
          }
        }
        else
        {
          if(minPQ.top() >= num)
          {
            maxPQ.push(num);
          }
          else
          {
            int top = minPQ.top();
            minPQ.pop();
            
            maxPQ.push(top);
            minPQ.push(num);
          }
        }
      }
    }
    
    double findMedian() 
    {
      if(minPQ.size() == maxPQ.size())
      {
        double num1 = minPQ.top() * 1.0;
        double num2 = maxPQ.top() * 1.0;
        
        return (num1 + num2) / 2.0;
      }
      else if(maxPQ.size() > minPQ.size())
      {
        return maxPQ.top() * 1.0;
      }
      
      return minPQ.top() * 1.0;
    }
};