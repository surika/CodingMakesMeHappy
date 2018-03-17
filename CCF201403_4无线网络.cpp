/*
��������
����Ŀǰ��һ���ܴ��ƽ�淿������ n ������·����,ÿ������·�������̶���ĳ�����ϡ��κ���������·����ֻҪ���벻���� r ���ܻ��ཨ���������ӡ�
������������,���� m �����԰ڷ�����·������λ�á����������Щλ����ѡ������ k �������µ�·������
�������Ŀ����ʹ�õ� 1 ��·�����͵� 2 ��·����֮����������Ӿ��������ٵ���ת·���������������ŷ�������ת·���������ٸ����Ƕ���?
�����ʽ
������һ�а����ĸ������� n,m,k,r��(2 �� n �� 100,1 �� k �� m �� 100, 1 �� r �� 108)��
���������� n ��,ÿ�а����������� xi �� yi,��ʾһ���Ѿ����úõ����� ·������ (xi, yi) �㴦���������ݱ�֤�� 1 �͵� 2 ��·�����ڽ����� n ��·������������Ѿ����Ի�������(����һϵ�е���ת·����)��
���������� m ��,ÿ�а����������� xi �� yi,��ʾ (xi, yi) �㴦�������� һ��·������
�������������е�����ľ���ֵ������ 108,��֤�����е����������ͬ��
�����ʽ
�������ֻ��һ����,����ָ����λ�������� k ��·������,�ӵ� 1 ��· �������� 2 ��·�������پ�������ת·�����ĸ�����
��������
5 3 1 3
0 0
5 5
0 3
0 5
3 5
3 3
4 4
3 0
�������
2
*/ 


#include<bits/stdc++.h>//����ͷ�ļ� 
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
