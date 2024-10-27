// leetcode34-在排序数组中查找元素的第一个和最后一个位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// 直接遍历
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> temp; 
		int left = 0;
		vector<int> res;
		unordered_map<int, int> hashmap;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == target) {
				temp.push_back(i);
			}
		}
		if (temp.size() == 0) {
			res.push_back(-1);
			res.push_back(-1);
			return res; 
		}
		else {
			res.push_back(temp[0]);
			res.push_back(temp[temp.size() - 1]);
			return res;
		}
	}
};

// 方法二: 二分
/*
在一个排序数组中查找某个元素的算法，我们很容易可以写出来寻找一个元素左边界的二
分算法，即将target与mid相等时，将右边界r变为mid-1，向右移动即可！
那么怎么去查找某个元素的第一个和最后一个位置呢？很简单的思路，
我们将左边界算法的查找目标target变化一下就可以了，第一次查找target，
可以得到左边界的位置，第二次查找target+1，
可能找到也可能找不到，但返回的都是最后位置+1的位置。
*/


class Solution2 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int idx1 = lower_bound(nums, target);
		int idx2 = lower_bound(nums, target + 1) - 1;
		if (idx1 < nums.size() && nums[idx1] == target)
			return { idx1, idx2 };
		else

			return { -1, -1 };
	}
	int lower_bound(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] < target)
				l = mid + 1;
			else
				r = mid - 1;
		}
		return l;
	}
};


// 来自微信公众号的 二分法
class Solution3 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0) return { -1,-1 };
		int left = 0;
		int right = nums.size() - 1;
		int l = 0;
		int r = right;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		if (left > right || nums[left] != target) {
			return { -1,-1 };
		}
		while (l < r) {
			int mid = (l + r) / 2 + 1;
			if (nums[mid] > target) {
				r = mid - 1;
			}
			else {
				l = mid ;
			}
		}
		if (left > right || left > r) {
			return { -1,-1 };
		}
		else {
			return { left,r };
		}
	}
};

