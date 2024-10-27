// newcoder12-数值的整数次方.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include <iostream>
using namespace std; 

class Solution {
public:
	// 来自别人： 简单快速幂
	double Power(double base, int exponent) {
		long long p = abs((long long)exponent);
		double r = 1.0;
		while (p) {
			if (p & 1) r = r * base;
			base = base * base;
			p >>= 1; // 减一
		}
		return exponent < 0 ? 1 / r : r;
	}
};


/**
 * 1.全面考察指数的正负、底数是否为零等情况。
 * 2.写出指数的二进制表达，例如13表达为二进制1101。
 * 3.举例:10^1101 = 10^0001*10^0100*10^1000。
 * 4.通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。
 */
class Solution2 {
public:
	double Power(double base, int n) {
		double res = 1, curr = base;
		int exponent;
		if (n > 0) {
			exponent = n;
		}
		else if (n < 0) {
			if (base == 0)
				cout << "分母不能为0" << endl;
			exponent = -n;
		}
		else {// n==0
			return 1;// 0的0次方
		}
		while (exponent != 0) {
			if ((exponent & 1) == 1)
				res *= curr;
			curr *= curr;// 翻倍
			exponent >>= 1;// 右移一位
		}
		return n >= 0 ? res : (1 / res);
	}
};
void main() {
	Solution S;
	Solution2 S2; 
	double base = 5;
	int exponent = 3;
	int res = S.Power(base, exponent);
	int res2 = S2.Power(base, exponent);
	cout << res << endl;
	cout << res2 << endl;
}