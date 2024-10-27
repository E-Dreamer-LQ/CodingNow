// leetcode313-超级丑数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std; 


class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> dp(n); 
		dp[0] = 1; 
		vector<int> index(primes.size(), 0); 
		for (int i = 1; i < n; i++) {
			int min = INT_MAX;  
			for (int j = 0; j < index.size(); j++) {
				if (dp[index[j]] * primes[j] < min) {
					min = dp[index[j] * primes[j]]; 
				}
				dp[i] = min;  
			}
			for (int j = 0; j < index.size(); j++) {
				if (min == dp[index[j]] * primes[j]) {
					index[j]++;  
				}
			}
		}
		return dp[n - 1];  
	}
};

