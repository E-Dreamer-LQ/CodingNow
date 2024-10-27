// newcoder9-变态跳台阶.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

// 规律分析:  https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387?f=discussion


class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 1) return 1;
		if (number == 2) return 2;
		if (number >= 3) {
			return 2 * jumpFloorII(number - 1);
		}

	}
};