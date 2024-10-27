// leetcode441-排列硬币.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/arranging-coins/

#include <iostream>
using namespace std;
//给定整数n，求[1,k]（k为整数）之间满足1+2+3+4...+k<=n的最大k值。
class Solution {
public:
	int arrangeCoins(int n) {
		for (int i = 1; i < n; i++) {
			if (i * (i + 1) > 2 * n) {   // 1 .....i 的和
				return i-1;
			}
			else if (i * (i + 1) > 2 * n) {
				return i;
			}
		}
	}
};

void main() {
	Solution S;
	int n = 6;
	int res = S.arrangeCoins(n);
	cout << res << endl;
}