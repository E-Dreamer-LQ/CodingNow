// leetcode401-二进制手表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/binary-watch

#include <iostream>
#include <vector>
#include <string>

using namespace  std; 

// 暴力枚举
class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> res;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 60; j++) {
				if (count(i) + count(j) == num) {
					string tmp = to_string(j);
					if (j < 10)
						tmp = "0" + to_string(j); // "01", "02" ... "09"
					res.push_back(to_string(i) + ":" + tmp);
				}
			}
		}
		return res;

	}
	// 计算二进制中1的个数
	int count(int n) {
		int res = 0;
		while (n != 0) {
			n = n & (n - 1); // if(n = n&1) res++; n = n >> 1;
			res++;
		}
		return res;
	}
};


void main() {
	Solution S;
	int num = 1;
	vector<string> res = S.readBinaryWatch(num);
	for (auto it : res) {
		cout << it + " " ;
	}


}