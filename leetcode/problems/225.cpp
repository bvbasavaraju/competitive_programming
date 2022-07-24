#include<bits/stdc++.h>
using namespace std;

class MyStack 
{
private:
  queue<int> q1;
  queue<int> q2;
  
  int switchQ(queue<int>& q1_, queue<int>& q2_, bool remove = true)
  {
    while(q1_.size() > 1)
    {
      q2_.push(q1_.front());
      q1_.pop();
    }
    
    int retVal = q1_.front();
    q1_.pop();
    
    if(!remove)
    {
      q2_.push(retVal);
    }
    
    return retVal;
  }
  
public:
  MyStack() {}

  void push(int x) 
  {
    if(q1.size() > 0)
    {
      q1.push(x);
    }
    else if(q2.size() > 0)
    {
      q2.push(x);
    }
    else
    {
      q1.push(x);
    }
  }

  int pop() 
  {
    if(q1.size() > q2.size())
    {
      return switchQ(q1, q2);
    }
    
    return switchQ(q2, q1);
  }

  int top() 
  {
    if(q1.size() > q2.size())
    {
      return switchQ(q1, q2, false);
    }
    
    return switchQ(q2, q1, false);
  }

  bool empty() 
  {
    return ((q1.size() + q2.size()) == 0);
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */