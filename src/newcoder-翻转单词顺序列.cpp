// newcoder-翻转单词顺序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std; 

// 来自别人的答案
class Solution {
public:
	string ReverseSentence(string str) {
		auto size = str.size();
		if (size == 0) return "";
		int mark = 0;
		str += ' ';
		for (int i = 0; i < size + 1; ++i) {
			if (str[i] == ' ') {
				ReverseWord(str, mark, i - 1);
				mark = i + 1;
			}
		}
		str = str.substr(0, size);
		ReverseWord(str, 0, size - 1);
		return str;
	}
	void ReverseWord(string& str, int l, int r) {
		while (l < r) {
			swap(str[l], str[r]);
			++l;
			--r;
		}
	}
};





// 来自别人的答案
class Solution2 {
public:
	//翻转str从s到e的部分
	void ReverseWord(string& str, int s, int e)
	{
		while (s < e)
			swap(str[s++], str[e--]);
	}

	string ReverseSentence(string str) {
		ReverseWord(str, 0, str.size() - 1); //先整体翻转
		int s = 0, e = 0;
		int i = 0;
		while (i < str.size())
		{
			while (i < str.size() && str[i] == ' ') //空格跳过
				i++;
			e = s = i; //记录单词的第一个字符的位置
			while (i < str.size() && str[i] != ' ') //不是空格 找单词最后一个字符的位置
			{
				i++;
				e++;
			}
			ReverseWord(str, s, e - 1); //局部翻转
		}
		return str;
	}
};



// 赛码 OJ
#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;


void Reverseword(string str, int l, int r) {
	while (l < r) {
		swap(str[l++], str[r--]);
	}
}
int main0() {
	int n;
	while (cin >> n) {
		string str;
		cin >> str;
		int length = str.size();
		Reverseword(str, 0, length - 1);
		int start = 0, end = 0;
		int i = 0;
		while (i < length) {
			while (i < length && str[i] == ' ') {
				i++;
			}
			end = start = i; //记录单词的第一个字符的位置
			// 反转每个单词
			while (i < str.size() && str[i] != ' ') {
				i++;
				end++; 
			}
			Reverseword(str, start, end-1); // 局部反转
		}
		for (auto s : str) {
			cout << s;
		}
	}
	return 0; 

}


#include <iostream> 
using namespace std;

void main() {
	int num;
	while (cin >> num) {
		if (num < 0) cout << boolalpha << false;
		int help = 1;
		while (num) {
			help = help * 10;
			num = num / 10;
		}
		while (num) {
			if (num / help != num % 10) {
				cout << boolalpha << false;
			}
			num = (num % help) / 10;
			help = help / 100;
		}
		cout << boolalpha << true;
	}
}


