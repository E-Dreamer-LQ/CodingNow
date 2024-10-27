// leetcode540-有序数组中的单一元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/single-element-in-a-sorted-array/

#include <iostream>
#include <vector>
using namespace std; 

// 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。

// 方法一 ， 异或运算
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int res = nums[0];
		for (int i = 1; i < nums.size();i++) {
			res ^= nums[i];
		}
		return res; 

	}
};

void main() {
	Solution S;
	vector<int> nums{1,1,2,3,3,4,4,8,8};
	int res = S.singleNonDuplicate(nums);
	cout << res << endl;

}


// 方法二: hashmap


// 方法三
class Solution3 {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int i = 0;
		if (nums.size() == 1) return nums[0];
		while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {   // 对i进行范围限制
			i = i + 2;
		}
		return nums[i];
	}
};