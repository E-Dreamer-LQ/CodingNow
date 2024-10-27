// leetcode324-摆动排序 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/wiggle-sort-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

/*
先对数组排序，然后找出数组中间位置数，将数组分为两段，先从前半段取最后一个数放在原数组第一个位置，
然后从后半段取最后一个数放在原数组第二个位置，这样保证第一个数小于第二个数，然后再从前半段取大数第二个数，
放在原数组第三个位置，从后半段取倒数第二个数放在原数组第四个位置，这保证第三个数小于第二个数且小于第四个数，
以此类推。
*/
// 方法一： 两端排序, 排序后也可以用栈实现
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int size = nums.size();
		vector<int> tmp(nums);
		int end = size - 1, mid = (size + 1) / 2 - 1;
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < size; ++i) {
			nums[i] = i % 2 == 0 ? tmp[mid--] : tmp[end--];
		}
	}
};



// 方法二 : 三路
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		auto midptr = nums.begin() + nums.size() / 2;
		nth_element(nums.begin(), midptr, nums.end());
		int mid = *midptr;

		// 3-way-partition
		int i = 0, j = 0, k = nums.size() - 1;
		while (j < k) {
			if (nums[j] > mid) {
				swap(nums[j], nums[k]);
				--k;
			}
			else if (nums[j] < mid) {
				swap(nums[j], nums[i]);
				++i;
				++j;
			}
			else {
				++j;
			}
		}

		if (nums.size() % 2) ++midptr;
		vector<int> tmp1(nums.begin(), midptr);
		vector<int> tmp2(midptr, nums.end());
		for (int i = 0; i < tmp1.size(); ++i) {
			nums[2 * i] = tmp1[tmp1.size() - 1 - i];
		}
		for (int i = 0; i < tmp2.size(); ++i) {
			nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
		}
	}
};

