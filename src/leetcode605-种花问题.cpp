// leetcode605-种花问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/can-place-flowers/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int count = 0, i = 0;
		int len = flowerbed.size() - 1;
		while (i <= len) {
			if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == len || flowerbed[i + 1] == 0)) {
				flowerbed[i] = 1;
				count++;   // 每三个零中间中一个，注意左右边界
			}
			i++;
		}
		return count >= n;
	}
};