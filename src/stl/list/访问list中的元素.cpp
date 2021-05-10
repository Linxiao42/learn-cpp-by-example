/**
* 访问 list 容器中存储元素的方式很有限，即要么使用 front() 和 back() 成员函数，要么使用 list 容器迭代器
* list 容器不支持随机访问，未提供下标操作符 [] 和 at() 成员函数，也没有提供 data() 成员函数
*/

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lst{1, 2, 3, 4};
    int &first = lst.front();
    int &last = lst.back();

    cout << first << " " << last << endl;
    first = 10;
    last = 20;
    cout << lst.front() << " " << lst.back() << endl;
}