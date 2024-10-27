// leetcode396-旋转函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/rotate-function

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 假设 Bk 是数组 A 顺时针旋转 k 个位置后的数组，我们定义 A 的“旋转函数” F 为：F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n - 1) * Bk[n - 1]。


// 每个F(n)等于上一个F(n-1)的前n-1项和相加再减去最后一项数

class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		int n = A.size();
		int max_sum = LONG_MIN;
		int sum = 0;
		int res = 0; 
		for (int i = 0; i < n; i++) {
			res += A[i] * i;
			sum += res;
		}
		for (int i = 0; i < n; i++) {
			max_sum = max(max_sum, res + n * A[i] - sum);  //F(0) + sum - n * A[最后一项]
		}
		return max_sum;


	}
};


