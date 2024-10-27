// leetcode454-四数相加 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/4sum-ii/

#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int N = A.size();
		int res = 0;
		map<int, int> rb_map;     // a+b+c+d = 0 
		for (auto a : A) {
			for (auto b : B) {
				rb_map[(a + b)]++;
			}
		}
		for (auto c : C) {
			for (auto d : D) {
				res += rb_map[-(c + d)];
			}
		}
		return res;
	}
};

