/*
��������
����С����С����ȥ����棬С�����𿪳���С����������
����С�������ܵĵ�·��Ϊ�����С��������ȽϺ��ߣ�ÿ��1����С��������1��ƣ�Ͷȡ�С�������ߣ����������С����С����ƣ��ֵ��������ӣ�������s����С��������s2��ƣ�Ͷȡ�
�������磺��5��·�ڣ�1��·�ڵ�2��·��ΪС����2��·�ڵ�3��·��ΪС����3��·�ڵ�4��·��Ϊ�����4��·�ڵ�5��·��ΪС��������·��֮��ľ��붼��2������С����1��·�ڵ�5��·�ڣ�����ƣ��ֵΪ(2+2)2+2+22=16+2+4=22��
��������С���õ��˵�ͼ����������滮һ��������·�ߣ�ʹ�ð����·�߿���С����ƣ�Ͷ���С��
�����ʽ
��������ĵ�һ�а�����������n, m���ֱ��ʾ·�ڵ������͵�·��������·����1��n��ţ�С����Ҫ������1��·�ڵ�n��·�ڡ�
����������m��������·��ÿ�а����ĸ�����t, a, b, c����ʾһ������Ϊt������a��b����·�ڣ�����Ϊc�����˫���·������tΪ0��ʾ�����tΪ1��ʾС������֤1��·�ں�n��·������ͨ�ġ�
�����ʽ
�������һ����������ʾ����·����С����ƣ�Ͷȡ�
��������
6 7
1 1 2 3
1 2 3 2
0 1 3 30
0 3 4 20
0 4 5 30
1 3 5 6
1 5 6 1
�������
76
����˵��
������1��С����2������С����3��ƣ�Ͷ�Ϊ52=25��Ȼ���3�ߴ������4����5��ƣ�Ͷ�Ϊ20+30=50������5��С����6��ƣ�Ͷ�Ϊ1���ܹ�Ϊ76��
���ݹ�ģ��Լ��
��������30%������������1 �� n �� 8��1 �� m �� 10��
������������20%������������������С����
������������20%���������������е�С�����ཻ��
����������������������1 �� n �� 500��1 �� m �� 105��1 �� a, b �� n��t��0��1��c �� 105����֤�𰸲�����106��
*/ 

#include<bits/stdc++.h>//����ͷ�ļ� 
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
			if(vec[u][j].type==0){//��· 
				if(d[v]>d[u]+vec[u][j].len){
					d[v]=d[u]+vec[u][j].len;
					dt[v]=0;
				//cout<<" v="<<v<<" dv="<<d[v]<<endl;
				}
			}else{//С· 
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
