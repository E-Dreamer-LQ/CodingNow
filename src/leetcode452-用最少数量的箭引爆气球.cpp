// leetcode452-用最少数量的箭引爆气球.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		int res = 0;
		auto cmp = [](const vector<int>& a, const vector<int>& b) {
			return a[0] < b[0];
		};
		sort(points.begin(), points.end(), cmp);
		int start = points[0][0];
		int end = points[0][1];
		for (int i = 1; i < points.size(); i++) {
			if (points[i][0] > start&& points[i][0] < end) {
				start = points[i][0];
				end = min(end, points[i][1]);
				res++;
			}
			else {
				start = points[i][0];
				end = points[i][1];
			}
		}
		return res;

	}
};

void main() {

}