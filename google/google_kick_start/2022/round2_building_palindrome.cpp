#include<bits/stdc++.h>
using namespace std;

class Solution_t
{
private:
    bool isPalindromePossible(const string& str, vector<int> freq, pair<int, int>& p, int mini, int maxi)
    {
        if(p.first > mini)
        {
            for(int i = mini; i < p.first; ++i)
            {
                freq[str[i]-'A']--;
            }
        }
        
        if(p.second < maxi)
        {
            for(int i = maxi; i > p.second; --i)
            {
                freq[str[i]-'A']--;
            }
        }
        
        int oddCount = 0;
        int evenCount = 0;
        for(int f : freq)
        {
            if(f % 2 == 0)
            {
                evenCount++;
            }
            else
            {
                oddCount++;
            }
        }
        
        return oddCount > 1 ? false : true;
    }
    
public:
    int getPalindromeCount(const string& str, vector<int> freq, vector<pair<int, int>> query, int mini, int maxi)
    {
        int ans = 0;
        for(pair<int, int> q : query)
        {
            if(isPalindromePossible(str, freq, q, mini, maxi))
            {
                ans++;
            }
        }
        
        return ans;
    }
};

int main()
{
    int T = 0;
    std::cin >> T;
    
    int count = 1;
    Solution_t s;
    while(count <= T)
    {
        int N = 0;
        int Q = 0;
        std::cin >> N;
        std::cin >> Q;
        
        string str;
        std::cin >> str;
        
        vector<int> freq(26, 0);
        for(char ch : str)
        {
            freq[ch - 'A']++;
        }
        
        int mini = INT_MAX;
        int maxi = 0;
        vector<pair<int, int>> query;
        while(Q > 0)
        {
            int i = 0;
            int j = 0;
            
            std::cin >> i;
            std::cin >> j;
            
            //as indexing in query is from 1 to n. reduce the index by 1 to have indexing 0 to n-1
            i--;
            j--;
            
            mini = min(mini, i);
            maxi = max(maxi, j);
            
            query.push_back({i, j});
            
            Q--;
        }
        
        for(int i = 0; i < mini; ++i)
        {
            freq[str[i]-'A']--;
        }
        
        for(int i = maxi+1; i < str.size(); ++i)
        {
            freq[str[i]-'A']--;
        }
        
        std::cout << "Case #" << count << ": " << s.getPalindromeCount(str, freq, query, mini, maxi) << std::endl;
        
        count++;
    }
    
    return 0;
}