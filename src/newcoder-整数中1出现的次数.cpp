// newcoder-整数中1出现的次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res += count(i); 
		}
		return res;
	}
	int count(int n) {
		int sum = 0;
		while (n) {
			int s = n % 10;
			if (s == 1) {
				sum++;
			}
			n = n / 10;
		}
		return sum;
	}
};


void main() {
	Solution S;
	int n = 13;
	int res = S.NumberOf1Between1AndN_Solution(n);
	cout << res << endl;
}


// 来自讨论区
int NumberOf1Between1AndN_Solution(int n)
{
	int ones = 0;
	for (long long m = 1; m <= n; m *= 10) {
		int a = n / m, b = n % m;
		if (a % 10 == 0)
			ones += a / 10 * m;
		else if (a % 10 == 1)
			ones += (a / 10 * m) + (b + 1);
		else
			ones += (a / 10 + 1) * m;
	}
	return ones;
}

/*
	主要思路：设定整数点（如1、10、100等等）作为位置点i（对应n的各位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析
	根据设定的整数位置，对n进行分割，分为两部分，高位n/i，低位n%i
	当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，
	此时百位为1的次数有a/10+1=32（最高两位0~31），
	每一次都包含100个连续的点，即共有(a%10+1)*100个点的百位为1


	当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，
	则共有a%10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），
	本次只对应局部点00~56，共b+1次，所有点加起来共有（a%10*100）+(b+1)，这些点百位对应为1


	当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30）


	综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1
	之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)

*/

class Solution111 {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		long long i = 1;
		for (i = 1; i <= n; i *= 10)
		{
			//i表示当前分析的是哪一个数位
			int a = n / i, b = n % i;
			count = count + (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
		}
		return count;
	}
};