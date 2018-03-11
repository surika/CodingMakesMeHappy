/*
用来测试各种写法是否正确的测试专用程序
Practise makes perfect. 
*/ 
#include<iostream>
#include<string>
#include<map>
using namespace std;


int main(){
	map<char,string> m;
	m['a']="1";
	if(m.find('b')==m.end())cout<<"yes\n";
	else cout<<"no\n";
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
