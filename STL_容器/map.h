/*
map的一些操作
*/

#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
//map 默认的排序方式是从小到大，现在写一个函数将排序方式转变为从大到小。
using namespace std;
typedef pair<string,int> PAIR;

bool cmp_by_value(const PAIR &lhs,const PAIR &rhs){
return lhs.second<rhs.second;
}
struct CmpByValue{
    bool operator()(const PAIR &lhs,const PAIR & rhs)
    {
        return lhs.second<rhs.second;
    }

};
int main(){

map<string ,int> name_score_map;
name_score_map["zzz"]=90;
name_score_map["ppp"]=79;
name_score_map["ooo"]=92;
name_score_map.insert(make_pair("aaa",34));
name_score_map.insert(make_pair("bbb",56));
/*将map中的元素转存到vector中*/
vector<PAIR>name_score_vec(name_score_map.begin(),name_score_map.end());

/*sort(name_score_vec.begin(),name_score_vec.end(),cmp_by_value);*/
sort(name_score_vec.begin(),name_score_vec.end(),CmpByValue());

/*
map内部本身就是按序存储的（红黑树），在插入键值对是，按照key的大小顺序进行存储。
这也是存储在map中的key必须能够进行<运算比较的原因。
map是一个集合容器，map里存储的元素是pair，但不是线性存储的。
stl中的sort算法只能对序列容器进行排序，而且是线性的，所以不能直接使用sort对map进行排序，
可以将map的元素放到序列容器(比如vector中),然后sort对vector内元素进行排序。
*/


//sort算法支队
//sort(name_score_vec.begin(),name_score_vec.end());//map排序默认是pair.first 从小到大，这里自定义为
//map.second  从到小


auto iter=name_score_vec.begin();
for(;iter!=name_score_vec.end();++iter){

    std::cout<<(*iter).first<<"---"<<(*iter).second<<endl;
}

return 0;
}
