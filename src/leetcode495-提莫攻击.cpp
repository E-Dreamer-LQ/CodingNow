// leetcode495-提莫攻击.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/teemo-attacking/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.size() == 0) return 0;
		int res = 0; 
		sort(timeSeries.begin(), timeSeries.end());
		for (int i = 0; i < timeSeries.size()-1; i++) {
			if ((timeSeries[i+1] - timeSeries[i]) <= duration) {
				res += timeSeries[i + 1] - timeSeries[i]; 
			}
			else {
				res += duration; 
			}
		}
		return res+duration; 

	}
};


void main() {
	vector<int> timeSeries{1,2,3,4,5,6,7,8,9};
	int duration = 1;
	Solution S;
	int res = S.findPoisonedDuration(timeSeries, duration);
	cout << res << endl;

}