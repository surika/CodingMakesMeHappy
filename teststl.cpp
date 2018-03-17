/*
用来测试各种写法是否正确的测试专用程序
Practise makes perfect. 
*/ 
#include<bits/stdc++.h>
using namespace std;

string int2string(int n){
	stringstream ss;
	ss<<n;
	return ss.str();
}
int string2int(string str){
	stringstream ss(str);
	int temp;
	ss>>temp;
	return temp;
}
map<char,string> m;
int main(){
	
	m['a']="1";
	if(m.find('b')==m.end())cout<<"yes\n";
	else cout<<"no\n";
	
	int s;
	cin>>s;
	string t=int2string(s);
	cout<<t.find('3');
}

void map(){
//判断map中有无一个key
	//1.map::find，返回迭代器 
	if(m.find('b')==m.end())cout<<"yes\n";
	else cout<<"no\n";
	//2.map::count，返回出现次数 
	if(m.count('b')==0)cout<<"yes\n";
	else cout<<"no\n";
}
