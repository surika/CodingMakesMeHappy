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

typedef long long ll
#include<bits/stdc++.h>//万能头文件 
using namespace std;
map<string,int> month,week;
struct time{
	int year;
	int mon;
	int day;
	int hour;
	int minute;
}; 
time ll2time(ll a){
	time t;
	t.minute=a%100;a/=100;
	t.hour=a%100;a/=100;
	t.day=a%100;a/=100;
	t.mon=a%100;a/=100;
	t.year=a;
	return t;
}
int getInt(string str){
	int i=atoi(str.c_str());
	return i;
}
string getString(int i){
	string str=new string(itoa(i));
	return str;
}
vector<string> dou(string str){
	vector<string> v;
	int a=str.find(",");
	while(a!=string::npos){
		int i=str.find(',');
		string s=str.substr(0,i);
		str=str.substr(i+1);
		v.push_back(s);
		a=str.find(",");
	}
	v.push_back(str);
	return v;
}
vector<int> heng(vector<string> v){
	vector<int>vec;
	for(vector<string>::iterator it=v.begin();it!=v.end();it++){
		string str=*it;
		int i=str.find("-");
		if(i==string::npos){
			vec.push_back(getInt(str));
			continue;
		}else{
			string s=str.substr(0,i);
			str=str.substr(i+1);
			int a=getInt(s);
			int b=getInt(str);
			for(int j=a;j<=b;j++){
				vec.push_back(j);
			}
		}
	}	
	return vec;
}
vector<int> hengM(vector<string> v){
	vector<int>vec;
	for(vector<string>::iterator it=v.begin();it!=v.end();it++){
		string str=*it;
		int i=str.find("-");
		if(i==string::npos){
			vec.push_back(month[str]);
			continue;
		}else{
			string s=str.substr(0,i);
			str=str.substr(i+1);
			int a=month[s];
			int b=month[str];
			for(int j=a;j<=b;j++){
				vec.push_back(j);
			}
		}
	}	
	return vec;
}
vector<int> hengW(vector<string> v){
	vector<int>vec;
	for(vector<string>::iterator it=v.begin();it!=v.end();it++){
		string str=*it;
		int i=str.find("-");
		if(i==string::npos){
			vec.push_back(week[str]);
			continue;
		}else{
			string s=str.substr(0,i);
			str=str.substr(i+1);
			int a=week[s];
			int b=week[str];
			for(int j=a;j<=b;j++){
				vec.push_back(j);
			}
		}
	}	
	return vec;
}
int main(){
	month["Jan"]=1;month["Feb"]=2;month["Mar"]=3;month["Apr"]=4;month["May"]=5;month["Jun"]=6;
	month["Jul"]=7;month["Aug"]=8;month["Sep"]=9;month["Oct"]=10;month["Nov"]=11;month["Dec"]=12;
	month["1"]=1;month["2"]=2;month["3"]=3;month["4"]=4;month["5"]=5;month["6"]=6;
	month["7"]=7;month["8"]=8;month["9"]=9;month["10"]=10;month["11"]=11;month["12"]=12;
	week["Mon"]=1;week["Tue"]=2;week["Wed"]=3;week["Thu"]=4;week["Fri"]=5;week["Sat"]=6;week["Sun"]=0;
	week["1"]=1;week["2"]=2;week["3"]=3;week["4"]=4;week["5"]=5;week["6"]=6;week["7"]=0;
	int n;
	ll s,t;
	scanf("%d%lld%lld",&n,&s,&t);
	time early,late;
	early=ll2time(s);
	late=ll2time(t);
	for(int i=0;i<n;i++){
		string mi,h,d,m,w,command;
		cin>>mi>>h>>d>>m>>w>>command;
		
		vector<int> minute_v;
		if(mi=="*"){
			for(int i=0;i<60;i++){
				minute_v.push_back(i);
			}
		}else{
			minute_v=heng(dou(mi));
		}
		
		vector<int> hour_v;
		if(h=="*"){
			for(int i=0;i<24;i++){
				hour_v.push_back(i);
			}
		}else{
			hour_v=heng(dou(h));
		}
		
		vector<int> day_v;
		if(d=="*"){
			for(int i=1;i<=31;i++){
				day_v.push_back(i);
			}
		}else{
			day_v=heng(dou(mi));
		}
		
		vector<int> month_v;
		if(m=="*"){
			for(int i=1;i<=12;i++){
				month_v.push_back(i);
			}
		}else{
			month_v=hengM(dou(mi));
		}
		
		vector<int> week_v;
		if(w=="*"){
			for(int i=0;i<7;i++){
				week_v.push_back(i);
			}
		}else{
			week_v=hengW(dou(mi));
		}
	}
	return 0;
}
