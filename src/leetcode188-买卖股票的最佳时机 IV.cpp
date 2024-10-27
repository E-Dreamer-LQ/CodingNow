// leetcode188-买卖股票的最佳时机 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// k 为有限次交易

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int maxk = k;
		int n = prices.size();
		if (maxk > n / 2) {    // maxk 如果大于n/2,则相当于是k为正无穷
			int dp_i_0 = 0, dp_i_1 = INT_MIN;
			for (int i = 0; i < prices.size(); i++) {
				int tmp = dp_i_0;
				dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
				dp_i_1 = max(dp_i_1, tmp - prices[i]);
			}
			return dp_i_0;
		}
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxk + 1, vector<int>(2)));  // 三维数组的定义
		if (prices.size() == 0) return 0;
		for (int i = 0; i < n; i++) {
			for (int k = 1; k <= maxk; k++) {   // k从1开始
				if (i - 1 == -1) {    // base case
					dp[i][k][0] = 0;
					dp[i][k][1] = -prices[i];   // dp[-1][k][0] = 0
					continue;
				}
				dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
				dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
			}
		}
		return dp[n - 1][maxk][0];
	}
};