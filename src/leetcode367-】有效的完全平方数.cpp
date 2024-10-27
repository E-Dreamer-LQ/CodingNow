// leetcode367-】有效的完全平方数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/valid-perfect-square

#include <iostream>
using namespace std;

// 二分法
class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num == 0) return true;
		int l = 0, r = 46340;  // pow(INT_MAX) = 46340
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (mid * mid < num) {
				l = mid + 1;
			}
			else if (mid * mid > num) {
				r = mid - 1;
			}
			else {
				return true;
			}
		}
		return false;
	}
};

void main() {
	Solution S;
	int num = 14;
	bool res = S.isPerfectSquare(num);
	cout << boolalpha <<  res << endl;
}