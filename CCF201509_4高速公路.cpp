/*
��������
����ĳ����n�����У�Ϊ��ʹ�ó��м�Ľ�ͨ���������ù����������ڳ���֮����һЩ���ٹ�·�����ھ������ƣ����������һ�׶����ڲ��ֳ���֮����һЩ����ĸ��ٹ�·��
�������ڣ����ǰ��������һ���޸��ٹ�·�ļƻ������˼ƻ��󣬹������֣���Щ����֮�����ͨ�����ٹ�·ֱ�ӣ��������������У����ӣ�����һ�������������У�������е�ȴ���ܡ��������A����ͨ�����ٹ�·�������B�����ҳ���BҲ����ͨ�����ٹ�·�������A�������������б���Ϊ�������жԡ�
����������֪�����ڴ��Ǹ����ļƻ��У��ж��ٸ��������жԡ�
�����ʽ
��������ĵ�һ�а�����������n, m���ֱ��ʾ���к͵�����ٹ�·��������
����������m�У�ÿ����������a, b����ʾ����a��һ������ĸ��ٹ�·�������b��
�����ʽ
�������һ�У�����һ����������ʾ�������жԵ�������
��������
5 5
1 2
2 3
3 4
4 2
3 5
�������
3
����˵��

�������м��������ͼ��ʾ����3���������жԣ����Ƿֱ���(2, 3), (2, 4), (3, 4)����ע��(2, 3)��(3, 2)����ͬһ���������жԡ�
����������ģ��Լ��
����ǰ30%��������������1 �� n �� 100, 1 �� m �� 1000��
����ǰ60%��������������1 �� n �� 1000, 1 �� m �� 10000��
��������������������1 �� n �� 10000, 1 �� m �� 100000��
*/ 


#include<bits/stdc++.h>//����ͷ�ļ� 
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
			low[u]=min(low[u],low[v]);//�ݹ�Ĳ���֮�������ջ֮��Ĳ��� 
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
