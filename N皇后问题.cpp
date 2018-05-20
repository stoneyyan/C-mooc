//用递归替代多重循环
/*
输入一个正整数n,程序输出N皇后问题的全部摆法
输出结果里的每一行都代表一种摆法，行里的第i个数字如果是n，则代表第i行的皇后应该放在第n列
样例输入：
4
样例输出：
2 4 1 3
3 1 4 2 
*/ 
#include <iostream>
#include <cmath>
using namespace std;
int N;//有N行N列 
int queenPos[100];
void NQueen(int k);
int main(){
	cin >> N;
	NQueen(0);
	return 0;

}
void NQueen(int k){//在0~k-1行皇后已经摆好的情况下 
	int i;
	if(k==N){//N个皇后都已经摆好了，输出皇后的位置 
		for(i=0;i<N;i++)
			cout << queenPos[i] +1 << " " ;//queenPos[i] 表示列号 
		cout <<endl;
		return; 
		
	}
		for(i=0;i<N;i++){//第k行一共有N个位置 
			int j;
			for(j=0;j<k;j++){//和已经摆好的k个皇后的位置比较，看是否冲突 
				if(queenPos[j]==i || abs(queenPos[j]-i)==abs(k-j)){//abs(queenPos[j]-i)==abs(k-j)看斜边是否在一条直线 
					break;//有一个冲突就退出 
				}
			}
				if(j==k){//j如果等于k,说明没有break 
					queenPos[k]=i;//将第k个皇后摆在位置i 
					NQueen(k+1);
				}
			
		}
	}
