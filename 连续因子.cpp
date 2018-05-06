/*
一个正整数N的因子中可能存在若干连续的数字。例如630可以分解为3*5*6*7，其中5、6、7就是3个连续的数字。给定任一正整数N，
要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：
输入在一行中给出一个正整数N（1<N<2^31）。
输出格式：
首先在第1行输出最长连续因子的个数；然后在第2行中按“因子1*因子2*……*因子k”的格式输出最小的连续因子序列，
其中因子按递增顺序输出，1不算在内。

输入样例：
630
输出样例：
3
5*6*7
*/

/*
首先应该注意到2^31的值为2147483648，13的阶乘为6227020800，13!>2^31，也就是说最多只要12个连续的数相乘（不包括1）
就能够达到2^31，题目的要求是找出正整数N的最长连续因子，并输出最小的连续因子序列，也就是说可以在长度为2到12中找到一些
相乘的连续因子，看是否可以被N整除，如果能被整除就可以不断地更新这个序列，最终得出正确答案。
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int max = sqrt(n);//得到一个上限值sqrt(N)，从2到sqrt(N)依次作为开始值进行寻找
	for(int len=12;len>=1;len--)//注意到2^31的值为2147483648，13的阶乘为6227020800，13!>2^31，也就是说最多只要12个连续的数相乘（不包括1）就能够达到2^31，
	{
		for(int start=2;start<=max;start++)
		{
			int a=1;
			for(int i=start;i<=start+len-1;i++){
				a*=i;
			}
			if(n%a==0)
			{
		 		printf("%d\n%d", len, start);
			
			for(int i=start+1;i<=start+len-1;i++)
			{
			 printf("*%d", i);
			}
			return 0;
	}
		}			
   }
	return 0;
}
