// leetcode55-跳跃游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/jump-game

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
	bool canJump(vector<int>& nums) { // 关键： 如果第一个格子能跳3， 则后面三个格子都能当起点跳
		int k=0;
		for (int i = 0; i < nums.size(); i++) {
			if (i > k) return false;
			k = max(k, nums[i] + i);
		}
		return true; 
	}
};

// 方法二

