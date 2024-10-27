// leetcode537-复数乘法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
// 在C++中，atoi是将const char* 类型转为int类型，而stoi是将string类型转为int类型

class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		auto pos_add = a.find('+');
		auto pos_add_b = b.find('+');
		map<string,int> rb_map;
		string num1 = "",num2 = "",num3="",num4 = "";

		int na = a.size();
		int nb = b.size();
		for (int i = 1; i <= 100; i++) {
			rb_map[to_string(i)] = i; 
		}
		if (pos_add != a.npos)
		{
			num1 = a.substr(0, pos_add);
			num2 = a.substr(pos_add + 1, na - pos_add - 2);
		}

		if (pos_add_b != b.npos)
		{
			num3 = b.substr(0, pos_add_b);
			num4 = b.substr(pos_add_b + 1, na - pos_add_b - 2);
		}

		int k1, k2, k3, k4;
		k1 = rb_map.find(num1)->second * rb_map.find(num3)->second;
		k2 = rb_map.find(num1)->second * rb_map.find(num4)->second;
		k3 = rb_map.find(num2)->second * rb_map.find(num3)->second;
		k4 = rb_map.find(num2)->second * rb_map.find(num4)->second;

		return to_string(k1 - k4) + "+" + to_string(k2 + k3) + "i";
		
	}

};

void main() {
	Solution S;
	string a = "1+1i";
	string b = "1-1i";
	S.complexNumberMultiply(a, b);
}


// 来自别人的精简代码
class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		auto res1 = split(a);
		auto res2 = split(b);
		int k1, k2, k3, k4;
		k1 = res1.first * res2.first;
		k2 = res1.second * res2.first;
		k3 = res1.first * res2.second;
		k4 = res1.second * res2.second;
		return to_string(k1 - k4) + "+" + to_string(k2 + k3) + "i";
	}
private:
	pair<int, int> split(string s) {
		string num1 = "", num2 = "";
		int n = s.length();
		int pos = s.find('+');
		if (pos != s.npos) {
			num1 = s.substr(0, pos);
			num2 = s.substr(pos + 1, n - pos - 2);
		}
		int res1 = num1.length() != 0 ? stoi(num1) : 0;
		int res2 = num2.length() != 0 ? stoi(num2) : 0;
		return { res1, res2 };
	}
};