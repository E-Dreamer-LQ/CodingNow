// leetcode357-计算各个位数不同的数字个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/count-numbers-with-unique-digits

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
 
// 使用动态规划

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0) return 0;
		if (n == 1) return 10;
		if (n > 10) return 0;  // 一定会有重复的
		int sum = 10;
		int dp = 9; // 多位数的第一位不为零，因此有9种选择
		for (int i = 2; i < n; i++) {
			dp = dp * (10 - i + 1);
			sum += dp; // 加上前一个位的个数
		}
		return sum;  
	}
};



class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		//各位数字都不同。
		//来详解一下
		//dp[i]=dp[i-1]+(dp[i-1]-dp[i-2])*(10-(i-1));
		//加上dp[i-1]没什么可说的，加上之前的数字
		//dp[i-1]-dp[i-2]的意思是我们之前判断各位不重复的数字
		//我们要在这些数字后面填新的数字。当i=2时，说明之前选取的数字只有
		//1位，那么我们只要与这一位不重复即可，所以其实有9(10-1)种情况（比如1，后面可以跟0,2,3,4,5,6,7,8,9）。
		//当i=3时，说明之前选取的数字有2位，那么我们需要与2位不重复，所以剩余的
		//有8（10-2）种（比如12，后面可以跟0,3,4,5,6,7,8,9）
		if (n == 0)
			return 1;
		vector<int> dp;
		dp[0] = 1;
		dp[1] = 10;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * (10 - (i - 1));
		}
		return dp[n];
	}
};



