// leetcode503-下一个更大的元素 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/next-greater-element-ii

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n);
		stack<int> datastack;
		//假设数组长度为原来的两倍
		for (int i = 2 * n - 1; i > -1; i--) {
			while (!datastack.empty() && nums[i] > datastack.top()) {
				datastack.pop();
			}
			//模拟循环数组
			res[i % n] = datastack.empty() ? -1 : datastack.top();
			datastack.push(nums[i % n]);
		}
		
		return res;
	}
};