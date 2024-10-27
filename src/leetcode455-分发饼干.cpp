// leetcode455-分发饼干.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/assign-cookies/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// 题目转化为 数组s中有多少个数大于等于 g中的数的个数
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		auto cmp = [](const int& a, const int& b) {
			return a > b;
		};
		auto cmp1 = [](const int& a, const int& b) {
			return a < b;
		};
		sort(g.begin(), g.end(),cmp);
		sort(s.begin(), s.end(), cmp1);
		int res = 0;
		stack<int> sta; 
		for (auto num : g) {
			sta.push(num);
		}
		for (auto it : s) {
			if (it >= sta.top()) {
				res += 1; 
				sta.pop();
			}
			else {
				break;
			}
		}
		return res; 
	}
};


void main() {
	Solution S;
	vector<int> g{1,2,3};
	vector<int> s{1,1};
	int res = S.findContentChildren(g, s);
	cout << res << endl;

}