// leetcode507-完美数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/perfect-number/

#include <iostream>
using namespace std; 

/*对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。*/
class Solution {
public:
	bool checkPerfectNumber(int num) {
		int n = 1;
		int sum = 0;
		while (n <= num) {
			if (num % n == 0) {
				sum += n + num / n;
			}
			n++;
		}
		cout << sum << endl;
		return sum/2-num == num ? true : false;

	}
};
void main() {
	Solution S;
	int num = 28;
	bool res = S.checkPerfectNumber(num);
	cout << boolalpha << res << endl;
}

// 超出时间限制

// 优化
class Solution2 {
public:
	bool checkPerfectNumber(int num) {
		if (num == 0) return false;
		int res = num, i = 1;
		while (i <= res / 2) {
			if (res % i == 0) 
				num -= i;
			i++;
		}
		return num == 0;
	}
};
