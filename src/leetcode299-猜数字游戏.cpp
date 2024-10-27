// leetcode299-猜数字游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/bulls-and-cows

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
 
// 方法一： 先算公牛再算奶牛，用过的做标记
class Solution {
public:
	string getHint(string secret, string guess) {
		if (secret.size() != guess.size())
			cout << "size must be same" << endl;
		int bulls_cnt=0,cows_cnt=0;
		for (int i=0; i < secret.size(); i++) {
			if (secret[i] == guess[i])
			{
				bulls_cnt += 1;
				secret[i] = '*';
				guess[i] = '#';
			}
		}
		for (int i = 0; i < secret.length(); i++)
		{
			int j = guess.find(secret[i]);
			if (j != guess.npos && guess[j] != '#')   // 如果没有查询到，则返回string：：npos，这是一个很大的数，其值不需要知
			{
				cows_cnt++;
				secret[i] = '*';
				guess[j] = '#';
			}
		}

		return to_string(bulls_cnt) + "A" + to_string(cows_cnt) + "B";


	}
};

void main() {
	Solution s;
	string screte = "1780";
	string guess = "1870";
	cout << s.getHint(screte, guess) << endl;
}



// 方法二 ： 使用hashmap 
class Solution2 {
public:
	string getHint(string secret, string guess) {
		unordered_map <char, int> map;
		int a = 0, b = 0;
		for (int i = 0; i < secret.size(); i++) {
			if (secret[i] == guess[i])
				a++;
			map[secret[i]]++;
			map[guess[i]]--;   
		}

		for (int j = 0; j < 10; j++)
		{
			if (map[char(j + '0')] > 0)   //  ‘0’ 的ascII 为48 ， j+‘0’ = char j 
				b += map[char(j + '0')];//此时b为不相同的数字个数
		}
		b = secret.size() - b - a;//总个数减去不相同的个数=A个数+B个数
		return to_string(a) + "A" + to_string(b) + "B";

	}
};