// leetcode-寻找两个有序数组的中位数（log(m+n)).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
	 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		int left = (n + m + 1) / 2;
		int right = (n + m + 2) / 2;
		//将偶数和奇数的情况合并，如果是奇数，会求两次同样的 k 。
		return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
	}

private:
	int getKth(vector<int> & nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
		int len1 = end1 - start1 + 1;
		int len2 = end2 - start2 + 1;
		//让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1 
		if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
		if (len1 == 0) return nums2[start2 + k - 1];

		if (k == 1) return min(nums1[start1], nums2[start2]);

		int i = start1 + min(len1, k / 2) - 1; // 防止数组长度小于 k / 2
		int j = start2 + min(len2, k / 2) - 1;

		if (nums1[i] > nums2[j]) {
			return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
		}
		else {
			return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
		}
	}
 };



// 来自大神答案：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/

#include <stdio.h>
#include <vector>
using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)  //保证数组1一定最短
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n+1长度,hi 是下标
		//加了虚拟数之后的两个数组m'、n'合并之后的数组总长度为2*(m+n) + 2

		while (lo <= hi)   //二分
		{
			c1 = (lo + hi) / 2;  //c1是二分的结果
			c2 = m + n - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
	}
};


int main(int argc, char* argv[])
{
	vector<int> nums1 = { 2,3, 5 };
	vector<int> nums2 = { 1,4,7, 9 };

	Solution solution;
	double ret = solution.findMedianSortedArrays(nums1, nums2);
	return 0;
}


