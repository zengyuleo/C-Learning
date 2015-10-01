#ifndef COURSE_M_H_INCLUDED
#define COURSE_M_H_INCLUDED

#include <stdio>
#include <string>
#include "course.h"

using namespace std;
class CourseManage{
//friend int search_id(vector<Course>&,int);
//friend int search_id(vector<Course>&,string);
friend ifstream writefile(const vector<Course>& , string);//写入文件帮助

private:
    vector<Course> course_list;

public:
    //构造函数
    CourseManage = default;
    CourseManage(vector<Course>&);
   // CourseManage(Course &);//未完成

    //功能实现
    int add_course(const string &);
    int add_course(Course &);
    int rm_recent();
    int rm_course(const int &);
    int rm_course(const string &);
    int print_list();
    int print_course(const int &);
    int print_course(const string &);
    int output_f(const string &);
    vector<Course>::size_type course_num(){return this.size()}
};

//具体实现

//构造函数
CourseManager::CourseManager(vector<Course> &item){
    for(auto it=item.begin();it!=item.end();++it)
        this.course_list.push_back(*it);
}

//添加课程str
int CourseManage::add_course(const string &n){
    this.course_list.push_back(Course(n));//Course是一个构造函数
    return 0;
}
int CourseManage::add_course(Course &item){
    this.course_list.push_back(item);
    return 0;
}
int rm_recent(){
    this.course_list.pop_back();
    return 0;
}


//删除课程id
int rm_course(int &n){
    for (auto it=this.course_list.begin();it!=this.course_list.end();++it){
        if (it->id == n){
            it=this.course_list.erase(it);
            return 0;
        }
        else continue;
    }
    return 1;
}

//删除课程str
int rm_course(string &n){
    for (auto it=this.course_list.begin();it!=this.course_list.end();++it){
        if (it->name == n){
            it=this.course_list.erase(it);
            return 0;
        }
        else continue;
    }
    return 1;
}

//打印整个list
int print_list(){
    for (auto it=this.course_list.begin();it!=this.course_list.end();++it){
        print(cout,*it);
        cout<<endl;
    }
    return 0;
}

//打印id特定的course
int print_course(int &n){
    for (auto it=this.course_list.begin();it!=this.course_list.end();++it){
        if (it->id == n){
            print(cout,*it);
            cout<<endl;
            return 0;
        }
        else continue;
    }
    return 1;
}

//打印名字特定的course
int print_course(string &n){
    for (auto it=this.course_list.begin();it!=this.course_list.end();++it){
        if (it->name == n){
            print(cout,*it);
            cout<<endl;
            return 0;
        }
        else continue;
    }
    return 1;
}

//给一个n可以让文件输出道filex里面
int output_f(const string n){
    ofstream output("file"+n);
    for (auto it=this.course_list.begin();it!=this.course_list.end();++it){
        print(output,*it);
        output<<endl;
    }
    return 0;
}

#endif // COURSE_M_H_INCLUDED
