/*
问题描述
　　目前在一个很大的平面房间里有 n 个无线路由器,每个无线路由器都固定在某个点上。任何两个无线路由器只要距离不超过 r 就能互相建立网络连接。
　　除此以外,另有 m 个可以摆放无线路由器的位置。你可以在这些位置中选择至多 k 个增设新的路由器。
　　你的目标是使得第 1 个路由器和第 2 个路由器之间的网络连接经过尽量少的中转路由器。请问在最优方案下中转路由器的最少个数是多少?
输入格式
　　第一行包含四个正整数 n,m,k,r。(2 ≤ n ≤ 100,1 ≤ k ≤ m ≤ 100, 1 ≤ r ≤ 108)。
　　接下来 n 行,每行包含两个整数 xi 和 yi,表示一个已经放置好的无线 路由器在 (xi, yi) 点处。输入数据保证第 1 和第 2 个路由器在仅有这 n 个路由器的情况下已经可以互相连接(经过一系列的中转路由器)。
　　接下来 m 行,每行包含两个整数 xi 和 yi,表示 (xi, yi) 点处可以增设 一个路由器。
　　输入中所有的坐标的绝对值不超过 108,保证输入中的坐标各不相同。
输出格式
　　输出只有一个数,即在指定的位置中增设 k 个路由器后,从第 1 个路 由器到第 2 个路由器最少经过的中转路由器的个数。
样例输入
5 3 1 3
0 0
5 5
0 3
0 5
3 5
3 3
4 4
3 0
样例输出
2
*/ 


#include<bits/stdc++.h>//万能头文件 
using namespace std;
const int MAXN=205;
struct node{
	int x,y,step=0,kc=0;
	node(){	}
	node(long long xx,long long yy){
		x=xx;y=yy;
	}
	
};
vector<node> vec;
bool vis[MAXN]={false};
int result,n,m,k;
long long r;
queue<node> q;
int bfs(int s){
	vis[s]=true;
	node start;
	start.x=vec[s].x;start.y=vec[s].y;start.step=0;
	q.push(start);
	while(!q.empty()){
		node front=q.front();
		q.pop();
		if(front.x==vec[1].x && front.y==vec[1].y){
			return front.step-1;
		}
		node v;
		for(int i=0;i<n+m;i++){
			if(!vis[i] && (vec[i].x-front.x)*(vec[i].x-front.x)+(vec[i].y-front.y)*(vec[i].y-front.y) <= r*r){
				vis[i]=true;
				v.x=vec[i].x;
				v.y=vec[i].y;
				v.step=front.step+1;
				q.push(v);
			}
		}
	}
}
int main(){
	result=0;
	cin>>n>>m>>k>>r;
	for(int i=0;i<n+m;i++){
		int x,y;
		cin>>x>>y;
		vec.push_back(node(x,y));
	}
	result=bfs(0);
	cout<<result;
	return 0;
}
