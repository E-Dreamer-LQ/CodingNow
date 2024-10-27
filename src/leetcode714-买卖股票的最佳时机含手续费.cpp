// leetcode714-买卖股票的最佳时机含手续费.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int dp_i_0 = 0, dp_i_1 = INT_MIN;
		for (int i = 0; i < prices.size(); i++) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_0 + prices[i]);
			dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
		}
		return dp_i_0;
	}
};