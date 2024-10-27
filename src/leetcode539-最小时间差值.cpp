// leetcode539-最小时间差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std; 


class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		vector<int> res; 
		for (int i = 0; i < timePoints.size();i++) {
			auto time = split(timePoints[i]);
			int all_points = time.first * 60 + time.second;
			res.push_back(all_points);
		}
		auto cmp = [](const int& a, const int& b) {
			return a > b; 
		};
		return res[0] - res[1];

	}

	pair<int, int> split(string a) {
		string num1 = "", num2 = "";
		int pos = a.find(":");
		int n = a.size();
		if (pos != a.npos) {
			num1 = a.substr(0, pos);
			num2 = a.substr(pos + 1, n);
		}
		int res1 = num1.length() == 0 ? 0: stoi(num1);
		int res2 = num2.length() == 0 ? 0 : stoi(num2);
		return { res1, res2 };

	}
};