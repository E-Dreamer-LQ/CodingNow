// newcoder-连续子数组的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


/*
使用动态规划
F（i）：以array[i]为末尾元素的子数组的和的最大值，子数组的元素的相对位置不变
F（i）=max（F（i-1）+array[i] ， array[i]）
res：所有子数组的和的最大值
res=max（res，F（i））
*/

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int res = array[0]; // 记录当前所有子数组的和的最大值
		int max1 = array[0]; // 包含array[i] 的连续数组最大值
		for (int i = 1; i < array.size(); i++) {
			max1 = max(max1 + array[i], array[i]);
			res = max(res, max1);
		}
		return res; 
	}
};
// 动态规划， 选择拿还是不拿
class Solution2 {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		vector<int> dp(array.size());
		dp[0] = array[0];
		for (int i = 1; i < array.size(); i++) {
			dp[i] = max(array[i] , dp[i - 1] + array[i]);
		}
		int res = dp[0];
		for (int i = 1; i < array.size();i++) {
			//cout << dp[i]; 
			if (dp[i] > res) {
				res = dp[i];
			}
		}
		return res; 

	}
};


void main() {
	vector<int> array{6,-3,-2,7,-15,1,2,2 };
	Solution S;
	Solution2 S2; 
	int res = S.FindGreatestSumOfSubArray(array); 
	int res2 = S2.FindGreatestSumOfSubArray(array); 
	cout << res << endl; 
	cout << res2 << endl; 

}

