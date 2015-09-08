#include <iostream>
#include <vector>

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
	cout <<"课头号:"<<courses[i].id ;
 	cout <<" 课程名:"<<courses[i].name<<endl;
	}
 	cout <<"以上就是所有课程"<<endl;
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
	if (courses.empty())
		cout << "删除错误，没有课程" << endl;
	else{
		courses.pop_back();
		cout << "删除成功"<<endl;
//		listcour(courses);
	}
	return 0;
}
//主函数

int main()
{
	
	vector<Course_struct> courses = initvec();
	cout<<"初始化完毕！"<<endl;
	char choice;
	showhelp();
	cout<<"输入选项."<<endl;
	while(cin >> choice){
		switch(choice)
		{
			case '0':showhelp();break;
			case '1':listcour(courses);break;
			case '2':cout<< courses.size()<<"门课程可供学习"<<endl;break;
			case '3':listlongest(courses);break;
			case '4':delcour(courses);break;
			case '5':return 0;
			default: cout<<"Invalid input"<<endl;break;
		}
		cout<<"输入选项."<<endl;
	}
}
