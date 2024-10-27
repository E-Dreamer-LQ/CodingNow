// leetcode436-寻找右区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/find-right-interval/

#include <iostream>
#include <vector>
#include <map>
using namespace std;


// 大致方法一定要走对

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1)  return { -1 };
		vector<int> res;
		map<int, int> record; // 使用low_bound   
		res.reserve(intervals.size());
		for (int i = 0; i < intervals.size(); i++) {
			record[intervals[i][0]] = i;   //加入元素时已经排序好
		}
		for (auto val : intervals) {
			auto it = record.lower_bound(val[1]); // 查找不小于(>=)区间尾的record中元素的最小位置
			if (it != record.end()) {
				res.push_back(it->second);
			}
			else
				res.push_back(-1);
		}
		return res;
	}
};


