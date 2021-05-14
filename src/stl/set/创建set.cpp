#include <iostream>
#include <set>

using namespace std;

set<char> retSet()
{
    set<char> temp{'a', 'b', 'c'};
    return temp;
}

int main()
{
    // 方式一：
    // 调用默认构造函数，创建空的set容器
    set<char> set1;

    // 方式二：
    // 创建set容器的同时，进行初始化
    set<char> set2{'a', 'b', 'c'};

    // 方式三：
    // 使用拷贝构造函数，在创建新set容器的同时，将已有set容器中存储的所有元素都复制到新set容器中
    set<char> set3(set2);
    // 等同于以下语句
    set<char> set4 = set2;

    // C++ 11 标准还为 set 类模板新增了移动构造函数，其功能是实现创建新 set 容器的同时，利用临时的 set 容器为其初始化
    set<char> set5(retSet());

    // 方式四：
    // 从已有的set容器中选取指定区域元素，创建并初始化新的set容器
    set<char> set6(++set5.begin(), set5.end());

    // 方式五：
    // 以上方法在创建set容器时都采用了默认的std::less<T>排序规则
    // 其实可以在创建set容器时手动修改排序规则
    set<char, greater<char>> set7{'a', 'b'};
}