
/*
vevtor的实现简单实现
理解模板的用法。
*/

#ifndef MYVECTOR_H
#define MYVECTOR_H
#include<algorithm>
#include<iostream>
#include<assert.h>
using namespace std;
template<typename T>
class myVector{
private:
    #define WALK_LENGTH 64;
public:
myVector():array(0),theSize(0),theCapacity(0){}
myVector(const T& t,unsigned int n):array(0),theSize(0),theCapacity(0)
{
    while(n--){
        push_back(t);
    }
}
myVector(const myVector<T>&  other):array(0),theSize(0),theCapacity(0)
{
    *this=other;//拷贝构造函数
}
 myVector<T>& operator=(myVector<T>& other){//拷贝赋值函数
    if(this==&other)    //避免自赋值，因为传进来的是是一个引用，所以要用取值符
        return *this;
    clear();
    theSize=other.theSize;
    theCapacity=other.theCapacity;
    array=new T[theCapacity];
    for(unsigned int i=0;i<theSize;++i){
        array[i]=other[i];
    }
    return *this;
}
~myVector(){
clear();
}
 T& operator[](unsigned int pos ){
    assert(pos<theSize);//计算表达式，如果表达式出错，则输出。
    return array[pos];
}
void push_back(const T& t)
{
    insert_after(theSize-1,t);
}
void push_front(const T& t)
{
    insert_before(0,t);
}
void insert_after(int pos,const T& t)
{
    insert_before(pos+1,t);
}
void insert_before(int pos,const T&t)
{
    if(theSize==theCapacity){
        T* oldArray=array;
        theCapacity+=WALK_LENGTH;
        array=allocator(theCapacity);
        for(unsigned int i=0;i<theSize;++i)
        {
            array[i]=oldArray[i];
        }
        deallocator(oldArray);
    }

    for(int i=(int)theSize++;i>pos;--i){
        array[i]=array[i-1];
    }
    array[pos]=t;
}
void erase(unsigned int pos)
{
    if(pos<theSize){
        --theSize;
        for(unsigned int i=pos;i<theSize;++i)
        {
            array[i]=array[i+1];
        }
    }
}
unsigned int capacity()
{
    return theCapacity;
}
unsigned int size()
{
    return theSize;
}
bool empty()
{
return theSize==0;
}

void clear(){
    deallocator(array);
    array=0;
    theCapacity=0;
    theSize=0;
}
private:
    T* allocator(unsigned int size)
    {
        return new T[size];  //申请一个新的大小为size的数组
    }
    void deallocator(T* arr){
        if(arr)
            delete[] arr;//如果arr不为空，删除指向数组的指针
            arr=0;//然后将指针赋值为0，避免空悬指针。
    }
private:
    T*  array;//指向T 类型的指针。
    unsigned int theSize;
    unsigned int theCapacity;
};
template<typename T> void printfVector(myVector<T> & vector1)
{
    for(unsigned int i=0;i<vector1.size();++i){
        std::cout<<vector1[i]<<",";
    }
    std::cout<<"alloc capacity= "<<vector1.capacity()<<",size= "<<vector1.size()<<std::endl;
}

#endif MYVECTOR_H
