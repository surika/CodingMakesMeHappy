/*
问题描述
　　请你写一个命令行分析程序,用以分析给定的命令行里包含哪些选项。每个命令行由若干个字符串组成,它们之间恰好由一个空格分隔。这些字符串中的第一个为该命令行工具的名字,由小写字母组成,你的程序不用对它进行处理。在工具名字之后可能会包含若干选项,然后可能会包含一 些不是选项的参数。
　　选项有两类:带参数的选项和不带参数的选项。一个合法的无参数选项的形式是一个减号后面跟单个小写字母,如"-a" 或"-b"。而带参数选项则由两个由空格分隔的字符串构成,前者的格式要求与无参数选项相同,后者则是该选项的参数,是由小写字母,数字和减号组成的非空字符串。
　　该命令行工具的作者提供给你一个格式字符串以指定他的命令行工具需要接受哪些选项。这个字符串由若干小写字母和冒号组成,其中的每个小写字母表示一个该程序接受的选项。如果该小写字母后面紧跟了一个冒号,它就表示一个带参数的选项,否则则为不带参数的选项。例如, "ab:m:" 表示该程序接受三种选项,即"-a"(不带参数),"-b"(带参数), 以及"-m"(带参数)。
　　命令行工具的作者准备了若干条命令行用以测试你的程序。对于每个命令行,你的工具应当一直向后分析。当你的工具遇到某个字符串既不是合法的选项,又不是某个合法选项的参数时,分析就停止。命令行剩余的未分析部分不构成该命令的选项,因此你的程序应当忽略它们。
输入格式
　　输入的第一行是一个格式字符串,它至少包含一个字符,且长度不超过 52。格式字符串只包含小写字母和冒号,保证每个小写字母至多出现一次,不会有两个相邻的冒号,也不会以冒号开头。
　　输入的第二行是一个正整数 N(1 ≤ N ≤ 20),表示你需要处理的命令行的个数。
　　接下来有 N 行,每行是一个待处理的命令行,它包括不超过 256 个字符。该命令行一定是若干个由单个空格分隔的字符串构成,每个字符串里只包含小写字母,数字和减号。
输出格式
　　输出有 N 行。其中第 i 行以"Case i:" 开始,然后应当有恰好一个空格,然后应当按照字母升序输出该命令行中用到的所有选项的名称,对于带参数的选项,在输出它的名称之后还要输出它的参数。如果一个选项在命令行中出现了多次,只输出一次。如果一个带参数的选项在命令行中出 现了多次,只输出最后一次出现时所带的参数。
样例输入
albw:x
4
ls -a -l -a documents -b
ls
ls -w 10 -x -w 15
ls -a -b -c -d -e -l
样例输出
Case 1: -a -l
Case 2:
Case 3: -w 15 -x
Case 4: -a -b

*/ 

//30分，不知道哪里有问题 
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<map> 
#include<string>
#include<cstring>
#include<vector>
using namespace std;
vector<string> cut(string old){
	string nnew;
	vector<string> v;
	while(old[0]==' ')old=old.substr(1);
	int a=old.find(' ');
	while(a!=string::npos){
		nnew=old.substr(0,a);
		v.push_back(nnew);
		old=old.substr(a+1);
		a=old.find(' ');
	}
	v.push_back(old);
	return v;
}
int main(){
	char c[53];
	map<char,string> m;
	scanf("%s",&c);
	for(int i=0;i<strlen(c);i++){
		if(c[i+1]==':'){//带参数的选项 
			m[c[i]]="*";//用*表示该选项需要参数 
			i++;//下一次跳过冒号 
		}else{//无参数的选项 
			m[c[i]]="";
		}
	}
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string str;
		bool f=true;//标记是否遇见非法输入 
		map<char,string> row;
		cin.get();
		getline(cin,str);
		//cout<<"***"<<str<<endl;
		vector<string> v=cut(str);
		for(vector<string>::iterator it=v.begin();it!=v.end();it++){
			if(it==v.begin())continue;//如果是命令，跳过 
			string s=*it;
			if(s.size()==2 && s[0]=='-'){//是选项
				map<char,string>::iterator iter=m.find(s[1]);
				if(iter!=m.end()){//存在该选项 
					if(iter->second!=""){//应该带参数 
						it++;
						row[s[1]]=*it;
					}else{//不带参数 
						it++;
						if((*it)[0]=='-'){//下一个是选项，不是参数，正常 
							row[s[1]]="";
						}else{
							f=false;
						}
						it--;
					}
				}else{//没有这个选项，结束这一行的处理 
					f=false;
				}
			}else{//不是选项，则可能是参数 
				f=false;
			} 
			if(!f)break;
		}
		
		//处理完毕，输出 
		cout<<"Case "<<(i+1)<<": ";
		for(map<char,string>::iterator it=row.begin();it!=row.end();it++){
			cout<<"-"<<(it->first)<<" "; 
			if(it->second!="")cout<<(it->second)<<" "; 
		}
		cout<<endl;
	}
		
	return 0;
}
