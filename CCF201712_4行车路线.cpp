/*
样例输入
3 201711170032 201711222352
0 7 * * 1,3-5 get_up
30 23 * * Sat,Sun go_to_bed
15 12,18 * * * have_dinner
样例输出
201711170700 get_up
201711171215 have_dinner
201711171815 have_dinner
201711181215 have_dinner
201711181815 have_dinner
201711182330 go_to_bed
201711191215 have_dinner
201711191815 have_dinner
201711192330 go_to_bed
201711200700 get_up
201711201215 have_dinner
201711201815 have_dinner
201711211215 have_dinner
201711211815 have_dinner
201711220700 get_up
201711221215 have_dinner
201711221815 have_dinner

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
