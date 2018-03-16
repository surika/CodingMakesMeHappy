/*
问题描述
　　某国有n个城市，为了使得城市间的交通更便利，该国国王打算在城市之间修一些高速公路，由于经费限制，国王打算第一阶段先在部分城市之间修一些单向的高速公路。
　　现在，大臣们帮国王拟了一个修高速公路的计划。看了计划后，国王发现，有些城市之间可以通过高速公路直接（不经过其他城市）或间接（经过一个或多个其他城市）到达，而有的却不能。如果城市A可以通过高速公路到达城市B，而且城市B也可以通过高速公路到达城市A，则这两个城市被称为便利城市对。
　　国王想知道，在大臣们给他的计划中，有多少个便利城市对。
输入格式
　　输入的第一行包含两个整数n, m，分别表示城市和单向高速公路的数量。
　　接下来m行，每行两个整数a, b，表示城市a有一条单向的高速公路连向城市b。
输出格式
　　输出一行，包含一个整数，表示便利城市对的数量。
样例输入
5 5
1 2
2 3
3 4
4 2
3 5
样例输出
3
样例说明

　　城市间的连接如图所示。有3个便利城市对，它们分别是(2, 3), (2, 4), (3, 4)，请注意(2, 3)和(3, 2)看成同一个便利城市对。
评测用例规模与约定
　　前30%的评测用例满足1 ≤ n ≤ 100, 1 ≤ m ≤ 1000；
　　前60%的评测用例满足1 ≤ n ≤ 1000, 1 ≤ m ≤ 10000；
　　所有评测用例满足1 ≤ n ≤ 10000, 1 ≤ m ≤ 100000。
*/ 


#include<bits/stdc++.h>//万能头文件 
using namespace std;
const int MAXN=10010;
vector<int> vec[MAXN];
int dfn[MAXN];
int low[MAXN];
bool instack[MAXN]={false};
bool vis[MAXN]={false};
int cnt=1;
stack<int> s;
int result;
void tarjin(int u){
	vis[u]=true;
	dfn[u]=low[u]=cnt++;
	s.push(u);
	instack[u]=true;
	for(int j=0;j<vec[u].size();j++){
		int v=vec[u][j];
		if(!vis[v]){
			tarjin(v);
			low[u]=min(low[u],low[v]);//递归的步骤之后就是退栈之后的操作 
		}else if(instack[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	
	int m;
	int num=0;
	
	if(dfn[u]==low[u]){
		do{
			m=s.top();
			instack[m]=false;
			s.pop();
			num++;
		}while(m!=u);
		if(num>1)
			result+=num*(num-1)/2;
	}
}	
	
int main(){
	result=0;
	fill(dfn,dfn+MAXN,0);
	fill(low,low+MAXN,0);
	int n,m,total=0;
	cin>>n>>m;
	//fill(isconnect,(n+1)*(n+1),0);
	for(int i=0;i<m;i++){
		int s,e;
		cin>>s>>e;
		vec[s].push_back(e);
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i]){
			tarjin(i);
		}
	} 
	cout<<result;
	return 0;
}
