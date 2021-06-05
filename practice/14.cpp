#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
	int curr;
	int a;
	int b;

	vector<vector<int>> maxi;
	

	void calculate(int num, int i)
    {
    	maxi.push_back({num, i});
    
    	sort(maxi.begin(), maxi.end(), [](const vector<int>& p1, const vector<int>& p2) -> bool
             {
             	if(p1[0] > p2[0])
                {
                	return true;
                }
             	else
                {
                	if(p1[0] == p2[0])
                    {
                    	return p1[1] < p2[2];
                    }
                }
             
             	return false;
             });
    
    	if(maxi.size() > 2)
        {
        	maxi.pop_back();
        }
    }
public:
	Solution(int curr_, int a_, int b_)
    	: curr(curr_),
		  a(a_),
		  b(b_)
    {}

	void FirstAndSecondLargest(int n)
    {
    	static const int MOD = 1791791791;
    	
    	for(int i = 0; i < n; ++i)
        {
        	curr = (curr * a + b) % MOD;
          calculate(curr, i);
        }
    	
    	std::cout << (maxi[0][1]+1) << "  " << (maxi[1][1] + 1);
    }
};

int main()
{
	int n = 0;
	std::cin >> n;

	int curr = 0;
	int a = 0;
	int b = 0;

	std::cin >> curr >> a >> b;

	Solution s(curr, a, b);
	s.FirstAndSecondLargest(n);

	return 0;
}