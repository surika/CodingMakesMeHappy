/*
问题描述
　　用 ASCII 字符来画图是一件有趣的事情，并形成了一门被称为 ASCII Art 的艺术。例如，下图是用 ASCII 字符画出来的 CSPRO 字样。
　　..____.____..____..____...___..
　　./.___/.___||.._.\|.._.\./._.\.
　　|.|...\___.\|.|_).|.|_).|.|.|.|
　　|.|___.___).|..__/|.._.<|.|_|.|
　　.\____|____/|_|...|_|.\_\\___/.
　　本题要求编程实现一个用 ASCII 字符来画图的程序，支持以下两种操作：
　　? 画线：给出两个端点的坐标，画一条连接这两个端点的线段。简便起见题目保证要画的每条线段都是水平或者竖直的。水平线段用字符 - 来画，竖直线段用字符 | 来画。如果一条水平线段和一条竖直线段在某个位置相交，则相交位置用字符 + 代替。
　　? 填充：给出填充的起始位置坐标和需要填充的字符，从起始位置开始，用该字符填充相邻位置，直到遇到画布边缘或已经画好的线段。注意这里的相邻位置只需要考虑上下左右 4 个方向，如下图所示，字符 @ 只和 4 个字符 * 相邻。
　　.*.
　　*@*
　　.*.
输入格式
　　第1行有三个整数m, n和q。m和n分别表示画布的宽度和高度，以字符为单位。q表示画图操作的个数。
　　第2行至第q + 1行，每行是以下两种形式之一：
　　? 0 x1 y1 x2 y2：表示画线段的操作，(x1, y1)和(x2, y2)分别是线段的两端，满足要么x1 = x2 且y1 ≠ y2，要么 y1 = y2 且 x1 ≠ x2。
　　? 1 x y c：表示填充操作，(x, y)是起始位置，保证不会落在任何已有的线段上；c 为填充字符，是大小写字母。
　　画布的左下角是坐标为 (0, 0) 的位置，向右为x坐标增大的方向，向上为y坐标增大的方向。这q个操作按照数据给出的顺序依次执行。画布最初时所有位置都是字符 .（小数点）。
输出格式
　　输出有n行，每行m个字符，表示依次执行这q个操作后得到的画图结果。
样例输入
4 2 3
1 0 0 B
0 1 0 2 0
1 0 0 A
样例输出
AAAA
A--A
样例输入
16 13 9
0 3 1 12 1
0 12 1 12 3
0 12 3 6 3
0 6 3 6 9
0 6 9 12 9
0 12 9 12 11
0 12 11 3 11
0 3 11 3 1
1 4 2 C
样例输出
................
...+--------+...
...|CCCCCCCC|...
...|CC+-----+...
...|CC|.........
...|CC|.........
...|CC|.........
...|CC|.........
...|CC|.........
...|CC+-----+...
...|CCCCCCCC|...
...+--------+...
................
评测用例规模与约定
　　所有的评测用例满足：2 ≤ m, n ≤ 100，0 ≤ q ≤ 100，0 ≤ x < m（x表示输入数据中所有位置的x坐标），0 ≤ y < n（y表示输入数据中所有位置的y坐标）。
*/ 

#include<stdio.h>
#include<map> 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int a,b;//横着长为a,纵长为b（0<x<a,0<y<b） 
char **arr;
bool **vis;
void line(int x1,int y1,int x2,int y2){
	if(x1==x2){//横坐标相等，画竖线|
		if(y1>y2){//使y1是较小的那个 
			int temp=y2;
			y2=y1;
			y1=temp;
		}
	 	for(int i=y1;i<=y2;i++){
	 		if(arr[i][x1]=='-')
	 			arr[i][x1]='+';
	 		else
	 			arr[i][x1]='|';
		}
	}else{//纵坐标相等，画横线 
		if(x1>x2){//使x1是较小的那个 
			int temp=x2;
			x2=x1;
			x1=temp;
		}
	 	for(int i=x1;i<=x2;i++){
	 		if(arr[y1][i]=='|')
	 			arr[y1][i]='+';
	 		else
	 			arr[y1][i]='-';
		}
	}
	
}
bool limit(int x,int y){
	if(x>=a || y>=b || x<0 || y<0)return false;
	if(vis[x][y])return false;
	if(arr[x][y]=='-' ||arr[x][y]=='|'||arr[x][y]=='+')return false;
    else return true;
}

void paint(int x,int y,char c){
	if(vis[x][y])return;
	else{
		printf("%d %d %c\n",x,y,c);
		arr[x][y]=c;
		vis[x][y]=true;
	}
	if(limit(x+1,y))paint(x+1,y,c);
	if(limit(x,y+1))paint(x,y+1,c);
	if(limit(x-1,y))paint(x-1,y,c);
	if(limit(x,y-1))paint(x,y-1,c);
	
}

void dfs(int x,int y,char c){
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			vis[i][j]=false;
		}
	}
	paint(x,y,c);
}
int main(){
	int n;
	scanf("%d %d %d",&b,&a,&n);
	arr=new char*[a];
	for(int i=0;i<a;i++)
		arr[i]=new char[b];
	vis=new bool*[a];
	for(int i=0;i<a;i++)
		vis[i]=new bool[b];
		
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			arr[i][j]='.';
		}
	}
		
	int type;
	for(int i=0;i<n;i++){
		scanf("%d",&type);
		if(type==0){//画线 
			int x1,y1,x2,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			line(x1,y1,x2,y2);
		}else if(type==1){//填充 
			int x,y;
			char c;
			scanf("%d %d %c",&x,&y,&c);
			dfs(y,x,c);
		}
	}
	
	for(int i=a-1;i>=0;i--){
		for(int j=0;j<b;j++){
			printf("%c",arr[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
