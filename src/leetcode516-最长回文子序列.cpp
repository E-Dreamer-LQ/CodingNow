// leetcode516-最长回文子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// hashmap 做不出来
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		multimap<string, int> rb_map(s.begin(),s.end());
		int res = 0;
		if (s.size() == 0) return res;
		for (auto it = rb_map.begin(); it != rb_map.end(); ++it) {
			if (it->second %2== 0 ) {
				res += it->second;
			}
			else if (it->second > 2 && it->second % 2 != 0) {
				res += it->second - 1;
			}
		}



	}
};

// 来自别人: 动态规划 （解析： https://leetcode-cn.com/problems/longest-palindromic-subsequence/solution/zi-xu-lie-wen-ti-tong-yong-si-lu-zui-chang-hui-wen/）
int longestPalindromeSubseq(string s) {
	int n = s.size();
	// dp 数组全部初始化为 0
	vector<vector<int>> dp(n, vector<int>(n, 0));
	// base case
	for (int i = 0; i < n; i++)
		dp[i][i] = 1;
	// 反着遍历保证正确的状态转移
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			// 状态转移方程
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	// 整个 s 的最长回文子串长度
	return dp[0][n - 1];
}