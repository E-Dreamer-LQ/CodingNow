// 使用异或运算找到数组中出现一次的数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std; 
/*
首先：位运算中异或的性质：两个相同数字异或=0，一个数和0异或还是它本身。
当只有一个数出现一次时，我们把数组中所有的数，依次异或运算，最后剩下的就是落单的数，因为成对儿出现的都抵消了。
依照这个思路，我们来看两个数（我们假设是AB）出现一次的数组。我们首先还是先异或，剩下的数字肯定是A、B异或的结果，
这个结果的二进制中的1，表现的是A和B的不同的位。我们就取第一个1所在的位数，假设是第3位，接着把原数组分成两组，
分组标准是第3位是否为1。如此，相同的数肯定在一个组，因为相同数字所有位都相同，
而不同的数，肯定不在一组。然后把这两个组按照最开始的思路，依次异或，剩余的两个结果就是这两个只出现一次的数字。*/

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
		int length = data.size();
		if (length == 2) {
			*num1 = data[0];
			*num2 = data[1];
			return;
		}
		int bitResult = 0;
		for (int i = 0; i < length; ++i) {
			bitResult ^= data[i];    // 全体异或
		}
		int index = findFirst1(bitResult); // 找到第一个位为1的数
		for (int i = 0; i < length; ++i) {
			if (isBit1(data[i], index)) {   // 查看当前数的index位是不是1 
				*num1 ^= data[i];
			}
			else {
				*num2 ^= data[i];
			}
		}
	}
	int findFirst1(int bitResult) {
		int index = 0;    // 注意这里是第0 位开始，java是第一位
		while ((bitResult & 1) == 0 && index < 32) {   // 找到第一位1 
			bitResult >>= 1;   // 右移一位
			index++; 
		}
		return index; 
	}

	bool isBit1(int target, int index) {
		return ((target >> index) & 1) == 1;
	}
};

