// leetcode275-h-指数II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/h-index-ii

/*  h指数的定义：h 指数的定义: “h 代表“高引用次数”（high citations），
 一名科研人员的 h 指数是指他（她)的（N 篇论文中）至多有 h 篇论文分别被引用了至少 h 次。
（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）" */


#include <iostream>
#include <vector>
using namespace std; 


class Solution {
public:
	int hIndex(vector<int>& citations) {
		int N = citations.size();
		int h = 0;
		while (citations[N - h - 1] >= h) {
			h++;
		}
		return h;
	}
};


// 二分法查找
int hIndex2(vector<int>& citations) {
	int total = citations.size();
	int l = 0, r = citations.size() - 1;
	int res=0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (citations[mid] >= total - res) {
			res = total - mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return res;
	

}