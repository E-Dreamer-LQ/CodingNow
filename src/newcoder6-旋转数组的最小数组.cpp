// newcoder6-旋转数组的最小数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0) return 0;
		int left = 0;
		int right = rotateArray.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (rotateArray[mid] > rotateArray[right]) {
				left = mid + 1;
			}
			else if (rotateArray[mid] < rotateArray[right]) {
				right = mid;
			}
			else {
				right = right - 1;
			}
		}
		return rotateArray[left];
	}
};



