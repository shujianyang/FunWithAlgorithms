#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int lengthOfLIS(vector<int>& nums);
int lengthOfLIS2(vector<int>& nums);

int main(int argc, char *argv[])
{
    srand(time(0));
    
	vector<int> list;
    
    int count;
    cout << "Enter number of integers:";
    cin >> count;
    
    for(int i=0; i<count; ++i){
        list.push_back(rand() % 1000);
    }
    
    //for(auto& val : list)
    //    cout << val << " ";
    //cout << endl;
    clock_t start, end;
    int clock_per_ms = CLOCKS_PER_SEC / 1000;
    
    start = clock();
	cout << lengthOfLIS2(list) << endl;
    end = clock();
    cout << "Time:" << double(end - start) / clock_per_ms << "ms" << endl;
    
    
    start = clock();
	cout << lengthOfLIS(list) << endl;
    end = clock();
    cout << "Time:" << double(end - start) / clock_per_ms << "ms" << endl;

	return 0;
}

int lengthOfLIS(vector<int>& nums)
{
	int len = nums.size();
	vector<int> lis;
	
	for(auto& val : nums){
        int min = 0;
        int max = lis.size() - 1;
        while(min <= max){
            int mid = (min + max) / 2;
            if(lis[mid] == val){
                min = mid;
                break;
            }
            else if(lis[mid] > val)
                max = mid - 1;
            else
                min = mid + 1;
        }
        if(min < lis.size())
            lis[min] = val;
        else
            lis.push_back(val);
    }
    
    return lis.size();
}

int lengthOfLIS2(vector<int>& nums)
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

