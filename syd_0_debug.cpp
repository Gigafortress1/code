#include<iostream>              //n<=20
using namespace std;
//定义一个数组，用来存储子集价值
int Subset(int* array,int* b, int m, int n,bool* list, int& value)//n代表元素个数	//用引用将value的值传入函数
																				  //引用可以理解为直接对这个变量进行操作，只需要在函数的参数列表里写&即可
{
	int j = 0, sum = 0;
	if (m >= 0 && m < n)//m相当于一个标签
	{//将布尔型数组list中元素值初始化为0,1，此时0,1机会均等
		list[m] = 1;
		Subset(array,b, m + 1, n,list,value);
		list[m] = 0;
		Subset(array,b, m + 1, n,list,value);
	}
	if (m == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (list[i])//当list[i]=1时
			{
				b[j] = array[i];//将值存到数组b中
				j++;
			}
		}
		for (int k = 0; k < j; k++)
			sum += b[k] * (k + 1); //子集价值
		value ^= sum; //求异或和
	}
	return value;
}
int main()
{
	
	bool list[20];
	int b[100];
	int n;
	int a[20];
	int res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << Subset(a,b, 0, n,list,res) << endl;
	return 0;
}