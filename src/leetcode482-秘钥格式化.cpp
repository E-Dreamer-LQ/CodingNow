// leetcode482-秘钥格式化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string res = "";
		string temp = "";
		for (auto s : S) {
			if (s != '-') {
				temp.push_back(s);
			}
		}
		int N = temp.size();
		int i=0;
		while (i<N) {
			res += toupper(temp[i]);
			if ((i+1)%K == 0)
				res += '-';
			i++;
		}
		return res;
	}
};
// 正确解法
class Solution2 {
public:
	string licenseKeyFormatting(string S, int K) {
		cout << count(S.begin(), S.end(), '-'); //  ‘-’数量
		cout << endl;
		int num = K - (S.size() - count(S.begin(), S.end(), '-') % K);  // 如果不能整除K，那么多余的将在第一个分组
		string res = "";
		for (auto ch : S) {
			if (ch == '-') continue;
			if (num == 0 && res != "") res += '-';
			res += toupper(ch);
			num = (num + 1) % K;
		}
		return res;
	}
};

void main() {
	Solution S;
	Solution2 S2;
	string str = "2-5g-3J";
	int K = 2;
	string res = S.licenseKeyFormatting(str, K);
	string res2 = S2.licenseKeyFormatting(str, K);
	cout << res << endl;
	cout << res2 << endl;
}


/* python 代码

class Solution:
	def licenseKeyFormatting(self, S: str, K: int) -> str:
		# 逆序思维，假如题目中第一组的条件是用在最后一组，是不是很容易做：遇到合适索引就拼接-
		# 所以本题将字符串翻转一下，然后每次换成前插就好了
		s = S.upper().replace('-','')[::-1] // 1. 逆序   2.将字母变成大写  3. '-'换成 ''
		res = ''
		for i in range(len(s)):
			if i%K == 0 and i!=0: 
				res = '-' + res
			res = s[i] + res
		return res

*/
