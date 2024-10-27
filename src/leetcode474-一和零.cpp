// leetcode474-一和零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/ones-and-zeroes/

#include <iostream>

#include<vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		if (strs.size() == 0 || (m == 0 && n == 0))
			return 0;
		auto cmp = [](const string& a, const string& b) {
			return a.size() < b.size();
		};
		sort(strs.begin(), strs.end(), cmp);
		int N = strs.size()-1;
		while (N--) {
			int a = 0, b = 0;
			for (auto str : strs[N]) {
				if (str == '0') {
					a++;
				}
				else {
					b++;
				}
			}
			if (a <= m && b <= n) {
				return strs[N].size();
				break;
			}
		}
		return 0; 

	}
};


// 方法二： 动态规划
/*
这个题最重要的是找到物品 和 容量。
换个思路：
A:如果题目是给你一个序列，里面存的是由0组成的字符串，每个字符串的长度不一定，但是都由0组成，给你m个0.求这m个0最多可以装多少个字符串？
B:如果题目给你一个序列，里面存了好多个字符串，每个字符串代表一个物品，长度越长代表物品越沉，背包最大承载量为100，求最多能装多少个物品？

这就熟悉了->01背包
题目就是换了个思路，两维了。一方面要考虑0的情况，一方面要考虑1的情况。
物品没有变，是strs
容量有两个，m和n，要都满足。

动态转移方程
for(0..strs.size)
 for(m...0)
  for(n...0)
	dp[i][j] = max(dp[i][j], dp[i-0数量][j-1数量]+1)

*/


class Solution2 {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		if (strs.size() == 0) return 0;
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		// dp[i][j]表示使用i个0和j个1能表示的字符串的最大数量
		for (auto str : strs) {
			int zeros = 0, ones = 0;
			for (auto s : str) {
				if (s == '0') {
					zeros++;
				}
				else {
					ones++;
				}
			}
			// 动态规划套路
			for (int i = m; i >= zeros; i--) {
				for (int j = n; j >= ones; j--) {
					dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
				}
			}
		}
		return dp[m][n];
	}
};




void main() {
	Solution S;
	vector<string> arr{ "10", "0001", "111001", "1", "0" };
	int m = 5, n = 3;
	int res = S.findMaxForm(arr,m,n);
	cout << res << endl;
}