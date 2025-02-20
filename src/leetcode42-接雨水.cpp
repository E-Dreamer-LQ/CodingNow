﻿// leetcode42-接雨水.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/trapping-rain-water/

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std; 

// 单调栈

class Solution {
public:
	int trap(vector<int>& height) {
		int ret = 0;
		stack<int> s;
		for (int i = 0; i < height.size(); i++) {
			while (!s.empty() && height[i] > height[s.top()]) {
				int cur = height[s.top()];
				s.pop();
				int l = s.empty() ? -1 : s.top();
				// l此时指向的是此次接住的雨水的左边界的位置。右边界是当前的柱体，即i。
				// min(height[l], height[i] )是左右柱子高度的min，减去 cur 就是雨水的高度。
				// i - l - 1 是雨水的宽度。
				ret += l == -1 ? 0 : (min(height[l], height[i]) - cur) * (i - l - 1);
			}
			s.push(i);
		}
		return ret;
	}
};