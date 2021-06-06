/*
  Q: 
*/
#include <iostream>
#include <vector>

using namespace std;

/*int getSteps(const vector<int>& nums)
{
	int l = 0;
	int h = nums.size()-1;
	
	int ans = 0;
	while(l <= h)
    {
    	int m = l + (h-l)/2;
    	if(nums[m] == 1)
        {
        	h = m-1;
        }
    	else
        {
        	l = m+1;
        }
    
    	ans++;
    }

	return ans;
}*/

int getSteps(int h, int index)
{
	int l = 0;
	
	int ans = 0;
	while(l <= h)
    {
    	ans++;
    
    	int m = l + (h-l)/2;
    	if(m >= index)
        {
        	h = m-1;
        }
    	else
        {
        	l = m+1;
        }
    }

	return ans;
}

int main()
{
	int n = 0;
	int	m = 0;

	std::cin >> n >> m;
	
	for(int i = 0; i < m; ++i)
    {
    	int q = 0;
    	std::cin >> q;
    
    	/* TLE
      vector<int> nums(n);
    	for(int j = 0; j < n; ++j)
        {
        	nums[j] = (j >= q) ? 1 : 0;
        }
    
    	std::cout << getSteps(nums) << std::endl;*/
    	std::cout << getSteps(n-1, q) << std::endl;	
    }

	return 0;
}