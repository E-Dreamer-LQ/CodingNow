// leetcode263-丑数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/ugly-number

#include <iostream>
using namespace std; 

class Solution {
public:
	bool isUgly(int num) {
		int d[] = { 2,3,5 };
		for (auto s : d) {
			while (num > 0 && num%s == 0) {
				num = num / s;
			}
		}
		return num == 1 ? true : false;
	}
};

void main() {
	Solution S;
	int num = 8;
	bool res = S.isUgly(num);
	cout << res << endl;
}

