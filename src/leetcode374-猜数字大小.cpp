// leetcode374-猜数字大小.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/guess-number-higher-or-lower/

#include <iostream>
using namespace std; 

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int l = 1;
		int r = n;
		int res = 0;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			int temp = guess(mid);
			if (temp == 0) {
				res = mid;
				break; 
			}
			else if (temp < 0) { // 输入数字 > 猜的数字
				r = mid - 1;
			}
			else { // 输入数字 < 猜的数字
				l = mid + 1;
			}
		}
		return res;
	}
};