// 最长公共子序列问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 使用动态规划解决 最长公共子序列问题

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 



class Solution {
public:  
	int LongConmmonSubsquence(string str1, string str2) {
		// 创建一个dp数组(备忘录)，  dp[i][j] 的含义是：对于 s1[1..i] 和 s2[1..j]，它们的 LCS 长度是 dp[i][j]
		int m = str1.size();
		int n = str2.size(); 
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for (int i = 1; i < str1.size()+1; i++) {
			for (int j = 1; j < str2.size()+1; j++) {
				if (str1[i - 1] == str2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;  //这边找到一个 lcs 的元素，继续往前找
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //谁能让 lcs 最长，就听谁的
				}
			}
		}
		return dp[-1][-1];

	}
};


/*
(1) 如果S的最后一位等于T的最后一位，则最大子序列就是{s1,s2,s3...si-1}和{t1,t2,t3...tj-1}的最大子序列+1

(2) 如果S的最后一位不等于T的最后一位，那么最大子序列就是

① {s1,s2,s3..si}和 {t1,t2,t3...tj-1} 最大子序列

② {s1,s2,s3...si-1}和{t1,t2,t3....tj} 最大子序列
*/
