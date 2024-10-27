// 数组中的逆序对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std; 


//数组中的逆序对


class Solution {
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
		vector<int> tmp;      //tmp临时变量用来存储当前[start,end]段排序后的结果，然后再赋值给data
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
		}                                   //tmp就是存data(start,end)区间内从小到大的存储起来
		while (i <= mid) {
			tmp.push_back(data[i++]);//待合并排序的数据比如6789  2345那么这个循环执行的就是//tmp.push_back(7)tmp.push_back(8)tmp.push_back(9)
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



class Solution2 {
private:
	int num = 0;
	void merge(int start, int mid, int end, vector<int>& data)
	{
		int* left_data = new int[mid - start + 1];
		int* right_data = new int[end - mid];
		int p = 0, p1 = 0, p2 = 0;
		for (int i = start; i <= mid; ++i)
			left_data[p++] = data[i];
		p = 0;
		for (int i = mid + 1; i <= end; ++i)
			right_data[p++] = data[i];
		p = start;
		while (p1 < mid - start + 1 && p2 < end - mid)
		{
			if (left_data[p1] > right_data[p2])
			{
				num += mid - start + 1 - p1;//注意一下哦
				num %= 1000000007;
				data[p++] = right_data[p2++];
			}
			else
				data[p++] = left_data[p1++];
		}
		while (p1 < mid - start + 1)
			data[p++] = left_data[p1++];
		while (p2 < end - mid)
			data[p++] = right_data[p2++];
		delete[] left_data;
		delete[] right_data;
	}
	void mergeSort(int start, int end, vector<int>& data)
	{
		if (start < end)
		{
			int mid = (start + end) / 2;
			mergeSort(start, mid, data);
			mergeSort(mid + 1, end, data);
			merge(start, mid, end, data);
		}
	}
public:
	int InversePairs(vector<int> data)
	{
		mergeSort(0, data.size() - 1, data);
		return num % 1000000007;
	}
};


void main() {
	Solution S;
	Solution2 S2;
	vector<int> data{1,2,3,4,5,6,7,0};
	int res = S.InversePairs(data);
	int res2 = S2.InversePairs(data);
	cout << res << endl;
	cout << res2 << endl; 
}