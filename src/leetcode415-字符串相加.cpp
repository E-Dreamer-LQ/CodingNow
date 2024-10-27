// leetcode415-字符串相加.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 

#include <iostream>
#include <string>
using namespace std; 


// 类似于链表的相加
class Solution {
public:
	string addStrings(string num1, string num2) {
		int carry = 0;
		string res = "";
		int s;
		for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; i--, j--) {
			int x = num1[i] - '0';
			int y = num2[j] - '0';
			s = x + y +carry;
			carry = s % 10;
			res.insert(res.begin(),s%10 + '0'); // 数字型的char + '0' 等于整数时的字符类型
		}
		if (carry > 1) {
			res.insert(res.begin(), 1);
		}
	}
};