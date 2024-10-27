// leetcode496-下一个更大元素 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size()-1;
		vector<int> res;
		unordered_map <int, int> hash;
		for (int i = 0; i < nums2.size(); i++) {
			hash.insert(make_pair(nums2[i],i));
		}
		for (auto num : nums1) {
			int pos_in_nums2 = hash.find(num)->second;
			cout << "pos_in_nums2:";
			cout << pos_in_nums2 << endl;
			while (pos_in_nums2 < nums2.size()) {
				if (nums2[pos_in_nums2] > num) {
					res.push_back(nums2[pos_in_nums2]);
					break;
				}
				pos_in_nums2++;
				if (pos_in_nums2 == nums2.size())
				{
					res.push_back(-1);
				}
			}
		}
		return res;
	}
};

void main() {
	Solution S;
	vector<int> nums1{4,1,2};
	vector<int> nums2{1,3,4,2};
	vector<int> res = S.nextGreaterElement(nums1, nums2);
	for (auto num : res) {
		cout << num << endl; 
	}
}