// leetcode121-买卖股票的最佳时机.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
// 动态规划问题:
// 套路：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

// 方法一： 暴力法
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res=0; 
		for (int i = 0; i < prices.size()-1; i++) {   // 注意溢出问题
			for (int j = i+1; j < prices.size(); j++) {
				int profits = prices[j] - prices[i];
				if (profits>res) {
					res = profits;
				}
			}
		}
		return  res; 
	}
};


// 方法二： 动态规划
int maxProfit1(vector<int>& prices) {
	if (prices.size() <= 1) return 0;
	vector<int> diff(prices.size() - 1);
	for (int i = 0; i < prices.size() - 1; ++i) {
		diff[i] = prices[i + 1] - prices[i];
	}

	int last = 0;
	int profit = last;
	for (int i = 0; i < diff.size(); ++i) {
		last = max(0, last + diff[i]);
		profit = max(profit, last);
	}
	return profit;
}

int maxProfit2(vector<int>& prices) {
	int last = 0, profit = 0;
	for (int i = 0; i < (int)prices.size() - 1; ++i) {
		last = max(0, last + prices[i + 1] - prices[i]);
		profit = max(profit, last);
	}
	return profit;
}
//作者：ivan_allen
//链接：https ://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/121-mai-mai-gu-piao-de-zui-jia-shi-ji-dp-7-xing-ji/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// 空间复杂度O(1) 解法（重要）

int maxProfit3(vector<int>& price) {
	int dp_i_0 = 0, dp_i_1 = INT_MIN;
	for (int i = 0; i < price.size(); i++) {
		dp_i_0 = max(dp_i_0, dp_i_0 + price[i]);
		dp_i_1 = max(dp_i_1, -price[i]);  // dp_i_0 = 0
	}
	return dp_i_0;
}

