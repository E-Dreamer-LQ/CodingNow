// leetcode283-移动0.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;
// 双指针
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int start = 0;
		for (auto num : nums)
		{
			if (num != 0)
			{
				nums[start++] = num;
			}
		}
		while (start != nums.size())
		{
			nums[start++] = 0;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << endl;
		}
	}
};

void main() {

	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(4);
	s.moveZeroes(nums);

}
