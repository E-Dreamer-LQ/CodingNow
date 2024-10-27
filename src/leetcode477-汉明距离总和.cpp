// leetcode477-汉明距离总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/total-hamming-distance/


//两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量

#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i+1; j < nums.size(); j++) {
				sum += count_distance(nums[i], nums[j]);
			}
		}
		return sum;
	}
	int count_distance(int a, int b) {
		int res = 0;
		queue<int> que1;
		queue<int> que2;
		int temp = a;
		int temp2 = b;
		while (temp != 0) {
			que1.push(temp % 2);
			temp = temp >> 1;
		}
		while (temp2 != 0) {
			que2.push(temp2 % 2);
			temp2 = temp2 >> 1;
		}
		//if (que1.size() < que2.size()) {
		//	for (int i =0;i<que2.size()-que1.size();i++)
		//		que1.push(0);
		//}
		//if (que1.size() > que2.size()) {
		//	for (int i = 0; i < que1.size() - que2.size(); i++)
		//		que2.push(0);
		//}
		while(!que1.empty() && !que2.empty()) {
			if (que1.front() != que2.front()) {
				res++;
			}
			que1.pop();
			que2.pop();
		}
		return res;
	}
};


/*
使用一个cnt数组保存nums数组中某 i 位是 1 的个数，比如cnt[3]=2，表示这些数中第3位是1的有两个，那么汉明距离就是2*（n-2）,其中n-2就是零的个数。
*/

class Solution2 {
public:
	int totalHammingDistance(vector<int>& nums) {
		vector<int> cnt(32, 0);
		for (auto num : nums) {
			int i = 0;
			while (num) {
				if (num & 1) {   // 深刻体会num & 1 的妙用
					cnt[i]++;
				}
				num = num >> 1;
				i++;
			}
		}
		int res = 0;
		int n = nums.size();
		for (auto c : cnt) {
			res += c * (n - c);
		}
		return res;
	}
};


void main() {
	Solution S;
	Solution2 S2;
	vector<int> nums{ 4, 14, 2 };

	int res1 = S.totalHammingDistance(nums);
	int res2 = S2.totalHammingDistance(nums);

	cout << res1 << endl;
	cout << res2 << endl;

}


