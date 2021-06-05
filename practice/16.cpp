#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	std::cin >> n;

	vector<int> nums(n);
	for(int i = 0; i < n; ++i)
    {
    	std::cin >> nums[i];
    }

	int ans = 0;
	int sum = 0;
	
	for(int num : nums)
    {
    	sum = max(sum+num, num);
    	ans = max(ans, sum);
    }

	std::cout << ans << endl;
	return 0;
}