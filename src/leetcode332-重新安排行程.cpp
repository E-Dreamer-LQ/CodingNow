// leetcode332-重新安排行程.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/reconstruct-itinerary/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


  // 图的问题


class Solution {
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {

	}
};

class Solution {
public:
	int n = 0;
	map<string, map<string, int>> mp;
	vector<string> res, tmp;
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		n = tickets.size();
		for (auto& ticket : tickets) {
			++mp[ticket[0]][ticket[1]];
		}
		tmp.emplace_back("JFK");
		dfs();
		return res;
	}
	void dfs() {
		if (res.size() == n + 1) return;
		if (tmp.size() == n + 1) {
			res = tmp;  return;
		}
		for (auto& tt : mp[tmp.back()]) {
			if (tt.second == 0) continue;
			--tt.second;
			tmp.emplace_back(tt.first);
			dfs();
			tmp.pop_back();
			++tt.second;
		}
	}
};