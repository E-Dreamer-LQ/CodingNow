// leetcode476-数字的补数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//5的二进制是：0101，7的二进制是： 0111，它们的抑或为：0010，去掉前导零位即为取反。
//再来一个例子，假设a为1110 0101，b为1111 1111，a ^ b = 0001 1010是a的取反。
//也就是说二进制位数与num相同，且全为1的数tmp与num的抑或即为所求
class Solution {
public:
	int findComplement(int num) {
		int tmp = 1;
		while (tmp < num)
		{
			tmp <<= 1; // 左移动，+2 
			tmp += 1; // 加 1
		}
		return (tmp ^ num);
	}
};



// 方法二：
