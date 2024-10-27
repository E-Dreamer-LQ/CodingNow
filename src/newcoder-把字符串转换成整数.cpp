// newcoder-把字符串转换成整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std; 

/*
作者：马客(Mark)
链接：https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e?f=discussion
来源：牛客网

和res=res*10+str[i]-'0'是一样的。左移是乘以2的次方。
(res << 1) + (res << 3) = res * 2 + res * 8 = res * 10 。
字符'0'到'9'的ascii值的低4个二进制位刚好就是0到9所以str[i]&0xf
等于str[i]-'0'。位运算会比乘法运算效率高那么一点点点点...*/
class Solution {
public:
	int StrToInt(string str) {
		int n = str.size() - 1, s=1; 
		long long res = 0;
		if (!n) return 0;
		if (str[0] == '-') s = -1;
		for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < n; i++) {
			if (!('0' <= str[i] && str[i] <= '9')) return 0;
			res = res * 10 + str[i] - '0';
		}
		return res * s; 
	}
};

class Solution1 {
public:
	int StrToInt(string str) {
		int n = str.size(), s = 1;
		long long res = 0;
		if (!n) return 0;
		if (str[0] == '-') s = -1;
		for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < n; ++i) {
			if (!('0' <= str[i] && str[i] <= '9')) return 0;
			res = (res << 1) + (res << 3) + (str[i] & 0xf);//res=res*10+str[i]-'0';
		}
		return res * s;
	}
};

