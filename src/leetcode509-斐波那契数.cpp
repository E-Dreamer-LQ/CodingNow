// leetcode509-斐波那契数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/fibonacci-number/


// 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
#include <iostream>
using namespace std;

// 此种方法超时
class Solution {
public:
	int fib(int N) {
		if (N == 0) return 0;
		if (N == 1) return 1;
		if (N == 2) return 1; 
		if (N > 2)
			return fib(N - 1) + fib(N - 2);

	}
};

// 方法二： 迭代法
class Solution2 {
public:
	int fib(int N) {
		int prenum = 1;
		int preprenum = 0;
		int res=0;
		if (N == 0) return 0;
		if (N == 1) return 1;
		for(int i = 2;i<=N;i++) {
			res = prenum + preprenum;
			preprenum = prenum;  // 顺序不能乱
			prenum = res;
		}
		return res;
	}
};


void main() {
	Solution S;
	int N = 8;
	int res = S.fib(N);
	cout << res << endl;

	Solution2 S2;
	int res2 = S2.fib(N);
	cout << res2 << endl;
}