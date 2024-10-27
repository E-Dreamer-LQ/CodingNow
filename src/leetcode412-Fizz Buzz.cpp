// leetcode412-Fizz Buzz.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/fizz-buzz

#include <iostream>
#include <vector>
#include <string>
using namespace std; 


class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> res;
		for (int i = 1; i <= n; i++) {
			if (i % 3 == 0 && i % 5 != 0) {
				res.push_back("fizz");
			}
			else if (i % 5 == 0 && i % 3 != 0) {
				res.push_back("Buzz");
			}
			else if (i % 15 == 0) {
				res.push_back("fizzBuzz");
			}
			else res.push_back(to_string(i));
		}
		return res;
	}
};

void main() {
	int n = 20;
	Solution S;
	vector<string> res = S.fizzBuzz(n);
	for (auto it = res.begin(); it != res.end(); it++) {
		cout << *it + " ";
	}

}