// leetcode905-按奇偶排序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 双指针处理， python 中可以使用双端队列实现

#include <iostream>
#include <vector>

using namespace std; 


class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int l = 0, r = A.size() - 1;
		while (l < r) {
			while (A[l] % 2 == 0) {
				l++;
			}
			while (A[r] % 2 != 0) {
				r--;
			}
			A[l] ^= A[r];
			A[r] ^= A[l];
			A[l] ^= A[r];
		}
		return A;
	}
};