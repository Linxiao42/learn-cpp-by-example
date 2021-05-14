/**
 * multimultiset容器和multiset容器唯一的差别在于，multimultiset容器允许存储多个值相同的元素
 * 而multiset容器中只能存储互不相同的元素
 */
 
#include <iostream>
#include <set>

using namespace std;

multiset<char> retMultiset()
{
    multiset<char> temp{'a', 'b', 'c'};
    return temp;
}

void create() {
    // 方式一：
    // 调用默认构造函数，创建空的multiset容器
    multiset<char> multiset1;

    // 方式二：
    // 创建multiset容器的同时，进行初始化
    multiset<char> multiset2{'a', 'b', 'c'};

    // 方式三：
    // 使用拷贝构造函数，在创建新multiset容器的同时，将已有multiset容器中存储的所有元素都复制到新multiset容器中
    multiset<char> multiset3(multiset2);
    // 等同于以下语句
    multiset<char> multiset4 = multiset2;

    // C++ 11 标准还为 multiset 类模板新增了移动构造函数，其功能是实现创建新 multiset 容器的同时，利用临时的 multiset 容器为其初始化
    // 由于 retMultiset() 函数的返回值是一个临时 multiset 容器，因此在初始化 multiset5 容器时
    // 其内部调用的是 multiset 类模板中的移动构造函数，而非拷贝构造函数
    multiset<char> multiset5(retMultiset());

    // 方式四：
    // 从已有的multiset容器中选取指定区域元素，创建并初始化新的multiset容器
    multiset<char> multiset6(++multiset5.begin(), multiset5.end());

    // 方式五：
    // 以上方法在创建multiset容器时都采用了默认的std::less<T>排序规则
    // 其实可以在创建multiset容器时手动修改排序规则
    multiset<char, greater<char>> multiset7{'a', 'b'};
}
int main()
{
    create();
}
