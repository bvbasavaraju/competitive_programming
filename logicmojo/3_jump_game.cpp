#include <bits/stdc++.h>
using namespace std;

// find the minimum number of steps required to reach the end!

class Solution_t
{
public:
  int getMinJumpsRequired(vector<int> steps)
  {
    int l = steps.size();
    if(l <= 1)
    {
      return 0;
    }

    int jumps = 0;
    vector< pair<int, int> > data; // includes pair of {max_reach, jumps} till that index/position;
    
    int ans = INT_MAX;
    int remainingSteps = 0;
    for(int i = 0; i < l; ++i)
    {
      if(!data.empty() && data.back().first < i) 
      {
        return -1;  // if max reach is less than current location, then we can never reach the end!
      }

      remainingSteps--; // from previous jump

      int maxReachFromHere = i + steps[i];
      if(maxReachFromHere >= l)
      {
        ans = min(ans, jumps+1); // one additional steps required to reach the end!!
        //break;
      }

      data.push_back({maxReachFromHere, jumps});
      if(remainingSteps <= 0)
      {
        jumps++;  // need new jump from this index
        remainingSteps = steps[i];
      }
    }
    
    return ans;
  }
};

int main()
{
  vector<int> steps = {1,3,5,8,9,2,6,7,6,8,9};

  Solution_t s;
  std::cout<< s.getMinJumpsRequired(steps);

  return 0;
}