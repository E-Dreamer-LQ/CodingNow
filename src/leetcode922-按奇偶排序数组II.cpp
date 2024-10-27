// leetcode922-按奇偶排序数组II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		// 奇，偶指针
		int even = 0, odd = 1;
		while (even <= A.size() && odd <= A.size()) { 
			if (A[even] % 2 == 0) {    // 这里也可以使用while 循环
				even += 2;
			}else if (A[odd] % 2 == 1) {
				odd += 2;
			}
			else {
				A[even] ^= A[odd];
				A[odd] ^= A[even];
				A[even] ^= A[odd];
				even += 2;
				odd += 2;
			}
		}
		return A;
	}
};