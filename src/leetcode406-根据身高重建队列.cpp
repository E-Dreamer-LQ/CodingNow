// leetcode406-根据身高重建队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/queue-reconstruction-by-height

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std; 


class Solution {
public:
	//bool cmp1(vector<int>& a, vector<int>& b) {
	//	if (a[0] != b[0]) return a[0] > b[0];
	//	else return a[1] < b[1];
	//}

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		vector<vector<int>> res;
		auto cmp1 = [](const vector<int>& a,const  vector<int>& b) {
			if (a[0] != b[0]) { return a[0] > b[0]; }
			else { return a[1] < b[1]; }
		};
		if (people.size() == 0) return res;
		sort(people.begin(),people.end(),cmp1);
		for (auto person : people) {
			res.insert(res.begin() + person[1], person);
		}
		return res;
	}
};

void main() {
	Solution S;

}