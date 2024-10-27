// leetcode123-买卖股票的最佳时机 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int dp_i10 = 0, dp_i11 = INT_MIN;
		int dp_i20 = 0, dp_i21 = INT_MIN;
		for (int i = 0; i < prices.size(); i++) {
			dp_i20 = max(dp_i20, dp_i21 + prices[i]);
			dp_i21 = max(dp_i21, dp_i10 - prices[i]);
			dp_i10 = max(dp_i10, dp_i11 + prices[i]);
			dp_i11 = max(dp_i11, -prices[i]);
		}
		return dp_i20;
	}
};