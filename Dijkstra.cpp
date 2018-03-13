#include<bits/stdc++.h>//万能头文件 
using namespace std;
const int MAXV=1000;
const INF=0x3f3f3f3f;

int n,G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV]={false};

//邻接矩阵版 
void Dijkstra(int s){
	fill(d,d+MAXV,INF); 
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
		for(int v=0;v<n;v++){
			if(vis[v]==false && G[u][v]!=INF && d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];
			}
		}
	}
}
int main(){
	
	return 0;
}
