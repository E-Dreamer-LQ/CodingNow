// leetcode397-整数替换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/integer-replacement

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int integerReplacement(int n) {
		return func(n); 
	}
	long func(int n) {
		if (n == 1) return 0; 
		if (n % 2 == 0) {
			return 1 + func(n / 2);
		}
		else {
			return 1 + min(func(n + 1), func(n - 1));
		}
	}
};

void main() {
	Solution S;
	int num = 7;
	int res = S.integerReplacement(num);
	cout << res << endl;
}

