// leetcode504-七进制数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  https://leetcode-cn.com/problems/base-7/
 
#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
	string convertToBase7(int num) {
		string res = "";
		if (num == 0) return "0";
		int val = num;
		num = abs(num);
		while (num) {
			res.insert(0, to_string(num % 7));
			num /= 7;
		}
		if (val < 0) res.insert(0, "-");
		return res;
	}
};

string convertobase2(int num) {
	string res = "";
	if (num == 0) return "0";
	int val = num;
	num = abs(num);
	while (num) {
		res.insert(0, to_string(num % 2));
		num /= 2;
	}
	if (val < 0) res.insert(0, "-");
	return res;
}



void main() {
	Solution S;
	int num = 100;
	int num2 = 5;
	string res = S.convertToBase7(num);
	cout << res << endl;
	cout << convertobase2(5) << endl;
}