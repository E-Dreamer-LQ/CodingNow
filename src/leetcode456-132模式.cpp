// leetcode456-132模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/132-pattern/submissions/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;



class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int n = nums.size();
		int last = INT_MIN;   // 次大元素 : // 132中的2
		stack<int> sta;       // sta中存放最大元素 // 132中的3
		for (int i = n - 1; i >= 0; i--) {
			if (nums[i] < last) return true;  // 若出现132中的1，则返回
			while (!sta.empty() && nums[i] > sta.top()) { //更新栈中最大值
				last = sta.top();
				sta.pop();
			}
			sta.push(nums[i]);
		}
		return false;
	}
};


// 方法二： 降维
bool find132pattern(vector<int> nums) {
	int n = nums.size();
	if (n < 3) return false;
	int i = 0, j = 0, k = 0;
	int min_val = nums[0];
	for (int i = 0; i < n; i++) {  
		min_val = min(nums[i], min_val);  // 找到最小值即1
		if (min_val == nums[i]) { // 若最小值为当前值则进行下一次遍历
			continue;
		}
		for (int j = n - 1; j > i; j--) { 
			if (min_val < nums[j] && nums[j] < nums[i])  //若出现32则返回正确
				return true;
		}
	}
	return false;
}

