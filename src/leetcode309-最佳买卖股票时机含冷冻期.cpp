// leetcode309-最佳买卖股票时机含冷冻期.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
// 股票售出之后，隔一天才能再次买入
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int dp_i_0 = 0, dp_i_1 = INT_MIN;
		int dp_pre_0 = 0; // 代表 dp[i-2][0]
		for (int i = 0; i < prices.size(); i++) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_0 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
			dp_pre_0 = temp;   // 第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 
		}
	}
};