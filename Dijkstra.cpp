/*
����еڶ���ߣ���һ����Ǿ��룩e.g.��Ȩ֮����С����Ȩ֮����󣬶������·��,etc.
1.����һ����������������ı�Ȩ/��Ȩ/���·������
2.�޸��Ż�d[v]�Ĳ��� 
*/ 

#include<bits/stdc++.h>//����ͷ�ļ� 
using namespace std;
const int MAXV=1000;
const int INF=0x3fffffff;
//�ڽӾ��� 
int n,G[MAXV][MAXV];
//---------- �ڽӱ� begin ---------- 
struct Node{
	int v,dis;//���㣬��Ȩ 
};
vector<Node> Adj[MAXV];
//---------- �ڽӱ� end ---------- 
int d[MAXV];
bool vis[MAXV]={false};
int pre[MAXV];//******���Ҫ��¼�߹���·������Ҫ������ 


void Dijkstra(int s){//sΪ��� 
	fill(d,d+MAXV,INF); 
	for(int i=0;i<n;i++)pre[i]=i;//******��¼·������ 
	d[s]=0;
	for(int i=0;i<n;i++){//ÿ��ѡһ�������û�мӽ�ȥ�ģ���ôn����n��֮��һ������ȫ���ӽ�ȥ 
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		
		//�ڽӾ����д�� 
		for(int v=0;v<n;v++){
			//�������d[u]һ���ȷ������d[u]С�����µ�du�����du�ټ�һ������һ����ԭ��������ֻ�����Ż�δ���ʹ��� 
			if(vis[v]==false && G[u][v]!=INF && d[u]+G[u][v]<d[v]){//�ڽӾ�����Ҫ�ж��������Ƿ������������еڶ������� 
				d[v]=d[u]+G[u][v];
				pre[v]=u;//******��¼·������ 
				//����еڶ��߶��޸����� e.g.
			}
		}
		//�ڽӱ�
		for(int j=0;j<Adj[u].size();j++){
			int v=Adj[u][j].v;
			if(vis[v]==false && d[u]+Adj[u][j].dis<d[v]){//�ڽӱ���һ������ 
				d[v]=d[u]+Adj[u][j].dis;
				
			}
		} 
	}
}
//******�����¼��·�����õݹ鲻��Ѱ��ǰ����ֱ���ݹ����ʼ��� 
void DFS(int s,int v){
	//�ݹ�߽� 
	if(v==s){
		printf("%d\n",s);
		return;
	}
	
	DFS(s,pre[v]);
	printf("%d\n",v);
} 
//!!!�����еڶ�Ȩʱ��д�����ԵϽ�˹������ע�Ϳ��ϱߵķ��� 
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
		
		//�ڽӾ����д�� 
		for(int v=0;v<n;v++){
			if(vis[v]==false && G[u][v]!=INF){//�Ķ��ٲ�һ��Ҫ��һȨ��С
				if(d[u]+G[u][v]<d[v])//�����һȨ��С  
				{
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cost[u][v];
					num[v]=num[u];//ͳ�����·������Ŀ 
				}else if(d[u+G[u][v]==d[v]&&c[u]+cost[u][v]<c[v]]){//�����һȨ����ҵڶ�Ȩ��С 
					c[v]=c[u]+cost[u][v];
					num[v]+=num[u];//��������ô�����µ����·�� 
				}
			
				
			}
		}
		//�ڽӱ�
		for(int j=0;j<Adj[u].size();j++){
			int v=Adj[u][j].v;
			if(vis[v]==false && d[u]+Adj[u][j].dis<d[v]){//�ڽӱ���һ������ 
				d[v]=d[u]+Adj[u][j].dis;
				
			}
		} 
	}
}

int main(){
	
	return 0;
}
