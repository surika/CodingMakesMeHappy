/*
��������
�������׳а��˺ܶ�Ƭ���Ϊ�˹����Щ��������ڵ�һ����������һ�ں����ˮ�������е����ﶼ����ھ�����ˮ��ȡ�
����Ϊ�˹�ȣ�������Ҫ����һЩˮ����������ˮ�����������Ҳ�������ò���������Ϊ����תվ��������ˮ�����Ӳ�ͬ���������ֻҪһƬ�����ܱ���ȣ����������ӵ�����Ҳ�ܱ���ȡ�
������������֪����Щ����֮����Խ���ˮ���ͽ���ÿ��ˮ������Ҫ�ķ��ã�ע�ⲻ����������֮�䶼���Խ���ˮ���������ʹ����������������Ҫ���ٷ������޽�ˮ����
�����ʽ
��������ĵ�һ�а�������������n, m���ֱ��ʾ�����Ƭ�������׿��Խ�����ˮ��������������ʹ��1, 2, 3, �������α�š�
����������m�У�ÿ�а�����������ai, bi, ci����ʾ��aiƬ�������biƬ����֮����Խ���һ��ˮ��������Ҫ�ķ���Ϊci��
�����ʽ
�������һ�У�����һ����������ʾ���������������Ҫ����С���á�
��������
4 4
1 2 1
2 3 4
2 4 2
3 4 3
�������
6
����˵��
����������������ˮ��������1������2������2������4������4������3��
����������ģ��Լ��
����ǰ20%�������������㣺n��5��
����ǰ40%�������������㣺n��20��
����ǰ60%�������������㣺n��100��
���������������������㣺1��n��1000��1��m��100,000��1��ci��10,000��
*/ 


#include<bits/stdc++.h>//����ͷ�ļ� 
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
int temp;
bool cmp(edge a,edge b){
	return a.cost<b.cost;
}
int find(int a){
	int x=a;
	while(a!=father[a])a=father[a];
	int z=x;
	while(z!=father[z]){
		z=father[z];
		father[z]=a;
	} 
	return a;
}
void uunion(int a,int b){
	int fa=father[a];
	int fb=father[b];
	if(fa!=fb)father[b]=a;
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
			uunion(a,b);
			result+=vec[i].cost;
		}
	}
	cout<<result;
	return 0;
}
