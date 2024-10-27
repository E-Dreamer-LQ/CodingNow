// leetcode8-跳台阶.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class Solution {
public:
	// 动态规划
	int jumpFloor(int number) {
		if (number == 1) return 1;
		if (number == 2) return 2;
		if (number > 2) {
			return jumpFloor(number - 1) + jumpFloor(number - 2);
		}
	}
};

// 迭代法
class Solution2 {
public:
	// 动态规划
	int jumpFloor(int number) {
		if (number == 1) return 1;
		if (number == 2) return 2;
		int prenum = 2;
		int preprenum = 1;
		int res = 0;
		for (int i = 3; i <= number; i++) {
			res = prenum + preprenum;
			preprenum = prenum;
			prenum = res;
		}
		return res;


	}
};



void main() {
	Solution S;
	int number = 10;
	int res = S.jumpFloor(number);
	cout << res << endl;

	Solution2 S2;
	int res2 = S2.jumpFloor(number);
	cout << res2 << endl;
}