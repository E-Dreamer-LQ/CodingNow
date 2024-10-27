// leetcode386-字典序排数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/lexicographical-numbers

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;




class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> res;
		map<string, int> nums;
		for (int i = 1; i <= n; i++) {
			nums[to_string(i)] = i;
		}
		for (auto num : nums) {
			res.push_back(num.second);
		}
		return res; 
	}
};


void main() {
	Solution S;
	int n = 13;
	vector<int> res = S.lexicalOrder(n);
	vector<int>::iterator it; // 使用迭代器进行遍历
	for (it = res.begin(); it < res.end(); it++) {
		cout << *it;
	}
}


