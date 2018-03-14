/*
如果有第二标尺（第一标尺是距离）e.g.边权之和最小，点权之和最大，多条最短路径,etc.
1.增加一个数组来存放新增的边权/点权/最短路径条数
2.修改优化d[v]的步骤 
*/ 

#include<bits/stdc++.h>//万能头文件 
using namespace std;
const int MAXV=1000;
const int INF=0x3fffffff;
//邻接矩阵 
int n,G[MAXV][MAXV];
//---------- 邻接表 begin ---------- 
struct Node{
	int v,dis;//顶点，边权 
};
vector<Node> Adj[MAXV];
//---------- 邻接表 end ---------- 
int d[MAXV];
bool vis[MAXV]={false};
int pre[MAXV];//******如果要记录走过的路径则需要添加这个 


void Dijkstra(int s){//s为起点 
	fill(d,d+MAXV,INF); 
	for(int i=0;i<n;i++)pre[i]=i;//******记录路径新增 
	d[s]=0;
	for(int i=0;i<n;i++){//每次选一个最近的没有加进去的，那么n个点n次之后一定可以全都加进去 
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		
		//邻接矩阵的写法 
		for(int v=0;v<n;v++){
			//访问早的d[u]一定比访问晚的d[u]小，更新的du是晚的du再加一个数，一定比原来大，所以只可能优化未访问过的 
			if(vis[v]==false && G[u][v]!=INF && d[u]+G[u][v]<d[v]){//邻接矩阵需要判断两个点是否相连，所以有第二个条件 
				d[v]=d[u]+G[u][v];
				pre[v]=u;//******记录路径新增 
				//如果有第二尺度修改这里 e.g.
			}
		}
		//邻接表
		for(int j=0;j<Adj[u].size();j++){
			int v=Adj[u][j].v;
			if(vis[v]==false && d[u]+Adj[u][j].dis<d[v]){//邻接表中一定相连 
				d[v]=d[u]+Adj[u][j].dis;
				
			}
		} 
	}
}
//******输出记录的路径：用递归不断寻找前驱，直到递归深处开始输出 
void DFS(int s,int v){
	//递归边界 
	if(v==s){
		printf("%d\n",s);
		return;
	}
	
	DFS(s,pre[v]);
	printf("%d\n",v);
} 
//!!!这是有第二权时的写法，对迪杰斯特拉的注释看上边的方法 
void Dijkstra2(int s){
	fill(d,d+MAXV,INF); 
	for(int i=0;i<n;i++)pre[i]=i;
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		
		//邻接矩阵的写法 
		for(int v=0;v<n;v++){
			if(vis[v]==false && G[u][v]!=INF){//改动①不一定要第一权更小
				if(d[u]+G[u][v]<d[v])//如果第一权更小  
				{
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cost[u][v];
					num[v]=num[u];//统计最短路径的数目 
				}else if(d[u+G[u][v]==d[v]&&c[u]+cost[u][v]<c[v]]){//如果第一权相等且第二权更小 
					c[v]=c[u]+cost[u][v];
					num[v]+=num[u];//如果相等那么加上新的最短路径 
				}
			
				
			}
		}
		//邻接表
		for(int j=0;j<Adj[u].size();j++){
			int v=Adj[u][j].v;
			if(vis[v]==false && d[u]+Adj[u][j].dis<d[v]){//邻接表中一定相连 
				d[v]=d[u]+Adj[u][j].dis;
				
			}
		} 
	}
}

int main(){
	
	return 0;
}
