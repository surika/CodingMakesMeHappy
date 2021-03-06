/*
问题描述
　　雷雷承包了很多片麦田，为了灌溉这些麦田，雷雷在第一个麦田挖了一口很深的水井，所有的麦田都从这口井来引水灌溉。
　　为了灌溉，雷雷需要建立一些水渠，以连接水井和麦田，雷雷也可以利用部分麦田作为“中转站”，利用水渠连接不同的麦田，这样只要一片麦田能被灌溉，则与其连接的麦田也能被灌溉。
　　现在雷雷知道哪些麦田之间可以建设水渠和建设每个水渠所需要的费用（注意不是所有麦田之间都可以建立水渠）。请问灌溉所有麦田最少需要多少费用来修建水渠。
输入格式
　　输入的第一行包含两个正整数n, m，分别表示麦田的片数和雷雷可以建立的水渠的数量。麦田使用1, 2, 3, ……依次标号。
　　接下来m行，每行包含三个整数ai, bi, ci，表示第ai片麦田与第bi片麦田之间可以建立一条水渠，所需要的费用为ci。
输出格式
　　输出一行，包含一个整数，表示灌溉所有麦田所需要的最小费用。
样例输入
4 4
1 2 1
2 3 4
2 4 2
3 4 3
样例输出
6
样例说明
　　建立以下三条水渠：麦田1与麦田2、麦田2与麦田4、麦田4与麦田3。
评测用例规模与约定
　　前20%的评测用例满足：n≤5。
　　前40%的评测用例满足：n≤20。
　　前60%的评测用例满足：n≤100。
　　所有评测用例都满足：1≤n≤1000，1≤m≤100,000，1≤ci≤10,000。
*/ 


#include<bits/stdc++.h>//万能头文件 
using namespace std;
const int MAXN=1005;

struct edge{
	int from,to,cost;
	edge(){}
	edge(int f,int t,int c){
		from=f;to=t;cost=c;
	}
};
int father[MAXN];
int result;
bool vis[MAXN]={false};
vector<edge> vec;
bool cmp(edge a,edge b){
	return a.cost<b.cost;
}
int find(int x){
	int a=x;
	while(x!=father[x])x=father[x];
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	} 
	return x;
}
void Union(int a,int b){
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb)father[fa]=fb;
}
int main(){
	result=0;
	int n,m,total=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=0;i<m;i++){
		int s,e,c;
		cin>>s>>e>>c;
		vec.push_back(edge(s,e,c));
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<vec.size();i++){
		int a=vec[i].from;
		int b=vec[i].to;
		if(find(a)!=find(b)){
			Union(a,b);
			result+=vec[i].cost;
		}
	}
	cout<<result;
	
	return 0;
}
