#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

//定义course类

struct Course{
//一些有用朋友函数
friend istream &read(const isteam&,Course&);
friend ostream &print(const ostream&,Course&);

public:
    //构造函数
    Course() = default;//默认
    Course(string &a):name(a){}
    Course(int &a,string &b): id(a) , name(b){}//参数构造
    Course(isteam&);//用&istream初始化的构造函数

    //返回值函数
    int Course_id(){return id}
    string Course_name(){return name}

    //设置课名函数
    Course set_name(const string&);

private:
    //Course 类成员
    int id;
    string name;
};


//read函数定义
istream &read(coust isteam $is , Course &c){
    is>>c.Course_id>>c.name;
    return is;
}
//print函数定义
ostream &print(coust ostream $os , Course &c){
    os<<c.Course_id<<" "<<c.name;//输出不换行，换行交给main函数
    return os;
}
//构造函数外部定义
Course::Course(istream &is)
{
    read(&is,*this)
}//构造函数 不用返回值 所以没有函数的返回类型

//设置course名
Course &Course::set_name(const string &n){
    this.name=n;
    return *this;
}

#endif // COURSE_H_INCLUDED
