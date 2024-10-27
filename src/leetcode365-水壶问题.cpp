// leetcode365-水壶问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/water-and-jug-problem

#include <iostream>
using namespace std;

/*
ax + by = z 求是否有合理的解 ，x ，y 为系数
化简 a * t1 * k + b * t2 * k == z;
然后 k * (a * t1 + b * t2) = z;
也就是说z为 a 和 b 的gcd 的倍数
特判为 0 的时候 以及 使得等式成立的基本条件 x + y >= z
*/

// GCD定理

// 暴力法
class Solution {
public:
	// 求最大公约数
	int gcd(int x,  int y) {
		if(y == 0) return x;
		int r = x % y;
		return gcd(y, r); 
	}
	bool canMeasureWater(int x, int y, int z) {
		if (z == 0)
			return true;
		if (x + y < z)
			return false;
		return (z % gcd(x, y) == 0 && (x + y) >= z);
	}
};

void main() {
	Solution S;
	int x = 3, y = 5, z = 4;
	bool res = S.canMeasureWater(x, y, z);
	cout << res << endl;
}