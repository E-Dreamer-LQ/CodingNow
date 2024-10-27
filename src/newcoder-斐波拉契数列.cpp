// newcoder-斐波拉契数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/coin-change/solution/dong-tai-gui-hua-tao-lu-xiang-jie-by-wei-lai-bu-ke/

#include <iostream>
#include <vector>
using namespace std; 


int fib(int N) {
	if (N < 1) return 0;
	// 备忘录全初始化为 0
	vector<int> memo(N + 1, 0);
	// 初始化最简情况
	return helper(memo, N);
}

int helper(vector<int>& memo, int n) {
	// base case 
	if (n == 1 || n == 2) return 1;
	// 已经计算过
	if (memo[n] != 0) return memo[n];
	memo[n] = helper(memo, n - 1) +
		helper(memo, n - 2);
	return memo[n];
}


int fib(int N) {
	vector<int> dp(N + 1, 0);
	// base case
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[N];
}