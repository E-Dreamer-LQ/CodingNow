// leetcode492-构造矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/construct-the-rectangle

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
	vector<int> constructRectangle(int area) {
		int w = sq(area);
		//寻找一个数的两个最相邻的因数
		while (area % w != 0) w--;
		return { area / w, w };
	}
private:
	int sq(int area) {     // 牛顿法求平方根
		long x = area;
		while (x * x > area) {
			x = (x + area / x) / 2;
		}
		return x;
	}
};