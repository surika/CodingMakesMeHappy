/*
问题描述
　　G国国王来中国参观后，被中国的高速铁路深深的震撼，决定为自己的国家也建设一个高速铁路系统。
　　建设高速铁路投入非常大，为了节约建设成本，G国国王决定不新建铁路，而是将已有的铁路改造成高速铁路。现在，请你为G国国王提供一个方案，将现有的一部分铁路改造成高速铁路，使得任何两个城市间都可以通过高速铁路到达，而且从所有城市乘坐高速铁路到首都的最短路程和原来一样长。请你告诉G国国王在这些条件下最少要改造多长的铁路。
输入格式
　　输入的第一行包含两个整数n, m，分别表示G国城市的数量和城市间铁路的数量。所有的城市由1到n编号，首都为1号。
　　接下来m行，每行三个整数a, b, c，表示城市a和城市b之间有一条长度为c的双向铁路。这条铁路不会经过a和b以外的城市。
输出格式
　　输出一行，表示在满足条件的情况下最少要改造的铁路长度。
样例输入
4 5
1 2 4
1 3 5
2 3 2
2 4 3
3 4 2
样例输出
11
评测用例规模与约定
　　对于20%的评测用例，1 ≤ n ≤ 10，1 ≤ m ≤ 50；
　　对于50%的评测用例，1 ≤ n ≤ 100，1 ≤ m ≤ 5000；
　　对于80%的评测用例，1 ≤ n ≤ 1000，1 ≤ m ≤ 50000；
　　对于100%的评测用例，1 ≤ n ≤ 10000，1 ≤ m ≤ 100000，1 ≤ a, b ≤ n，1 ≤ c ≤ 1000。输入保证每个城市都可以通过铁路达到首都。
*/ 


#include<bits/stdc++.h>//万能头文件 
using namespace std;

vector<int> v[1024];
int isconnect[1024][1024];
void dfsSolve(int u,int visit[],int cur){
	visit[u]=1;
	isconnect[u][cur]=isconnect[cur][u]=1;
	for(size_t i=0;i<v[u].size();i++)
	{
		if(visit[v[u][i]]==0)
			dfsSolve(v[u][i],visit,cur);
	}
}
int main(){
	int n,m,total=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int s,e;
		cin>>s>>e;
		v[s].push_back(e);
	}
	for(int i=1;i<=n;++i)
	{
		int visit[1024]={0};
		dfsSolve(i,visit,i);
	} 
	for(int i=1;i<=n;++i)
	{
		int j;
		for(j=1;j<=n;++j)
			if(isconnect[i][j]==0)break;
		if(j==n+1)++total;
	}
	cout<<total;
	return 0;
}
