// leetcode462-最少移动次数使数组元素相等II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// 超出时间限制
class Solution {
public:
	int minMoves2(vector<int>& nums) {
		int res = 0;
		sort(nums.begin(), nums.end());
		int l = 0;
		int r = nums.size() - 1;
		int median =int( l + (r - l)/ 2);
		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] != nums[median]) {
				if (nums[i] < nums[median]) {
					nums[i]++;
					res++;
				}
				else if (nums[i] > nums[median]) {
					nums[i]--;
					res++;
				}
			}
		}
		return res;
	}
};


// 简洁写法， 中位数的改进

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		int res = 0, i = 0, j = nums.size() - 1;
		sort(nums.begin(), nums.end());
		while (i < j) {
			res += nums[j--] - nums[i++];
		}
		return res;
	}
};

void main() {
	Solution S;
	vector<int> nums{ 1,2,3 };
	int res = S.minMoves2(nums);
	cout << res << endl;
}