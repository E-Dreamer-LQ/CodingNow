// leetcode322-零钱兑换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/coin-change/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


// 方法一: 有问题
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int res = 0;
		int rest = amount;
		auto cmp = [](const int& a, const int& b) {
			return a < b;
		};
		sort(coins.begin(), coins.end(),cmp);
		while (rest != 0 && coins.size() != 0) {
			if (rest - coins.back() < 0) {
				coins.pop_back();
			}
			else {
				rest = rest - coins.back();
				res++;
			}      
		}
		if (rest != 0) return -1; 
		return res;

	}
};



class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		// 数组大小为 amount + 1，初始值也为 amount + 1
		vector<int> dp(amount + 1, amount + 1);
		// base case
		dp[0] = 0;
		for (int i = 0; i <= amount; i++) {
			// 内层 for 在求所有子问题 + 1 的最小值
			for (int coin : coins) {
				// 子问题无解，跳过
				if (i - coin < 0) continue;
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}
		}
		return (dp[amount] == amount + 1) ? -1 : dp[amount];
	}
};


// 方法二：完全背包问题
class Solution2 {
public:
	int coinChange(vector<int>& coins, int amount) {
		int INF = amount + 1;
		vector<int> dp(amount + 1, INF + 1);
		dp[0] = 0;
		for (int i = 0; i < coins.size(); i++) {
			for (int j = coins[i]; j < amount + 1; j++) {
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
		return dp[amount] < INF ? dp[amount] : -1;
	}
};

