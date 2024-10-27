#include<iostream>
using namespace std;

void main(){
	vector<int> nums{1,2,3,45,5};
	int n = nums.size();
	int N = 2*n-1;
	vector<int> res;
	for (int i = N; i>=0; i--){
		res[i%N] = nums[i%n];
	}
	for (int i=0;i < res.size();i++){
		cout << res[i] << endl; 
	}
}