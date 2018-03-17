/*
问题描述
　　小明和小芳出去乡村玩，小明负责开车，小芳来导航。
　　小芳将可能的道路分为大道和小道。大道比较好走，每走1公里小明会增加1的疲劳度。小道不好走，如果连续走小道，小明的疲劳值会快速增加，连续走s公里小明会增加s2的疲劳度。
　　例如：有5个路口，1号路口到2号路口为小道，2号路口到3号路口为小道，3号路口到4号路口为大道，4号路口到5号路口为小道，相邻路口之间的距离都是2公里。如果小明从1号路口到5号路口，则总疲劳值为(2+2)2+2+22=16+2+4=22。
　　现在小芳拿到了地图，请帮助她规划一个开车的路线，使得按这个路线开车小明的疲劳度最小。
输入格式
　　输入的第一行包含两个整数n, m，分别表示路口的数量和道路的数量。路口由1至n编号，小明需要开车从1号路口到n号路口。
　　接下来m行描述道路，每行包含四个整数t, a, b, c，表示一条类型为t，连接a与b两个路口，长度为c公里的双向道路。其中t为0表示大道，t为1表示小道。保证1号路口和n号路口是连通的。
输出格式
　　输出一个整数，表示最优路线下小明的疲劳度。
样例输入
6 7
1 1 2 3
1 2 3 2
0 1 3 30
0 3 4 20
0 4 5 30
1 3 5 6
1 5 6 1
样例输出
76
样例说明
　　从1走小道到2，再走小道到3，疲劳度为52=25；然后从3走大道经过4到达5，疲劳度为20+30=50；最后从5走小道到6，疲劳度为1。总共为76。
数据规模和约定
　　对于30%的评测用例，1 ≤ n ≤ 8，1 ≤ m ≤ 10；
　　对于另外20%的评测用例，不存在小道；
　　对于另外20%的评测用例，所有的小道不相交；
　　对于所有评测用例，1 ≤ n ≤ 500，1 ≤ m ≤ 105，1 ≤ a, b ≤ n，t是0或1，c ≤ 105。保证答案不超过106。
*/ 

#include<bits/stdc++.h>//万能头文件 
using namespace std;
const int MAXN=505;
const int INF=0x3f3f3f3f;
struct edge{
	long long from,to,type,len;
	edge(){
	}
	edge(long long f,long long t,long long ty,long long l){
		from=f;to=t;type=ty;len=l;
	}
};
vector<edge> vec[MAXN];
bool vis[MAXN]={false};
long long n,m=0;
long long d[MAXN];
long long len=0,result=0;
long long dt[MAXN];
void dij(int s){
	fill(d,d+n+1,INF);
	fill(dt,dt+n+1,0);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,ty=-1;long long c=INF;
		for(int j=1;j<=n;j++){
			//cout<<j<<endl;
			if(!vis[j] && d[j]<c ){
				u=j;
				c=d[j];
				//ty=dt[j];
			}
		}
		if(u==-1){
			return;
		}
		vis[u]=true;
		result=c;
		//cout<<"u="<<u<<" result="<<result<<endl;
		for(int j=0;j<vec[u].size();j++){
			long long v=vec[u][j].to;
			if(vis[v])continue;
			if(vec[u][j].type==0){//大路 
				if(d[v]>d[u]+vec[u][j].len){
					d[v]=d[u]+vec[u][j].len;
					dt[v]=0;
				//cout<<" v="<<v<<" dv="<<d[v]<<endl;
				}
			}else{//小路 
				long long tmp;
				if(dt[u]==0){
					tmp = vec[u][j].len * vec[u][j].len;
                    if(d[v] > d[u] + tmp){
                        d[v] = d[u] + tmp;
                        dt[v] = vec[u][j].len;
                    }
				}else{
					tmp = (dt[u] + vec[u][j].len) * (dt[u] + vec[u][j].len);
                    tmp -= dt[u] * dt[u];
                    if(d[v] > d[u] + tmp){
                        d[v] = d[u] + tmp;
                        dt[v] = dt[u] + vec[u][j].len;
                    }
				}
				long long nlen=dt[u]+vec[u][j].len;
				if(d[v]>d[u]-dt[u]*dt[u]+nlen*nlen){
					d[v]=d[u]-dt[u]*dt[u]+nlen*nlen;
					//cout<<" v="<<v<<" len="<<len<<" nlen="<<nlen<<" dv="<<d[v]<<endl;
					dt[v]=nlen;
				}
			}
		}
	}
	
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		long long f,t,ty;long long l;
		cin>>ty>>f>>t>>l;
		vec[f].push_back(edge(f,t,ty,l));
		vec[t].push_back(edge(t,f,ty,l));
	}
	dij(1);
	cout<<d[n];
	return 0;
}
