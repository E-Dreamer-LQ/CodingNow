// leetcode518-零钱兑换II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 动态规划
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1);
		dp[0] = 1;
		for (auto coin : coins) {
			for (int j = 1; j <= amount; j++) {
				if (j >= coin) {
					dp[j] = dp[j] + dp[j - coin];
				}
			}
		}
		return dp[amount];
	}
};

void main() {
	Solution S;
	vector<int> coins{ 1,2,5 };
	int amount = 5;
	int res = S.change(amount, coins);
	cout << res << endl;
}


// dp[i][j]表示用硬币的前i个可以凑成金额j的个数， 使用二维矩阵的动态规划
// 动态规划
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		
	}
};

