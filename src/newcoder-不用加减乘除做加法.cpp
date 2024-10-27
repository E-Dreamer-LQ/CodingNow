// newcoder-不用加减乘除做加法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std; 

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0) {  // 进位值为0 跳出循环
			int temp = num1 ^ num2; // 得到二进制的相加
			num2 = (num1 & num2) << 1;   // 得到二进制的进位
			num1 = temp;
		}
		return num1;
	}
};




