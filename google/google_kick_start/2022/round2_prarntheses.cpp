#include<bits/stdc++.h>
using namespace std;

class Solution_t
{
private:
    int getGroupOfOne(int val)
    {
        int ans = 0;
        
        while(val > 0)
        {
            if(val & 0x01)
            {
              ans++;
              if(ans > 1)
              {
                  break;
              }
              
              while(val & 0x01)
              {
                  val >>= 1;
              }
            }
            else
            {
              val >>= 1;
            }
        }
        
        return ans;
    }
    
public:
    int getBalancedSubStringCount(int leftCount, int rightCount)
    {
        long long mini = static_cast<long long>(min(leftCount, rightCount));
        return static_cast<int>((mini * (mini+1)) / 2);   // This is giving wrogn answer!!??
        // int maxi = (1 << mini);
        
        // int ans = 0;
        // for(int i = 0; i < maxi; ++i)    // this ig TLE!!??
        // {
        //     if(getGroupOfOne(i) == 1)
        //     {
        //         ans++;
        //     }
        // }
        
        // return ans;
    }
};

int main()
{
    int tests;
    std::cin >> tests;
    
    int count = 1;
    Solution_t s;
    //vector<pair<int, int>> leftAndRight;
    while(count <= tests)
    {
        int leftCount = 0;
        int rightCount = 0;
        
        std::cin >> leftCount;
        std::cin >> rightCount;
        
        //leftAndRight.push_back({leftCount, rightCount});
        std::cout << "Case #" << count << ": " << s.getBalancedSubStringCount(leftCount, rightCount) << std::endl;
        count++;
    }
    
    // count = 1;
    // Solution_t s;
    // unordered_map<int, int> balanced;
    // for(pair<int, int> p : leftAndRight)
    // {
    //     int mini = min(p.first, p.second);
    //     if(balanced.find(mini) == balanced.end())
    //     {
    //         balanced[mini] = s.getBalancedSubStringCount(p.first, p.second);
    //     }
    //     std::cout << "Case #" << count << ": " << balanced[mini] << std::endl;
        
    //     count++;
    // }
    
    return 0;
}