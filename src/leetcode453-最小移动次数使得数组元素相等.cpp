// leetcode453-最小移动次数使得数组元素相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/

#include <iostream>
#include <vector>
using namespace std;


/*
移动一次使得n-1个元素增加1，那么相反的意思就是每移动一次元素，使得一个元素减1，
最后全部相等即可（必定相等于最小值）
*/

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int min = INT_MAX;
		for (auto num : nums) {
			if (min > num) min = num;
		}
		int res = 0;
		for (auto num : nums)
			res += (num - min); // 每个都数都变到最小
		return res;
	}
};

