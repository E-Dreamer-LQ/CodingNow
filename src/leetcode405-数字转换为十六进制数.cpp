// leetcode405-数字转换为十六进制数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std; 

class Solution {
public:
	string toHex(int num) {
		if (num == 0) return "0";
		string hex = "0123456789abcdef", ans = "";
		while (num && ans.size() < 8) {
			ans = hex[num & 0xf] + ans;  //使用位与   num & 15
			num >>= 4;   //无符号右移，左边填0
		}
		return ans;
	}
};


class Solution2 {
public:
	string toHex(int num) {
		if (num == 0) return "0";
		string res = ""; 
		unordered_map<int, string> hashmap;
		for (int i = 0; i < 10; i++) {
			hashmap[i] = to_string(i);
		}
		hashmap.insert(make_pair(10,"a"));
		hashmap.insert(make_pair(11,"b"));
		hashmap.insert(make_pair(12, "c"));
		hashmap.insert(make_pair(13, "d"));
		hashmap.insert(make_pair(14, "e"));
		hashmap.insert(make_pair(15, "f"));

		while (num) {
			int temp = num % 16;
			//res += hashmap.find(temp)->second;
			res.insert(0, hashmap.find(temp)->second);
			num = num / 16; 
		}

		return res;
	}
};


void main() {
	Solution S;
	int num = 80;
	string res = S.toHex(num);
	Solution2 S2;
	string res2 = S2.toHex(num);
	cout << res << endl;
	cout << res2 << endl;
}
/*
使用位运算，每4位，对应1位16进制数字。 将输入右移4位，再做一次，直到输入变为0 这里两个概念了解下：

位与(&)：第一个操作数的的第n位与第二个操作数的第n位如果都是1，那么结果的第n为也为1，否则为0。 无符号右移：
位运算符（>>>），它使用了“零扩展”：无论正负，都在高位插入0。
*/

