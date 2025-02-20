﻿// leetcode421-数组中两个数的最大异或值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include <iostream>
#include <vector>
#include <set>
using namespace std; 


// 方法一： 利用异或运算的性质、假设修正
class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		// 先确定高位，再确定低位（有点贪心算法的意思），才能保证这道题的最大性质
		// 一位接着一位去确定这个数位的大小
		// 利用性质： a ^ b = c ，则 a ^ c = b，且 b ^ c = a
		int res = 0;
		int mask = 0;
		for (int i = 31; i >= 0; i++) {
			// 注意点1：注意保留前缀的方法，mask 是这样得来的
			// 用异或也是可以的 mask = mask ^ (1 << i);
			mask = mask | (1 << i);
			set<int> hashset;
			for (auto num : nums) {
				// 注意点2：这里使用 & ，保留前缀的意思（从高位到低位）
				hashset.insert(num & mask);
			}
			int temp = res | (1 << i);
			// 这里先假定第 n 位为 1 ，前 n-1 位 res 为之前迭代求得
			for (auto it = hashset.begin(); it != hashset.end(); it++) {
				if (hashset.find(*it ^ temp) != hashset.end()) {
					res = temp;
					break;
				}
			}
		}
		return res;


	}
};


/* java 代码
import java.util.HashSet;
import java.util.Set;

public class Solution {

	// 先确定高位，再确定低位（有点贪心算法的意思），才能保证这道题的最大性质
	// 一位接着一位去确定这个数位的大小
	// 利用性质： a ^ b = c ，则 a ^ c = b，且 b ^ c = a

	public int findMaximumXOR(int[] nums) {
		int res = 0;
		int mask = 0;
		for (int i = 31; i >= 0; i--) {
			// 注意点1：注意保留前缀的方法，mask 是这样得来的
			// 用异或也是可以的 mask = mask ^ (1 << i);
			mask = mask | (1 << i);

			// System.out.println(Integer.toBinaryString(mask));
			Set<Integer> set = new HashSet<>();
			for (int num : nums) {
				// 注意点2：这里使用 & ，保留前缀的意思（从高位到低位）
				set.add(num & mask);
			}

			// 这里先假定第 n 位为 1 ，前 n-1 位 res 为之前迭代求得
			int temp = res | (1 << i);
			for (Integer prefix : set) {
				if (set.contains(prefix ^ temp)) {
					res = temp;
					break;
				}
			}
		}
		return res;
	}
}

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/solution/li-yong-yi-huo-yun-suan-de-xing-zhi-tan-xin-suan-f/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/