// leetcode264-丑数II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/ugly-number-ii

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std; 

// 三指针法求解
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n);
		dp[0] = 1;
		int i2 = 0, i3 = 0, i5 = 0, i = 1;
		while (i < n) {
			dp[i] = min(2 * dp[i2], min(3 * dp[i3], 5 * dp[i5]));
			if (dp[i] == 2 * dp[i2]) i2++;
			if (dp[i] == 3 * dp[i3]) i3++;
			if (dp[i] == 5 * dp[i5]) i5++;
			i++;
		}
		return dp[n - 1];
	}
};

// 方法二 最小堆+ 哈希表去重
int nthUglyNumber2(int n) {
	priority_queue<int, vector<int>, greater<int>> minheap;
	set<int> numSet; //哈希表去重
	vector<int> dp(n);  // 这里需要初始化大小
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int factor[] = { 2,3,5 };
		for (auto x : factor) {
			int val = dp[i-1] * x;
			if (!numSet.count(val)) { 
				minheap.push(val); 
				numSet.insert(val);
			}
		}
		dp[i] = minheap.top();  // 取堆顶的元素
		minheap.pop();
	}
	return dp[n - 1];
}

void main() {
	Solution S;
	int n = 10;
	int res = S.nthUglyNumber(n);
	int res2 = nthUglyNumber2(n);
	cout << res << endl;
	cout << res2 << endl;
}


