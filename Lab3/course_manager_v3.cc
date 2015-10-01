#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdexcept>
using namespace std;


//定义struct course 类型
struct Course_struct
{
	int id;
	string name;
} ;

//初始化COURSE类型的vector courses
vector<Course_struct> initvec()
{
	vector<Course_struct> courses;
	vector<string> n{"linux","python","node js","html","C++","HTML"};

	for (int id_t=0 ;id_t < n.size();++id_t){
		Course_struct course_temp;
		course_temp.id = 20150900 + id_t ;
		course_temp.name = n[id_t];
		courses.push_back(course_temp);
	}
	return courses;
}

//帮助页面菜单
int showhelp(){
	cout << "========================================================================="<<endl;
	cout << "|输入0，获取帮助                                                   	|" << endl;
	cout << "|输入1，打印出程序中存储的所有课程ID和课程名                         	|" << endl;
	cout << "|输入2，打印出课程数量                                              	|" << endl;
	cout << "|输入3，打印出名字最长的课程信息，如果有多个相同长度的课程名则都打印  	|" << endl;
	cout << "|输入4，删除最后一个课程，如果没有课程会返回错误信息                 	|" << endl;
	cout << "|输入5，退出程序                                                   	|" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	return 0;
}

//功能1列出所有课程
int listcour(vector<Course_struct> courses){
	for (int i=0;i<courses.size();++i){
	cout <<"课头:"<<courses[i].id ;
 	cout <<"课名:"<<courses[i].name<<endl;
	}
	try{
        if (courses.empty())
            throw runtime_error("没有课程可供选择！");
	}catch(runtime_error err){
        cerr << err.what()<<endl;
        return -1;
    }
 	cout <<"以上课程可供选择！"<<endl;
	return 0;
}

//功能3打印名字最长的课程名
int listlongest(vector<Course_struct> courses){

	Course_struct course_temp=courses[0];
	for (int i =0;i<courses.size();++i){
	if (courses[i].name.size() > course_temp.name.size())
		course_temp = courses[i];
	}

	for (int i =0;i<courses.size();++i){
	if (courses[i].name.size() == course_temp.name.size())
		cout << course_temp.name;
	}
	cout<<endl;
	return 0;
}

//功能4删除最后一个课程
int delcour(vector<Course_struct> &courses){
	try{
        if (courses.empty())//添加 through 功能
            throw runtime_error("没有课程可供移除");
	} catch(runtime_error err){
     cerr<<err.what()<<endl;
     return -1;
	 }

    courses.pop_back();
    cout << "删除成功！"<<endl;
//		listcour(courses);
	return 0;
}
//主函数

int main()
{

	auto courses = initvec();
	cout<<"初始化完毕\n\n"<<endl;
	char choice;
	showhelp();
	cout<<"\n请输入你的选择： ";
    while(cin >> choice){
        try{
            switch(choice)
            {
                case '0':system("cls");showhelp();break;
                case '1':system("cls");listcour(courses);break;
                case '2':system("cls");cout<< courses.size()<<" courses available!"<<endl;break;
                case '3':system("cls");listlongest(courses);break;
                case '4':system("cls");delcour(courses);break;
                case '5':system("cls");return 0;
                default:throw runtime_error("Invalid input");
            }
        }catch(runtime_error err){
                cerr<<err.what()<<endl;
                cout<<"\n请输入你的选择： ";
                continue;
         }
        cout<<"\n请输入你的选择： ";
    }
}
