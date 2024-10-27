// 归并排序+最小和+逆序对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 归并排序+ 最小和 + 逆序对

#include <iostream>
#include<vector>
#include <cassert>
#include <time.h>
using namespace std; 

class Solution {    // 归并排序
public:
	void Merge_Sort(vector<int> nums) {
		if (nums.size() == 0) return;
		sort_process(nums, 0, nums.size() - 1);
	}
	void sort_process(vector<int> nums, int l, int r) {
		// 递归停止
		if (r == l) return;
		int mid = l + (r - l) / 2;
		sort_process(nums, mid + 1, r);
		sort_process(nums, l, mid);
		merge(nums, l, mid, r);
	}
	void merge(vector<int> arr, int l, int mid, int r) {
		vector<int> helper(r - l + 1);  // 辅助数组
		int i = 0;
		int p1 = l;
		int p2 = mid + 1;
		while (p1 < mid && p2 <= r) {
			if (arr[p1] < arr[p2]) {
				helper[i++] = arr[p1++];
			}
			else {
				helper[i++] = arr[p2++];
			}
		}
		while (p1 <= mid) {
			helper[i++] = arr[p1++];
		}
		while (p2 <= r) {
			helper[i++] = arr[p2++];
		}
		// 将辅助数组元素位置拷贝会arr
		for (int i = 0; i < helper.size(); i++) {
			arr[l + i] = helper[i];
		}
	}
	void test() {
		vector<int> nums{ 1,5,9,6,8,7,4,2,3 };
		for (auto num : nums) {
			cout << num;
			cout << " ";
		}
		vector<int> temp(nums.begin(), nums.end());
		Merge_Sort(temp);
		cout << endl;
		for (auto num : temp) {
			cout << num;
			cout << " ";
		}
	}
};



// 小和问题
class Solution2 {  
public:
	void Small_sum(vector<int> nums) {
		if (nums.size() == 0) return;
		sort_process(nums, 0, nums.size() - 1);
	}
	int  sort_process(vector<int> &nums, int l, int r) {
		// 递归停止
		if (r == l) return;
		int mid = l + (r - l) / 2;
		return sort_process(nums, mid + 1, r)+
			sort_process(nums, l, mid)+ merge(nums, l, mid, r);

	}
	int  merge(vector<int> &arr, int l, int mid, int r) {
		vector<int> helper(r - l + 1);  // 辅助数组
		int res = 0;  // 产生小和数目
		int i = 0;
		int p1 = l;
		int p2 = mid + 1;
		while (p1 < mid && p2 <= r) {
			if (arr[p1] < arr[p2]) {
				res += (r - p2 + 1) * arr[p1];
				helper[i++] = arr[p1++];
			}
			else {
				helper[i++] = arr[p2++];
			}
		}
		while (p1 <= mid) {
			helper[i++] = arr[p1++];
		}
		while (p2 <= r) {
			helper[i++] = arr[p2++];
		}
		// 将辅助数组元素位置拷贝会arr
		for (int i = 0; i < helper.size(); i++) {
			arr[l + i] = helper[i];
		}
		return res; 
	}
};

// 逆序对问题
class Solution3 {
public:
	int cnt = 0;
	int InversePairs(vector<int> data) {
		int n = data.size();
		if (n != 0)
		{
			mergesort(data, 0, n - 1);   //调用归并排序的分解函数
		}
		return cnt;
	}

	void mergesort(vector<int>& data, int start, int end)   //分解
	{
		if (start < end)
		{
			int mid = (start + end) >> 1;
			mergesort(data, start, mid);
			mergesort(data, mid + 1, end);
			merge(data, start, mid, end); //调用归并排序的合并排序函数
		}
	}

	void merge(vector<int>& data, int start, int mid, int end)
	{
		vector<int> tmp;                    //tmp临时变量用来存储当前[start,end]段排序后的结果，然后再赋值给data
		int i = start, j = mid + 1;         //采用的是引用传递，所以修改的是原数组
		while (i <= mid && j <= end)
		{
			if (data[i] > data[j])         //6789   2345   6大于2  那么cnt+=4   tmp.push_back(2)
			{  // 此时产生逆序对
				cnt = (cnt + mid - i + 1) % 1000000007;  ///对1000000007取余是为了防止整形溢出
				tmp.push_back(data[j++]);
			}
			else
				tmp.push_back(data[i++]);  //6789   10 11 12 13   6小于10  那么tmp.push_back(6)
		}								   //tmp就是存data(start,end)区间内从小到大的存储起来
		while (i <= mid) {
			tmp.push_back(data[i++]);//待合并排序的数据比如6789  2345那么这个循环执行的就是				
									//tmp.push_back(7)tmp.push_back(8)tmp.push_back(9)
		}
		while (j <= end) {
			tmp.push_back(data[j++]);
		}
		for (int i = 0; i < tmp.size(); ++i)
		{
			data[start + i] = tmp[i];
		}
	}
};








