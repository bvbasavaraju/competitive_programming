//Technical Screening - Feb 5th - virtual video conference

/*
  Q: Write 2 functions which can calculate the median at runtime.

  Ex: void CaptureNum(int n) and 
      double GetMedian(void).
    
    At run time these functions can be called and n any order

  Note: It was my bad luck. I assumed many things.
        + I thought I have to give average first
        + Then I assumed, all the input will be given in sorted order. So, I did not sort initially. when the use case was given I realized.
        + Then, even though I came up with the better approach, My code for that better approach was not very clean. It was more of a rough work.
        + So, I did not go through!! :(
      Sad news but, it was not my day unfortunately. I made several silly assumptions.
      It is a lesson again. Just DO NOT ASSUME STUFFS and DO NOT START WRITING CODE IMMEDIATELY after asking question!!!
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//There is a better approach (below Solution2_t) which I was able to think immediately after solving this before even interviewer asked.

class Solution1_t  // first attempt, SC => O(n). 
{
private:
  vector<uint32_t> nums;

public:
  void CaptureNum(uint32_t n)  // TC => O(1)
  {
    nums.push_back(n); 
  }

  double GetMedian(void)  // TC => O(NlogN)
  {
    int l = nums.size();

    sort(nums.begin(), nums.end());

    double ans = 0.0;
    if(l/2 == 0)
    {
      ans = (((nums[l/2-1] + nums[l/2]) / 2.0 ) * 1.0);
    }
    else
    {
      ans = nums[l/2] * 1.0;
    }
    
    return ans;
  }
};

//I could not write the code this clean. there was one mistake of not re arrangement. But the log was much faster than previous approach
class Solution2_t // improvisation. SC => O(n)
{
  private:

    priority_queue<int> smaller_queue; // numbers smaller than median. stored as descending order. ex: 10, 4, 2
    priority_queue<int, vector<int>, greater<int> > larger_queue; // numbers larger than median. stored as ascending order ex: 50, 100, 200

    void ReArrangeQueue() // TC => O(1)
    {
      int sl = smaller_queue.size();
      int ll = larger_queue.size();

      if(larger_queue.size() == smaller_queue.size() + 2)
      {
        smaller_queue.push(larger_queue.top());
        larger_queue.pop();
      }
      else if(larger_queue.size() + 2 == smaller_queue.size())
      {
        larger_queue.push(smaller_queue.top());
        smaller_queue.pop();
      }
    }

  public:
    void CaptureNum(int n)  //TC => O(logN)
    {
      int median = static_cast<int>(GetMedian());
      if(n < median)
      {
        smaller_queue.push(n);
      }
      else
      {
        larger_queue.push(n);
      }

      ReArrangeQueue(); //This I realized after interviewer pointed mistake.
    }

    double GetMedian(void)  // TC => O(1)
    {
      int sl = smaller_queue.size();
      int ll = larger_queue.size();

      if(sl + ll == 0)
      {
        return 0.0;
      }

      double ans = 0.0;
      if((sl + ll) % 2 == 0)
      {
        ans = (((smaller_queue.top() + larger_queue.top()) / 2.0) * 1.0);
      }
      else
      {
        ans = sl > ll ? smaller_queue.top() : larger_queue.top();
      }
      
      return ans;
    }
};