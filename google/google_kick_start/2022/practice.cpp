#include<bits/stdc++.h>
using namespace std;

class Solution_t
{
//   private:
//     int getCount(int city, vector<vector<int>>& gBus)
//     {
//         int l = 0;
//         int h = gBus.size();
        
//         int count = 0;
//         while(l <= h)
//         {
//             int m = l + (h-l)/2;
            
//             if(gBus[m][0] >= city && gBus[m][1] <= city)
//             {
//                 count++;
//             }
            
//             if(city > g[m][0])
//             {
//                 l = m+1;
//             }
//             else
//             {
//                 h = m-1;
//             }
//         }
        
//         return count;
//     }
    
  public:
    vector<int> getCount(vector<vector<int>>& gBus, vector<int> interested)
    {
        // sort(gBus.begin(), gBus.end(), [](const vector<int>& b1, const vector<int>& b2) -> bool 
        // {
        //     if(b1[0] < b2[0] || (b1[0] == b2[0] && b1[1] <= b2[2]))
        //     {
        //         return true;
        //     }
            
        //     return false;
        // });
        
        vector<int> ans;
        for(int city : interested)
        {
            // ans.push_back(getCount(city, gBus));
            int count = 0;
            for(const vector<int>& startEnd : gBus)
            {
                if(startEnd[0] <= city && startEnd[1] >= city)
                {
                    count++;
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};

int main()
{
  vector< vector<int> > gBus = {{15, 25}, {30, 35},  {45, 50}, {10, 20}};

  vector<int> interested = {15, 25};

  Solution_t s;
  vector<int> gBusCount = s.getCount(gBus, interested);
  std::cout << "Case #" << 1 << ":";
  for(int n : gBusCount)
  {
      std::cout << " ";
      std::cout << n;
  }
  std::cout << std::endl;

  return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// class Solution_t
// {
//   public:
//     vector<int> getReachabel(int r, int c, vector<int> start, const string& path)
//     {
//         vector< vector<bool> > visited(r, vector<bool>(c, false));
        
//         int i = start[0]-1;
//         int j = start[1]-1;
//         visited[i][j] = true;
//         for(char ch : path)
//         {
//             switch(ch)
//             {
//             case 'N':
//                 do
//                 {
//                     visited[i][j] = true;
//                     i--;
//                 }while(visited[i][j]);

//                 break;
                
//             case 'S':
//                 do
//                 {
//                     visited[i][j] = true;
//                     i++;
//                 }while(visited[i][j]);
                
//                 break;

//             case 'E':
//                 do
//                 {
//                     visited[i][j] = true;
//                     j++;
//                 }while(visited[i][j]);
                
//                 break;
                
//             case 'W':
//                 do
//                 {
//                     visited[i][j] = true;
//                     j--;
//                 }while(visited[i][j]);
                
//                 break;
//             }
//         }
        
//         i++;
//         j++;
        
//         return {i, j};
//     }
// };

// int main()
// {
//   Solution_t s;
//   s.getReachabel(3,6,{2,3}, "EEWNS");
//     // int T;
//     // std::cin >> T;
    
//     // int count = 0;
//     // while(count <= T)
//     // {
//     //     int N,R,C,rs,cs;
//     //     std::cin >> N >> R >> C >> rs >> cs;
        
//     //     string path;
//     //     std::cin >> path;
        
//     //     Solution_t s;
//     //     vector<int> dest = s.getReachabel(R, C, {rs, cs}, path);
        
//     //     std::cout << "Case #" << count << ": " << dest[0] << " " << dest[1] << std::endl;
        
//     //     count--;
//     // }
//     return 0;
// }