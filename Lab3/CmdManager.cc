#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#inclulde course.h
#include course_m.h


using namespace std;
//CmdManager类
class CmdManager{
public:
	//构造函数
	CmdManager()=default;
	const void PrintHelp();
	const bool workOnot(string&);

private:
string<string> CmdHelp;
vector<string> CmdList;
};	

const bool workOnot(string $n){
	for(it=this.CmdList.begin();it!=this.CmdList.end();++it){
	if (n==it->name)
		return ture;
	}
	return false;
}

const void PrintHelp(){
	decltype(CmdList.size()) i;
	for(i=0;i!=CmdList.size();++i){
	cin<<"Comand Name:"<<CmdList[i]<<endl;
	cin<<"Usage:"<<CmdHelp[i]<<endl;
	} 
}
