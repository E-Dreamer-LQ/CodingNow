// leetcode274-H-指数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/h-index

// H指数定义：一名科研人员的 h 指数是指他（她）的 （N 篇论文中）至多有 h 篇论文分别被引用了至少 h 次
// 大小为N的数组中，至少有h个元素大于等于h

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 

class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());
		int N = citations.size();
		int h = 0;
		while (citations[N - h-1] >= h) {
			h++;
		}
		return h;
	}
};

void main() {
	Solution S;
	vector<int> citations{ 3,0,6,1,5 };
	int res = S.hIndex(citations);
	cout << res << endl;
}


