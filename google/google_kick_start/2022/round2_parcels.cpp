#include<bits/stdc++.h>
using namespace std;

class Solution_t
{
private:
    int getMinDistance(int r, int c, vector<pair<int, int>>& po)
    {
        int ans = INT_MAX;
        for(pair<int, int> p : po)
        {
            ans = min(ans, (abs(p.first - r) + abs(p.second - c)));
        }
        
        return ans;
    }
    
    int getWorstDistance(int r, int c, vector< vector<int> >& minDist)
    {
        int ans = 0;
        for(vector<int>& md : minDist)
        {
            int newDist = (abs(md[0] - r) + abs(md[1] - c));
            
            ans = max({ans, md[2], newDist});
        }
        
        return ans;
    }
    
public:
    int getBestTime(int r, int c, vector<vector<int>> loc, vector<pair<int, int>> po)
    {
        vector< vector<int> > minDist;
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(loc[i][j] == 1)
                {
                    continue;
                }
                
                minDist.push_back({i, j, getMinDistance(i, j, po)});
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(loc[i][j] == 1)
                {
                    continue;
                }
                
                ans = min(ans, getWorstDistance(i, j, minDist));
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    int T;
    std::cin >> T;
    
    int count = 1;
    Solution_t s;
    while(count <= T)
    {
        int R = 0;
        int C = 0;
        
        std::cin >> R;
        std::cin >> C;
        
        vector<pair<int, int>> po;
        vector< vector<int> > loc(R);
        for(int i = 0; i < R; ++i)
        {
            string str;
            std::cin >> str;
            
            int j = 0;
            for(char ch : str)
            {
                loc[i].push_back(ch-'0');
                if(loc[i][j] == 1)
                {
                    po.push_back({i, j});
                }

                j++;
            }
        }
        
        std::cout << "Case #" << count << ": " << s.getBestTime(R, C, loc, po) << std::endl;
        
        count++;
    }
    return 0;
}