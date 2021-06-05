#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, t;
	std::cin >> n >> t;

	vector<int> sum;
	for(int i = 0; i < n; ++i)
    {
    	int num = 0;
    	std::cin >> num;
    
		  sum.push_back(num + (sum.size() > 0 ? sum.back() : 0));
    }

	for(int i = 0; i < t; ++i)
    {
    	int l, r;
    	std::cin >> l >> r;
    	
    	int ans = sum[r-1] - ((l > 1) ? sum[l-1-1] : 0);
    	std::cout << ans << endl;
    }

	return 0;
}