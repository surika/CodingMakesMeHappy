/*
�������Ը���д���Ƿ���ȷ�Ĳ���ר�ó���
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
//�ж�map������һ��key
	//1.map::find�����ص����� 
	if(m.find('b')==m.end())cout<<"yes\n";
	else cout<<"no\n";
	//2.map::count�����س��ִ��� 
	if(m.count('b')==0)cout<<"yes\n";
	else cout<<"no\n";
}
