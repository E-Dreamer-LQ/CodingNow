// leetcode435-无重叠区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/non-overlapping-intervals

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		auto cmp = [](const vector<int>& a, const vector<int>& b) {
			return a[1] < b[1];
		};
		sort(intervals.begin(), intervals.end(), cmp);
		int end = intervals[0][1];
		int count = 1;
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] >= end) {
				end = intervals[i][1];
				count++;
			}
		}
		return intervals.size() - count;
	}
};


// 好想法
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	auto cmp = [](const vector<int>& a, const vector<int> b) {
		return a[0] < b[0];
	};
	sort(intervals.begin(), intervals.end(), cmp);
	int end = intervals[0][1];
	int res = 0;
	for (int i = 1; i < intervals.size(); i++) {
		if (intervals[i][0] < end) {
			end = min(intervals[i][0], end);
			res += 1;
		}
		else {
			end = intervals[i][1];
		}
	}
	return res;

}


void main() {
	Solution S;
	

}