// leetcode插入排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public: 
	void insertSort(vector<int>& arr) {
		if (arr.size() == 0) {
			return;
		}
		for (int i = 1; i < arr.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	vector<int> generateRandomArr(int maxsize, int minsize, int length) {
		vector<int> arr(length);
		for (int i = 0; i < length; i++) {
			arr[i] = rand() % (maxsize - minsize) + minsize + 1;
		}
		return arr;
	}
};

void main() {
	Solution S; 
	vector<int> arr = S.generateRandomArr(100, 1, 20); 
	for (auto s : arr) {
		cout << s; 
		cout << " "; 
	}
	cout << endl; 
	S.insertSort(arr); 
	for (auto s : arr) {
		cout << s;
		cout << " ";
	}
}