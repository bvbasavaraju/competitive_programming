#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minJumps(int arr[], int n)
  {
    stack< pair<int, int> > jumps;
    
    int ans = INT_MAX;
    jumps.push({arr[0], 0});
    while(!jumps.empty())
    {
        int nextPos = jumps.top().first + jumps.top().second;
        if(nextPos >= n)
        {
            ans = min(ans, static_cast<int>(jumps.size()));
        }
        
        jumps.top().first--;
        
        if((nextPos < n) && (arr[nextPos] > 0) && (nextPos > jumps.top().second))
        {
            //jumps.pop();
            jumps.push({arr[nextPos], nextPos});
        }
        else if(jumps.top().first <= 0)
        {
          jumps.pop();
        }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};

int main()
{
  //int arr[] = {1, 3, 5, 1, 0, 2, 6, 7, 6, 8, 9};

  int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
  Solution s;
  s.minJumps(arr, 10);

  return 0;
}