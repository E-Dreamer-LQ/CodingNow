// leetcode1306-跳跃游戏III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 

#include <iostream>
#include <vector>
using namespace std; 

class Solution1 {
public:
	bool canReach(vector<int>& arr, int start) {
		vector<bool> dp(arr.size(), false);
		return dfs(dp, arr, start);
	}private:
		bool dfs(vector<bool>& dp, vector<int>& arr, int start) {
			if (start < 0 || start >= arr.size()) return false;
			if (dp[start] == false) { // 没有跳到过的位置
				dp[start] = true;
				if (arr[start] == 0) return true;
				return dfs(dp, arr, start - arr[start]) || dfs(dp, arr, start + arr[start]);
			}
			else
				return false;
		}
};

//  oj 出错
class Solution {
public:
	bool canReach(vector<int>& arr, int start) {
		int length = arr.size();
		int zero_prosition = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 0) {
				zero_prosition = i;
			}
		}
		if (start + arr[start] > length || start - arr[start] < 0) {
			return false;
		}
		else if (start + arr[start] <= length || start - arr[start] >= 0) { // 往右边跳
			start = start + arr[start];
			canReach(arr, start);
		}
		else if (start + arr[start] > length || start - arr[start] >= 0) {  // 往左边跳
			start = start - arr[start];
			canReach(arr, start);
		}
		return  start == zero_prosition ? true : false;
	}
};


void main() {
	Solution S;
	vector<int> arr{4,2,3,0,3,1,2};
	int start = 5;
	bool res = S.canReach(arr, start);
	cout << boolalpha << res << endl;
}