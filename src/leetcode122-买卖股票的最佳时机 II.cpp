// leetcode122-买卖股票的最佳时机 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// k = +infinity时的情况
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int dp_i_0 = 0, dp_i_1 = INT_MIN;
		for (int i = 0; i < prices.size(); i++) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]); // dp_i_k_0 = max(dp_i-1_k_0,dp_i-1_k_1+prices[i])
			dp_i_1 = max(dp_i_1, temp + prices[i]); // dp_i_k_1 = max(dp_i-1_k_1,dp_i-1_k-1_0-prices[i])
		}
		return dp_i_0;
	}
};