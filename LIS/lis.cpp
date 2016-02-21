#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums);

int main()
{
	vector<int> list = {10, 9, 2, 5, 3, 7, 101, 18};
	cout << lengthOfLIS(list) << endl;

	return 0;
}

int lengthOfLIS(vector<int>& nums)
{
	int len = nums.size();
	vector<int> lis(len, 1);
	
	for(int x=0; x<len; ++x){
		for(int y=0; y<x; ++y){
			if(nums[x] > nums[y])
				lis[x] = lis[x] > lis[y]+1 ? lis[x] : lis[y]+1;
		}
	}
	
	int max=0;
	for(auto val : lis)
		max = val > max ? val : max;

	return max;
}

