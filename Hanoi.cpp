#include <iostream> 
using namespace std;
void Hanoi(int n,char A,char B,char C){
//将A上的n个盘子，以B为中转，移动到C 
	if(n==1){//只需移动一个盘子时，直接将盘子从A移动到C 
		cout << A << "->" << C << endl;
		return;//递归终止 
	}
	Hanoi(n-1,A,C,B);//先将n-1个盘子从A移动到B 
	cout << A << "->" << C << endl;//再将一个盘子从A移动到C
	Hanoi(n-1,B,A,C);//最后将n-1个盘子从B移动到C 
	return;
}
int main()
{
	int n;
	cin >> n;//盘子的数目 
	Hanoi(n,'A','B','C') ;
	return 0;
} 
