// vector的insert使用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>  
#include<iostream>  
using namespace std;

int main()
{
	vector<int> v(3);
	v[0] = 2; //v[0]是第0个元素 
	v[1] = 7;
	v[2] = 9;
	// 第一种： 固定位置插入
	v.insert(v.begin(), 8);//在最前面插入新元素。  
	v.insert(v.begin() + 2, 1);//在迭代器中第二个元素前插入新元素  
	v.insert(v.end(), 3);//在向量末尾追加新元素。  

	// 第二种： 插入多个元素
	v.insert(v.end(), 4, 1);//在尾部插入4个1


	int a[] = { 1,2,3,4 };
	v.insert(v.end(), a[1], a[3]);//在尾部插入a[1]个a[3]

	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}

//8 2 1 7 9 3 1 1 1 1 4 4
//请按任意键继续. . .