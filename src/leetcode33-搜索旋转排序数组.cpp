// leetcode33-搜索旋转排序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std; 


class Solution {
public:
	int search(vector<int>& nums, int target) {
		int length = nums.size();
		int l = 0;
		int r = length - 1;
		
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (target == nums[mid]) {
				return mid;
			}
			if (nums[mid] < nums[r]) { // 右半区域有序
				if (target >= nums[mid] && target <= nums[r]) {
					l = mid + 1;  //如果target落在有序部分，那么l = mid + 1
				}
				else {
					r = mid - 1;
				}
			}
			else {      //  // 如果右半部分不是有序的，那必定左半部分有序
				if (target < nums[mid] && target >= nums[l])
					r = mid - 1;
				else
					l = mid + 1;
			}
		}
		return -1;

	}
};


